//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

int main() {
    int choice;
    contact contacts[100];
    int num_contacts = 0;
    FILE *file;

    file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fscanf(file, "%s %s\n", contacts[num_contacts].name, contacts[num_contacts].email)!= EOF) {
        num_contacts++;
    }

    fclose(file);

    while (1) {
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Print contacts\n");
        printf("4. Save to file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter email: ");
                scanf("%s", contacts[num_contacts].email);
                num_contacts++;
                printf("Contact added successfully\n");
                break;

            case 2:
                printf("Enter name of contact to remove: ");
                scanf("%s", contacts[num_contacts - 1].name);
                for (int i = 0; i < num_contacts - 1; i++) {
                    strcpy(contacts[i].name, contacts[i + 1].name);
                    strcpy(contacts[i].email, contacts[i + 1].email);
                }
                num_contacts--;
                printf("Contact removed successfully\n");
                break;

            case 3:
                printf("Name\tEmail\n");
                for (int i = 0; i < num_contacts; i++) {
                    printf("%s\t%s\n", contacts[i].name, contacts[i].email);
                }
                break;

            case 4:
                file = fopen("contacts.txt", "w");
                if (file == NULL) {
                    printf("Error opening file\n");
                    exit(1);
                }

                for (int i = 0; i < num_contacts; i++) {
                    fprintf(file, "%s %s\n", contacts[i].name, contacts[i].email);
                }

                fclose(file);
                printf("Contacts saved to file successfully\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}