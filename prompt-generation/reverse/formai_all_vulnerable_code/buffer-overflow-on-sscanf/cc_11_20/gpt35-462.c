//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//This program is a subnet calculator designed to aid in network configuration.
//The user will enter an IP address and a subnet mask to determine the network
//address and the number of available hosts on the network.

//The program will begin with a prompt for the user to input the IP address.
//Sherlock Holmes would appreciate the precise attention to detail, for he
//is a master of observation and deduction.

int main(){

    //Prompt for IP address
    printf("Please enter an IP address in the form xxx.xxx.xxx.xxx:\n");

    //Use fgets to read in user input as a string variable
    char ip_address[16];
    fgets(ip_address, 16, stdin);

    //Verify that input contains four segments separated by periods
    int period_count = 0;
    int digit_count = 0;
    for(int i = 0; i < strlen(ip_address); i++){
        if(ip_address[i] == '.'){
            period_count++;
            //Reset digit count to ensure each segment has appropriate length
            digit_count = 0;
        }
        else if(ip_address[i] >= '0' && ip_address[i] <= '9'){
            digit_count++;
        }
        else{
            //Invalid character detected
            printf("Invalid IP address format.\n");
            return 0;
        }
        //Check if current segment has appropriate length
        if(digit_count > 3){
            printf("Invalid IP address format.\n");
            return 0;
        }
    }

    //Ensure that IP address has four segments separated by periods
    if(period_count != 3){
        printf("Invalid IP address format.\n");
        return 0;
    }

    //If IP address is valid, prompt for subnet mask
    printf("Please enter a subnet mask in the form xxx.xxx.xxx.xxx:\n");

    //Use fgets to read in subnet mask as a string variable
    char subnet_mask[16];
    fgets(subnet_mask, 16, stdin);

    //Verify that subnet mask format is valid
    period_count = 0;
    digit_count = 0;
    int valid_bits = 0; //Count the number of "1" bits in the subnet mask
    for(int i = 0; i < strlen(subnet_mask); i++){
        if(subnet_mask[i] == '.'){
            period_count++;
            //Reset digit count to ensure each segment has appropriate length
            digit_count = 0;
        }
        else if(subnet_mask[i] >= '0' && subnet_mask[i] <= '9'){
            digit_count++;
            if(subnet_mask[i] == '1'){
                valid_bits++;
            }
        }
        else{
            //Invalid character detected
            printf("Invalid subnet mask format.\n");
            return 0;
        }
        //Check if current segment has appropriate length
        if(digit_count > 3){
            printf("Invalid subnet mask format.\n");
            return 0;
        }
        //Ensure that subnet mask is composed of valid values ("0" or "1")
        if(subnet_mask[i] != '0' && subnet_mask[i] != '1' && subnet_mask[i] != '.'){
            printf("Invalid subnet mask format.\n");
            return 0;
        }
    }

    //Ensure that subnet mask has four segments separated by periods
    if(period_count != 3){
        printf("Invalid subnet mask format.\n");
        return 0;
    }

    //Ensure that subnet mask has valid number of "1" bits
    if(valid_bits % 8 != 0){
        printf("Invalid subnet mask format.\n");
        return 0;
    }

    //If IP address and subnet mask are valid, calculate subnet information
    int ip_segments[4];
    int mask_segments[4];
    sscanf(ip_address, "%d.%d.%d.%d", &ip_segments[0], &ip_segments[1], &ip_segments[2], &ip_segments[3]);
    sscanf(subnet_mask, "%d.%d.%d.%d", &mask_segments[0], &mask_segments[1], &mask_segments[2], &mask_segments[3]);

    //Calculate network address
    int network_segments[4];
    for(int i = 0; i < 4; i++){
        network_segments[i] = ip_segments[i] & mask_segments[i];
    }

    //Calculate number of available hosts
    int host_bits = 32 - valid_bits;
    unsigned long int hosts = pow(2, host_bits) - 2; //Subtract 2 for network and broadcast addresses

    //Print network address and number of available hosts
    printf("The network address is %d.%d.%d.%d\n", network_segments[0], network_segments[1], network_segments[2], network_segments[3]);
    printf("The number of available hosts on the network is %lu\n", hosts);

    return 0;
}