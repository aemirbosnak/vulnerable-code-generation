//FormAI DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_LIST_LENGTH 10
#define MAX_FILENAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

int main() {
    contact mailingList[MAX_LIST_LENGTH];
    int numContacts = 0;
    char filename[MAX_FILENAME_LENGTH];

    while (1) {
        printf("Enter an option:\n");
        printf("1. Add a contact\n");
        printf("2. Remove a contact\n");
        printf("3. View all contacts\n");
        printf("4. Save contacts to file\n");
        printf("5. Load contacts from file\n");
        printf("6. Exit program\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1: {
                if (numContacts >= MAX_LIST_LENGTH) {
                    printf("Cannot add more contacts, list is full.\n");
                    break;
                }

                printf("Enter name: ");
                char newName[MAX_NAME_LENGTH];
                scanf("%s", newName);

                printf("Enter email: ");
                char newEmail[MAX_EMAIL_LENGTH];
                scanf("%s", newEmail);

                contact newContact;
                strncpy(newContact.name, newName, MAX_NAME_LENGTH);
                strncpy(newContact.email, newEmail, MAX_EMAIL_LENGTH);
                mailingList[numContacts++] = newContact;

                printf("Contact added successfully.\n");
                break;
            }

            case 2: {
                printf("Enter name of contact to remove: ");
                char removeName[MAX_NAME_LENGTH];
                scanf("%s", removeName);

                int removeIndex = -1;

                for (int i = 0; i < numContacts; i++) {
                    if (strcmp(mailingList[i].name, removeName) == 0) {
                        removeIndex = i;
                        break;
                    }
                }

                if (removeIndex == -1) {
                    printf("Contact not found.\n");
                } else {
                    for (int i = removeIndex; i < numContacts - 1; i++) {
                        mailingList[i] = mailingList[i+1];
                    }

                    numContacts--;
                    printf("Contact removed successfully.\n");
                }

                break;
            }

            case 3: {
                printf("--- Mailing List ---\n");

                for (int i = 0; i < numContacts; i++) {
                    printf("Name: %s\n", mailingList[i].name);
                    printf("Email: %s\n", mailingList[i].email);
                }

                printf("--------------------\n");

                break;
            }

            case 4: {
                printf("Enter filename to save contacts: ");
                scanf("%s", filename);

                FILE* file = fopen(filename, "w");

                if (file == NULL) {
                    printf("Failed to open file for writing.\n");
                } else {
                    for (int i = 0; i < numContacts; i++) {
                        fprintf(file, "%s,%s\n", mailingList[i].name, mailingList[i].email);
                    }

                    fclose(file);
                    printf("Contacts saved to file successfully.\n");
                }

                break;
            }

            case 5: {
                printf("Enter filename to load contacts: ");
                scanf("%s", filename);

                FILE* file = fopen(filename, "r");

                if (file == NULL) {
                    printf("Failed to open file for reading.\n");
                } else {
                    int count = 0;

                    while (!feof(file)) {
                        char line[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH];
                        fgets(line, MAX_NAME_LENGTH + MAX_EMAIL_LENGTH, file);

                        if (strlen(line) <= 1) {
                            break;
                        }

                        char* name = strtok(line, ",");
                        char* email = strtok(NULL, ",");

                        if (name == NULL || email == NULL) {
                            printf("Failed to parse line %d in file.\n", count + 1);
                        } else {
                            contact newContact;
                            strncpy(newContact.name, name, MAX_NAME_LENGTH);
                            strncpy(newContact.email, email, MAX_EMAIL_LENGTH);
                            mailingList[numContacts++] = newContact;
                            count++;
                        }
                    }

                    fclose(file);
                    printf("Contacts loaded from file successfully.\n");
                }

                break;
            }

            case 6: {
                printf("Exiting program...\n");
                return 0;
            }

            default: {
                printf("Invalid option selected.\n");
                break;
            }
        }
    }
}