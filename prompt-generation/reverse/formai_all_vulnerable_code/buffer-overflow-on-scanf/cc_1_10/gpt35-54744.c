//FormAI DATASET v1.0 Category: Firewall ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Function to check if the user has entered alphabets in the IP address
int is_valid_ip_address(char *ip_address){
    int num, dots = 0, len = 0;
    int i, j;

    //Checking if the IP address has 4 parts separated by periods
    for(i = 0;i < strlen(ip_address);i++){
        if(ip_address[i] == '.')
            dots++;
    }

    if(dots != 3) return 0;
    
    //Checking if all the characters in the IP address are digits or periods
    for(i = 0;i < strlen(ip_address);i++){
        if(!isdigit(ip_address[i]) && ip_address[i] != '.') 
            return 0;
    }

    //Checking if all the 4 parts of the IP address are valid
    char *ptr = strtok(ip_address, ".");
    while(ptr != NULL){
        len = strlen(ptr);
        if(len == 0 || len > 3) 
            return 0;
        if(len > 1 && ptr[0] == '0') 
            return 0;
        num = 0;
        for(j = 0;j < len;j++){
            if(!isdigit(ptr[j])) 
                return 0;
            num = num * 10 + (ptr[j] - '0');
        }
        if(num > 255) 
            return 0;
        ptr = strtok(NULL, ".");
    }

    return 1;
}

int main(){
    char ip[15];

    printf("Enter the IP address to be blocked: ");
    scanf("%s", ip);
    if(is_valid_ip_address(ip)){
        printf("IP address is valid and can be blocked.");
        // Code for blocking IP address here
    }
    else{
        printf("IP address is invalid and cannot be blocked.");
        // Code for taking any other action here
    }

    return 0;
}