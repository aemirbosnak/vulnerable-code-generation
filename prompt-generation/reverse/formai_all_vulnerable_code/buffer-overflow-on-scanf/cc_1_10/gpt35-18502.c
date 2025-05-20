//FormAI DATASET v1.0 Category: Firewall ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Defining Constants
#define MAX_SIZE 100
#define BLOCKED_IP "192.168.1.10"

//Function to check for blocked IPs
int check_blocked_ip(char* ip_address){
    if(strcmp(ip_address, BLOCKED_IP) == 0)
        return 1;
    else
        return 0;
}

//Function to validate IP address
int validate_ip_address(char* ip_address){
    //Checking for empty IPs
    if(strlen(ip_address) == 0)
        return 0;
    //Checking for valid IP address formats
    int count=0, num=0;
    for(int i=0; i<=strlen(ip_address); i++){
        if(ip_address[i] == '.' || ip_address[i] == '\0'){
            if(count>3 || num < 0 || num > 255)
                return 0;
            count++;
            num=0;
        }
        else if(isdigit(ip_address[i]))
            num = num*10 + (ip_address[i]-'0');
        else
            return 0;
    }
    return 1;
}

int main(){
    char ip_address[MAX_SIZE];
    printf("Welcome to My Firewall Program!\n");
    printf("Please enter the IP address to check: ");
    scanf("%s", ip_address);

    if(!validate_ip_address(ip_address)){
        printf("Invalid IP address format!\n");
        exit(0);
    }

    if(check_blocked_ip(ip_address)){
        printf("Access Denied! %s is a blocked IP address.\n", ip_address);
    }
    else{
        printf("Access granted! %s is not a blocked IP address.\n", ip_address);
    }

    return 0;
}