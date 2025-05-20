//FormAI DATASET v1.0 Category: Firewall ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RULES 50
#define MAX_RULE_LEN 100
#define BUFFER_SIZE 1024

struct rule {
    char protocol[10];
    char source_ip[16];
    int source_port;
    char dest_ip[16];
    int dest_port;
    char action[10];
};

int parse_rule(char* rule_str, struct rule* r) {
    char *token;
    int i = 0;

    token = strtok(rule_str, " ");
    while(token != NULL) {
        switch(i) {
            case 0:
                strcpy(r->protocol, token);
                break;
            case 1:
                strcpy(r->source_ip, token);
                break;
            case 2:
                r->source_port = atoi(token);
                break;
            case 3:
                strcpy(r->dest_ip, token);
                break;
            case 4:
                r->dest_port = atoi(token);
                break;
            case 5:
                strcpy(r->action, token);
                break;
            default:
                break;
        }
        i++;
        token = strtok(NULL, " ");
    }
    return 0;
}

int check_rule(struct rule* r, char* protocol, char* source_ip, int source_port, char* dest_ip, int dest_port) {
    if(strcmp(r->protocol, protocol) == 0 && strcmp(r->source_ip, source_ip) == 0 && r->source_port == source_port && strcmp(r->dest_ip, dest_ip) == 0 && r->dest_port == dest_port) {
        if(strcmp(r->action, "allow") == 0)
            return 1;
        else
            return -1;
    }
    return 0;
}

int main() {
    struct rule rules[MAX_RULES];
    int num_rules = 0;
    char buffer[BUFFER_SIZE];
    char protocol[10], source_ip[16], dest_ip[16], action[10];
    int source_port, dest_port;
    int i, j, num_tokens;
    int allowed = 0;

    printf("Enter the number of rules: ");
    scanf("%d", &num_rules);
    getchar(); // to remove '\n' from the stdin buffer

    for(i=0; i<num_rules; i++) {
        printf("Enter rule %d: ", i+1);
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strlen(buffer)-1] = '\0';
        parse_rule(buffer, &rules[i]);
    }

    printf("Enter the protocol: ");
    scanf("%s", protocol);
    printf("Enter the source IP: ");
    scanf("%s", source_ip);
    printf("Enter the source port: ");
    scanf("%d", &source_port);
    printf("Enter the destination IP: ");
    scanf("%s", dest_ip);
    printf("Enter the destination port: ");
    scanf("%d", &dest_port);

    for(i=0; i<num_rules; i++) {
        allowed = check_rule(&rules[i], protocol, source_ip, source_port, dest_ip, dest_port);
        if(allowed != 0) {
            if(allowed == 1) {
                printf("Allowed. Action: allow\n");
            }
            else {
                printf("Blocked. Action: deny\n");
            }
            exit(0);
        }
    }

    printf("Blocked. Action: deny\n");

    return 0;
}