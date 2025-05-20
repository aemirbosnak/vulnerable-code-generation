//FormAI DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

int main() {
    FILE *file;
    Contact contacts[10];
    int numContacts = 0;
    int option;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add contact\n");
        printf("2. View contacts\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                if (numContacts >= 10) {
                    printf("Maximum contacts reached.\n");
                    break;
                }
                Contact newContact;
                printf("Enter name: ");
                scanf("%s", newContact.name);
                printf("Enter email: ");
                scanf("%s", newContact.email);

                file = fopen("contacts.txt", "a");
                if (file == NULL) {
                    printf("Error in opening file\n");
                    return -1;
                }

                fprintf(file, "%s,%s\n", newContact.name, newContact.email);
                fclose(file);

                contacts[numContacts++] = newContact;
                printf("Contact added successfully.\n");
                break;
            }
            case 2: {
                file = fopen("contacts.txt", "r");
                if (file == NULL) {
                    printf("Error in opening file\n");
                    return -1;
                }

                int i = 0;
                char name[MAX_NAME_LENGTH];
                char email[MAX_EMAIL_LENGTH];
                printf("\nContacts:\n");
                printf("---------------\n");
                printf("No.   Name     Email\n");
                printf("---------------\n");
                while ((fscanf(file, "%[^,],%s\n", name, email) == 2)) {
                    printf("%-5d %-9s%s\n", ++i, name, email);
                }

                fclose(file);
                break;
            }
            case 3:
                printf("Program exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }
}