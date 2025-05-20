//FormAI DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

int main() {
    struct Contact phonebook[100];
    int num_contacts = 0;

    int choice;
    do {
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Show All Contacts\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_contacts < 100) {
                    printf("Enter name: ");
                    scanf("%s", phonebook[num_contacts].name);
                    printf("Enter phone number: ");
                    scanf("%s", phonebook[num_contacts].phone);
                    printf("Enter email address: ");
                    scanf("%s", phonebook[num_contacts].email);
                    num_contacts++;
                    printf("Contact added!\n");
                } else {
                    printf("Phonebook is full!\n");
                }
                break;
            case 2:
                if (num_contacts > 0) {
                    char search_name[50];
                    printf("Enter name to search for: ");
                    scanf("%s", search_name);

                    int found = 0;
                    for (int i = 0; i < num_contacts; i++) {
                        if (strcmp(search_name, phonebook[i].name) == 0) {
                            printf("Name: %s\n", phonebook[i].name);
                            printf("Phone: %s\n", phonebook[i].phone);
                            printf("Email: %s\n", phonebook[i].email);
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Contact not found!\n");
                    }
                } else {
                    printf("Phonebook is empty!\n");
                }
                break;
            case 3:
                if (num_contacts > 0) {
                    char edit_name[50];
                    printf("Enter name to edit: ");
                    scanf("%s", edit_name);

                    int found = 0;
                    for (int i = 0; i < num_contacts; i++) {
                        if (strcmp(edit_name, phonebook[i].name) == 0) {
                            printf("Enter new phone number: ");
                            scanf("%s", phonebook[i].phone);
                            printf("Enter new email address: ");
                            scanf("%s", phonebook[i].email);
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Contact not found!\n");
                    } else {
                        printf("Contact updated!\n");
                    }
                } else {
                    printf("Phonebook is empty!\n");
                }
                break;
            case 4:
                if (num_contacts > 0) {
                    char delete_name[50];
                    printf("Enter name to delete: ");
                    scanf("%s", delete_name);

                    int found = 0;
                    for (int i = 0; i < num_contacts; i++) {
                        if (strcmp(delete_name, phonebook[i].name) == 0) {
                            for (int j = i; j < num_contacts - 1; j++) {
                                strcpy(phonebook[j].name, phonebook[j+1].name);
                                strcpy(phonebook[j].phone, phonebook[j+1].phone);
                                strcpy(phonebook[j].email, phonebook[j+1].email);
                            }
                            num_contacts--;
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Contact not found!\n");
                    } else {
                        printf("Contact deleted!\n");
                    }
                } else {
                    printf("Phonebook is empty!\n");
                }
                break;
            case 5:
                if (num_contacts > 0) {
                    printf("All contacts in phonebook:\n");
                    for (int i = 0; i < num_contacts; i++) {
                        printf("Name: %s\n", phonebook[i].name);
                        printf("Phone: %s\n", phonebook[i].phone);
                        printf("Email: %s\n", phonebook[i].email);
                    }
                } else {
                    printf("Phonebook is empty!\n");
                }
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}