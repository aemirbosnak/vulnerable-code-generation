//FormAI DATASET v1.0 Category: Firewall ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *rule;
    struct Node* next;
} Node;

void addRule(Node **head, char *rule) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->rule = (char*) malloc(strlen(rule) + 1);
    strcpy(newNode->rule, rule);
    newNode->next = *head;
    *head = newNode;
}

void printRules(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->rule);
        temp = temp->next;
    }
}

int main() {
    Node *rules = NULL;
    char rule[1024];

    printf("Welcome to the Shape-Shifting Firewall Configuration Tool!\n\n");

    while (1) {
        printf("Please enter a rule (or 'done' to finish):\n");
        scanf("%s", rule);

        if (strcmp(rule, "done") == 0) {
            printf("\nHere are your rules:\n");
            printRules(rules);
            printf("\nThank you for using the Shape-Shifting Firewall Configuration Tool!\n");
            exit(0);
        }

        addRule(&rules, rule);

        printf("\nYour rules so far:\n");
        printRules(rules);
        printf("\n");
    }

    return 0;
}