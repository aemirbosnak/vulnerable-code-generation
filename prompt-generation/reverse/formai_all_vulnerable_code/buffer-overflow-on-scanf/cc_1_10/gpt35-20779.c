//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//function prototypes
void getIP(char *ipAddress);
void getSubnet(int *subnetBits);
void calculateSubnet(char *ipAddress, int subnetBits);

int main(){
    char ipAddress[20]; //to store the ip address entered by user
    int subnetBits; //to store the subnet bits entered by user

    printf("Welcome to the C Subnet Calculator\n");

    getIP(ipAddress); //call getIP function to get user's IP address
    getSubnet(&subnetBits); //call getSubnet function to get user's subnet bits

    calculateSubnet(ipAddress, subnetBits); //call calculateSubnet function to calculate the subnet

    printf("\nThank you for using the C Subnet Calculator\n");
    
    return 0;
}

//function to get user's IP address
void getIP(char *ipAddress){
    printf("\nEnter your IP address (e.g. 192.168.1.1): ");
    scanf("%s", ipAddress);
}

//function to get user's subnet bits
void getSubnet(int *subnetBits){
    printf("\nEnter the number of subnet bits (e.g. 24): ");
    scanf("%d", subnetBits);
}

//function to calculate the subnet
void calculateSubnet(char *ipAddress, int subnetBits){
    int subnetMask[4]; //to store the subnet mask
    int octets[4]; //to store the IP address in octet format
    int binary[32]; //to store the binary representation of the subnet mask
    int i, j, k, temp, decimal;
    char subnet[20];

    //initialize octets array with 0
    for(i = 0; i < 4; i++){
        octets[i] = 0;
    }

    //split the IP address into octets
    for(i = 0, j = 0, k = 0; i < strlen(ipAddress); i++){
        if(ipAddress[i] == '.'){
            j++;
            k = 0;
        }
        else{
            octets[j] = 10 * octets[j] + (ipAddress[i] - '0');
            k++;
        }
    }

    //initialize binary array with 0
    for(i = 0; i < 32; i++){
        binary[i] = 0;
    }

    //calculate the binary representation of the subnet mask
    for(i = 0; i < subnetBits; i++){
        binary[i] = 1;
    }

    //calculate the decimal representation of the subnet mask and store it in subnetMask array
    for(i = 0, j = 0, k = 0, temp = 0; i < 32; i++){
        temp = 2 * temp + binary[i];
        k++;
        if(k == 8){
            subnetMask[j] = temp;
            temp = 0;
            k = 0;
            j++;
        }
    }

    //print the subnet mask
    printf("\nThe subnet mask is: ");
    for(i = 0; i < 4; i++){
        printf("%d", subnetMask[i]);
        if(i != 3){
            printf(".");
        }
    }

    //calculate the decimal representation of the subnet and store it in subnet array
    for(i = 0, j = 0, temp = 0, decimal = 0; i < 32; i++){
        temp = 2 * temp + binary[i];
        k++;
        if(k == 8){
            decimal = decimal * 256 + temp;
            temp = 0;
            k = 0;
            j++;
            sprintf(subnet + strlen(subnet), "%d", decimal);
            if(j != 4){
                sprintf(subnet + strlen(subnet), ".");
            }
            decimal = 0;
        }
    }

    //print the subnet
    printf("\nThe subnet is: %s\n", subnet);
}