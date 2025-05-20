//FormAI DATASET v1.0 Category: Firewall ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Shape Shifting C Firewall Example Program */

void print_menu();
void print_rules(char** rules, int count);
void add_rule(char** rules, int* count);
void remove_rule(char** rules, int* count);
void modify_rule(char** rules, int count);
int check_packet(char* packet, char** rules, int count);

int main()
{
    char** rules = (char**)malloc(sizeof(char*) * 10);
    int count = 0;
    char packet[100];

    printf("--- Shape Shifting Firewall ---\n");

    while(1)
    {
        print_menu();
        int choice;
        scanf("%d", &choice);
        getchar(); // flush newline character

        switch(choice)
        {
            case 1:
                print_rules(rules, count);
                break;
            case 2:
                add_rule(rules, &count);
                break;
            case 3:
                remove_rule(rules, &count);
                break;
            case 4:
                modify_rule(rules, count);
                break;
            case 5:
                printf("Enter packet to check: ");
                fgets(packet, sizeof(packet), stdin);
                packet[strcspn(packet, "\n")] = 0; // remove newline character

                if(check_packet(packet, rules, count))
                    printf("Packet allowed.\n");
                else
                    printf("Packet blocked.\n");
                break;
            case 6:
                printf("Exiting Shape Shifting Firewall...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

void print_menu()
{
    printf("\n1. View Rules\n");
    printf("2. Add Rule\n");
    printf("3. Remove Rule\n");
    printf("4. Modify Rule\n");
    printf("5. Check Packet\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void print_rules(char** rules, int count)
{
    printf("\n--- Firewall Rules ---\n");
    for(int i=0; i<count; i++)
        printf("%d. %s\n", i+1, rules[i]);
}

void add_rule(char** rules, int* count)
{
    if(*count == 10)
    {
        printf("Max limit reached. Cannot add more rules.\n");
        return;
    }

    char rule[50];
    printf("Enter rule: ");
    fgets(rule, sizeof(rule), stdin);
    rule[strcspn(rule, "\n")] = 0; // remove newline character

    rules[*count] = (char*)malloc(sizeof(char) * strlen(rule) + 1);
    strcpy(rules[*count], rule);
    (*count)++;

    printf("Rule added successfully.\n");
}

void remove_rule(char** rules, int* count)
{
    if(*count == 0)
    {
        printf("No rules to remove.\n");
        return;
    }

    int index;
    printf("Enter rule number to remove: ");
    scanf("%d", &index);

    if(index <= 0 || index > *count)
    {
        printf("Invalid rule number.\n");
        return;
    }

    free(rules[index-1]);

    for(int i=index-1; i<*count-1; i++)
        rules[i] = rules[i+1];

    (*count)--;
    printf("Rule removed successfully.\n");
}

void modify_rule(char** rules, int count)
{
    if(count == 0)
    {
        printf("No rules to modify.\n");
        return;
    }

    int index;
    printf("Enter rule number to modify: ");
    scanf("%d", &index);
    getchar(); // flush newline character

    if(index <= 0 || index > count)
    {
        printf("Invalid rule number.\n");
        return;
    }

    char modified_rule[50];
    printf("Enter modified rule: ");
    fgets(modified_rule, sizeof(modified_rule), stdin);
    modified_rule[strcspn(modified_rule, "\n")] = 0; // remove newline character

    free(rules[index-1]);
    rules[index-1] = (char*)malloc(sizeof(char) * strlen(modified_rule) + 1);
    strcpy(rules[index-1], modified_rule);

    printf("Rule modified successfully.\n");
}

int check_packet(char* packet, char** rules, int count)
{
    for(int i=0; i<count; i++)
    {
        if(strstr(packet, rules[i]) != NULL) // rule found in packet
            return 1;
    }

    return 0; // no rule found in packet
}