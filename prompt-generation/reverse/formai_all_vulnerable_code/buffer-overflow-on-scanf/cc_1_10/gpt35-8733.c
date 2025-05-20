//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct node_t {
    char data[BUFFER_SIZE];
    struct node_t* next;
} node_t;

node_t* head = NULL;

void add_email(char* email) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    strncpy(new_node->data, email, BUFFER_SIZE);
    new_node->next = head;
    head = new_node;
}

void remove_email(char* email) {
    if (head == NULL) {
        return;
    }
    if (strcmp(head->data, email) == 0) {
        node_t* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    node_t* temp = head;
    while (temp->next != NULL && strcmp(temp->next->data, email) != 0) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        return;
    }
    node_t* delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
}

void print_list() {
    node_t* current = head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    int choice;
    do {
        printf("Enter 1 to add email to list\n");
        printf("Enter 2 to remove email from list\n");
        printf("Enter 3 to print list\n");
        printf("Enter 4 to exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter email: ");
                scanf("%s", buffer);
                add_email(buffer);
                printf("Email added to list\n");
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", buffer);
                remove_email(buffer);
                printf("Email removed from list\n");
                break;
            case 3:
                printf("Email list:\n");
                print_list();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);
    return 0;
}