//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 110
#define BUFFER_SIZE 1024

typedef struct {
    char server[100];
    char username[50];
    char password[50];
} Pop3Client;

void die(const char *message) {
    perror(message);
    exit(1);
}

void receive_email(Pop3Client *client) {
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("Socket creation error");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    struct hostent *host = gethostbyname(client->server);
    if (host == NULL) {
        die("No such host");
    }

    memcpy(&serv_addr.sin_addr, host->h_addr_list[0], host->h_length);
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        die("Connection to server failed");
    }

    char buffer[BUFFER_SIZE];
    int valread;

    // Receive welcome message
    valread = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[valread] = '\0';
    printf("Server: %s\n", buffer);

    // Send USER command
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", client->username);
    send(sock, buffer, strlen(buffer), 0);
    valread = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[valread] = '\0';
    printf("Server: %s\n", buffer);

    // Send PASS command
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", client->password);
    send(sock, buffer, strlen(buffer), 0);
    valread = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[valread] = '\0';
    printf("Server: %s\n", buffer);

    // Send LIST command to get email list
    send(sock, "LIST\r\n", strlen("LIST\r\n"), 0);
    valread = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[valread] = '\0';
    printf("Server: %s\n", buffer);
    
    // Fetch each email
    char *line = strtok(buffer, "\r\n");
    while (line != NULL) {
        printf("Email ID: %s\n", line);
        int email_id = atoi(line);
        
        // Fetch the individual email
        snprintf(buffer, sizeof(buffer), "RETR %d\r\n", email_id);
        send(sock, buffer, strlen(buffer), 0);
        valread = recv(sock, buffer, BUFFER_SIZE, 0);
        buffer[valread] = '\0';
        printf("Email #%d:\n%s\n", email_id, buffer);
        
        line = strtok(NULL, "\r\n");
    }

    // Send QUIT command
    send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    valread = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[valread] = '\0';
    printf("Server: %s\n", buffer);

    close(sock);
}

int main() {
    Pop3Client client;
    
    printf("Enter POP3 server address: ");
    scanf("%s", client.server);
    printf("Enter username: ");
    scanf("%s", client.username);
    printf("Enter password: ");
    scanf("%s", client.password);

    receive_email(&client);

    return 0;
}