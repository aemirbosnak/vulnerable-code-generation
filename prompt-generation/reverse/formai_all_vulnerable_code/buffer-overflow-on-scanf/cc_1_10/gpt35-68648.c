//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

typedef struct {
    char ip[16];
    char subnet[16];
    char network[16];
    char broadcast[16];
    char range_start[16];
    char range_end[16];
} NetworkData;

void calculate_network_details(char *ip, char *subnet, NetworkData *data) {
    int octet_ip[4], octet_subnet[4], octet_netid[4], octet_bcid[4],i;
    char binary_ip[33], binary_subnet[33], binary_netid[33], binary_bcid[33];

    sscanf(ip, "%d.%d.%d.%d", &octet_ip[0], &octet_ip[1], &octet_ip[2], &octet_ip[3]);
    sscanf(subnet, "%d.%d.%d.%d", &octet_subnet[0], &octet_subnet[1], &octet_subnet[2], &octet_subnet[3]);

    for(i = 0; i < 4; i++) {
        binary_ip[i * 8 + 0] = (octet_ip[i] & 0x80) ? '1' : '0';
        binary_ip[i * 8 + 1] = (octet_ip[i] & 0x40) ? '1' : '0';
        binary_ip[i * 8 + 2] = (octet_ip[i] & 0x20) ? '1' : '0';
        binary_ip[i * 8 + 3] = (octet_ip[i] & 0x10) ? '1' : '0';
        binary_ip[i * 8 + 4] = (octet_ip[i] & 0x08) ? '1' : '0';
        binary_ip[i * 8 + 5] = (octet_ip[i] & 0x04) ? '1' : '0';
        binary_ip[i * 8 + 6] = (octet_ip[i] & 0x02) ? '1' : '0';
        binary_ip[i * 8 + 7] = (octet_ip[i] & 0x01) ? '1' : '0';

        binary_subnet[i * 8 + 0] = (octet_subnet[i] & 0x80) ? '1' : '0';
        binary_subnet[i * 8 + 1] = (octet_subnet[i] & 0x40) ? '1' : '0';
        binary_subnet[i * 8 + 2] = (octet_subnet[i] & 0x20) ? '1' : '0';
        binary_subnet[i * 8 + 3] = (octet_subnet[i] & 0x10) ? '1' : '0';
        binary_subnet[i * 8 + 4] = (octet_subnet[i] & 0x08) ? '1' : '0';
        binary_subnet[i * 8 + 5] = (octet_subnet[i] & 0x04) ? '1' : '0';
        binary_subnet[i * 8 + 6] = (octet_subnet[i] & 0x02) ? '1' : '0';
        binary_subnet[i * 8 + 7] = (octet_subnet[i] & 0x01) ? '1' : '0';
    }

    binary_ip[32] = '\0';
    binary_subnet[32] = '\0';

    for(i = 0; i < 32; i++) {
        binary_netid[i] = binary_ip[i] & binary_subnet[i];
        binary_bcid[i] = binary_ip[i] | ~binary_subnet[i];
    }

    binary_netid[32] = '\0';
    binary_bcid[32] = '\0';

    sscanf(binary_netid, "%d.%d.%d.%d", &octet_netid[0], &octet_netid[1], &octet_netid[2], &octet_netid[3]);
    sscanf(binary_bcid, "%d.%d.%d.%d", &octet_bcid[0], &octet_bcid[1], &octet_bcid[2], &octet_bcid[3]);

    sprintf(data->ip, "%d.%d.%d.%d", octet_ip[0], octet_ip[1], octet_ip[2], octet_ip[3]);
    sprintf(data->subnet, "%d.%d.%d.%d", octet_subnet[0], octet_subnet[1], octet_subnet[2], octet_subnet[3]);
    sprintf(data->network, "%d.%d.%d.%d", octet_netid[0], octet_netid[1], octet_netid[2], octet_netid[3]);
    sprintf(data->broadcast, "%d.%d.%d.%d", octet_bcid[0], octet_bcid[1], octet_bcid[2], octet_bcid[3]);
    sprintf(data->range_start, "%d.%d.%d.%d", octet_netid[0], octet_netid[1], octet_netid[2], octet_netid[3] + 1);   
    sprintf(data->range_end, "%d.%d.%d.%d", octet_bcid[0], octet_bcid[1], octet_bcid[2], octet_bcid[3] - 1);   
}

int main() {
    char ip[16], subnet[16];
    NetworkData data;
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter subnet mask: ");
    scanf("%s", subnet);

    calculate_network_details(ip, subnet, &data);

    printf("IP address: %s\n", data.ip);
    printf("Subnet mask: %s\n", data.subnet);
    printf("Network address: %s\n", data.network);
    printf("Broadcast address: %s\n", data.broadcast);
    printf("Range start: %s\n", data.range_start);
    printf("Range end: %s\n", data.range_end);

    return 0;
}