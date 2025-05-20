//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<netdb.h>

int main(int argc, char *argv[]){
    
    int sock, len, bytes_sent;
    struct sockaddr_in server_addr;
    char message[1024];
    struct hostent *host;
    int port = 5000;
    
    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if(sock < 0){
        perror("Failed to create socket\n");
        exit(1);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    host = gethostbyname(argv[1]);
    if(host == NULL){
        perror("Error finding host\n");
        exit(1);
    }
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(port);
    
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0 ){
        perror("Failed to connect\n");
        exit(1);
    }

    while(1){
        printf("Enter a message to send: ");
        fgets(message, sizeof(message), stdin);
        len = strlen(message) - 1;
        message[len] = '\0';
        bytes_sent = send(sock, message, len, 0);
        if(bytes_sent < 0){
            perror("Failed to send message\n");
            break;
        }
        
        /* Quality of Service Monitor */
        int qos_score = 100;
        if(bytes_sent > 50){
            qos_score -= 50;
        }
        if(qos_score >= 75){
            printf("My network is strong, my love!\n");
        }else if(qos_score >= 50){
            printf("My network is average, but my love is not!\n");
        }else{
            printf("Alas, my network is weak and so is my heart.\n");
        }
        
        /* Wait for server response */
        len = recv(sock, message, sizeof(message), 0);
        if(len < 0){
            perror("Failed to receive message\n");
            break;
        }
        message[len] = '\0';
        printf("Server replied: %s\n", message);
    }
    
    close(sock);
    return 0;
}