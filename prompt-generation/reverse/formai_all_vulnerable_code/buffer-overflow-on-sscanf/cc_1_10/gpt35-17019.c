//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024 // Maximum buffer size

int main(int argc, char *argv[]) {
    int sock;
    char message[BUF_SIZE], recv_buff[BUF_SIZE];
    struct sockaddr_in pop_server;
    
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&pop_server, 0, sizeof(pop_server));
    pop_server.sin_family = AF_INET;
    pop_server.sin_port = htons(110); // POP3 port
    pop_server.sin_addr.s_addr = inet_addr(argv[1]);
    
    if(connect(sock, (struct sockaddr *)&pop_server, sizeof(pop_server)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
    
    recv(sock, recv_buff, BUF_SIZE, 0); // Welcome message from server
    
    sprintf(message, "USER %s\r\n", argv[2]);
    send(sock, message, strlen(message), 0); // Send username
    
    recv(sock, recv_buff, BUF_SIZE, 0); // Response from server
    
    sprintf(message, "PASS %s\r\n", argv[3]);
    send(sock, message, strlen(message), 0); // Send password
    
    recv(sock, recv_buff, BUF_SIZE, 0); // Response from server
    
    sprintf(message, "STAT\r\n");
    send(sock, message, strlen(message), 0); // Request for message count
    
    recv(sock, recv_buff, BUF_SIZE, 0); // Response from server
    
    int msg_count, msg_size, i;
    sscanf(recv_buff, "+OK %d %d", &msg_count, &msg_size); // Parse message count and size
    
    printf("Total Messages: %d\nTotal Size: %d\n", msg_count, msg_size); // Display message count and size
    
    for(i = 1; i <= msg_count; i++) {
        sprintf(message, "RETR %d\r\n", i);
        send(sock, message, strlen(message), 0); // Request for message
        
        recv(sock, recv_buff, BUF_SIZE, 0); // Response from server
        
        printf("Message %d:\n", i); // Display message
        
        do {
            recv(sock, recv_buff, BUF_SIZE, 0);
            printf("%s", recv_buff);
        } while(strstr(recv_buff, "\r\n.\r\n") == NULL); // End of message
    }
    
    sprintf(message, "QUIT\r\n");
    send(sock, message, strlen(message), 0); // Quit session
    
    recv(sock, recv_buff, BUF_SIZE, 0); // Response from server
    
    close(sock); // Close socket
    
    return 0;
}