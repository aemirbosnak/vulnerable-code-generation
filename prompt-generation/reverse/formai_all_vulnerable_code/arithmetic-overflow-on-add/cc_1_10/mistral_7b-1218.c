//MISTRAL-7B DATASET v1.0 Category: Port Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define TIMEOUT 1000

struct addrinfo hints, *res;
char ipstr[INET6_ADDRSTRLEN];
int sockfd, i, j, port, status;
char buf[BUF_SIZE];
struct sockaddr_in serv_addr;

void die(const char *msg) {
    perror(msg);
    exit(1);
}

void print_banner() {
    printf("\n");
    printf("-------------------------------------------------------------------------\n");
    printf("|                     Dr. Watson's Port Scanner v1.0                      |\n");
    printf("|                             By Sherlock Holmes                         |\n");
    printf("|                             221B Baker Street                          |\n");
    printf("|                              London, England                           |\n");
    printf("-------------------------------------------------------------------------\n");
}

void scan_port(int port) {
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(ipstr);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        status = 0;
    } else {
        send(sockfd, "Sherlock Holmes, 221B Baker Street, London, England\r\n", 43, 0);
        memset(buf, 0, BUF_SIZE);
        i = recv(sockfd, buf, BUF_SIZE, 0);

        if (i > 0 && strstr(buf, "200 OK") != NULL) {
            status = 1;
        }

        close(sockfd);
    }
}

int main(int argc, char **argv) {
    print_banner();

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(argv[1], NULL, &hints, &res) < 0) {
        die("getaddrinfo");
    }

    if (inet_ntop(AF_INET, &(res->ai_addr)->sa_data, ipstr, sizeof ipstr) == NULL) {
        die("inet_ntop");
    }

    if ((sockfd = socket(res->ai_family, res->ai_socktype, IPPROTO_TCP)) < 0) {
        die("socket");
    }

    for (i = 1, port = 1; port <= 65535; i++, port += 10) {
        printf("Scanning port %d... ", port);
        fflush(stdout);
        scan_port(port);
        if (status == 1) printf("OPEN\n"); else printf("CLOSED\n");
        usleep(TIMEOUT);
    }

    freeaddrinfo(res);
    close(sockfd);
    return 0;
}