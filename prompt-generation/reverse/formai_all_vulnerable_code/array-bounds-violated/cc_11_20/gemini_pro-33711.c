//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_HOST_NAME_LEN 256
#define MAX_IP_ADDR_LEN 16

void fatal(char *s) {
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

int main(void) {
    struct hostent *host;
    struct sockaddr_in addr;
    int sockfd;
    int port;
    char host_name[MAX_HOST_NAME_LEN];
    char ip_addr[MAX_IP_ADDR_LEN];
    char buf[1024] = "Hello, world!";
    char *args[] = {"smtpd", "localhost", "587", NULL};
    time_t rawtime;
    struct tm *timeinfo;

    if (args[1] == NULL) {
        printf("Usage: %s [host] [port]\n", args[0]);
        exit(EXIT_FAILURE);
    }
    if (args[2] != NULL) {
        port = atoi(args[2]);
    } else {
        port = 25;
    }

    if (gethostname(host_name, MAX_HOST_NAME_LEN) == -1) {
        fatal("gethostname() failed");
    }
    if ((host = gethostbyname(args[1])) == NULL) {
        fatal("gethostbyname() failed");
    }
    if (inet_ntop(AF_INET, host->h_addr, ip_addr, MAX_IP_ADDR_LEN) == NULL) {
        fatal("inet_ntop() failed");
    }
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fatal("socket() failed");
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *((struct in_addr *)host->h_addr);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        fatal("connect() failed");
    }
    if (write(sockfd, "EHLO ", 5) == -1) {
        fatal("write() failed");
    }
    if (write(sockfd, host_name, strlen(host_name)) == -1) {
        fatal("write() failed");
    }
    if (write(sockfd, "\r\n", 2) == -1) {
        fatal("write() failed");
    }
    if (write(sockfd, "MAIL FROM: ", 11) == -1) {
        fatal("write() failed");
    }
    if (write(sockfd, args[3], strlen(args[3])) == -1) {
        fatal("write() failed");
    }
    if (write(sockfd, "\r\n", 2) == -1) {
        fatal("write() failed");
    }
    if (write(sockfd, "RCPT TO: ", 9) == -1) {
        fatal("write() failed");
    }
    if (write(sockfd, args[4], strlen(args[4])) == -1) {
        fatal("write() failed");
    }
    if (write(sockfd, "\r\n", 2) == -1) {
        fatal("write() failed");
    }
    if (write(sockfd, "DATA\r\n", 6) == -1) {
        fatal("write() failed");
    }
    if (write(sockfd, buf, strlen(buf)) == -1) {
        fatal("write() failed");
    }
    if (write(sockfd, "\r\n.\r\n", 5) == -1) {
        fatal("write() failed");
    }
    if (write(sockfd, "QUIT\r\n", 6) == -1) {
        fatal("write() failed");
    }
    if (close(sockfd) == -1) {
        fatal("close() failed");
    }
    if (time(&rawtime) == -1) {
        fatal("time() failed");
    }
    if ((timeinfo = localtime(&rawtime)) == NULL) {
        fatal("localtime() failed");
    }
    if (strftime(buf, sizeof(buf), "%c", timeinfo) == 0) {
        fatal("strftime() failed");
    }
    if (printf("Date: %s\n", buf) < 0) {
        fatal("printf() failed");
    }
    return EXIT_SUCCESS;
}