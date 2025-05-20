//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

int main() {
    int choice;
    FILE *file;
    Contact contacts[100];
    int num_contacts = 0;

    do {
        printf("Mailing List Manager\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. View contacts\n");
        printf("4. Save contacts to file\n");
        printf("5. Load contacts from file\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", contacts[num_contacts].name);
            printf("Enter email: ");
            scanf("%s", contacts[num_contacts].email);
            num_contacts++;
            break;
        case 2:
            printf("Enter name to remove: ");
            scanf("%s", contacts[num_contacts - 1].name);
            num_contacts--;
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
                printf("Error: could not open file.\n");
            } else {
                for (int i = 0; i < num_contacts; i++) {
                    fprintf(file, "%s\t%s\n", contacts[i].name, contacts[i].email);
                }
                fclose(file);
                printf("Contacts saved to file.\n");
            }
            break;
        case 5:
            file = fopen("contacts.txt", "r");
            if (file == NULL) {
                printf("Error: could not open file.\n");
            } else {
                while (fscanf(file, "%s\t%s", contacts[num_contacts].name, contacts[num_contacts].email)!= EOF) {
                    num_contacts++;
                }
                fclose(file);
                printf("Contacts loaded from file.\n");
            }
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 6);

    return 0;
}