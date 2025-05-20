//FormAI DATASET v1.0 Category: Firewall ; Style: calm
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct firewallRule {            // A struct defining our firewall rule
    char source[20];
    char destination[20];
    char protocol[10];
    int port;
};

int main() {
    struct firewallRule rule1;  // Declare our first rule
    strcpy(rule1.source, "192.168.1.2");
    strcpy(rule1.destination, "192.168.1.1");
    strcpy(rule1.protocol, "tcp");
    rule1.port = 80;

    struct firewallRule rule2;  // Declare our second rule
    strcpy(rule2.source, "192.168.1.3");
    strcpy(rule2.destination, "192.168.1.1");
    strcpy(rule2.protocol, "udp");
    rule2.port = 53;

    struct firewallRule rule3;  // Declare our third rule
    strcpy(rule3.source, "192.168.1.4");
    strcpy(rule3.destination, "192.168.1.1");
    strcpy(rule3.protocol, "icmp");
    rule3.port = 0;

    struct firewallRule firewallRules[3];   // Create an array of firewall rules
    firewallRules[0] = rule1;
    firewallRules[1] = rule2;
    firewallRules[2] = rule3;

    char sourceIP[20];
    char destIP[20];
    char proto[10];
    int portNum;
    int blocked = 0;

    printf("Enter source IP address: ");
    scanf("%s", sourceIP);        // Take input from user
    printf("Enter destination IP address: ");
    scanf("%s", destIP);
    printf("Enter protocol: ");
    scanf("%s", proto);
    printf("Enter port number: ");
    scanf("%d", &portNum);

    for(int i=0; i<3; i++) {      // Loop through each firewall rule and compare it with user input
        if(strcmp(sourceIP, firewallRules[i].source) == 0 && 
           strcmp(destIP, firewallRules[i].destination) == 0 && 
           strcmp(proto, firewallRules[i].protocol) == 0 &&
           (portNum == firewallRules[i].port || firewallRules[i].port == 0)) { // if the rule matches the user input, block traffic
            blocked = 1;
            printf("Traffic blocked by firewall rule %d\n", i+1);
            break;
        }
    }

    if(blocked == 0) {            // If no firewall rule matched, allow traffic
        printf("Traffic allowed\n");
    }

    return 0;                     // End program
}