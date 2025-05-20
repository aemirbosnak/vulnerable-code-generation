//FormAI DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 50
#define MAX_NAME_LEN 20
#define MAX_PHONE_LEN 15

typedef struct Contact {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} contact_t;

int main() {
    contact_t contacts[MAX_CONTACTS];
    int count = 0;

    // Load existing contacts from file
    FILE *fp = fopen("contacts.txt", "r");
    if (fp != NULL) {
        char line[100];
        while (fgets(line, sizeof(line), fp) != NULL) {
            // Strip newline character
            line[strcspn(line, "\n")] = 0;

            // Parse name and phone number
            char *name = strtok(line, ",");
            char *phone = strtok(NULL, ",");

            // Add contact to array
            strcpy(contacts[count].name, name);
            strcpy(contacts[count].phone, phone);
            count++;
        }
        fclose(fp);
    }

    // Main loop
    while (1) {
        printf("1. Add Contact\n");
        printf("2. Search For Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < MAX_CONTACTS) {
                    printf("Enter name: ");
                    scanf("%s", contacts[count].name);
                    printf("Enter phone number: ");
                    scanf("%s", contacts[count].phone);
                    count++;

                    // Save contact to file
                    fp = fopen("contacts.txt", "a");
                    fprintf(fp, "%s,%s\n", contacts[count-1].name, contacts[count-1].phone);
                    fclose(fp);

                    printf("Contact added successfully.\n");
                } else {
                    printf("Phone book is full.\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("Phone book is empty.\n");
                } else {
                    char searchName[MAX_NAME_LEN];
                    printf("Enter name to search: ");
                    scanf("%s", searchName);
                    int found = 0;
                    for (int i = 0; i < count; i++) {
                        if (strcmp(contacts[i].name, searchName) == 0) {
                            printf("%s: %s\n", contacts[i].name, contacts[i].phone);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Contact not found.\n");
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    printf("Phone book is empty.\n");
                } else {
                    printf("Contacts:\n");
                    for (int i = 0; i < count; i++) {
                        printf("%s: %s\n", contacts[i].name, contacts[i].phone);
                    }
                }
                break;

            case 4:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}