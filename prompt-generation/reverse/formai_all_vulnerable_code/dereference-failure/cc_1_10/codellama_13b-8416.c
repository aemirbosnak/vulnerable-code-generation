//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: rigorous
/*
 * C Network Ping Test Example
 *
 * This program demonstrates how to use the POSIX ping function to send
 * an ICMP echo request to a host and receive a response.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <errno.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_RESPONSE_LEN 256

int main(int argc, char *argv[]) {
    char hostname[MAX_HOSTNAME_LEN];
    char response[MAX_RESPONSE_LEN];
    struct hostent *host;
    struct sockaddr_in server;
    struct sockaddr_in client;
    socklen_t client_len;
    int sockfd;
    int response_len;

    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    /* Get the hostname from the command line argument */
    strncpy(hostname, argv[1], MAX_HOSTNAME_LEN);

    /* Look up the hostname and get its IP address */
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Could not resolve hostname: %s\n", hstrerror(h_errno));
        return 1;
    }

    /* Create a socket for sending and receiving data */
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    /* Set the IP address and port number for the server */
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = *(long *)host->h_addr;
    server.sin_port = 0;

    /* Bind the socket to the local IP address and port */
    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        return 1;
    }

    /* Send an ICMP echo request to the server */
    if (sendto(sockfd, "Ping!", 6, 0, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("sendto");
        return 1;
    }

    /* Receive the ICMP echo response from the server */
    client_len = sizeof(client);
    response_len = recvfrom(sockfd, response, MAX_RESPONSE_LEN, 0, (struct sockaddr *)&client, &client_len);
    if (response_len < 0) {
        perror("recvfrom");
        return 1;
    }

    /* Print the IP address and port number of the server */
    printf("Received response from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

    /* Print the response data */
    printf("Response data: %s\n", response);

    /* Close the socket */
    close(sockfd);

    return 0;
}