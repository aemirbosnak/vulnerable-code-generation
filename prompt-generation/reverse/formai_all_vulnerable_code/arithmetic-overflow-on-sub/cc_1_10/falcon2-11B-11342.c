//Falcon2-11B DATASET v1.0 Category: Networking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Function to establish a TCP connection
int establish_connection(const char *host, const char *port) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    portno = htons(atoi(port));
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send data over TCP connection
void send_data(int sockfd, char *data, int length) {
    int sent = 0;
    while (sent < length) {
        sent += send(sockfd, data + sent, length - sent, 0);
        if (sent < length)
            usleep(10); // Pause for 10 milliseconds
    }
}

// Function to receive data over TCP connection
int receive_data(int sockfd, char *buffer, int length) {
    int received = 0;
    while (received < length) {
        received += recv(sockfd, buffer + received, length - received, 0);
        if (received < length)
            usleep(10); // Pause for 10 milliseconds
    }
    return received;
}

// Function to close TCP connection
void close_connection(int sockfd) {
    if (sockfd > 0) {
        close(sockfd);
    }
}

int main() {
    int sockfd, portno;
    char buffer[1024];
    struct hostent *server;

    sockfd = establish_connection("example.com", "8080");
    if (sockfd < 0) {
        perror("ERROR establishing connection");
        exit(EXIT_FAILURE);
    }

    printf("Enter a message to send:\n");
    fgets(buffer, sizeof(buffer), stdin);

    send_data(sockfd, buffer, strlen(buffer));

    printf("Received data:\n");
    int data_length = receive_data(sockfd, buffer, sizeof(buffer));
    buffer[data_length] = '\0';
    printf("%s\n", buffer);

    close_connection(sockfd);

    return 0;
}