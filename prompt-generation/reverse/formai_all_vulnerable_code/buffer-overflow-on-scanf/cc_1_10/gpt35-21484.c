//FormAI DATASET v1.0 Category: Mailing list manager ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char email[50];
    struct node *next;
}Node;

Node *head = NULL;
Node *tail = NULL;

void addEmail(char *email){
    Node *newEmail = (Node*)malloc(sizeof(Node));
    if(newEmail == NULL){
        printf("Error: Memory allocation failed.");
        exit(1);
    }
    strcpy(newEmail->email, email);
    newEmail->next = NULL;
    if(head == NULL){
        head = newEmail;
        tail = newEmail;
    }
    else{
        tail->next = newEmail;
        tail = newEmail;
    }
}

void removeEmail(char *email){
    Node *prev = NULL, *curr = head;
    while(curr != NULL){
        if(strcmp(curr->email, email) == 0){
            if(curr == head){
                head = curr->next;
            }
            else if(curr == tail){
                tail = prev;
                tail->next = NULL;
            }
            else{
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void displayList(){
    Node *ptr = head;
    printf("Mailing List:\n");
    while(ptr != NULL){
        printf("%s\n", ptr->email);
        ptr = ptr->next;
    }
}

int main(){
    char email[50];
    int choice;
    while(1){
        printf("\nMailing List Manager\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Email: ");
                scanf("%s", email);
                addEmail(email);
                printf("Email added to mailing list.\n");
                break;
            case 2:
                printf("Enter Email: ");
                scanf("%s", email);
                removeEmail(email);
                printf("Email removed from mailing list.\n");
                break;
            case 3:
                displayList();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.");
                break;
        }
    }
    return 0;
}