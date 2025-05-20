//FormAI DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_EMAILS 100

int main() {
    char emails[MAX_EMAILS][MAX_EMAIL_LENGTH];
    char new_email[MAX_EMAIL_LENGTH];
    int count = 0;
    char option;

    printf("Welcome to The Mailing List Manager\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add email address\n");
        printf("2. Display mailing list\n");
        printf("3. Remove email address\n");
        printf("4. Quit\n");

        scanf(" %c", &option);

        switch(option) {
            case '1':
                printf("\nEnter email address: ");
                scanf("%s", new_email);

                for (int i = 0; i < count; i++) {
                    if (strcmp(emails[i], new_email) == 0) {
                        printf("Email address already exists in mailing list.\n");
                        break;
                    }
                }

                strcpy(emails[count], new_email);
                count++;
                printf("Email address has been added to mailing list.\n");
                break;
            case '2':
                if (count == 0) {
                    printf("\nMailing list is currently empty.\n");
                } else {
                    printf("\nEmail Addresses:\n");
                    for (int i = 0; i < count; i++) {
                        printf("%d. %s\n", i+1, emails[i]);
                    }
                }
                break;
            case '3':
                printf("\nEnter email address to remove: ");
                scanf("%s", new_email);
                int removed = 0;

                for (int i = 0; i < count; i++) {
                    if (strcmp(emails[i], new_email) == 0) {
                        strcpy(emails[i], emails[count-1]);
                        count--;
                        removed = 1;
                        printf("Email address has been removed from mailing list.\n");
                        break;
                    }
                }

                if (!removed) {
                    printf("Email address was not found in mailing list.\n");
                }
                break;
            case '4':
                printf("\nExiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid option selected.\n");
                break;
        }
    }

    return 0;
}