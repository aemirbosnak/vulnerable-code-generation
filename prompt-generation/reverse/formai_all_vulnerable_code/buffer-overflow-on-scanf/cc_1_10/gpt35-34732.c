//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {

    char server_ip[20], username[50], password[50];    
    struct sockaddr_in server_addr;
    char buffer[MAX_BUF_SIZE];        
    
    printf("Enter the Server IP Address: ");
    scanf("%s", server_ip);
    
    printf("Enter your Username: ");
    scanf("%s", username);
    
    printf("Enter your Password: ");
    scanf("%s", password);
    
    /* Create Socket */
    int client_socket = socket(AF_INET,SOCK_STREAM,0);
    
    if(client_socket< 0){
        perror("Failed to create socket");
        exit(1);
    }
    
    /* Assign values to server address struct */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);      
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    
    /* Connect to the server */
    if(connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr))< 0){
        perror("Failed to connect");
        exit(1);
    }
    
    /* Receive the greeting message from server */
    recv(client_socket, buffer, MAX_BUF_SIZE, 0);
    printf("%s\n", buffer);
    
    /* Send the username */
    char* user = "USER ";
    strcat(user, username);
    strcat(user, "\n");    
    send(client_socket, user, strlen(user), 0);
    recv(client_socket, buffer, MAX_BUF_SIZE, 0);
    printf("%s\n", buffer);
    
    /* Send the password */
    char* pass = "PASS ";
    strcat(pass, password);
    strcat(pass, "\n");
    send(client_socket, pass, strlen(pass), 0);
    recv(client_socket, buffer, MAX_BUF_SIZE, 0);
    printf("%s\n", buffer);
    
    /* List the emails */
    char* list = "LIST\n";
    send(client_socket, list, strlen(list), 0);    
    recv(client_socket, buffer, MAX_BUF_SIZE, 0);
    printf("%s", buffer);    
    
    /* Quit the connection */
    char* quit = "QUIT\n";
    send(client_socket, quit, strlen(quit), 0);
    recv(client_socket, buffer, MAX_BUF_SIZE, 0);
    printf("%s\n", buffer);    
    
    /* Close Socket */
    close(client_socket);
    
    return 0;
}