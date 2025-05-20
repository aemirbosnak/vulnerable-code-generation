//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct mail_node {
    char name[50];
    struct mail_node *next;
} mail_node;

mail_node *head = NULL;

void add_to_list(char *name) {
    mail_node *new_node = (mail_node *)malloc(sizeof(mail_node));
    strcpy(new_node->name, name);
    new_node->next = head;
    head = new_node;
}

mail_node *search_list(char *name) {
    mail_node *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void remove_from_list(char *name) {
    mail_node *current = head, *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void print_list() {
    mail_node *current = head;
    printf("Mailing List:\n");
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    char command[20], name[50];
    int choice;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Name\n");
        printf("2. Remove Name\n");
        printf("3. Search Name\n");
        printf("4. Display List\n");
        printf("5. Quit\n");
        scanf("%s", command);

        choice = atoi(strtok(command, " "));
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                add_to_list(name);
                break;
            case 2:
                printf("Enter Name: ");
                scanf("%s", name);
                remove_from_list(name);
                break;
            case 3:
                printf("Enter Name: ");
                scanf("%s", name);
                if (search_list(name) != NULL) {
                    printf("Name found!\n");
                } else {
                    printf("Name not found.\n");
                }
                break;
            case 4:
                print_list();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Command.\n");
                break;
        }
    }

    return 0;
}