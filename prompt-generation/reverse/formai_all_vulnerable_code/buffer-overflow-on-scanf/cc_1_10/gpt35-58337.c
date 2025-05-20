//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: active
#include<stdio.h>
#include<math.h>

// function to convert IP address to binary format
void convertIPtoBinary(int ip[], int binaryIP[]){
    int i, j, count=0;
    for(i=0; i<4; i++){
        int num = ip[i];
        for(j=7; j>=0; j--){
            binaryIP[count++] = (num >> j) & 1;
        }
    }
}

// function to convert binary format to IP address
void convertBinaryToIP(int binaryIP[], int ip[]){
    int i, j, count=0, num=0;
    for(i=0; i<32; i++){
        num += binaryIP[i]*pow(2, (7-count%8));
        count++;
        if(count%8 == 0){
            ip[count/8-1] = num;
            num = 0;
        }
    }
}

int main(){
    int ip[4], binaryIP[32];
    printf("Enter IP Address (in the form of x.x.x.x): ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Enter Subnet Mask (in the form of x.x.x.x): ");
    int subnetIP[4], binarySubnetIP[32];
    scanf("%d.%d.%d.%d", &subnetIP[0], &subnetIP[1], &subnetIP[2], &subnetIP[3]);

    // convert IP address to binary format
    convertIPtoBinary(ip, binaryIP);

    // convert subnet mask to binary format
    convertIPtoBinary(subnetIP, binarySubnetIP);

    // find the prefix length
    int prefixLength = 0;
    for(int i=0; i<32; i++){
        if(binarySubnetIP[i] == 1){
            prefixLength++;
        }
        else{
            break;
        }
    }

    // find subnet ID, broadcast ID and number of hosts
    int subnetID[4], broadcastID[4];
    int numHosts = pow(2, (32-prefixLength)) - 2;
    for(int i=0; i<32; i++){
        if(i < prefixLength){
            subnetID[i/8] += binaryIP[i]*pow(2, (7-i%8));
            broadcastID[i/8] += binaryIP[i]*pow(2, (7-i%8));
        }
        else{
            broadcastID[i/8] += pow(2, (7-i%8));
        }
    }

    // convert subnet ID and broadcast ID to IP address format
    int subnetIPdisp[4], broadcastIPdisp[4];
    convertBinaryToIP(subnetID, subnetIPdisp);
    convertBinaryToIP(broadcastID, broadcastIPdisp);

    // display the results
    printf("Subnet ID: %d.%d.%d.%d\n",subnetIPdisp[0],subnetIPdisp[1],subnetIPdisp[2],subnetIPdisp[3]);
    printf("Broadcast ID: %d.%d.%d.%d\n",broadcastIPdisp[0],broadcastIPdisp[1],broadcastIPdisp[2],broadcastIPdisp[3]);
    printf("Number of hosts: %d", numHosts);

    return 0;
}