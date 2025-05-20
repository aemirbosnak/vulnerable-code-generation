//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

void print_menu() {
    printf("Mailing List Manager\n");
    printf("1. Add contact\n");
    printf("2. Remove contact\n");
    printf("3. Send email to all contacts\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char input[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2]; // +2 for space and null terminator
    Contact contacts[100]; // Maximum of 100 contacts
    int num_contacts = 0;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", input);
                strcpy(contacts[num_contacts].name, input);

                printf("Enter email: ");
                scanf("%s", input);
                strcpy(contacts[num_contacts].email, input);

                num_contacts++;
                break;

            case 2:
                printf("Enter name of contact to remove: ");
                scanf("%s", input);

                for (int i = 0; i < num_contacts; i++) {
                    if (strcmp(contacts[i].name, input) == 0) {
                        for (int j = i; j < num_contacts - 1; j++) {
                            strcpy(contacts[j].name, contacts[j + 1].name);
                            strcpy(contacts[j].email, contacts[j + 1].email);
                        }
                        num_contacts--;
                        break;
                    }
                }

                break;

            case 3:
                printf("Enter subject: ");
                scanf("%s", input);

                printf("Enter body: ");
                scanf("%s", input);

                for (int i = 0; i < num_contacts; i++) {
                    sprintf(input, "To: %s\nSubject: %s\n\n%s", contacts[i].email, input, input);
                    system(input);
                }

                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}