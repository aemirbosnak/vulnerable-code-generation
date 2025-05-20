//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_LOG_LENGTH 2048

// function to parse the input string
void parse_input(char* input, char* source_ip, char* target_ip, char* message) {
    int i = 0, j = 0;
    while(input[i] != '|') {
        source_ip[i] = input[i];
        i++;
    }
    source_ip[i] = '\0';
    i++;
    while(input[i] != '|') {
        target_ip[j] = input[i];
        i++;
        j++;
    }
    target_ip[j] = '\0';
    i++;
    j = 0;
    while(input[i] != '\0') {
        message[j] = input[i];
        i++;
        j++;
    }
    message[j] = '\0';
}

// function to log the detected intrusion
void log_intrusion(char* source_ip, char* target_ip, char* message) {
    FILE* fp;
    char log_entry[MAX_LOG_LENGTH];
    snprintf(log_entry, MAX_LOG_LENGTH, "INTRUSION DETECTED from %s to %s : %s", source_ip, target_ip, message);
    fp = fopen("intrusion_logs.txt", "a");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp, "%s\n", log_entry);
    fclose(fp);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char source_ip[20], target_ip[20], message[100];
    char* blacklist[5] = {"10.0.0.5", "192.168.1.2", "172.20.10.1", "10.1.0.4", "192.168.2.3"};

    printf("Enter the input string : ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strlen(input)-1] = '\0';

    parse_input(input, source_ip, target_ip, message);

    // check if the source IP is present in the blacklist
    for(int i=0; i<5; i++) {
        if(strcmp(source_ip, blacklist[i]) == 0) {
            log_intrusion(source_ip, target_ip, message);
            printf("Intrusion detected and logged!\n");
            exit(0);
        }
    }

    printf("No intrusion detected!\n");

    return 0;
}