//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s server_address port_number\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get server address
    struct hostent *he = gethostbyname(argv[1]);
    if (he == NULL) {
        herror("Error getting host by name");
        exit(1);
    }

    // Set server address and port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    memcpy(&server_address.sin_addr, he->h_addr_list[0], he->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send user and password
    char user[BUFFER_SIZE], pass[BUFFER_SIZE];
    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);
    char auth[BUFFER_SIZE];
    sprintf(auth, "USER %s\r\n", user);
    write(sockfd, auth, strlen(auth));
    char response[BUFFER_SIZE];
    read(sockfd, response, BUFFER_SIZE);
    sprintf(auth, "PASS %s\r\n", pass);
    write(sockfd, auth, strlen(auth));
    read(sockfd, response, BUFFER_SIZE);

    // Send list command to retrieve list of emails
    write(sockfd, "LIST\r\n", 6);
    read(sockfd, response, BUFFER_SIZE);
    printf("Server response: %s", response);
    char *p = strchr(response, '\n');
    p = strchr(p+1, '\n');
    while (*p != '.') {
        p++;
        printf("%s", p);
        p = strchr(p, '\n');
    }

    // Get email number
    int email_number;
    printf("Enter email number: ");
    scanf("%d", &email_number);

    // Send retr command to retrieve specified email
    char retr[BUFFER_SIZE];
    sprintf(retr, "RETR %d\r\n", email_number);
    write(sockfd, retr, strlen(retr));
    read(sockfd, response, BUFFER_SIZE);
    printf("Server response: %s", response);

    // Parse email
    char *body = strstr(response, "\r\n\r\n") + 4;
    printf("%s", body);

    // Close connection
    write(sockfd, "QUIT\r\n", 6);
    read(sockfd, response, BUFFER_SIZE);
    printf("Server response: %s", response);
    close(sockfd);

    return 0;
}