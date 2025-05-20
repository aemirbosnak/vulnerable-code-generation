//FormAI DATASET v1.0 Category: Phone Book ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone_number[20];
    int id;
};

int main() {
    int num_contacts = 0;
    struct contact *contacts = malloc(num_contacts * sizeof(struct contact));

    printf("Welcome to the Irregular Phone Book!\n");

    while (1) {
        printf("-----------------------------------\n");
        printf("1. Add a Contact\n");
        printf("2. Search Contacts\n");
        printf("3. Delete a Contact\n");
        printf("4. View All Contacts\n");
        printf("5. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                printf("\nEnter name: ");
                char name[50];
                fgets(name, 50, stdin);
                strncpy(contacts[num_contacts].name, name, strlen(name)-1);

                printf("Enter phone number: ");
                char phone_number[20];
                fgets(phone_number, 20, stdin);
                strncpy(contacts[num_contacts].phone_number, phone_number, strlen(phone_number)-1);

                contacts[num_contacts].id = num_contacts+1;
                num_contacts++;

                printf("\n%s added successfully!\n", name);
                break;
            }
            case 2: {
                printf("\nEnter name to search: ");
                char search_name[50];
                fgets(search_name, 50, stdin);

                int found = 0;
                for (int i = 0; i < num_contacts; i++) {
                    if (strcasecmp(search_name, contacts[i].name) == 0) {
                        printf("\n%s (%s): %d\n", contacts[i].name, contacts[i].phone_number, contacts[i].id);
                        found = 1;
                    }
                }

                if (!found) {
                    printf("\nNo contacts found with name %s\n", search_name);
                }
                break;
            }
            case 3: {
                printf("\nEnter ID of the contact to delete: ");
                int delete_id;
                scanf("%d", &delete_id);
                getchar();

                int deleted = 0;
                for (int i = 0; i < num_contacts; i++) {
                    if (contacts[i].id == delete_id) {
                        printf("\n%s (%s) deleted successfully!\n", contacts[i].name, contacts[i].phone_number);

                        for (int j = i; j < num_contacts - 1; j++) {
                            contacts[j] = contacts[j+1];
                        }
                        num_contacts--;
                        deleted = 1;
                        break;
                    }
                }

                if (!deleted) {
                    printf("\nNo contacts found with ID %d\n", delete_id);
                }
                break;
            }
            case 4: {
                printf("\n--- All Contacts ---\n");
                for (int i = 0; i < num_contacts; i++) {
                    printf("%s (%s): %d\n", contacts[i].name, contacts[i].phone_number, contacts[i].id);
                }
                break;
            }
            case 5: {
                printf("\nGoodbye!\n");
                free(contacts);
                return 0;
            }
            default: {
                printf("\nInvalid choice, try again.\n");
                break;
            }
        }
    }
}