//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

#define POP3_SERVER_DEFAULT_PORT 110
#define POP3_RESPONSE_CODE_LENGTH 3

void cleanup(int sockfd, char* buffer) {
    close(sockfd);
    free(buffer);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <pop3-server> [pop3-server-port]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* pop3_server_address = argv[1];

    int pop3_server_port = POP3_SERVER_DEFAULT_PORT;
    if (argc >= 3) {
        pop3_server_port = atoi(argv[2]);
    }

    // Create a socket for connecting to the POP3 server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the POP3 server
    struct hostent* pop3_server = gethostbyname(pop3_server_address);
    if (pop3_server == NULL) {
        perror("ERROR: no such host\n");
        cleanup(sockfd, NULL);
        return EXIT_FAILURE;
    }
    char* pop3_server_ip_address = inet_ntoa(*((struct in_addr*) pop3_server->h_addr_list[0]));
    if (pop3_server_ip_address == NULL) {
        perror("ERROR: invalid address\n");
        cleanup(sockfd, NULL);
        return EXIT_FAILURE;
    }

    // Connect to the POP3 server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(pop3_server_port);
    server_addr.sin_addr.s_addr = inet_addr(pop3_server_ip_address);

    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting to POP3 server");
        cleanup(sockfd, NULL);
        return EXIT_FAILURE;
    }

    char* buffer = (char*) malloc(BUFFER_SIZE * sizeof(char));
    if (buffer == NULL) {
        perror("ERROR allocating memory");
        cleanup(sockfd, NULL);
        return EXIT_FAILURE;
    }

    printf("Connected to POP3 server %s:%d\n", pop3_server_address, pop3_server_port);

    // Wait for the initial greeting from the server
    memset(buffer, 0, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
        perror("ERROR reading from POP3 server");
        cleanup(sockfd, buffer);
        return EXIT_FAILURE;
    }

    printf("POP3 server response:\n%s\n", buffer);

    // Send the user name to the server
    printf("Enter user name:\n");
    fgets(buffer, BUFFER_SIZE, stdin);
    char* user_name = strtok(buffer, "\n");

    char user_name_command[BUFFER_SIZE];
    sprintf(user_name_command, "USER %s\r\n", user_name);
    if (write(sockfd, user_name_command, strlen(user_name_command)) < 0) {
        perror("ERROR writing to POP3 server");
        cleanup(sockfd, buffer);
        return EXIT_FAILURE;
    }

    // Wait for the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
        perror("ERROR reading from POP3 server");
        cleanup(sockfd, buffer);
        return EXIT_FAILURE;
    }

    // Check the response
    if (strncmp(buffer, "+OK", POP3_RESPONSE_CODE_LENGTH) != 0) {
        printf("ERROR: user name not accepted by server\n");
        cleanup(sockfd, buffer);
        return EXIT_FAILURE;
    }
    printf("POP3 server response:\n%s\n", buffer);

    // Send the password to the server
    printf("Enter password:\n");
    fgets(buffer, BUFFER_SIZE, stdin);
    char* password = strtok(buffer, "\n");

    char password_command[BUFFER_SIZE];
    sprintf(password_command, "PASS %s\r\n", password);
    if (write(sockfd, password_command, strlen(password_command)) < 0) {
        perror("ERROR writing to POP3 server");
        cleanup(sockfd, buffer);
        return EXIT_FAILURE;
    }

    // Wait for the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
        perror("ERROR reading from POP3 server");
        cleanup(sockfd, buffer);
        return EXIT_FAILURE;
    }

    // Check the response
    if (strncmp(buffer, "+OK", POP3_RESPONSE_CODE_LENGTH) != 0) {
        printf("ERROR: password not accepted by server\n");
        cleanup(sockfd, buffer);
        return EXIT_FAILURE;
    }
    printf("POP3 server response:\n%s\n", buffer);

    // Send the LIST command to the server to get a list of all emails
    if (write(sockfd, "LIST\r\n", strlen("LIST\r\n")) < 0) {
        perror("ERROR writing to POP3 server");
        cleanup(sockfd, buffer);
        return EXIT_FAILURE;
    }

    // Wait for the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
        perror("ERROR reading from POP3 server");
        cleanup(sockfd, buffer);
        return EXIT_FAILURE;
    }
    printf("POP3 server response:\n%s\n", buffer);

    // Parse the email list
    printf("Email list:\n");
    char* email_list = strtok(buffer, "\n");
    while (email_list != NULL) {
        if (strncmp(email_list, "+OK", POP3_RESPONSE_CODE_LENGTH) != 0 &&
            strncmp(email_list, ".", 1) != 0) {
            printf("%s\n", email_list);
        }
        email_list = strtok(NULL, "\n");
    }

    // Ask the user which email to retrieve
    printf("Enter email number to retrieve:\n");
    fgets(buffer, BUFFER_SIZE, stdin);
    char* email_number = strtok(buffer, "\n");

    char retr_command[BUFFER_SIZE];
    sprintf(retr_command, "RETR %s\r\n", email_number);
    if (write(sockfd, retr_command, strlen(retr_command)) < 0) {
        perror("ERROR writing to POP3 server");
        cleanup(sockfd, buffer);
        return EXIT_FAILURE;
    }

    // Wait for the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
        perror("ERROR reading from POP3 server");
        cleanup(sockfd, buffer);
        return EXIT_FAILURE;
    }
    printf("POP3 server response:\n%s\n", buffer);

    // Check if the email was found
    if (strncmp(buffer, "+OK", POP3_RESPONSE_CODE_LENGTH) != 0) {
        printf("ERROR: email not found\n");
        cleanup(sockfd, buffer);
        return EXIT_FAILURE;
    }

    // Print the email content
    printf("Email content:\n");
    char* email_content = strtok(buffer, "\n");
    while (email_content != NULL) {
        if (strncmp(email_content, ".", 1) != 0) {
            printf("%s\n", email_content);
        }
        email_content = strtok(NULL, "\n");
    }

    cleanup(sockfd, buffer);
    return EXIT_SUCCESS;
}