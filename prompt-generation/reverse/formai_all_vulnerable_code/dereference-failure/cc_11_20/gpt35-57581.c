//FormAI DATASET v1.0 Category: Firewall ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX_LINES 5000
#define MAX_LENGTH 80

void firewall(char *filename);

int main(int argc, char *argv[]) {
    
    if(argc != 2) {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        exit(1);
    }
    
    firewall(argv[1]);
    return 0;
}

void firewall(char *filename) {
    FILE *fp;
    char line[MAX_LENGTH], command[MAX_LENGTH], ip[MAX_LENGTH], port[MAX_LENGTH];
    int line_count = 0;
    int i, j, k, l, m;
    int count_ip_rules = 0;
    int count_port_rules = 0;
    char allow_ip[MAX_LINES][MAX_LENGTH];
    char deny_ip[MAX_LINES][MAX_LENGTH];
    char allow_port[MAX_LINES][MAX_LENGTH];
    char deny_port[MAX_LINES][MAX_LENGTH];
    
    fp = fopen(filename, "r");
    if(fp == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        exit(1);
    }
    
    while(fgets(line, sizeof(line), fp) != NULL) {
        line_count++;
        if(line[strlen(line) - 1] != '\n') {
            fprintf(stderr, "Line %d: Input too long\n", line_count);
            exit(1);
        }
        if(sscanf(line, "%s %s %s", command, ip, port) != 3) {
            fprintf(stderr, "Line %d: Invalid input format\n", line_count);
            exit(1);
        }
        if(strcmp(command, "allow") != 0 && strcmp(command, "deny") != 0) {
            fprintf(stderr, "Line %d: Invalid command\n", line_count);
            exit(1);
        }
        i = j = k = l = m = 0;
        while(ip[i] != '\0') {
            if(!isdigit(ip[i]) && ip[i] != '.') {
                fprintf(stderr, "Line %d: Invalid IP address\n", line_count);
                exit(1);
            }
            if(ip[i] == '.') {
                j++;
            }
            i++;
        }
        if(j != 3) {
            fprintf(stderr, "Line %d: Invalid IP address\n", line_count);
            exit(1);
        }
        if(strcmp(port, "any") != 0) {
            while(port[k] != '\0') {
                if(!isdigit(port[k])) {
                    fprintf(stderr, "Line %d: Invalid port number\n", line_count);
                    exit(1);
                }
                k++;
            }
        }
        if(strcmp(command, "allow") == 0) {
            if(strcmp(port, "any") == 0) {
                strcpy(allow_ip[count_ip_rules], ip);
                count_ip_rules++;
            } else {
                strcpy(allow_port[count_port_rules], port);
                count_port_rules++;
            }
        } else {
            if(strcmp(port, "any") == 0) {
                strcpy(deny_ip[count_ip_rules], ip);
                count_ip_rules++;
            } else {
                strcpy(deny_port[count_port_rules], port);
                count_port_rules++;
            }
        }
    }
    
    fclose(fp);
    
    printf("Firewall rules: Allow IP addresses\n");
    for(i = 0; i < count_ip_rules; i++) {
        printf("%s\n", allow_ip[i]);
    }
    
    printf("\nFirewall rules: Deny IP addresses\n");
    for(i = 0; i < count_ip_rules; i++) {
        printf("%s\n", deny_ip[i]);
    }
    
    printf("\nFirewall rules: Allow ports\n");
    for(i = 0; i < count_port_rules; i++) {
        printf("%s\n", allow_port[i]);
    }
    
    printf("\nFirewall rules: Deny ports\n");
    for(i = 0; i < count_port_rules; i++) {
        printf("%s\n", deny_port[i]);
    }
    
    return;
}