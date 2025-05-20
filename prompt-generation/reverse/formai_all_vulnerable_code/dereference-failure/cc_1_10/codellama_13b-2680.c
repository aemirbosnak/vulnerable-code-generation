//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: accurate
/*
 * imap_client.c
 *
 * A simple IMAP client program in C
 *
 * Usage: imap_client <server> <username> <password>
 *
 * Author: Nishant Arora
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_PORT 993
#define IMAP_MAX_LINE 1024

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: imap_client <server> <username> <password>\n");
    return 1;
  }

  char *server = argv[1];
  char *username = argv[2];
  char *password = argv[3];

  struct addrinfo hints = {0};
  struct addrinfo *result, *rp;

  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;

  int err = getaddrinfo(server, NULL, &hints, &result);
  if (err != 0) {
    printf("Error: %s\n", gai_strerror(err));
    return 1;
  }

  int sock = -1;
  for (rp = result; rp != NULL; rp = rp->ai_next) {
    sock = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (sock == -1) {
      continue;
    }

    if (connect(sock, rp->ai_addr, rp->ai_addrlen) != -1) {
      break;
    }

    close(sock);
    sock = -1;
  }

  freeaddrinfo(result);

  if (sock == -1) {
    printf("Error: Could not connect to server\n");
    return 1;
  }

  SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
  if (ctx == NULL) {
    printf("Error: Could not create SSL context\n");
    return 1;
  }

  SSL *ssl = SSL_new(ctx);
  if (ssl == NULL) {
    printf("Error: Could not create SSL connection\n");
    return 1;
  }

  SSL_set_fd(ssl, sock);
  if (SSL_connect(ssl) != 1) {
    printf("Error: Could not establish SSL connection\n");
    return 1;
  }

  char buf[IMAP_MAX_LINE];
  snprintf(buf, IMAP_MAX_LINE, "* OK IMAP4rev1 %s\r\n", server);
  SSL_write(ssl, buf, strlen(buf));

  snprintf(buf, IMAP_MAX_LINE, "a001 CAPABILITY\r\n");
  SSL_write(ssl, buf, strlen(buf));

  SSL_read(ssl, buf, IMAP_MAX_LINE);
  printf("%s\n", buf);

  snprintf(buf, IMAP_MAX_LINE, "a002 LOGIN %s %s\r\n", username, password);
  SSL_write(ssl, buf, strlen(buf));

  SSL_read(ssl, buf, IMAP_MAX_LINE);
  printf("%s\n", buf);

  snprintf(buf, IMAP_MAX_LINE, "a003 LIST \"\" \"\"\r\n");
  SSL_write(ssl, buf, strlen(buf));

  SSL_read(ssl, buf, IMAP_MAX_LINE);
  printf("%s\n", buf);

  snprintf(buf, IMAP_MAX_LINE, "a004 SELECT INBOX\r\n");
  SSL_write(ssl, buf, strlen(buf));

  SSL_read(ssl, buf, IMAP_MAX_LINE);
  printf("%s\n", buf);

  snprintf(buf, IMAP_MAX_LINE, "a005 EXAMINE INBOX\r\n");
  SSL_write(ssl, buf, strlen(buf));

  SSL_read(ssl, buf, IMAP_MAX_LINE);
  printf("%s\n", buf);

  snprintf(buf, IMAP_MAX_LINE, "a006 FETCH 1:* FLAGS\r\n");
  SSL_write(ssl, buf, strlen(buf));

  SSL_read(ssl, buf, IMAP_MAX_LINE);
  printf("%s\n", buf);

  SSL_shutdown(ssl);
  SSL_free(ssl);
  SSL_CTX_free(ctx);
  close(sock);

  return 0;
}