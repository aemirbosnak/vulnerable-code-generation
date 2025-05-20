//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct {
    char username[50];
    char password[50];
    int socket;
} pop3_client;

int main() {
    pop3_client client;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int n, i;

    printf("Greetings, intrepid adventurer! Enter your credentials:\n");
    printf("Username: ");
    scanf("%s", client.username);
    printf("Password: ");
    scanf("%s", client.password);

    // Connect to the POP3 server
    printf("Connecting to the server...\n");
    struct hostent *host = gethostbyname("pop.example.com");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    server_addr.sin_addr = *(struct in_addr*)host->h_addr;

    client.socket = socket(AF_INET, SOCK_STREAM, 0);
    connect(client.socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Send the USER command
    sprintf(buffer, "USER %s\r\n", client.username);
    send(client.socket, buffer, strlen(buffer), 0);
    n = recv(client.socket, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send the PASS command
    sprintf(buffer, "PASS %s\r\n", client.password);
    send(client.socket, buffer, strlen(buffer), 0);
    n = recv(client.socket, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send the STAT command
    sprintf(buffer, "STAT\r\n");
    send(client.socket, buffer, strlen(buffer), 0);
    n = recv(client.socket, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send the LIST command
    sprintf(buffer, "LIST\r\n");
    send(client.socket, buffer, strlen(buffer), 0);
    n = recv(client.socket, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send the RETR command for each message
    for (i = 1; i <= 5; i++) {
        sprintf(buffer, "RETR %d\r\n", i);
        send(client.socket, buffer, strlen(buffer), 0);
        n = recv(client.socket, buffer, sizeof(buffer), 0);
        printf("%s", buffer);
    }

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    send(client.socket, buffer, strlen(buffer), 0);
    close(client.socket);

    return 0;
}