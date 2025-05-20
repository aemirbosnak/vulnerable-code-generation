//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>
#include <openssl/ssl.h>

#define BUF_SIZE 1024
#define MAX_CONNECTIONS 10

char buf[BUF_SIZE];
int sockfd;
SSL *ssl;
pthread_t tid[MAX_CONNECTIONS];
pthread_mutex_t lock;

void *client_handler(void *arg) {
  int sockfd = *(int *)arg;
  while (1) {
    int num_bytes = recv(sockfd, buf, BUF_SIZE, 0);
    if (num_bytes <= 0) {
      if (num_bytes == 0) {
        printf("Peer closed connection.\n");
      } else {
        printf("Recv error: %s\n", strerror(errno));
      }
      close(sockfd);
      pthread_exit(NULL);
    }
    buf[num_bytes] = '\0';
    printf("Received from peer: %s", buf);
    char *response = "Received your message.";
    int num_bytes_sent = send(sockfd, response, strlen(response), 0);
    if (num_bytes_sent < 0) {
      printf("Send error: %s\n", strerror(errno));
      close(sockfd);
      pthread_exit(NULL);
    }
  }
}

int main(int argc, char *argv[]) {
  int port = atoi(argv[1]);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Socket creation failed");
    return -1;
  }
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(port);
  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("Bind failed");
    return -1;
  }
  if (listen(sockfd, MAX_CONNECTIONS) < 0) {
    perror("Listen failed");
    return -1;
  }
  SSL_library_init();
  SSL_load_error_strings();
  SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_server_method());
  if (!ctx) {
    perror("SSL context creation failed");
    return -1;
  }
  if (SSL_CTX_use_certificate_file(ctx, "server.crt", SSL_FILETYPE_PEM) != 1) {
    perror("Unable to load server certificate");
    return -1;
  }
  if (SSL_CTX_use_PrivateKey_file(ctx, "server.key", SSL_FILETYPE_PEM) != 1) {
    perror("Unable to load server private key");
    return -1;
  }
  pthread_mutex_init(&lock, NULL);
  while (1) {
    int new_sockfd;
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len);
    if (new_sockfd < 0) {
      perror("Accept failed");
      continue;
    }
    pthread_mutex_lock(&lock);
    SSL *new_ssl = SSL_new(ctx);
    SSL_set_fd(new_ssl, new_sockfd);
    if (SSL_accept(new_ssl) <= 0) {
      perror("SSL accept failed");
      SSL_free(new_ssl);
      close(new_sockfd);
      pthread_mutex_unlock(&lock);
      continue;
    }
    ssl = new_ssl;
    pthread_create(&tid[new_sockfd], NULL, client_handler, &new_sockfd);
    pthread_detach(tid[new_sockfd]);
    pthread_mutex_unlock(&lock);
  }
  close(sockfd);
  return 0;
}