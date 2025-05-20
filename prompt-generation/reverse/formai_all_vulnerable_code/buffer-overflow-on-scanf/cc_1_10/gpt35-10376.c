//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include<stdio.h>
#include<string.h>

void decToBin(int n, char binaryNum[]){
    int i;
    for (i = 7; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            strcat(binaryNum, "1");
        else
            strcat(binaryNum, "0");
    }
}

int main(){
    char ip[16];
    int subnet_mask, first_octet, second_octet, third_octet, fourth_octet;
    printf("Enter IP Address: ");
    scanf("%s", &ip);
    printf("Enter Subnet Mask in Bits: ");
    scanf("%d", &subnet_mask);

    strtok(ip, ".");
    first_octet = atoi(strtok(NULL, "."));
    second_octet = atoi(strtok(NULL, "."));
    third_octet = atoi(strtok(NULL, "."));
    fourth_octet = atoi(strtok(NULL, "."));

    //calculating binary equivalent of the subnet mask
    char binary_subnet[33];
    int i;
    for(i=0;i<subnet_mask;i++) {
        binary_subnet[i] = '1';   
    }
    for(;i<32;i++) {
        binary_subnet[i] = '0';   
    }
    binary_subnet[32]='\0';

    //calculating network address by ANDing IP and subnet mask
    int binary_ip1[8]={0},binary_ip2[8]={0},binary_ip3[8]={0},binary_ip4[8]={0};
    char binary_subnet_octet[9];
    int network_first_octet, network_second_octet, network_third_octet, network_fourth_octet;
    for(i=0;i<8;i++) {
        binary_subnet_octet[i] = binary_subnet[i];
    }
    binary_subnet_octet[8] = '\0';
    network_first_octet = first_octet & strtol(binary_subnet_octet, 0, 2);
    decToBin(network_first_octet, binary_subnet_octet);
    strncpy(binary_subnet_octet, "00000000", sizeof(binary_subnet_octet));
    for(i=0;i<8;i++) {
        binary_subnet_octet[i] = binary_subnet[i+8];
    }
    binary_subnet_octet[8] = '\0';
    network_second_octet = second_octet & strtol(binary_subnet_octet, 0, 2);
    decToBin(network_second_octet, binary_subnet_octet);
    strncpy(binary_subnet_octet, "00000000", sizeof(binary_subnet_octet));
    for(i=0;i<8;i++) {
        binary_subnet_octet[i] = binary_subnet[i+16];
    }
    binary_subnet_octet[8] = '\0';
    network_third_octet = third_octet & strtol(binary_subnet_octet, 0, 2);
    decToBin(network_third_octet, binary_subnet_octet);
    strncpy(binary_subnet_octet, "00000000", sizeof(binary_subnet_octet));
    for(i=0;i<8;i++) {
        binary_subnet_octet[i] = binary_subnet[i+24];
    }
    binary_subnet_octet[8] = '\0';
    network_fourth_octet = fourth_octet & strtol(binary_subnet_octet, 0, 2);
    decToBin(network_fourth_octet, binary_subnet_octet);

    //calculating broadcast address by ORing IP and bitwise complement of subnet mask
    int broadcast_first_octet, broadcast_second_octet, broadcast_third_octet, broadcast_fourth_octet;
    for(i=0;i<8;i++) {
        binary_subnet_octet[i] = '1';
    }
    for(;i<32;i++) {
        binary_subnet_octet[i] = '0';
    }
    binary_subnet_octet[32]='\0';
    broadcast_first_octet = first_octet | strtol(binary_subnet_octet, 0, 2);
    decToBin(broadcast_first_octet, binary_subnet_octet);
    strncpy(binary_subnet_octet, "00000000", sizeof(binary_subnet_octet));
    for(i=0;i<8;i++) {
        binary_subnet_octet[i] = '1';
    }
    for(;i<32;i++) {
        binary_subnet_octet[i] = '0';
    }
    binary_subnet_octet[32]='\0';
    broadcast_second_octet = second_octet | strtol(binary_subnet_octet, 0, 2);
    decToBin(broadcast_second_octet, binary_subnet_octet);
    strncpy(binary_subnet_octet, "00000000", sizeof(binary_subnet_octet));
    for(i=0;i<8;i++) {
        binary_subnet_octet[i] = '1';
    }
    for(;i<32;i++) {
        binary_subnet_octet[i] = '0';
    }
    binary_subnet_octet[32]='\0';
    broadcast_third_octet = third_octet | strtol(binary_subnet_octet, 0, 2);
    decToBin(broadcast_third_octet, binary_subnet_octet);
    strncpy(binary_subnet_octet, "00000000", sizeof(binary_subnet_octet));
    for(i=0;i<8;i++) {
        binary_subnet_octet[i] = '1';
    }
    for(;i<32;i++) {
        binary_subnet_octet[i] = '0';
    }
    binary_subnet_octet[32]='\0';
    broadcast_fourth_octet = fourth_octet | strtol(binary_subnet_octet, 0, 2);
    decToBin(broadcast_fourth_octet, binary_subnet_octet);

    //outputting the network address and broadcast address
    printf("Network Address: %d.%d.%d.%d\n", network_first_octet, network_second_octet, network_third_octet, network_fourth_octet);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_first_octet, broadcast_second_octet, broadcast_third_octet, broadcast_fourth_octet);
    return 0;
}