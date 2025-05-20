//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 50 // Maximum length of logs

typedef struct node{
    char log[MAX_LENGTH]; // Log entry
    struct node *left; // Pointer to left child
    struct node *right; // Pointer to right child
}Node;

void insert(Node **node, char *log){ // Insert logs into binary tree
    if((*node) == NULL){
        (*node) = (Node*)malloc(sizeof(Node));
        strcpy((*node)->log, log);
        (*node)->left = (*node)->right = NULL;
        return;
    }
    if(strcmp(log, (*node)->log) < 0){
        insert(&((*node)->left), log);
    }else{
        insert(&((*node)->right), log);
    }
}

int search(Node *node, char *log){ // Search for logs in binary tree
    if(node == NULL){
        return 0;
    }
    if(strcmp(log, node->log) == 0){
        return 1;
    }
    if(strcmp(log, node->log) < 0){
        return search(node->left, log);
    }else{
        return search(node->right, log);
    }
}

int main(){
    Node *root = NULL;
    char logs[3][MAX_LENGTH] = {"Unauthorized access to admin account", "Port scan detected from IP address 192.168.0.2", "ARP spoofing attack detected from MAC address 00:11:22:33:44:55"};
    char log[MAX_LENGTH];
    int choice, flag;
    while(1){ // Main menu
        printf("\nIntrusion Detection System");
        printf("\n1. Insert Log");
        printf("\n2. Search Log");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: // Insert logs
                printf("\nEnter log: ");
                fflush(stdin);
                fgets(log, MAX_LENGTH, stdin);
                log[strcspn(log, "\n")] = '\0'; // Remove newline character
                insert(&root, log);
                printf("\nLog added successfully!");
                break;
            case 2: // Search logs
                printf("\nEnter log to search: ");
                fflush(stdin);
                fgets(log, MAX_LENGTH, stdin);
                log[strcspn(log, "\n")] = '\0'; // Remove newline character
                flag = search(root, log); 
                if(flag){
                    printf("\nLog found!");
                }else{
                    printf("\nLog not found.");
                }
                break;
            case 3: // Exit program
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }
    return 0;
}