//Falcon-180B DATASET v1.0 Category: Firewall ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct rule{
    char service[10];
    char action[6];
    int port;
};

void add_rule(struct rule rules[], int num_rules){
    char service[11], action[7];
    int port;
    printf("\nEnter the service name (http/ftp/telnet): ");
    scanf("%s", service);
    printf("Enter the action (allow/deny): ");
    scanf("%s", action);
    printf("Enter the port number: ");
    scanf("%d", &port);

    strcpy(rules[num_rules].service, service);
    strcpy(rules[num_rules].action, action);
    rules[num_rules].port = port;

    printf("\nRule added successfully!\n");
    num_rules++;
}

void display_rules(struct rule rules[], int num_rules){
    printf("\nThe current rules are:\n");
    for(int i=0; i<num_rules; i++){
        printf("%s %s port %d\n", rules[i].service, rules[i].action, rules[i].port);
    }
}

int main(){
    struct rule rules[MAX];
    int num_rules = 0;

    while(1){
        printf("\n1. Add rule\n2. Display rules\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(num_rules == MAX){
                    printf("\nMaximum number of rules reached!\n");
                }
                else{
                    add_rule(rules, num_rules);
                }
                break;

            case 2:
                display_rules(rules, num_rules);
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}