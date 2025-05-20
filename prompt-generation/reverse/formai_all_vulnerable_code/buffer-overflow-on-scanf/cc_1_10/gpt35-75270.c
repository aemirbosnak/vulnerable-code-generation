//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <sys/socket.h>  
#include <arpa/inet.h>  
#include <unistd.h>  
  
#define SERVER_IP "127.0.0.1"  
#define SERVER_PORT 21  
  
int main(int argc, char const *argv[])  
{  
    int socket_desc, numBytes;  
    struct sockaddr_in server_addr;  
    char buffer[1024] = {0};  
  
    // Create socket  
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);  
    if (socket_desc == -1)  
    {  
        printf("Socket creation error\n");  
        return -1;  
    }  
  
    // Set server address and port  
    server_addr.sin_family = AF_INET;  
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);  
    server_addr.sin_port = htons(SERVER_PORT);  
  
    // Connect to server  
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)  
    {  
        printf("Connection error\n");  
        close(socket_desc);  
        return -1;  
    }  
  
    // Send user command "USER <username>"  
    char user_command[50] = {0};  
    printf("FTP Client username: ");  
    scanf("%s", user_command);  
    send(socket_desc, user_command, strlen(user_command), 0);  
    numBytes = recv(socket_desc, buffer, 1024, 0);  
    if (numBytes < 0)  
    {  
        printf("Error reading from server\n");  
        close(socket_desc);  
        return -1;  
    }  
    printf("%s\n", buffer);  
  
    // Send password command "PASS <password>"  
    char pass_command[50] = {0};  
    printf("FTP Client password: ");  
    scanf("%s", pass_command);  
    send(socket_desc, pass_command, strlen(pass_command), 0);  
    numBytes = recv(socket_desc, buffer, 1024, 0);  
    if (numBytes < 0)  
    {  
        printf("Error reading from server\n");  
        close(socket_desc);  
        return -1;  
    }  
    printf("%s\n", buffer);  
  
    close(socket_desc);  
    return 0;  
}