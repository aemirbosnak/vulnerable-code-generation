//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SUBSCRIBERS 1000

typedef struct Subscriber {
    char name[50];
    char email[100];
    struct Subscriber *next;
} Subscriber;

Subscriber *head = NULL;
Subscriber *current = NULL;
Subscriber *new_subscriber = NULL;

void print_menu() {
    printf("\n------ Mail List Manager ------\n");
    printf("1. Subscribe\n");
    printf("2. Unsubscribe\n");
    printf("3. Display Subscribers\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char name[50];
    char email[100];

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Email: ");
                scanf("%s", email);

                new_subscriber = (Subscriber *)malloc(sizeof(Subscriber));
                strcpy(new_subscriber->name, name);
                strcpy(new_subscriber->email, email);
                new_subscriber->next = NULL;

                if (head == NULL) {
                    head = new_subscriber;
                    current = head;
                } else {
                    current->next = new_subscriber;
                    current = new_subscriber;
                }
                break;

            case 2:
                printf("Enter Name to Unsubscribe: ");
                scanf("%s", name);

                if (head == NULL) {
                    printf("No subscribers found.\n");
                } else {
                    current = head;
                    Subscriber *prev = NULL;

                    while (current != NULL && strcmp(current->name, name) != 0) {
                        prev = current;
                        current = current->next;
                    }

                    if (current == NULL) {
                        printf("Subscriber not found.\n");
                    } else {
                        if (prev == NULL) {
                            head = current->next;
                        } else {
                            prev->next = current->next;
                        }
                        free(current);
                    }
                }
                break;

            case 3:
                if (head == NULL) {
                    printf("No subscribers found.\n");
                } else {
                    current = head;
                    printf("\nSubscribers:\n");
                    while (current != NULL) {
                        printf("%s (%s)\n", current->name, current->email);
                        current = current->next;
                    }
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}