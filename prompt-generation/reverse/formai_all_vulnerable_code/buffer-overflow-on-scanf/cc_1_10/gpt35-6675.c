//FormAI DATASET v1.0 Category: Password management ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char website[20];
    char username[20];
    char password[20];
    struct node* next;
};

void saveToFile(struct node* head) {
    FILE* fp = fopen("passwords.txt", "w");
    struct node* current = head;
    while(current != NULL) {
        fprintf(fp, "%s:%s:%s\n", current -> website, current -> username, current -> password);
        current = current -> next;
    }
    fclose(fp);
}

struct node* readFromFile() {
    struct node* head = NULL;
    FILE* fp;
    char website[20], username[20], password[20], line[60];
    fp = fopen("passwords.txt", "r");
    if(fp == NULL) {
        printf("Passwords file not found.\n");
        return head;
    }
    while(fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%[^:]:%[^:]:%s\n", website, username, password);
        struct node* current = malloc(sizeof(struct node));
        current -> next = head;
        strcpy(current -> website, website);
        strcpy(current -> username, username);
        strcpy(current -> password, password);
        head = current;
    }
    fclose(fp);
    return head;
}

void printNode(struct node* current) {
    printf("\nWebsite: %s\n", current -> website);
    printf("Username: %s\n", current -> username);
    printf("Password: %s\n", current -> password);
}

void deleteNode(struct node** head, struct node* toDelete) {
    if(*head == toDelete) {
        *head = toDelete -> next;
        free(toDelete);
        return;
    }
    struct node* current = *head;
    while(current -> next != NULL && current -> next != toDelete) {
        current = current -> next;
    }
    if(current -> next != NULL) {
        current -> next = toDelete -> next;
        free(toDelete);
        return;
    }
    printf("Couldn't find the node to delete.\n");
}

void deleteAll(struct node** head) {
    struct node* current = *head;
    while(current != NULL) {
        struct node* toDelete = current;
        current = current -> next;
        free(toDelete);
    }
    *head = NULL;
}

void printList(struct node* head) {
    struct node* current = head;
    while(current != NULL) {
        printNode(current);
        current = current -> next;
    }
}

void addNode(struct node** head, char website[], char username[], char password[]) {
    struct node* current = malloc(sizeof(struct node));
    strcpy(current -> website, website);
    strcpy(current -> username, username);
    strcpy(current -> password, password);
    current -> next = *head;
    *head = current;
}

int main() {
    struct node* head = readFromFile();
    int choice;
    do {
        printf("\n1. Add new password\n");
        printf("2. Show all passwords\n");
        printf("3. Quit\n");
        scanf("%d", &choice);
        if(choice == 1) {
            char website[20], username[20], password[20];
            printf("Enter website name: ");
            scanf("%s", website);
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            addNode(&head, website, username, password);
            saveToFile(head);
            printf("Password added successfully.\n");
        } else if(choice == 2) {
            if(head == NULL) {
                printf("No passwords added yet.\n");
            } else {
                printList(head);
            }
        }
    } while(choice != 3);
    deleteAll(&head);
    return 0;
}