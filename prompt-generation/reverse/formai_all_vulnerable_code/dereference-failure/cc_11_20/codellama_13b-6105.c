//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: Ada Lovelace
/*
 * POP3 Client Example Program
 *
 * This program demonstrates how to connect to a POP3 server and retrieve
 * emails using the POP3 protocol.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    /* Create a socket for connecting to the POP3 server */
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    /* Get the address of the POP3 server */
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Could not find host %s\n", argv[1]);
        return 1;
    }

    /* Connect to the POP3 server */
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(POP3_PORT);
    addr.sin_addr = *((struct in_addr *)host->h_addr);
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    /* Send the USER command to the POP3 server */
    char *username = getenv("USER");
    char buf[BUFSIZE];
    snprintf(buf, BUFSIZE, "USER %s\r\n", username);
    send(sock, buf, strlen(buf), 0);

    /* Read the response from the POP3 server */
    char resp[BUFSIZE];
    if (recv(sock, resp, BUFSIZE, 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("Response: %s\n", resp);

    /* Send the PASS command to the POP3 server */
    char *password = getenv("PASSWORD");
    snprintf(buf, BUFSIZE, "PASS %s\r\n", password);
    send(sock, buf, strlen(buf), 0);

    /* Read the response from the POP3 server */
    if (recv(sock, resp, BUFSIZE, 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("Response: %s\n", resp);

    /* Send the STAT command to the POP3 server */
    snprintf(buf, BUFSIZE, "STAT\r\n");
    send(sock, buf, strlen(buf), 0);

    /* Read the response from the POP3 server */
    if (recv(sock, resp, BUFSIZE, 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("Response: %s\n", resp);

    /* Send the LIST command to the POP3 server */
    snprintf(buf, BUFSIZE, "LIST\r\n");
    send(sock, buf, strlen(buf), 0);

    /* Read the response from the POP3 server */
    if (recv(sock, resp, BUFSIZE, 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("Response: %s\n", resp);

    /* Send the RETR command to the POP3 server */
    snprintf(buf, BUFSIZE, "RETR 1\r\n");
    send(sock, buf, strlen(buf), 0);

    /* Read the response from the POP3 server */
    if (recv(sock, resp, BUFSIZE, 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("Response: %s\n", resp);

    /* Send the DELE command to the POP3 server */
    snprintf(buf, BUFSIZE, "DELE 1\r\n");
    send(sock, buf, strlen(buf), 0);

    /* Read the response from the POP3 server */
    if (recv(sock, resp, BUFSIZE, 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("Response: %s\n", resp);

    /* Send the NOOP command to the POP3 server */
    snprintf(buf, BUFSIZE, "NOOP\r\n");
    send(sock, buf, strlen(buf), 0);

    /* Read the response from the POP3 server */
    if (recv(sock, resp, BUFSIZE, 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("Response: %s\n", resp);

    /* Send the QUIT command to the POP3 server */
    snprintf(buf, BUFSIZE, "QUIT\r\n");
    send(sock, buf, strlen(buf), 0);

    /* Read the response from the POP3 server */
    if (recv(sock, resp, BUFSIZE, 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("Response: %s\n", resp);

    return 0;
}