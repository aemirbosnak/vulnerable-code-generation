//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: intelligent
#include <stdio.h>
#include <math.h>

int main() {
    char ip[15];
    int subnet;
    printf("Enter IP Address (e.g. 192.168.0.1): ");
    scanf("%s", ip);
    printf("Enter Subnet Mask (e.g. 24): ");
    scanf("%d", &subnet);
    // calculate number of hosts in subnet
    int hosts = pow(2, 32-subnet)-2;
    // convert IP address to binary
    int ip_binary[32];
    int i, j, k;
    j = k = 0;
    for(i = 0; i < 32; i++) {
        ip_binary[i] = 0;
    }
    i = 0;
    while(ip[j] != '\0') {
        if(ip[j] == '.') {
            k++;
            i = 0;
        }
        else {
            ip_binary[(k*8)+i] = ((ip[j]-'0')/8)%2;
            ip_binary[(k*8)+i+1] = ((ip[j]-'0')/4)%2;
            ip_binary[(k*8)+i+2] = ((ip[j]-'0')/2)%2;
            ip_binary[(k*8)+i+3] = (ip[j]-'0')%2;
            i += 4;
        }
        j++;
    }
    // find network address and broadcast address
    int net_address[32], broad_address[32];
    for(i = 0; i < 32; i++) {
        if(i < subnet) {
            net_address[i] = ip_binary[i];
            broad_address[i] = ip_binary[i];
        }
        else {
            net_address[i] = 0;
            broad_address[i] = 1;
        }
    }
    // convert binary to decimal for display
    int dec_ip[4], dec_net[4], dec_broad[4];
    for(i = 0; i < 4; i++) {
        dec_ip[i] = 0;
        dec_net[i] = 0;
        dec_broad[i] = 0;
        for(j = 0; j < 8; j++) {
            dec_ip[i] += ip_binary[(i*8)+j] * pow(2, 7-j);
            dec_net[i] += net_address[(i*8)+j] * pow(2, 7-j);
            dec_broad[i] += broad_address[(i*8)+j] * pow(2, 7-j);
        }
    }
    // print results
    printf("\nIP Address: %s\n", ip);
    printf("Subnet Mask: %d\n", subnet);
    printf("Number of Hosts: %d\n", hosts);
    printf("Network Address: %d.%d.%d.%d\n", dec_net[0], dec_net[1], dec_net[2], dec_net[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", dec_broad[0], dec_broad[1], dec_broad[2], dec_broad[3]);
    return 0;
}