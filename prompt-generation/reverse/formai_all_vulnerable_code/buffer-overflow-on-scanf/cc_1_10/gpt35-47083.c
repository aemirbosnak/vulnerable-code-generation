//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
 
int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in client;
    char server_reply[BUFFER_SIZE] = {'\0'};
    char username[BUFFER_SIZE] = {'\0'};
    char password[BUFFER_SIZE] = {'\0'};
    char message[BUFFER_SIZE] = {'\0'};
     
    // Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
        return 1;
    }
     
    client.sin_addr.s_addr = inet_addr("127.0.0.1");
    client.sin_family = AF_INET;
    client.sin_port = htons( 110 );
 
    // Connect to remote server
    if (connect(sock , (struct sockaddr *)&client , sizeof(client)) < 0)
    {
        printf("Connection error");
        return 1;
    }
     
    // Receive greeting message
    recv(sock , server_reply , BUFFER_SIZE , 0);
    printf("%s", server_reply);
     
    // Send username
    printf("Username: ");
    scanf("%s", username);
    snprintf(message, BUFFER_SIZE, "USER %s\n", username);
    send(sock , message , strlen(message) , 0);
     
    // Receive response
    recv(sock , server_reply , BUFFER_SIZE , 0);
    printf("%s", server_reply);
     
    // Send password
    printf("Password: ");
    scanf("%s", password);
    snprintf(message, BUFFER_SIZE, "PASS %s\n", password);
    send(sock , message , strlen(message) , 0);
     
    // Receive response
    recv(sock , server_reply , BUFFER_SIZE , 0);
    printf("%s", server_reply);
     
    // List messages
    snprintf(message, BUFFER_SIZE, "LIST\n");
    send(sock , message , strlen(message) , 0);
     
    // Receive response
    recv(sock , server_reply , BUFFER_SIZE , 0);
    printf("%s", server_reply);
     
    // Quit
    snprintf(message, BUFFER_SIZE, "QUIT\n");
    send(sock , message , strlen(message) , 0);
     
    // Receive response
    recv(sock , server_reply , BUFFER_SIZE , 0);
    printf("%s", server_reply);
     
    close(sock);
    return 0;
}