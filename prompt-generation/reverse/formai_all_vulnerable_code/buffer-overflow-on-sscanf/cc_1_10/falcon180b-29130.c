//Falcon-180B DATASET v1.0 Category: Firewall ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100
#define MAX_IP_LENGTH 16
#define MAX_PORT_LENGTH 6

struct rule{
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
    int action;
};

void add_rule(struct rule *rules, int num_rules, char *ip, char *port, int action){
    strcpy(rules[num_rules].ip, ip);
    strcpy(rules[num_rules].port, port);
    rules[num_rules].action = action;
    num_rules++;
}

int match_rule(struct rule *rules, int num_rules, char *ip, int port){
    int i;
    for(i=0; i<num_rules; i++){
        if(strcmp(rules[i].ip, ip) == 0 && rules[i].port[0] == '*' || strcmp(rules[i].port, port) == 0){
            return rules[i].action;
        }
    }
    return -1;
}

int main(){
    struct rule rules[MAX_RULES];
    int num_rules = 0;
    char input[MAX_RULE_LENGTH];
    char ip[MAX_IP_LENGTH];
    char port[MAX_PORT_LENGTH];
    int action;

    printf("Enter rules in the format: <ip> <port> <action> (e.g. 192.168.0.1 80 1)\n");

    while(fgets(input, MAX_RULE_LENGTH, stdin)!= NULL){
        sscanf(input, "%s %s %d", ip, port, &action);
        add_rule(rules, num_rules, ip, port, action);
    }

    printf("Enter IP address and port number to check:\n");
    scanf("%s %s", ip, port);

    int result = match_rule(rules, num_rules, ip, port);

    if(result == 1){
        printf("Allowed\n");
    }
    else if(result == 0){
        printf("Denied\n");
    }
    else{
        printf("No rule found\n");
    }

    return 0;
}