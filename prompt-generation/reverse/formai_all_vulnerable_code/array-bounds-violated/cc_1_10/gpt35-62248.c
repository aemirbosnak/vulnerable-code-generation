//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<limits.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define MAX_DEVICE_NUM 50
#define MAX_IP_LENGTH 16

struct device{
    char ip[MAX_IP_LENGTH];
    char mac_address[18];
};

int device_count = 0;
struct device devices[MAX_DEVICE_NUM];

int main(){
    int sockfd, n;
    struct sockaddr_in servaddr, addr;
    char recv_message[1024], send_message[1024];
    char *ptr;
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(0);
    
    bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("255.255.255.255");
    addr.sin_port = htons(5678);
    
    sprintf(send_message, "Who is there?");
    sendto(sockfd, send_message, strlen(send_message), 0, (struct sockaddr*)&addr, sizeof(addr));
    
    alarm(2);
    n = recvfrom(sockfd, recv_message, sizeof(recv_message)-1, 0, NULL, NULL);
    alarm(0);
    
    if(n < 0){
        printf("No response received\n");
        exit(1);
    }else{
        recv_message[n] = 0;
        printf("Received response: %s\n", recv_message);
    }
    
    ptr = strtok(recv_message,"/");
    while(ptr != NULL){
        strcpy(devices[device_count].ip, ptr);
        ptr = strtok(NULL, "/");
        strcpy(devices[device_count].mac_address, ptr);
        ptr = strtok(NULL, "/");
        device_count++;
    }
    
    for(int i = 0; i < device_count; i++){
        printf("Device %d: IP - %s, MAC Address - %s\n", i+1, devices[i].ip, devices[i].mac_address);
    }
    
    close(sockfd);
    return 0;
}