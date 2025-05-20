//FormAI DATASET v1.0 Category: Email Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_EMAIL_SIZE 1024
#define MAX_BUFFER_SIZE 2048

void display_menu();
void send_email(char* server_ip, int port);
void receive_email(char* server_ip, int port);
int validate_email_address(char* email_address);

int main() {
    char server_ip[16];
    int port;
    int choice;

    printf("Welcome to the C Email Client\n");
    printf("Please enter the IP address of your email server: ");
    fgets(server_ip, 16, stdin);
    printf("Please enter the port number of your email server: ");
    scanf("%d", &port);

    while(1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                send_email(server_ip, port);
                break;
            case 2:
                receive_email(server_ip, port);
                break;
            case 3:
                printf("Thank you for using the C Email Client\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void display_menu() {
    printf("\n");
    printf("C Email Client Menu\n");
    printf("--------------------\n");
    printf("1 - Send email\n");
    printf("2 - Receive email\n");
    printf("3 - Exit\n");
}

void send_email(char* server_ip, int port) {
    char email_address[MAX_EMAIL_SIZE];
    char email_subject[MAX_EMAIL_SIZE];
    char email_body[MAX_BUFFER_SIZE];
    char buffer[MAX_BUFFER_SIZE];
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    printf("Please enter the recipient's email address: ");
    fgets(email_address, MAX_EMAIL_SIZE, stdin);
    
    // Validate email address
    if(validate_email_address(email_address)) {
        printf("Please enter the subject of your email: ");
        fgets(email_subject, MAX_EMAIL_SIZE, stdin);
        printf("Please enter the body of your email: ");
        fgets(email_body, MAX_BUFFER_SIZE, stdin);
        
        // Connect to email server
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd < 0) {
            printf("Error: Could not create socket.\n");
            exit(1);
        }

        server = gethostbyname(server_ip);
        if(server == NULL) {
            printf("Error: Could not find email server.\n");
            exit(1);
        }

        bzero((char*) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(port);

        if(connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
            printf("Error: Could not connect to email server.\n");
            exit(1);
        }
        
        // Send email
        sprintf(buffer, "To: %sSubject: %s%s", email_address, email_subject, email_body);
        n = write(sockfd, buffer, strlen(buffer));
        if(n < 0) {
            printf("Error: Could not send email.\n");
            exit(1);
        }

        printf("Email sent successfully.\n");
        
        close(sockfd);
    } else {
        printf("Invalid email address.\n");
    }
}

void receive_email(char* server_ip, int port) {
    // Code to retrieve emails from server
    printf("This feature is not yet implemented.\n");
}

int validate_email_address(char* email_address) {
    // Code to validate email address format
    return 1;
}