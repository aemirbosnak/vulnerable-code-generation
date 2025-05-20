//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_IP_STRING_LEN 17
#define MAX_CIDR_STRING_LEN 3

int getNumberOfSubnets(int cidr) {
    return (int) pow(2, (32 - cidr));
}

void convertIpStringToIntArray(char* ipString, int *ip_int_array) {
    char *token;
    int i = 0;

    token = strtok(ipString, ".");
    while(token != NULL) {
        ip_int_array[i++] = atoi(token);
        token = strtok(NULL, ".");
    }
}

void printIntArray(int *arr, int len) {
    int i = 0;
    for(i = 0; i < len; i++) {
        printf("%d.", arr[i]);
    }
    printf("\n");
}

void calculateAndPrintSubnetDetails(char* ipString, char* cidrString) {
    int subnetIpIntArr[4];
    int maskIntArr[4];
    int cidr = atoi(cidrString);
    int numberOfSubnets = getNumberOfSubnets(cidr); 
    int subnetHosts = (int) pow(2, (32 - cidr)) - 2; 
    int i = 0;

    convertIpStringToIntArray(ipString, subnetIpIntArr);

    // Calculate the subnet mask
    for(i = 0; i < 4; i++) {
        if(cidr >= 8) {
            maskIntArr[i] = 255;
            cidr -= 8;
        } else if(cidr < 8 && cidr > 0) {
            maskIntArr[i] = (int) pow(2, cidr) - 1;
            maskIntArr[i] += (maskIntArr[i] << (8 - cidr));
            cidr = 0;
        } else {
            maskIntArr[i] = 0;
        }
    }

    printf("IP Address:\t\t%s\n", ipString);
    printf("CIDR Notation:\t\t%s\n", cidrString);
    printf("Subnet Mask:\t\t");
    printIntArray(maskIntArr, 4);
    printf("Number of Subnets:\t%d\n", numberOfSubnets);
    printf("Number of Hosts/Subnet:\t%d\n\n", subnetHosts);
}

void getInputAndCalculateSubnetDetails() {
    char ipString[MAX_IP_STRING_LEN];
    char cidrString[MAX_CIDR_STRING_LEN];
    bool inputValid = false;

    while(!inputValid) {
        printf("Enter IP Address (in dot notation format, e.g. 192.168.0.1):\n");
        scanf("%s", ipString);

        printf("Enter CIDR notation (e.g. 24):\n");
        scanf("%s", cidrString);  

        // Validate IP address and CIDR notation and prompt the user until these inputs are valid
        inputValid = true;
        int i = 0;
        int numPeriods = 0;
        int numDigits = 0;
        int ip_int_array[4];
        int cidr = atoi(cidrString);
      
        while(ipString[i] != '\0') {
            if(ipString[i] == '.') {
                numPeriods++;
                if(numDigits > 3 || (numDigits == 3 && (ipString[i - 1] == '0' || ipString[i - 2] == '0'))) {
                    inputValid = false;
                    printf("Invalid IP address. Please enter a valid IP address.\n");
                    break;
                }
                numDigits = 0;
            } else if(ipString[i] >= '0' && ipString[i] <= '9') {
                numDigits++;
            } else {
                inputValid = false;
                printf("Invalid IP address. Please enter a valid IP address.\n");
                break;
            }
            i++;
        }

        if(numPeriods != 3 || numDigits > 3 || (numDigits == 3 && (ipString[i - 1] == '0' || ipString[i - 2] == '0'))) {
            inputValid = false;
            printf("Invalid IP address. Please enter a valid IP address.\n");
        }

        if(cidr < 0 || cidr > 32) {
            inputValid = false;
            printf("Invalid CIDR notation. Please enter a valid CIDR notation.\n");
        }
    }

    calculateAndPrintSubnetDetails(ipString, cidrString);
}

int main() {
    char choice = 'y';
    while(choice == 'y' || choice == 'Y') {
        getInputAndCalculateSubnetDetails();
        printf("Do you want to calculate subnet details again? (Y/N)\n");
        scanf("%s", &choice);
    }
    return 0;
}