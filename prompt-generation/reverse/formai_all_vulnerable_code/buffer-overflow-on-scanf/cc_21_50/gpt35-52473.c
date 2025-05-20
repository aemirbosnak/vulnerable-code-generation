//FormAI DATASET v1.0 Category: Password management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 10
#define MAX_USERNAME_LENGTH 15
#define MAX_ENTRIES 10

struct passwords {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct passwords password_book[MAX_ENTRIES];

int main() {
    int user_choice = 0;
    int num_entries = 0;
    char username_input[MAX_USERNAME_LENGTH];
    char password_input[MAX_PASSWORD_LENGTH];

    printf("Welcome to our Password Manager!\n");
    printf("We will help you keep track of your login credentials securely.\n");
    printf("----------------------------------------------------------------------------\n\n");

    while(1) {
        printf("Please select an option: \n");
        printf("1. Add New Password\n");
        printf("2. View Password Book\n");
        printf("3. Search for an Entry\n");
        printf("4. Delete an Entry\n");
        printf("5. Exit Password Manager\n");

        printf("\nEnter Your Choice -> ");
        scanf("%d", &user_choice);

        switch(user_choice) {
            case 1:   // ADD NEW PASSWORD
                if(num_entries == MAX_ENTRIES) {
                    printf("\nSorry, no more memory available to store new passwords. Please delete some old entries to make space.\n\n");
                    break;
                }

                printf("\nEnter a username (Max %d characters) -> ", MAX_USERNAME_LENGTH);
                scanf("%s", username_input);

                if(strlen(username_input) > MAX_USERNAME_LENGTH) {
                    printf("\nUsername can't exceed %d characters. Please try again.\n\n", MAX_USERNAME_LENGTH);
                    break;
                }

                printf("\nEnter a password (Max %d characters) -> ", MAX_PASSWORD_LENGTH);
                scanf("%s", password_input);

                if(strlen(password_input) > MAX_PASSWORD_LENGTH) {
                    printf("\nPassword can't exceed %d characters. Please try again.\n\n", MAX_PASSWORD_LENGTH);
                    break;
                }

                for(int i = 0; i < num_entries; i++) {
                    if(strcmp(username_input, password_book[i].username) == 0) {
                        printf("\nSorry, an entry already exists for this username. Please try another username.\n\n");
                        break;
                    }
                }

                strcpy(password_book[num_entries].username, username_input);
                strcpy(password_book[num_entries].password, password_input);

                printf("\nPassword added successfully!\n\n");
                num_entries++;
                break;

            case 2:   // VIEW PASSWORD BOOK
                if(num_entries == 0) {
                    printf("\nThere are no entries in your password book yet.\n\n");
                    break;
                }

                printf("\n Here are your current password book entries: \n\n");

                for (int i = 0; i < num_entries; i++) {
                    printf("Username: %s \nPassword: %s\n", password_book[i].username,password_book[i].password);
                }

                printf("\n End of Password Book Entries. \n\n");
                break;

            case 3:  // SEARCH FOR AN ENTRY
                printf("\nEnter username for the password you want to search: ");
                scanf("%s", username_input);

                if(strlen(username_input) > MAX_USERNAME_LENGTH) {
                    printf("\nSearch query can't exceed %d characters. Please try again.\n\n", MAX_USERNAME_LENGTH);
                    break;
                }

                int found = 0;
                for(int i = 0; i < num_entries; i++) {
                    if(strcmp(username_input, password_book[i].username) == 0) {
                        printf("\nPassword Found! Username: %s \nPassword: %s\n\n", password_book[i].username,password_book[i].password);
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("\nSorry, no entries found for the username: %s \n\n", username_input);
                }

                break;

            case 4:   // DELETE AN ENTRY
                printf("\nEnter the username of the password you want to delete: ");
                scanf("%s", username_input);

                if(strlen(username_input) > MAX_USERNAME_LENGTH) {
                    printf("\nDeletion query can't exceed %d characters. Please try again.\n\n", MAX_USERNAME_LENGTH);
                    break;
                }

                int deleted = 0;
                for(int i = 0; i < num_entries; i++) {
                    if(strcmp(username_input, password_book[i].username) == 0) {
                        printf("\nDo you really want to delete the following entry? \nUsername: %s \nPassword: %s\n", password_book[i].username,password_book[i].password);
                        printf("(Y)es or (N)o\n");

                        char confirmation;
                        scanf(" %c", &confirmation);

                        if(confirmation == 'y' || confirmation == 'Y') {
                            for(int j = i; j < num_entries - 1; j++) {
                                strcpy(password_book[j].username, password_book[j+1].username);
                                strcpy(password_book[j].password, password_book[j+1].password);
                            }

                            num_entries--;
                            deleted = 1;
                            printf("\nEntry Deleted Successfully\n\n");
                            break;
                        }
                    }
                }

                if(!deleted) {
                    printf("\nSorry, no entries found for the username: %s \n\n", username_input); 
                }

                break;

            case 5:   // EXIT PASSWORD MANAGER
                printf("\nThank you for using our Password Manager. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid input. Please try again.\n\n");
                break;
        }
    }

    return 0;
}