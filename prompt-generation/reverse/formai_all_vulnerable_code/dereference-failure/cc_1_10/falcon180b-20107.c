//Falcon-180B DATASET v1.0 Category: Firewall ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

struct rule{
    char *protocol;
    char *ip_address;
    char *port;
    char action;
};

void add_rule(struct rule *rules, int count, char *protocol, char *ip_address, char *port, char action){
    if(count >= MAX_RULES){
        printf("Maximum number of rules exceeded\n");
        return;
    }

    int protocol_length = strlen(protocol);
    if(protocol_length > MAX_RULE_LENGTH){
        printf("Protocol name too long\n");
        return;
    }

    int ip_address_length = strlen(ip_address);
    if(ip_address_length > MAX_RULE_LENGTH){
        printf("IP address too long\n");
        return;
    }

    int port_length = strlen(port);
    if(port_length > MAX_RULE_LENGTH){
        printf("Port number too long\n");
        return;
    }

    strcpy(rules[count].protocol, protocol);
    strcpy(rules[count].ip_address, ip_address);
    strcpy(rules[count].port, port);
    rules[count].action = action;

    count++;
}

void print_rules(struct rule rules[], int count){
    printf("Firewall Rules:\n");
    for(int i=0; i<count; i++){
        printf("Rule %d: %s %s:%s %c\n", i+1, rules[i].protocol, rules[i].ip_address, rules[i].port, rules[i].action);
    }
}

int main(){
    struct rule rules[MAX_RULES];
    int count = 0;

    add_rule(rules, count, "TCP", "192.168.1.1", "80", 'A');
    add_rule(rules, count, "UDP", "192.168.1.2", "53", 'D');
    add_rule(rules, count, "ICMP", "192.168.1.3", "0", 'A');

    print_rules(rules, count);

    return 0;
}