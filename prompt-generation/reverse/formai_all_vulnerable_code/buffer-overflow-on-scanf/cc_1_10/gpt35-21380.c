//FormAI DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define a struct for the password manager
struct passwd {
    char name[20];
    char password[20];
} ;

// Function for adding new password
void add_password(struct passwd *password_db, int *num_passwords) {
    printf("Enter the name of the website/service: ");
    scanf("%s", password_db[*num_passwords].name);
    printf("Enter the password for %s: ", password_db[*num_passwords].name);
    scanf("%s", password_db[*num_passwords].password);
    (*num_passwords)++;
    printf("Password added successfully!\n");
}

// Function for displaying all passwords
void display_passwords(struct passwd *password_db, int *num_passwords) {
    printf("Name\tPassword\n");
    for(int i=0; i<*num_passwords; i++) {
        printf("%s\t%s\n", password_db[i].name, password_db[i].password);
    }
}

int main() {
    int choice, num_passwords = 0;
    struct passwd password_db[50];
    
    printf("Welcome to Password Manager!\n");
    
    // Loop for menu and user actions
    while(1) {
        printf("\nMenu:\n");
        printf("1. Add New Password\n");
        printf("2. Display All Passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                add_password(password_db, &num_passwords);
                break;
            case 2:
                display_passwords(password_db, &num_passwords);
                break;
            case 3:
                printf("\nThank you for using Password Manager!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please choose again.\n");
        }
    }

    return 0;
}