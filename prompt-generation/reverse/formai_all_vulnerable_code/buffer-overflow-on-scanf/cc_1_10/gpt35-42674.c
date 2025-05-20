//FormAI DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char email[50];
    struct node *next;
};

void addEmailToList(struct node **head, char *email) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->email, email);
    new_node->next = *head;
    *head = new_node;
}

void printEmailList(struct node *head) {
    struct node *current = head;
    printf("\nEmail List:\n");
    while(current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

void deleteEmailFromList(struct node **head, char *email) {
    struct node *prev_node, *current_node;
    prev_node = current_node = *head;

    while(current_node != NULL && strcmp(current_node->email, email) != 0) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if(current_node != NULL) {
        prev_node->next = current_node->next;
        free(current_node);
    }
}

int main() {
    struct node *email_list = NULL;
    int choice, cont = 1;
    char email[50];

    while(cont) {
        printf("\n***********Menu*********\n");
        printf("1. Add Email to List\n");
        printf("2. Delete Email from List\n");
        printf("3. Print Email List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter email to add: ");
                scanf("%s", email);
                addEmailToList(&email_list, email);
                break;
            
            case 2:
                printf("\nEnter email to delete: ");
                scanf("%s", email);
                deleteEmailFromList(&email_list, email);
                break;

            case 3:
                printEmailList(email_list);
                break;

            case 4:
                cont = 0;
                break;

            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}