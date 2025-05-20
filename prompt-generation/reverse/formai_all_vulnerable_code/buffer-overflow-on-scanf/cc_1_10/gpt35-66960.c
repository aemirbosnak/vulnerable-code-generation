//FormAI DATASET v1.0 Category: System administration ; Style: bold
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice, userCount = 0, userId;
    char username[20], password[20];

    while (1) {
        printf("\n\n\t\tMENU\n");
        printf("\n1. Create a new user account");
        printf("\n2. Change Password of a user");
        printf("\n3. Delete a user account");
        printf("\n4. View all user accounts");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the username: ");
                scanf("%s", username);
                printf("Enter the password: ");
                scanf("%s", password);
                printf("User account created with User ID: %d\n", ++userCount);
                break;
                
            case 2:
                printf("\nEnter the User ID to change password: ");
                scanf("%d", &userId);
                printf("Enter new password: ");
                scanf("%s", password);
                printf("Password changed successfully for User ID: %d\n", userId);
                break;
                
            case 3:
                printf("\nEnter the User ID to delete account: ");
                scanf("%d", &userId);
                printf("User account with User ID %d deleted successfully.\n", userId);
                break;
                
            case 4:
                printf("\nUSER ACCOUNTS:\n");
                printf("-----------------------\n");
                printf("| User ID | Username |\n");
                printf("-----------------------\n");
                for (int i = 1; i <= userCount; i++) {
                    printf("| %-7d | %-8s |\n", i, "username");
                }
                printf("-----------------------\n");
                break;
                
            case 5:
                printf("\nThank you for using this program!");
                exit(0);
                
            default:
                printf("\nInvalid choice! Please choose again.\n");
        }
    }

    return 0;
}