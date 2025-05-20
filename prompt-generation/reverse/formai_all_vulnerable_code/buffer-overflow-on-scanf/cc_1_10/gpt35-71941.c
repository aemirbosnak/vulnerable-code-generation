//FormAI DATASET v1.0 Category: Browser Plugin ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 8080

void send_request(char *ip_address, char *request_path){
    struct sockaddr_in serv_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Failed to create socket\n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0){
        printf("Invalid IP address\n");
        return;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        printf("Connection Failed\n");
        return;
    }

    char request[1024];
    sprintf(request, "GET %s HTTP/1.1\r\nHost:%s\r\nConnection:close\r\n\r\n", request_path, ip_address);

    if(send(sockfd, request, strlen(request), 0) < 0){
        printf("Failed to send request\n");
        return;
    }

    char response[4096];
    int valread = read(sockfd, response, 4096);
    if(valread < 0){
        printf("Failed to read response\n");
        return;
    }

    printf("Response:\n%s\n", response);
    close(sockfd);
}

int main(){
    char ip_address[20];
    char request_path[1024];

    printf("Enter IP Address: ");
    scanf("%s", ip_address);

    printf("Enter Request Path: ");
    scanf("%s", request_path);

    send_request(ip_address, request_path);
    return 0;
}