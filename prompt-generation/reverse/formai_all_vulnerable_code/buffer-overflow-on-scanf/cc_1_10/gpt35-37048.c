//FormAI DATASET v1.0 Category: Firewall ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct firewall{
   char ip[50];
   int port;
   char rule[10];
};

int main(){
    printf("Firewall Configuration Tool\n");

    int num_rules;
    printf("How many rules do you want to configure? ");
    scanf("%d",&num_rules);

    struct firewall rules[num_rules];
    int i;
    for(i=0;i<num_rules;i++){
        printf("\nEnter Rule %d Details:\n",i+1);
        printf("IP: ");
        scanf("%s",&rules[i].ip);
        printf("Port: ");
        scanf("%d",&rules[i].port);
        printf("Rule: ");
        scanf("%s",&rules[i].rule);
    }

    printf("\nConfigured Rules:\n");

    for(i=0;i<num_rules;i++){
        printf("Rule %d: IP=%s Port=%d Rule=%s\n",i+1,rules[i].ip,rules[i].port,rules[i].rule);
    }

    printf("\nEnter IP and Port to check if it matches any of the configured rules:\n");

    char check_ip[50];
    int check_port;
    printf("IP: ");
    scanf("%s",&check_ip);
    printf("Port: ");
    scanf("%d",&check_port);

    for(i=0;i<num_rules;i++){
        if(strcmp(rules[i].ip,check_ip)==0 && rules[i].port==check_port){
            printf("\nMatch Found. Rule=%s\n",rules[i].rule);
            exit(0);
        }
    }

    printf("\nNo Match Found.\n");
    return 0;
}