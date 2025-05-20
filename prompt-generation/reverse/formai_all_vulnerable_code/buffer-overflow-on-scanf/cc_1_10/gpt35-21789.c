//FormAI DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PWD_LEN 25
#define MAX_ATTEMPTS 3

struct account {
    char username[50];
    char password[MAX_PWD_LEN + 1];
};

typedef struct account account_t;

void change_password(account_t *account_ptr, char *new_password) {
    int attempts = 0;
    char current_password[MAX_PWD_LEN + 1], confirm_password[MAX_PWD_LEN + 1];
    
    while (attempts < MAX_ATTEMPTS) {
        printf("Enter current password: ");
        scanf("%s", current_password);
        
        if (strcmp(account_ptr->password, current_password) != 0) {
            attempts++;
            printf("Incorrect password!\n");
            printf("You have %d attempts remaining.\n", MAX_ATTEMPTS - attempts);
        } else {
            printf("Enter new password: ");
            scanf("%s", new_password);
            
            printf("Confirm new password: ");
            scanf("%s", confirm_password);
            
            if (strcmp(new_password, confirm_password) != 0) {
                printf("New passwords do not match, please try again.\n");
            } else {
                strncpy(account_ptr->password, new_password, MAX_PWD_LEN);
                printf("Password changed successfully!\n");
                return;
            }
        }
    }
    
    printf("Maximum number of attempts exceeded, please try again later.\n");
}

int main() {
    account_t test_account = {"test_user", "test_password123"};
    
    char new_password[MAX_PWD_LEN + 1];
    
    printf("Username: %s\n", test_account.username);
    printf("Password: %s\n", test_account.password);
    
    change_password(&test_account, new_password);
    
    printf("New password: %s\n", test_account.password);
    
    return 0;
}