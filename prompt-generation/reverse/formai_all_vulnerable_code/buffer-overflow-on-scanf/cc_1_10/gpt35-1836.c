//FormAI DATASET v1.0 Category: Firewall ; Style: genious
/* Sample code snippet for a basic firewall implementation in C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void blockIP(char* ip, FILE* fp) {
    fprintf(fp, "iptables -A INPUT -s %s -j DROP\n", ip);
}

void allowIP(char* ip, FILE* fp) {
    fprintf(fp, "iptables -A INPUT -s %s -j ACCEPT\n", ip);
}

int main() {
    FILE* fp;
    char choice;
    char ip[20];
    do {
        printf("\nWelcome to the Firewall settings!\n");
        printf("Choose an option:\n");
        printf("1. Block an IP address\n");
        printf("2. Allow an IP address\n");
        printf("3. Exit\n");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                printf("\nEnter the IP address: ");
                scanf("%s", ip);
                fp = popen("sudo iptables -L INPUT", "r");
                blockIP(ip, fp);
                printf("IP address %s is blocked\n", ip);
                pclose(fp);
                break;
            case '2':
                printf("\nEnter the IP address: ");
                scanf("%s", ip);
                fp = popen("sudo iptables -L INPUT", "r");
                allowIP(ip, fp);
                printf("IP address %s is allowed\n", ip);
                pclose(fp);
                break;
            case '3':
                printf("\nExiting Firewall settings...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again!\n");
                break;
        }
    } while(choice != '3');
    return 0;
}