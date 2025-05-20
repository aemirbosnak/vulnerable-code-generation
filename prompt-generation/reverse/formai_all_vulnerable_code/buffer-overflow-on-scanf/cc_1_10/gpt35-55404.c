//FormAI DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
// Romeo and Juliet's Password Manager - A Unique C Example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20
#define PASSWORD_LENGTH 8

typedef struct Password {
    char *name;
    char *value;
} Password;

void printHeader() {
    printf("####################################\n");
    printf("# Romeo and Juliet's Password Manager #\n");
    printf("####################################\n\n");
}

int getPasswordStrength(char *password) {
    int strength = 0;
    int len = strlen(password);
    
    if (len < PASSWORD_LENGTH) {
        strength = 0;
    } else if (len < (PASSWORD_LENGTH + 2)) {
        strength = 1;
    } else if (len < (PASSWORD_LENGTH + 4)) {
        strength = 2;
    } else if (len < (PASSWORD_LENGTH + 6)) {
        strength = 3;
    } else {
        strength = 4;
    }
    
    return strength;
}

void generatePassword(char *password) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}:<>?";
    int length = strlen(charset);
    
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = charset[rand() % length];
    }
    
    password[PASSWORD_LENGTH] = '\0';
}

void printMenu() {
    printf("Choose an option:\n");
    printf("1. Add Password\n");
    printf("2. List Passwords\n");
    printf("3. Remove Password\n");
    printf("4. Exit\n");
    printf("\n> ");
}

int main() {
    srand(time(NULL));
    char password[MAX_SIZE];
    int choice = 0, numPasswords = 0, i, found = 0;
    Password passwords[MAX_SIZE];
    
    printHeader();
    
    while (choice != 4) {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (numPasswords == MAX_SIZE) {
                    printf("\nSorry, you cannot add any more passwords!\n\n");
                    break;
                }
                
                printf("\nEnter the name of the password (max length 20): ");
                Password pw;
                char *passwordName = malloc(sizeof(char) * MAX_SIZE);
                
                scanf("%s", passwordName);
                pw.name = passwordName;
                
                printf("\nWould you like to generate a password? (Y/N) ");
                char generate;
                scanf(" %c", &generate);
                
                if (generate == 'Y' || generate == 'y') {
                    generatePassword(password);
                    pw.value = password;
                } else {
                    printf("\nEnter the password: ");
                    char *passwordValue = malloc(sizeof(char) * PASSWORD_LENGTH);
                    scanf("%s", passwordValue);
                    pw.value = passwordValue;
                }
                
                passwords[numPasswords] = pw;
                numPasswords++;
                
                printf("\nPassword added successfully!\n\n");
                break;
                
            case 2:
                if (numPasswords == 0) {
                    printf("\nSorry, there are no passwords to list!\n\n");
                    break;
                }
                
                printf("\nPasswords:\n");
                
                for (i = 0; i < numPasswords; i++) {
                    printf("%d. %s\n", i+1, passwords[i].name);
                }
                
                printf("\nEnter a password number to view the password: ");
                int passwordNumber;
                scanf("%d", &passwordNumber);
                
                if (passwordNumber < 1 || passwordNumber > numPasswords) {
                    printf("\nSorry, that is an invalid password number!\n\n");
                    break;
                } else {
                    printf("\nThe password for %s is %s\n\n", passwords[passwordNumber-1].name, passwords[passwordNumber-1].value);
                }
                
                break;
                
            case 3:
                if (numPasswords == 0) {
                    printf("\nSorry, there are no passwords to remove!\n\n");
                    break;
                }
                
                printf("\nEnter the name of the password to remove: ");
                char *passwordToRemove = malloc(sizeof(char) * MAX_SIZE);
                scanf("%s", passwordToRemove);
                
                for (i = 0; i < numPasswords; i++) {
                    if (strcmp(passwordToRemove, passwords[i].name) == 0) {
                        found = 1;
                        break;
                    }
                }
                
                if (found == 0) {
                    printf("\nSorry, that password could not be found!\n\n");
                    break;
                } else {
                    free(passwords[i].name);
                    free(passwords[i].value);
                    
                    for (; i < numPasswords-1; i++) {
                        passwords[i] = passwords[i+1];
                    }
                    
                    numPasswords--;
                    printf("\nPassword removed successfully!\n\n");
                }
                
                break;
                
            case 4:
                printf("\nGoodbye!\n\n");
                break;
                
            default:
                printf("\nSorry, that is an invalid choice!\n\n");
                break;
        }
        
        found = 0;
    }
    
    return 0;
}