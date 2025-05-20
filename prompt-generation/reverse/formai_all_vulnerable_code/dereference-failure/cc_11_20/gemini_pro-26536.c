//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

typedef struct {
    int sockfd;
    struct sockaddr_in server_addr;
    char *hostname;
    int port;
} smtp_client_t;

static void *smtp_client_thread(void *arg) {
    smtp_client_t *client = (smtp_client_t *)arg;
    int sockfd = client->sockfd;
    struct sockaddr_in server_addr = client->server_addr;
    char *hostname = client->hostname;
    int port = client->port;

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return NULL;
    }

    // Read the greeting from the SMTP server
    char buf[1024];
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return NULL;
    }

    // Send the HELO command to the SMTP server
    sprintf(buf, "HELO %s\r\n", hostname);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return NULL;
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return NULL;
    }

    // Send the MAIL FROM command to the SMTP server
    sprintf(buf, "MAIL FROM: <sender@example.com>\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return NULL;
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return NULL;
    }

    // Send the RCPT TO command to the SMTP server
    sprintf(buf, "RCPT TO: <recipient@example.com>\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return NULL;
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return NULL;
    }

    // Send the DATA command to the SMTP server
    sprintf(buf, "DATA\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return NULL;
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return NULL;
    }

    // Send the email message to the SMTP server
    sprintf(buf, "Subject: Test email\r\n\r\nThis is a test email.\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return NULL;
    }

    // Send the dot command to the SMTP server to indicate the end of the email message
    sprintf(buf, ".\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return NULL;
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return NULL;
    }

    // Send the QUIT command to the SMTP server
    sprintf(buf, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return NULL;
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return NULL;
    }

    // Close the connection to the SMTP server
    close(sockfd);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s hostname port num_threads\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    int num_threads = atoi(argv[3]);

    // Create a socket for the SMTP client
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the SMTP server
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Set up the sockaddr_in structure for the SMTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr_list[0];

    // Create a thread pool for the SMTP client
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        smtp_client_t *client = malloc(sizeof(smtp_client_t));
        client->sockfd = sockfd;
        client->server_addr = server_addr;
        client->hostname = hostname;
        client->port = port;

        if (pthread_create(&threads[i], NULL, smtp_client_thread, (void *)client) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    // Join the threads in the thread pool
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return EXIT_FAILURE;
        }
    }

    // Close the socket for the SMTP client
    close(sockfd);

    return EXIT_SUCCESS;
}