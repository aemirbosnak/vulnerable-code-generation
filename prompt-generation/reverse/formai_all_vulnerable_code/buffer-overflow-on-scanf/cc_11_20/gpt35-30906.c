//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip[16], subnet[16];
    printf("Enter IP address in the format XXX.XXX.XXX.XXX: ");
    scanf("%s", ip);
    printf("Enter subnet mask in the format XXX.XXX.XXX.XXX: ");
    scanf("%s", subnet);
    char *token1, *token2, *token3, *token4;
    token1 = strtok(ip, ".");
    token2 = strtok(NULL, ".");
    token3 = strtok(NULL, ".");
    token4 = strtok(NULL, ".");
    int ip1 = atoi(token1);
    int ip2 = atoi(token2);
    int ip3 = atoi(token3);
    int ip4 = atoi(token4);
    token1 = strtok(subnet, ".");
    token2 = strtok(NULL, ".");
    token3 = strtok(NULL, ".");
    token4 = strtok(NULL, ".");
    int sub1 = atoi(token1);
    int sub2 = atoi(token2);
    int sub3 = atoi(token3);
    int sub4 = atoi(token4);
    if(ip1 > 255 || ip2 > 255 || ip3 > 255 || ip4 > 255) {
        printf("Invalid IP address.");
        exit(0);
    }
    if(sub1 > 255 || sub2 > 255 || sub3 > 255 || sub4 > 255) {
        printf("Invalid subnet mask.");
        exit(0);
    }
    int mask[32];
    int i = 0;
    while(i < sub1) {
        mask[i] = 255;
        i++;
    }
    while(i < sub1+sub2) {
        mask[i] = 0;
        i++;
    }
    while(i < sub1+sub2+sub3) {
        mask[i] = 0;
        i++;
    }
    while(i < 32) {
        mask[i] = 0;
        i++;
    }
    int subnetAddr[4];
    subnetAddr[0] = ip1 & mask[0];
    subnetAddr[1] = ip2 & mask[1];
    subnetAddr[2] = ip3 & mask[2];
    subnetAddr[3] = ip4 & mask[3];
    int broadcastAddr[4];
    broadcastAddr[0] = subnetAddr[0] | (~mask[0] & 0xff);
    broadcastAddr[1] = subnetAddr[1] | (~mask[1] & 0xff);
    broadcastAddr[2] = subnetAddr[2] | (~mask[2] & 0xff);
    broadcastAddr[3] = subnetAddr[3] | (~mask[3] & 0xff);
    printf("Subnet Address: %d.%d.%d.%d\n", subnetAddr[0], subnetAddr[1], subnetAddr[2], subnetAddr[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddr[0], broadcastAddr[1], broadcastAddr[2], broadcastAddr[3]);
    printf("Number of hosts in the subnet: %d\n", (int)pow(2, (32-sub1-sub2-sub3))-2);
    return 0;
}