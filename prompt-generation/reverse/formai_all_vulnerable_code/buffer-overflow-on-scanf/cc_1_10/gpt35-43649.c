//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: innovative
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[])
{
    struct sockaddr_in server;
    char *hostname = "mail.example.com";
    char username[MAX_SIZE], password[MAX_SIZE];
    int sock, recv_size, total_size = 0;

    printf("POP3 Client Program\n");
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1){
        printf("Could not create socket\n");
        return 1;
    }

    printf("Socket created\n");

    // Configure server struct for connection
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(110);

    // Connect to remote server
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0){
        printf("Connection error\n");
        return 1;
    }

    printf("Connected to server %s on port %d\n", hostname, 110);

    // Read welcome message from the server
    char response[MAX_SIZE];
    recv_size = recv(sock, response, MAX_SIZE, 0);
    response[recv_size] = '\0';
    printf("%s", response);

    // Send login credentials to the server
    char request[MAX_SIZE];
    sprintf(request, "USER %s\r\n", username);
    send(sock, request, strlen(request), 0);

    recv_size = recv(sock, response, MAX_SIZE, 0);
    response[recv_size] = '\0';
    printf("%s", response);

    sprintf(request, "PASS %s\r\n", password);
    send(sock, request, strlen(request), 0);

    recv_size = recv(sock, response, MAX_SIZE, 0);
    response[recv_size] = '\0';
    printf("%s", response);

    // List emails in mailbox
    sprintf(request, "LIST\r\n");
    send(sock, request, strlen(request), 0);

    recv_size = recv(sock, response, MAX_SIZE, 0);
    response[recv_size] = '\0';
    printf("%s", response);

    // Read any emails from the server
    char email[MAX_SIZE];
    while(total_size < MAX_SIZE){
        recv_size = recv(sock, email, MAX_SIZE, 0);
        
        if(recv_size == 0){
            break;
        }

        email[recv_size] = '\0';
        total_size += recv_size;
        printf("%s", email);
    }

    // Logout from server
    sprintf(request, "QUIT\r\n");
    send(sock, request, strlen(request), 0);

    recv_size = recv(sock, response, MAX_SIZE, 0);
    response[recv_size] = '\0';
    printf("%s", response);

    close(sock);
    return 0;
}