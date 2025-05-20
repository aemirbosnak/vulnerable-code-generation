//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

/* Define the maximum number of hosts to scan */
#define MAX_HOSTS 256

/* Define some network constants */
#define PORT 80
#define TIMEOUT 5

/* The main function */
int main(int argc, char *argv[]) {
    /* Declare some variables */
    int sockfd, optval, nfound, i, j, k;
    struct sockaddr_in addr;
    char *hostname, *ipaddr, *ptr;
    fd_set readset;
    struct timeval tv;
    char buffer[1024];

    /* Check if the user has supplied an argument */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <network>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Get the network address */
    hostname = argv[1];

    /* Initialize the socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to initialize the socket");
        exit(EXIT_FAILURE);
    }

    /* Set the socket options */
    optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    /* Initialize the address structure */
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;

    /* Get the IP address of the network */
    struct hostent *he;
    if ((he = gethostbyname(hostname)) == NULL) {
        herror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    ipaddr = inet_ntoa(*(struct in_addr *)he->h_addr_list[0]);

    /* Start scanning the network */
    printf("Scanning network...\n\n");
    for (i = 0; i < MAX_HOSTS; i++) {
        /* Set the address */
        addr.sin_addr.s_addr = inet_addr(ipaddr) + htonl(i);

        /* Connect */
        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            continue;
        }

        /* Send a request */
        sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:100.0) Gecko/20100101 Firefox/100.0\r\nConnection: close\r\n\r\n", hostname);
        write(sockfd, buffer, strlen(buffer));

        /* Wait for a response */
        FD_ZERO(&readset);
        FD_SET(sockfd, &readset);
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;
        nfound = select(sockfd+1, &readset, NULL, NULL, &tv);
        if (nfound <= 0) {
            close(sockfd);
            continue;
        }

        /* Read the response */
        memset(buffer, 0, sizeof(buffer));
        nfound = read(sockfd, buffer, sizeof(buffer));
        if (nfound <= 0) {
            close(sockfd);
            continue;
        }

        /* Parse the response */
        ptr = strstr(buffer, "Server:");
        if (ptr == NULL) {
            close(sockfd);
            continue;
        }
        ptr += strlen("Server:");
        while (*ptr == ' ' || *ptr == '\t') ptr++;
        j = 0;
        while (ptr[j] != '\r' && ptr[j] != '\n') j++;
        ptr[j] = '\0';
        printf("%-15s %s\n", inet_ntoa(addr.sin_addr), ptr);

        /* Close the socket */
        close(sockfd);
    }

    /* End the program */
    printf("\nDone.\n");
    exit(EXIT_SUCCESS);
}