//FormAI DATASET v1.0 Category: Mailing list manager ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subscriber {
    char name[100];
    char email[100];
    struct subscriber *next;
};

typedef struct subscriber Subscriber;

int main() {
    Subscriber *head = NULL;
    char choice;
    do {
        printf("Enter your choice: \n1. Add subscriber\n2. Display list\n3. Delete subscriber\n4. Exit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1': {
                Subscriber *new_subscriber = malloc(sizeof(Subscriber));
                printf("Enter name: ");
                scanf("%s", new_subscriber->name);
                printf("Enter email: ");
                scanf("%s", new_subscriber->email);
                new_subscriber->next = head;
                head = new_subscriber;
                printf("Subscriber added successfully!\n");
                break;
            }
            case '2': {
                if (head == NULL) {
                    printf("Mailing list is empty\n");
                } else {
                    printf("Mailing list:\n");
                    Subscriber *current = head;
                    while (current != NULL) {
                        printf("%s <%s>\n", current->name, current->email);
                        current = current->next;
                    }
                }
                break;
            }
            case '3': {
                if (head == NULL) {
                    printf("Mailing list is empty\n");
                } else {
                    char email[100];
                    printf("Enter email of subscriber to delete: ");
                    scanf("%s", email);
                    Subscriber *current = head;
                    Subscriber *previous = NULL;
                    while (current != NULL && strcmp(current->email, email) != 0) {
                        previous = current;
                        current = current->next;
                    }
                    if (current == NULL) {
                        printf("Subscriber not found\n");
                    } else if (previous == NULL) {
                        head = current->next;
                        free(current);
                        printf("Subscriber deleted successfully!\n");
                    } else {
                        previous->next = current->next;
                        free(current);
                        printf("Subscriber deleted successfully!\n");
                    }
                }
                break;
            }
            case '4': {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice, try again\n");
                break;
            }
        }
    } while (choice != '4');
    return 0;
}