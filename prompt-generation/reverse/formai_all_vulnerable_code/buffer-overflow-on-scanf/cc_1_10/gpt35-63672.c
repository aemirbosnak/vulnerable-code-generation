//FormAI DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

void pingTest(char* ip_addr){
    struct timeval tv_out;
    tv_out.tv_sec = 2;
    tv_out.tv_usec = 0;

    struct sockaddr_in serv_addr;
    bzero((char*)&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_addr);

    int sockfd = socket(AF_INET,SOCK_DGRAM,IPPROTO_ICMP);
    if(sockfd < 0){
        printf("Socket creation failed.\n");
        return;
    }else{
        printf("Ping testing %s:\n",ip_addr);
    }

    setsockopt(sockfd,SOL_SOCKET,SO_RCVTIMEO,&tv_out,sizeof(tv_out));

    int ttl = 1;
    setsockopt(sockfd,IPPROTO_IP,IP_TTL,&ttl,sizeof(ttl));

    char *packet = (char*)malloc(sizeof(char)*1024);
    bzero((char*)packet,sizeof(packet));
    int msg_count = 0, i, addr_len,response_msg_count = 0;

    for(i=0; i<10; i++){
        msg_count++;
        struct timeval start_time,end_time;
        int packet_sent_time = gettimeofday(&start_time,NULL);

        if(sendto(sockfd,packet,sizeof(packet),0,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) <= 0){
            printf("Packet sending failed.\n");
            continue;
        }

        addr_len = sizeof(serv_addr);
        char buffer[1024] = {0};
        if(recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&serv_addr,&addr_len) < 0){
            printf("No response for packet %d.\n",msg_count);
            continue;
        }

        int packet_received_time = gettimeofday(&end_time,NULL);
        double response_time = (double)(end_time.tv_sec - start_time.tv_sec) * 1000 + (double)(end_time.tv_usec - start_time.tv_usec) / 1000;

        printf("%d byte from %s: icmp_seq=%d ttl=%u time=%.2f ms\n",sizeof(buffer),ip_addr,msg_count,ttl,response_time);
        response_msg_count++;
        usleep(1000000);
    }

    printf("Ping test results for %s:\n",ip_addr);
    printf("Total packets sent: %d | Received: %d | Lost: %d %%\n",msg_count,response_msg_count,(msg_count-response_msg_count)*10);
    close(sockfd);
}

int main(){
    char ip_address[20];
    printf("Enter the IP address for the Ping test: ");
    scanf("%s",&ip_address);
    pingTest(ip_address);
    return 0;
}