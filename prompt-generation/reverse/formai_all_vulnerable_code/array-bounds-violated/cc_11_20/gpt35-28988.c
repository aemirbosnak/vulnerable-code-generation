//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "pop.gmail.com"
#define PORT 995

int main(int argc, char **argv){
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
 
    if(sock == -1){
        printf("Error creating socket\n");
        return 1;
    }
     
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);
 
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){
        printf("Error connecting to server\n");
        return 1;
    }
    
    char user_input[1024];
    char buffer[1024];
    int read_size;
     
    printf("Enter your email address: ");
    fgets(user_input, 1024, stdin);
    user_input[strcspn(user_input, "\n")] = 0;
  
    char message[256];
    sprintf(message, "USER %s\r\n", user_input);
    if(send(sock, message, strlen(message), 0) == -1){
        printf("Error sending username\n");
        return 1;
    }
     
    if((read_size = recv(sock, buffer, 1024, 0)) == -1){
        printf("Error receiving message\n");
        return 1;
    }
     
    buffer[read_size] = '\0';
    printf("%s", buffer);
    
    printf("Enter your password: ");
    fgets(user_input, 1024, stdin);
    user_input[strcspn(user_input, "\n")] = 0;
     
    sprintf(message, "PASS %s\r\n", user_input);
    if(send(sock, message, strlen(message), 0) == -1){
        printf("Error sending password\n");
        return 1;
    }
     
    if((read_size = recv(sock, buffer, 1024, 0)) == -1){
        printf("Error receiving message\n");
        return 1;
    }
     
    buffer[read_size] = '\0';
    printf("%s", buffer);
    
    sprintf(message, "STAT\r\n");
    if(send(sock, message, strlen(message), 0) == -1){
        printf("Error sending request\n");
        return 1;
    }
     
    if((read_size = recv(sock, buffer, 1024, 0)) == -1){
        printf("Error receiving message\n");
        return 1;
    }
     
    buffer[read_size] = '\0';
    printf("%s", buffer);
    
    sprintf(message, "QUIT\r\n");
    if(send(sock, message, strlen(message), 0) == -1){
        printf("Error sending request\n");
        return 1;
    }
     
    if((read_size = recv(sock, buffer, 1024, 0)) == -1){
        printf("Error receiving message\n");
        return 1;
    }
     
    buffer[read_size] = '\0';
    printf("%s", buffer);
    
    close(sock);
     
    return 0;
}