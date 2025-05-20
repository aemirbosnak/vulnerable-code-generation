//FormAI DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100  // Maximum number of passwords that can be stored

// Structure to store the password details
typedef struct Password {
    char website[50];  // name of the website or service
    char username[50]; // username used for the login
    char password[50]; // password used for the login
} Password;

int main(void) {
    Password passwords[MAX_PASSWORDS]; // array to store all the passwords
    int numPasswords = 0; // number of passwords currently stored
    
    while (1) { // loop indefinitely until the user chooses to quit
        printf("\n");
        printf("======= Password Manager =======\n");
        printf("1. Add a new password\n");
        printf("2. Remove a password\n");
        printf("3. View all passwords\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice); // get the user's choice
        
        switch (choice) {
            case 1: // add a new password
                printf("\nEnter website: ");
                scanf("%s", passwords[numPasswords].website);
                printf("Enter username: ");
                scanf("%s", passwords[numPasswords].username);
                printf("Enter password: ");
                scanf("%s", passwords[numPasswords].password);
                numPasswords++;
                printf("\nPassword added!\n");
                break;
                
            case 2: // remove a password
                printf("\nEnter index of password to remove: ");
                int index;
                scanf("%d", &index);
                if (index >= 0 && index < numPasswords) {
                    // shift all passwords after the index back one slot
                    for (int i = index; i < numPasswords - 1; i++) {
                        passwords[i] = passwords[i+1];
                    }
                    numPasswords--;
                    printf("\nPassword removed!\n");
                } else {
                    printf("\nInvalid index!\n");
                }
                break;
                
            case 3: // view all passwords
                printf("\n");
                printf("%-20s%-20s%s\n", "Website", "Username", "Password");
                for (int i = 0; i < numPasswords; i++) {
                    printf("%-20s%-20s%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
                }
                break;
                
            case 4: // quit the program
                printf("\nThanks for using the Password Manager!\n");
                exit(0);
                
            default: // invalid choice
                printf("\nInvalid choice!\n");
                break;
        }
    }
    
    return 0;
}