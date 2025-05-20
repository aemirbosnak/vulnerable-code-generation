//FormAI DATASET v1.0 Category: Firewall ; Style: cheerful
#include<stdio.h>
#include<string.h>

/* This program is a cheerful implementation of a custom Firewall solution in C.
It uses an array of allowed IP addresses and ports to check incoming traffic and allow or block it accordingly.*/

int main(){
    char allowed_ip[5][16] = {"192.168.1.1", "10.0.0.1", "172.16.0.1", "192.168.0.1", "192.168.2.1"};
    int allowed_ports[10] = {80, 443, 22, 21, 25, 110, 143, 3306, 5432, 8080}; 
    char incoming_ip[16];
    int incoming_port;
    int i,j;

    printf("Welcome to My Firewall Solution!\n");

    while(1){
        printf("\nEnter incoming IP address: ");
        scanf("%s", incoming_ip);

        if(strcmp(incoming_ip,"q") == 0 || strcmp(incoming_ip,"Q") == 0){
            printf("Exiting...\n");
            break;
        }

        printf("Enter incoming port: ");
        scanf("%d", &incoming_port);

        int ip_allowed = 0;
        int port_allowed = 0;

        for(i=0; i<5; i++){
            if(strcmp(incoming_ip,allowed_ip[i]) == 0){
                ip_allowed = 1;
                break;
            }
        }

        for(j=0; j<10; j++){
            if(incoming_port == allowed_ports[j]){
                port_allowed = 1;
                break;
            }
        }

        if(ip_allowed == 1 && port_allowed == 1){
            printf("\nIncoming traffic from %s:%d is allowed!\n", incoming_ip, incoming_port);
        }
        else{
            printf("\n404 Not Found!\n");
            printf("\nAll incoming traffic from %s:%d has been blocked!\n", incoming_ip, incoming_port);
        }
    }

    return 0;
}