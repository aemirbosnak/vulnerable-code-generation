//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 110

struct message {
    char sender[100];
    char subject[100];
    char body[1000];
    int size;
};

int read_response(int socket, char* buffer, int size) {
    int total_read = 0;
    int bytes_read;
    while (total_read < size) {
        bytes_read = recv(socket, buffer + total_read, size - total_read, 0);
        if (bytes_read <= 0) {
            return total_read;
        }
        total_read += bytes_read;
    }
    return total_read;
}

int main() {
    char server_address[100];
    char username[100];
    char password[100];
    printf("Enter server address: ");
    scanf("%s", server_address);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Resolve server address
    struct hostent* server = gethostbyname(server_address);
    if (server == NULL) {
        printf("Error: could not resolve server address\n");
        exit(1);
    }

    // Connect to server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: could not create socket\n");
        exit(1);
    }
    struct sockaddr_in server_address_info;
    bzero(&server_address_info, sizeof(server_address_info));
    server_address_info.sin_family = AF_INET;
    server_address_info.sin_port = htons(PORT);
    bcopy((char*)server->h_addr, (char*)&server_address_info.sin_addr.s_addr, server->h_length);
    if (connect(sockfd, (struct sockaddr*)&server_address_info, sizeof(server_address_info)) < 0) {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    // Read initial response
    char response[1024];
    read_response(sockfd, response, sizeof(response));

    // Send login credentials
    char login[100];
    sprintf(login, "USER %s\r\n", username);
    send(sockfd, login, strlen(login), 0);
    read_response(sockfd, response, sizeof(response));
    char password_command[100];
    sprintf(password_command, "PASS %s\r\n", password);
    send(sockfd, password_command, strlen(password_command), 0);
    read_response(sockfd, response, sizeof(response));

    // List messages
    char list_command[] = "LIST\r\n";
    send(sockfd, list_command, strlen(list_command), 0);
    read_response(sockfd, response, sizeof(response));
    printf("Message list:\n");
    while (strstr(response, ".\r\n") == NULL) {
        printf("%s", response);
        read_response(sockfd, response, sizeof(response));
    }

    // Retrieve message
    int message_number;
    printf("Enter message number to retrieve: ");
    scanf("%d", &message_number);
    char retrieve_command[100];
    sprintf(retrieve_command, "RETR %d\r\n", message_number);
    send(sockfd, retrieve_command, strlen(retrieve_command), 0);
    read_response(sockfd, response, sizeof(response));

    // Parse message
    struct message message;
    char* message_start = strstr(response, "\r\n") + 2;
    char* sender_start = strstr(message_start, "From: ") + 6;
    char* sender_end = strstr(sender_start, "\r\n");
    strncpy(message.sender, sender_start, sender_end - sender_start);
    message.sender[sender_end - sender_start] = '\0';
    char* subject_start = strstr(message_start, "Subject: ") + 9;
    char* subject_end = strstr(subject_start, "\r\n");
    strncpy(message.subject, subject_start, subject_end - subject_start);
    message.subject[subject_end - subject_start] = '\0';
    char* body_start = strstr(subject_end + 2, "\r\n") + 2;
    char* body_end = strstr(body_start, "\r\n.\r\n");
    int body_length = body_end - body_start;
    strncpy(message.body, body_start, body_length);
    message.body[body_length] = '\0';
    message.size = strlen(message_start) - body_length - 4;

    // Print message
    printf("Message:\n");
    printf("From: %s\n", message.sender);
    printf("Subject: %s\n", message.subject);
    printf("Size: %d bytes\n", message.size);
    printf("Body: %s\n", message.body);

    // Disconnect from server
    char quit_command[] = "QUIT\r\n";
    send(sockfd, quit_command, strlen(quit_command), 0);
    read_response(sockfd, response, sizeof(response));
    close(sockfd);

    return 0;
}