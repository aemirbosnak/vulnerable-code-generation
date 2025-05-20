//FormAI DATASET v1.0 Category: Password management ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20

int main() {
    char passwords[10][MAX_PASSWORD_LENGTH];
    int numPasswords = 0;
    int choice, i;
    
    printf("Password Manager\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a password\n");
        printf("2. View passwords\n");
        printf("3. Remove a password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (numPasswords >= 10) {
                    printf("Maximum number of passwords reached.\n");
                    break;
                }
                
                char password[MAX_PASSWORD_LENGTH];
                printf("Enter the password (max %d characters): ", MAX_PASSWORD_LENGTH - 1);
                scanf("%s", password);
                
                if (strlen(password) >= MAX_PASSWORD_LENGTH) {
                    printf("Password too long.\n");
                    break;
                }
                
                strcpy(passwords[numPasswords], password);
                numPasswords++;
                
                printf("Password added successfully.\n");
                break;
                
            case 2:
                for (i = 0; i < numPasswords; i++) {
                    printf("%d. %s\n", i+1, passwords[i]);
                }
                
                if (numPasswords == 0) {
                    printf("No passwords saved.\n");
                }
                
                break;
                
            case 3:
                if (numPasswords == 0) {
                    printf("No passwords saved.\n");
                    break;
                }
                
                printf("Enter the number of the password you want to remove: ");
                scanf("%d", &i);
                
                if (i < 1 || i > numPasswords) {
                    printf("Invalid password number.\n");
                    break;
                }
                
                printf("Are you sure you want to remove password %d (y/n)? ", i);
                
                char answer;
                scanf(" %c", &answer);
                
                if (answer != 'y') {
                    break;
                }
                
                for (i--; i < numPasswords - 1; i++) {
                    strcpy(passwords[i], passwords[i+1]);
                }
                
                numPasswords--;
                printf("Password removed successfully.\n");
                
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