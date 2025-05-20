//FormAI DATASET v1.0 Category: Mailing list manager ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare struct for contact information
typedef struct Contact {
    char name[50];
    char email[50];
    struct Contact* next;
} Contact;

int main() {
    int choice;
    Contact* head = NULL;
    Contact* current_contact = NULL;

    do {
        printf("\n--- Mailing List Manager ---\n");
        printf("1) Add Contact\n");
        printf("2) View Contacts\n");
        printf("3) Search Contacts\n");
        printf("4) Remove Contact\n");
        printf("5) Exit\n\n");

        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Contact* new_contact = (Contact*) malloc(sizeof(Contact));

                printf("\nEnter Name: ");
                scanf("%s", new_contact->name);

                printf("Enter Email: ");
                scanf("%s", new_contact->email);

                new_contact->next = NULL;

                if (head == NULL) {
                    head = new_contact;
                    current_contact = head;
                } else {
                    current_contact->next = new_contact;
                    current_contact = new_contact;
                }

                printf("\nContact added successfully!\n");
                break;
            }

            case 2: {
                if (head == NULL) {
                    printf("\nList is empty!\n");
                } else {
                    printf("\n--- Contact List ---\n");

                    Contact* current = head;

                    while (current != NULL) {
                        printf("Name: %s\n", current->name);
                        printf("Email: %s\n\n", current->email);

                        current = current->next;
                    }
                }
                break;
            }

            case 3: {
                if (head == NULL) {
                    printf("\nList is empty!\n");
                } else {
                    char search_name[50];
                    printf("\nEnter the name to search: ");
                    scanf("%s", search_name);

                    Contact* current = head;
                    int found = 0;

                    while (current != NULL) {
                        if (strcmp(current->name, search_name) == 0) {
                            printf("Name: %s\n", current->name);
                            printf("Email: %s\n\n", current->email);
                            found = 1;
                        }
                        current = current->next;
                    }

                    if (!found) {
                        printf("\nContact not found!\n");
                    }
                }
                break;
            }

            case 4: {
                if (head == NULL) {
                    printf("\nList is empty!\n");
                } else {
                    char remove_name[50];
                    printf("\nEnter the name to remove: ");
                    scanf("%s", remove_name);

                    Contact* current = head;
                    Contact* previous = NULL;
                    int found = 0;

                    while (current != NULL) {
                        if (strcmp(current->name, remove_name) == 0) {
                            found = 1;

                            if (current == head) {
                                head = current->next;
                                free(current);
                                printf("\nContact removed successfully!\n");
                                break;
                            } else {
                                previous->next = current->next;
                                free(current);
                                printf("\nContact removed successfully!\n");
                                break;
                            }
                        }

                        previous = current;
                        current = current->next;
                    }

                    if (!found) {
                        printf("\nContact not found!\n");
                    }
                }
                break;
            }

            case 5: {
                printf("\nGoodbye!\n");
                break;
            }

            default: {
                printf("\nInvalid choice!\n");
                break;
            }
        }
        
    } while (choice != 5);

    return 0;
}