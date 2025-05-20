//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 100
#define PORT "80"

void scan(char *ip);

int main(int argc, char *argv[]) {
    char ip[MAX];
    FILE *fp;
    fp = fopen("ips.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    while (fscanf(fp, "%s", ip)!= EOF) {
        scan(ip);
    }
    fclose(fp);
    return 0;
}

void scan(char *ip) {
    int sock, port = 0;
    struct hostent *host;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    host = gethostbyname(ip);
    if (host == NULL) {
        printf("Error resolving host.\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(PORT));
    server.sin_addr = *((struct in_addr *) host->h_addr);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        printf("Error connecting to host.\n");
        exit(1);
    }

    printf("Host %s is up.\n", ip);
    close(sock);
}