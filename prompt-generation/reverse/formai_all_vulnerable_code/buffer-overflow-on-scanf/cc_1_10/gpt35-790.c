//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 1024

struct email_data {
    char username[50];
    char password[50];
    char server_address[50];
    int server_port;
};

void *fetch_emails(void *args) {
    struct email_data *details = (struct email_data *)args;

    // Connect to the POP3 server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        return NULL;
    }

    struct hostent *host = gethostbyname(details->server_address);
    if (host == NULL) {
        perror("Unknown host");
        return NULL;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(details->server_port);
    server_address.sin_addr = *((struct in_addr*)host->h_addr);

    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to server");
        return NULL;
    }

    // Login
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);
    sprintf(buffer, "USER %s\r\n", details->username);
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, MAX_BUFFER_SIZE);
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

    memset(buffer, 0, MAX_BUFFER_SIZE);
    sprintf(buffer, "PASS %s\r\n", details->password);
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, MAX_BUFFER_SIZE);
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

    // List emails
    memset(buffer, 0, MAX_BUFFER_SIZE);
    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, MAX_BUFFER_SIZE);
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);

    close(sockfd);
    return NULL;
}

int main() {
    // Collect email details from user
    struct email_data details;
    printf("Enter email address: ");
    scanf("%s", details.username);
    printf("Enter email password: ");
    scanf("%s", details.password);
    printf("Enter server address: ");
    scanf("%s", details.server_address);
    printf("Enter server port: ");
    scanf("%d", &details.server_port);

    // Create a new thread to fetch emails
    pthread_t email_thread;
    pthread_create(&email_thread, NULL, fetch_emails, (void *)&details);

    // Wait for thread to complete
    pthread_join(email_thread, NULL);

    return 0;
}