//FormAI DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct password {
    char website[50];
    char username[50];
    char password[50];
};

int main() {
    struct password passwords[10];
    int i = 0, choice;
    char new_password[50];

    printf("Welcome to your password manager!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a password\n");
        printf("2. View saved passwords\n");
        printf("3. Update a password\n");
        printf("4. Delete a password\n");
        printf("5. Generate a new password\n");
        printf("6. Quit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter website: ");
                scanf("%s", passwords[i].website);
                printf("Enter username: ");
                scanf("%s", passwords[i].username);
                printf("Enter password: ");
                scanf("%s", passwords[i].password);
                i++;
                printf("Password added successfully!\n");
                break;
            case 2:
                if (i == 0) {
                    printf("\nNo passwords saved yet!\n");
                    continue;
                }
                printf("\nSaved passwords:\n");
                for (int j = 0; j < i; j++) {
                    printf("Website: %s\n", passwords[j].website);
                    printf("Username: %s\n", passwords[j].username);
                    printf("Password: %s\n", passwords[j].password);
                    printf("\n");
                }
                break;
            case 3:
                if (i == 0) {
                    printf("\nNo passwords saved yet!\n");
                    continue;
                }
                printf("\nEnter website for which you want to update password: ");
                char update_website[50];
                scanf("%s", update_website);
                for (int j = 0; j < i; j++) {
                    if (strcmp(update_website, passwords[j].website) == 0) {
                        printf("\nEnter new password: ");
                        scanf("%s", new_password);
                        printf("Password updated successfully for %s!\n", passwords[j].website);
                        strcpy(passwords[j].password, new_password);
                        break;
                    }
                    if (j == i-1) {
                        printf("\nWebsite not found!\n");
                    }
                }
                break;
            case 4:
                if (i == 0) {
                    printf("\nNo passwords saved yet!\n");
                    continue;
                }
                printf("\nEnter website for which you want to delete password: ");
                char delete_website[50];
                scanf("%s", delete_website);
                for (int j = 0; j < i; j++) {
                    if (strcmp(delete_website, passwords[j].website) == 0) {
                        for (int k = j; k < i-1; k++) {
                            strcpy(passwords[k].website, passwords[k+1].website);
                            strcpy(passwords[k].username, passwords[k+1].username);
                            strcpy(passwords[k].password, passwords[k+1].password);
                        }
                        i--;
                        printf("Password deleted successfully for %s!\n", delete_website);
                        break;
                    }
                    if (j == i-1) {
                        printf("\nWebsite not found!\n");
                    }
                }
                break;
            case 5:
                printf("\nHow long should your password be? ");
                int password_length;
                scanf("%d", &password_length);
                printf("\nYour new password is: ");
                for (int j = 0; j < password_length; j++) {
                    printf("%c", rand() % 94 + 33);
                }
                printf("\n");
                break;
            case 6:
                printf("\nThank you for using your password manager!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }
}