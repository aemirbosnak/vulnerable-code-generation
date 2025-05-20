//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: authentic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define MAX_BUFSIZE 1024
#define MAX_PACKETS 10     //Maximum packets to monitor
#define MAX_INTERVAL 10    //Maximum interval time in seconds
#define MAX_IPV4_LEN 15    //Maximum IPv4 address length
#define MAX_PORT_LEN 5     //Maximum port number length

typedef struct {
    char ip[MAX_IPV4_LEN];  //IPv4 address
    char port[MAX_PORT_LEN];//port number
    int interval;           //interval time in seconds
    int packets;            //number of packets to monitor
} MonitoringInfo;

int main() {
    MonitoringInfo monitors[MAX_PACKETS];    //Array of monitoring information
    int total_monitors = 0;                  //Total number of monitors
    char buffer[MAX_BUFSIZE];                //Buffer to receive packets
    int sock, i, j, k;
    struct sockaddr_in server_address;

    //Create socket
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sock < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    //Bind to any available port
    memset((char *)&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(0);
    if(bind(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error binding socket\n");
        exit(EXIT_FAILURE);
    }

    //Get the assigned port number and display it
    struct sockaddr_in local_address;
    socklen_t address_length = sizeof(local_address);
    getsockname(sock, (struct sockaddr *)&local_address, &address_length);
    printf("QoS monitor started on port: %d\n\n", ntohs(local_address.sin_port));

    //Start monitoring
    char temp_ip[MAX_IPV4_LEN] = "";
    char temp_port[MAX_PORT_LEN] = "";
    int temp_interval = 0;
    int temp_packets = 0;
    char temp_str[10] = "";
    while(total_monitors < MAX_PACKETS) {
        //Get monitoring information from user
        printf("Please enter IPv4 address to monitor (or 'done' to stop adding monitors): ");
        scanf("%s", temp_str);
        if(strcmp(temp_str, "done") == 0)
            break;
        strncpy(temp_ip, temp_str, MAX_IPV4_LEN);
        printf("Please enter port number to monitor: ");
        scanf("%s", temp_port);
        printf("Please enter interval time in seconds (1-%d): ", MAX_INTERVAL);
        scanf("%d", &temp_interval);
        if(temp_interval > MAX_INTERVAL || temp_interval < 1) {
            printf("Invalid interval time\n");
            continue;
        }
        printf("Please enter number of packets to monitor: ");
        scanf("%d", &temp_packets);
        if(temp_packets < 1) {
            printf("Invalid number of packets\n");
            continue;
        }

        //Add monitor to array
        strcpy(monitors[total_monitors].ip, temp_ip);
        strcpy(monitors[total_monitors].port, temp_port);
        monitors[total_monitors].interval = temp_interval;
        monitors[total_monitors].packets = temp_packets;
        total_monitors++;

        //Reset temp variables
        strcpy(temp_ip, "");
        strcpy(temp_port, "");
        temp_interval = 0;
        temp_packets = 0;
    }

    //Start monitoring loop
    struct sockaddr_in target_address;
    socklen_t target_length;
    int packets_received = 0;
    while(1) {
        for(i = 0; i < total_monitors; i++) {
            //Convert IPv4 address and port number to network byte order
            memset(&target_address, 0, sizeof(target_address));
            target_address.sin_family = AF_INET;
            target_address.sin_port = htons(atoi(monitors[i].port));
            if(inet_aton(monitors[i].ip, &target_address.sin_addr) == 0) {
                fprintf(stderr, "Invalid IPv4 address: %s\n", monitors[i].ip);
                break;
            }

            //Send packets
            for(j = 0; j < monitors[i].packets; j++) {
                if(sendto(sock, "QoS monitor test packet", 23, 0, (struct sockaddr *)&target_address, sizeof(target_address)) < 0) {
                    fprintf(stderr, "Error sending packet to %s:%s\n", monitors[i].ip, monitors[i].port);
                    break;
                }
            }

            //Receive packets
            packets_received = 0;
            for(j = 0; j < monitors[i].packets; j++) {
                target_length = sizeof(target_address);
                if(recvfrom(sock, buffer, MAX_BUFSIZE, 0, (struct sockaddr *)&target_address, &target_length) < 0) {
                    fprintf(stderr, "Error receiving packet from %s:%s\n", monitors[i].ip, monitors[i].port);
                    break;
                }
                packets_received++;
            }

            //Output results
            printf("Monitor %d: %s:%s - Packets sent: %d | Packets received: %d | Packets lost: %d | Percentage of packets lost: %.2f%%\n",
                   i+1,
                   monitors[i].ip,
                   monitors[i].port,
                   monitors[i].packets,
                   packets_received,
                   monitors[i].packets - packets_received,
                   100.0*(monitors[i].packets - packets_received)/monitors[i].packets);
        }

        //Wait for interval time
        sleep(MAX_INTERVAL);
    }

    //Cleanup
    close(sock);
    return 0;
}