//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for read and write
#include <arpa/inet.h> // for sockets
#include <netinet/in.h> // for sockaddr_in
#include <sys/types.h> // for size_t
#include <sys/socket.h>
#include <netdb.h>

#define PORT 25 // SMTP Port for sending emails
#define BUFFER_SIZE 1024

void send_email(const char *host, const char *from, const char *to, const char *subject, const char *message) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    // Creating socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return;
    }
    
    // Setting up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    struct hostent *he = gethostbyname(host);
    if (he != NULL)
        memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);
    else {
        perror("gethostbyname");
        return;
    }
    
    // Connecting to SMTP Server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return;
    }

    // Reading server response
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Sending EHLO
    snprintf(buffer, sizeof(buffer), "EHLO %s\r\n", from);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Mail from
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", from);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
    
    // RCPT TO
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", to);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
    
    // DATA
    write(sockfd, "DATA\r\n", strlen("DATA\r\n"));
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
    
    // Message Data
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, message);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
    
    // QUIT Command
    write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
    
    // Closing socket
    close(sockfd);
}

void menu() {
    printf("=== Simple C Email Client ===\n");
    printf("1. Send Email\n");
    printf("2. Exit\n");
}

int main() {
    int choice;
    char host[100], from[100], to[100], subject[100], message[500];
    
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter SMTP server (e.g., smtp.example.com): ");
            scanf("%s", host);
            printf("Enter your email address: ");
            scanf("%s", from);
            printf("Enter recipient's email address: ");
            scanf("%s", to);
            printf("Enter subject: ");
            getchar(); // clear newline
            fgets(subject, sizeof(subject), stdin);
            subject[strcspn(subject, "\n")] = 0; // Removing newline character

            printf("Enter message body (end with 'END'): \n");
            while (1) {
                fgets(message, sizeof(message), stdin);
                if (strcmp(message, "END\n") == 0) {
                    break;
                }
                strcat(message, message); // Concatenating message
            }
            
            send_email(host, from, to, subject, message);
        } else if (choice == 2) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}