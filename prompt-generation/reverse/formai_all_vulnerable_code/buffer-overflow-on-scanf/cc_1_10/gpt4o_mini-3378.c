//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_EMAILS 100
#define SERVER "imap.gmail.com"
#define PORT 993

struct Email {
    char sender[256];
    char subject[256];
    char date[64];
};

struct Email emails[MAX_EMAILS];
int email_count = 0;

void get_emails(int sockfd) {
    char buffer[BUFFER_SIZE];
    // Use IMAP commands to fetch emails
    snprintf(buffer, sizeof(buffer), "A001 LIST \"\" \"%\"");
    send(sockfd, buffer, strlen(buffer), 0);
    // More IMAP commands to fetch emails, not fully implemented here
    printf("Fetching emails...\n");
    // Simulate fetching email for demonstration
    strcpy(emails[0].sender, "example1@gmail.com");
    strcpy(emails[0].subject, "Test Email 1");
    strcpy(emails[0].date, "2023-10-01");
    strcpy(emails[1].sender, "example2@gmail.com");
    strcpy(emails[1].subject, "Test Email 2");
    strcpy(emails[1].date, "2023-10-02");
    email_count = 2;
}

void print_emails() {
    printf("You have %d new emails:\n", email_count);
    for (int i = 0; i < email_count; ++i) {
        printf("%d. From: %s\n   Subject: %s\n   Date: %s\n", 
               i + 1, emails[i].sender, emails[i].subject, emails[i].date);
    }
}

int connect_to_server(const char *server, int port) {
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        fprintf(stderr, "Failed to resolve hostname: %s\n", server);
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&(server_addr.sin_addr.s_addr), host->h_addr, host->h_length);
    server_addr.sin_port = htons(port);
    
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", server, port);
    return sockfd;
}

void display_menu() {
    printf("\nEmail Client Menu:\n");
    printf("1. Connect to email server\n");
    printf("2. Fetch emails\n");
    printf("3. Print emails\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int sockfd = -1;
    int choice;
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                sockfd = connect_to_server(SERVER, PORT);
                break;
            case 2:
                if (sockfd == -1) {
                    printf("Please connect to the server first.\n");
                } else {
                    get_emails(sockfd);
                }
                break;
            case 3:
                print_emails();
                break;
            case 4:
                if (sockfd != -1) {
                    close(sockfd);
                }
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice, please choose again.\n");
        }
    }

    if (sockfd != -1) {
        close(sockfd);
    }
    return 0;
}