//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/utsname.h>

#define PORT 8080
#define MAX_READ_SIZE 1024

char buffer[MAX_READ_SIZE];
int sockfd;

void error(char *msg) {
    perror(msg);
    exit(0);
}

void send_data() {
    int n;

    printf("Enter message: ");

    bzero(buffer, sizeof(buffer));

    fgets(buffer, sizeof(buffer), stdin);

    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        error("Error writing to socket");
    }
}

void read_data() {
    int n;

    bzero(buffer, MAX_READ_SIZE);

    n = read(sockfd, buffer, MAX_READ_SIZE);

    if (n < 0) {
        error("Error reading from socket");
    }

    printf("%s\n", buffer);
}

int main() {
    int n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    struct utsname name;

    uname(&name);

    printf("Starting network QoS monitor on %s\n", name.nodename);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("Error opening socket");
    }

    server = gethostbyname("localhost");

    if (server == NULL) {
        error("Error, no such host");
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting");
    }

    while (1) {
        printf("Select option:\n1. Send data\n2. Read data\n3. Exit\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                send_data();
                break;
            case 2:
                read_data();
                break;
            case 3:
                printf("Exiting...\n");
                close(sockfd);
                return 0;
            default:
                printf("Error, invalid option selected\n");
                break;
        }
    }
    return 0;
}