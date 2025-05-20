//FormAI DATASET v1.0 Category: Password management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 50
#define MAX_WEBSITE_LENGTH 100
#define MAX_USERS 100

int main() {
    int choice, num_users = 0;
    char passwords[MAX_USERS][MAX_PASSWORD_LENGTH], websites[MAX_USERS][MAX_WEBSITE_LENGTH];
    char username[MAX_PASSWORD_LENGTH];

    do {
        printf("\n1. Store Password\n2. Retrieve Password\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                if(num_users == MAX_USERS) {
                    printf("Maximum number of users exceeded. Cannot store any more passwords.\n");
                    break;
                }

                printf("Enter website: ");
                scanf("%s", websites[num_users]);

                printf("Enter username: ");
                scanf("%s", username);

                printf("Enter password: ");
                scanf("%s", passwords[num_users]);

                printf("Password stored successfully!\n");
                num_users++;
                break;
            }

            case 2: {
                printf("Enter website: ");
                scanf("%s", username);

                int found = 0;
                for(int i = 0; i < num_users; i++) {
                    if(strcmp(websites[i], username) == 0) {
                        printf("Username: %s\nPassword: %s\n", username, passwords[i]);
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("No passwords found for this website.\n");
                }

                break;
            }

            case 3: {
                printf("Exiting...\n");
                break;
            }

            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    } while(choice != 3);

    return 0;
}