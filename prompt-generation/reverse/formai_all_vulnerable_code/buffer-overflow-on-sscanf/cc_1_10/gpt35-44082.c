//FormAI DATASET v1.0 Category: System administration ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_INPUT 100

int main() {
    char input[MAX_INPUT];
    char command[MAX_INPUT];
    int run = 1;

    printf("Welcome to the Castle Command Console!\n");

    while(run) {
        printf(">");
        fgets(input, MAX_INPUT, stdin);
        sscanf(input, "%s", command);
        
        if(strcmp(command, "help") == 0) {
            printf("Commands:\n");
            printf("  help                : Display this help message\n");
            printf("  exit                : Exit the Castle Command Console\n");
            printf("  status              : Display system status and resource usage\n");
            printf("  firewall status     : Display the status of the castle firewall\n");
            printf("  firewall enable     : Enable the castle firewall\n");
            printf("  firewall disable    : Disable the castle firewall\n");
        }
        else if(strcmp(command, "exit") == 0) {
            printf("Exiting Castle Command Console\n");
            run = 0;
        }
        else if(strcmp(command, "status") == 0) {
            printf("Checking system status and resource usage...\n");
            system("top -b -n 1 | grep -E '^%Cpu|^KiB' | awk '{print $1 $2 $3 $4 $5 $6 $7 $8}'");
        }
        else if(strcmp(command, "firewall") == 0) {
            char firewall[MAX_INPUT];
            char status[MAX_INPUT];
            sscanf(input, "%s %s", firewall, status);
            if(strcmp(status, "status") == 0) {
                printf("The castle firewall is currently enabled\n");
            }
            else if(strcmp(status, "enable") == 0) {
                printf("Enabling the castle firewall...\n");
                system("iptables -F; iptables -P INPUT DROP");
                printf("Castle firewall enabled!\n");
            }
            else if(strcmp(status, "disable") == 0) {
                printf("Disabling the castle firewall...\n");
                system("iptables -F; iptables -P INPUT ACCEPT");
                printf("Castle firewall disabled!\n");
            }
            else {
                printf("Usage: firewall [status|enable|disable]\n");
            }
        }
        else {
            printf("Command not recognized. Type 'help' for a list of available commands.\n");
        }
    }
    return 0;
}