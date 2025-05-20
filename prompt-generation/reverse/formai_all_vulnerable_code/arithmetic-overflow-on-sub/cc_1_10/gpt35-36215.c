//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<sys/time.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>

#define MAX_PKT_SIZE 65535

struct pkt_rcv {
    struct timeval ts;
    int size;
    unsigned char *pkt;
    uint32_t addr;
};

typedef struct pkt_rcv pkt_rcv;

void process_packet(unsigned char *buf, int size, uint32_t addr)
{
    struct iphdr *iph = (struct iphdr*)buf;
    struct tcphdr *tcph = (struct tcphdr*)(buf + (iph->ihl*4));

    printf("Source address: %s\n", inet_ntoa(*(struct in_addr*)&addr));
    printf("Source port: %d\n", ntohs(tcph->source));
    printf("Destination port: %d\n", ntohs(tcph->dest));
}

void *rcv_pkt()
{
    int saddr_size , data_size;
    struct sockaddr saddr;
    pkt_rcv *pkt_list[30];
    int pkt_index=0;
    unsigned char *buffer = (unsigned char *)malloc(MAX_PKT_SIZE);

    printf("Starting packets capture...\n");
    int sock_raw = socket(AF_INET , SOCK_RAW , IPPROTO_TCP);

    if(sock_raw < 0){
        printf("Socket Error\n");
        return 1;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    while((end.tv_sec - start.tv_sec) < 10){
        saddr_size = sizeof saddr;  
        data_size = recvfrom(sock_raw , buffer , MAX_PKT_SIZE , 0 , &saddr , (socklen_t*)&saddr_size);

        if(data_size < 0){
            printf("Recvfrom error , failed to get packets\n");
            return 1;
        }

        pkt_rcv *packet = (pkt_rcv*)malloc(sizeof(pkt_rcv));
        packet->size = data_size;
        packet->ts = end;
        packet->pkt = malloc(sizeof(unsigned char)*data_size);
        memcpy(packet->pkt, buffer, data_size);
        packet->addr = ntohl(((struct sockaddr_in *)&saddr)->sin_addr.s_addr);

        pkt_list[pkt_index] = packet;
        pkt_index++;
    }

    close(sock_raw);
    free(buffer);

    printf("Packets captured: %d. Processing packets...\n", pkt_index);

    int i;
    for(i = 0; i < pkt_index; i++){
        printf("Packet %d:\n", i);
        process_packet(pkt_list[i]->pkt, pkt_list[i]->size, pkt_list[i]->addr);
        printf("==================\n");
    }
    return NULL;
}

int main()
{
    rcv_pkt();
    return 0;
}