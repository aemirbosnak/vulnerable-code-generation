//Falcon2-11B DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// Define a structure to store the password information
struct password {
    char username[50];
    char password[50];
    int account_type;
};

// Define a function to add a new password
void add_password(struct password *password) {
    printf("Enter username: ");
    fgets(password->username, sizeof(password->username), stdin);
    
    printf("Enter password: ");
    fgets(password->password, sizeof(password->password), stdin);
    
    printf("Enter account type (1 for savings, 2 for checking): ");
    scanf("%d", &password->account_type);
}

// Define a function to display all passwords
void display_passwords(struct password *passwords, int count) {
    printf("Username\tPassword\tAccount Type\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%d\n", passwords[i].username, passwords[i].password, passwords[i].account_type);
    }
}

int main() {
    struct password passwords[100];
    int count = 0;
    
    while (1) {
        printf("1. Add Password\n2. Display Passwords\n3. Quit\n");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_password(&passwords[count]);
                count++;
                break;
            case 2:
                display_passwords(passwords, count);
                break;
            case 3:
                return 0;
        }
    }
    
    return 0;
}