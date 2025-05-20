//FormAI DATASET v1.0 Category: Phone Book ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[20];
};

int main() {
    int input;
    struct Contact* phonebook = NULL;
    int size = 0;

    do {
        printf("\n\n-----------Phonebook-----------\n\n");
        printf("1. Add contact\n");
        printf("2. View all contacts\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &input);

        switch (input) {
            case 1: {
                // Add contact
                printf("\nEnter name: ");
                char name[50];
                scanf("%s", name);
                
                printf("Enter phone number: ");
                char phone[20];
                scanf("%s", phone);
                
                struct Contact newContact;
                strcpy(newContact.name, name);
                strcpy(newContact.phone, phone);

                phonebook = (struct Contact*) realloc(phonebook, (size + 1) * sizeof(struct Contact));
                phonebook[size++] = newContact;
                
                printf("\nContact added successfully!");
                break;
            }
            case 2: {
                // View all contacts
                if (size == 0) {
                    printf("\nPhonebook is empty!");
                } else {
                    printf("\nAll contacts:\n\nName\t\t\t\tPhone\n\n");
                    for (int i = 0; i < size; i++) {
                        printf("%s\t\t\t\t%s\n", phonebook[i].name, phonebook[i].phone);
                    }
                }
                break;
            }
            case 3: {
                // Search contact
                if (size == 0) {
                    printf("\nPhonebook is empty!");
                } else {
                    printf("\nEnter name to search: ");
                    char name[50];
                    scanf("%s", name);
                    
                    int found = 0;
                    for (int i = 0; i < size; i++) {
                        if (strcmp(phonebook[i].name, name) == 0) {
                            found = 1;
                            printf("\nSearch result:\n\nName\t\t\t\tPhone\n\n");
                            printf("%s\t\t\t\t%s\n", phonebook[i].name, phonebook[i].phone);
                        }
                    }
                    if (!found) {
                        printf("\nNo contact found with name '%s'", name);
                    }
                }
                break;
            }
            case 4: {
                // Delete contact
                if (size == 0) {
                    printf("\nPhonebook is empty!");
                } else {
                    printf("\nEnter name to delete: ");
                    char name[50];
                    scanf("%s", name);

                    int index = -1;
                    for (int i = 0; i < size; i++) {
                        if (strcmp(phonebook[i].name, name) == 0) {
                            index = i;
                            break;
                        }
                    }
                    if (index == -1) {
                        printf("\nNo contact found with name '%s'", name);
                    } else {
                        for (int i = index; i < size - 1; i++) {
                            phonebook[i] = phonebook[i+1];
                        }
                        size--;
                        phonebook = (struct Contact*) realloc(phonebook, size * sizeof(struct Contact));
                        printf("\nContact deleted successfully!");
                    }
                }
                break;
            }
            case 5: {
                // Exit
                printf("\nGoodbye!");
                break;
            }
            default: {
                printf("\nInvalid input!");
                break;
            }
        }
    } while (input != 5);

    free(phonebook);

    return 0;
}