//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50
#define MAX_EMAILS 100
#define BUFFER_SIZE 1024

struct email {
    char sender[MAX_USERNAME_LEN];
    char subject[MAX_USERNAME_LEN];
    char message[BUFFER_SIZE];
};

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server address> <port number> <username>\n", argv[0]);
        return 0;
    }
    char *server_address = argv[1];
    int port_number = atoi(argv[2]);
    char *username = argv[3];
    char password[MAX_PASSWORD_LEN];
    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LEN, stdin);
    password[strlen(password) - 1] = '\0';
    
    // Connect to the server
    struct sockaddr_in server;
    struct hostent *hptr;
    int sock;
    if ((hptr = gethostbyname(server_address)) == NULL) {
        printf("Error: Invalid server address\n");
        return 0;
    }
    memset((void*)&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = ((struct in_addr *)(hptr->h_addr_list[0]))->s_addr;
    server.sin_port = htons(port_number);
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Unable to create socket\n");
        return 0;
    }
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error: Unable to connect to server\n");
        return 0;
    }
    
    // Authenticate the user
    char input[BUFFER_SIZE];
    recv(sock, input, BUFFER_SIZE, 0);
    printf("%s", input);
    sprintf(input, "USER %s\r\n", username);
    send(sock, input, strlen(input), 0);
    recv(sock, input, BUFFER_SIZE, 0);
    printf("%s", input);
    sprintf(input, "PASS %s\r\n", password);
    send(sock, input, strlen(input), 0);
    recv(sock, input, BUFFER_SIZE, 0);
    printf("%s", input);
    if (input[0] != '2') {
        printf("Error: Authentication failed\n");
        close(sock);
        return 0;
    }
    
    // Retrieve list of emails
    sprintf(input, "LIST\r\n");
    send(sock, input, strlen(input), 0);
    recv(sock, input, BUFFER_SIZE, 0);
    printf("%s", input);
    int num_emails = 0;
    struct email emails[MAX_EMAILS];
    while (1) {
        recv(sock, input, BUFFER_SIZE, 0);
        if (input[0] == '.') {
            break;
        } else {
            int email_num, email_size;
            sscanf(input, "%d %d", &email_num, &email_size);
            printf("Email %d: %d bytes\n", email_num, email_size);
            sprintf(input, "RETR %d\r\n", email_num);
            send(sock, input, strlen(input), 0);
            recv(sock, input, BUFFER_SIZE, 0);
            printf("%s", input);
            recv(sock, input, BUFFER_SIZE, 0);
            printf("From: %s", input);
            strcpy(emails[num_emails].sender, input);
            recv(sock, input, BUFFER_SIZE, 0);
            printf("Subject: %s", input);
            strcpy(emails[num_emails].subject, input);
            memset(input, 0, BUFFER_SIZE);
            while (strcmp(input, "\r\n") != 0) {
                recv(sock, input, BUFFER_SIZE, 0);
            }
            int message_len = 0;
            while (strcmp(input, "\r\n") != 0) {
                memset(input, 0, BUFFER_SIZE);
                recv(sock, input, BUFFER_SIZE, 0);
                strcat(emails[num_emails].message, input);
                message_len += strlen(input);
            }
            printf("%d bytes of message\n", message_len);
            num_emails++;
            if (num_emails >= MAX_EMAILS) {
                break;
            }
        }
    }
    close(sock);
    
    // Print list of emails
    printf("\n%d emails:\n", num_emails);
    for (int i = 0; i < num_emails; i++) {
        printf("Email %d:\n", i + 1);
        printf("\tFrom: %s", emails[i].sender);
        printf("\tSubject: %s", emails[i].subject);
        printf("\tMessage: %s", emails[i].message);
    }
    return 0;
}