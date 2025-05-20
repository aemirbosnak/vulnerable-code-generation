//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[50];
    char email[50];
    struct Node *next;
} Node;

Node *head = NULL;
int size = 0;

void add_email(char name[], char email[]) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = head;
    head = new_node;
    size++;
}

void remove_email(char name[]) {
    Node *current = head, *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            size--;
            break;
        }
        previous = current;
        current = current->next;
    }
}

int search_email(char name[]) {
    Node *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s: %s\n", current->name, current->email);
            return 1;
        }
        current = current->next;
    }

    printf("%s not found.\n", name);
    return 0;
}

void print_list() {
    Node *current = head;

    while (current != NULL) {
        printf("%s: %s\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    char name[50], email[50];
    int choice, search_name[50];

    while (1) {
        printf("\n1. Add Email\n2. Remove Email\n3. Search Email\n4. Display List\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Email: ");
                scanf("%s", email);
                add_email(name, email);
                break;

            case 2:
                printf("Enter Name to Remove: ");
                scanf("%s", search_name);
                remove_email(search_name);
                break;

            case 3:
                printf("Enter Name to Search: ");
                scanf("%s", search_name);
                search_email(search_name);
                break;

            case 4:
                print_list();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice.\n");
        }
    }

    return 0;
}