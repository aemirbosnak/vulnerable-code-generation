//FormAI DATASET v1.0 Category: Firewall ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Packet{
    char source_addr[20];
    char dest_addr[20];
    int protocol;
    char data[100];
} Packet;

typedef struct Firewall{
    char allowed_ips[10][20];
    int num_allowed;
} Firewall;

void initialize_firewall(Firewall *fw){
    strcpy(fw->allowed_ips[0], "192.168.0.1");
    strcpy(fw->allowed_ips[1], "10.0.0.1");
    strcpy(fw->allowed_ips[2], "172.16.0.1");
    fw->num_allowed = 3;
}

void print_packet(Packet p){
    printf("Source address: %s\n", p.source_addr);
    printf("Destination address: %s\n", p.dest_addr);
    printf("Protocol: %d\n", p.protocol);
    printf("Data: %s\n", p.data);
}

int is_packet_allowed(Packet p, Firewall fw){
    int i;
    for(i=0; i<fw.num_allowed; i++){
        if(strcmp(p.source_addr, fw.allowed_ips[i])==0){
            return 1;
        }
    }
    return 0;
}

int main(){
    Firewall fw;
    Packet p;
    initialize_firewall(&fw);
    printf("Enter source address:");
    scanf("%s", p.source_addr);
    printf("Enter destination address:");
    scanf("%s", p.dest_addr);
    printf("Enter protocol:");
    scanf("%d", &p.protocol);
    printf("Enter data:");
    scanf("%s", p.data);

    if(is_packet_allowed(p, fw)){
        print_packet(p);
    }
    else{
        printf("Packet blocked by firewall!\n");
    }
    return 0;
}