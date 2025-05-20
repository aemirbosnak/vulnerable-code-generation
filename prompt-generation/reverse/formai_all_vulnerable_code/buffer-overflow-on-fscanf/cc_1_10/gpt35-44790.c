//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: minimalist
#include <stdio.h>
#include <string.h>

// Structure to store Intrusion Log
struct intrusion_log{
    char ip_address[16];
    char attack_type[20];
};

// Function to check if IP is blacklisted
int isBlacklisted(char ip_address[], struct intrusion_log logs[], int num_logs){
    for(int i=0; i<num_logs; i++){
        if(strcmp(logs[i].ip_address, ip_address) == 0){
            return 1;
        }
    }
    return 0;
}

int main(){
    // Number of logs
    int n = 0;
    
    // Array to store intrusion logs
    struct intrusion_log logs[1000];
    
    // Open the log file
    FILE *fp;
    fp = fopen("intrusion_logs.txt", "r");
    if(fp == NULL){
        printf("Error opening log file\n");
        return 0;
    }
    
    // Read the logs and store them in the array
    while(!feof(fp)){
        fscanf(fp, "%s %s", logs[n].ip_address, logs[n].attack_type);
        n++;
    }
    fclose(fp);

    // Get input IP
    char ip_input[16];
    printf("Enter IP address: ");
    scanf("%s", ip_input);

    // Check if the IP is blacklisted
    if(isBlacklisted(ip_input, logs, n)){
        printf("IP %s is blacklisted\n", ip_input);
    }
    else{
        printf("IP %s is not blacklisted\n", ip_input);
    }
    
    return 0;
}