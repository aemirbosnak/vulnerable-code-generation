//FormAI DATASET v1.0 Category: Password management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Struct for a single Password Entry */
typedef struct {
    char website[50];
    char username[50];
    char password[50];
} PasswordEntry;

/* Function Declarations */
void addPasswordEntry();
void viewAll();
void searchWebsite();
void changePassword();
void deleteEntry();
void generatePassword();
void menu();

/* Global Variable Declarations */
PasswordEntry passwords[100];
int numPasswords = 0;

/* Main Function */
int main() {
    printf("Welcome to Password Manager!\n\n");
    menu();
    return 0;
}

/* Function Definitions */

/* Allows user to add new password entry */
void addPasswordEntry() {
    printf("Please enter the following details:\n");
    printf("Website: ");
    scanf("%s", passwords[numPasswords].website);
    printf("Username: ");
    scanf("%s", passwords[numPasswords].username);
    printf("Password: ");
    scanf("%s", passwords[numPasswords].password);
    numPasswords++;
    printf("\nPassword added successfully!\n\n");
    menu();
}

/* Displays all password entries */
void viewAll() {
    if(numPasswords == 0) {
        printf("No passwords found!\n\n");
    } else {
        printf("Here are all the passwords:\n\n");
        for(int i=0; i<numPasswords; i++) {
            printf("%d. Website: %s\n   Username: %s\n   Password: %s\n\n", i+1, passwords[i].website, passwords[i].username, passwords[i].password);
        }
    }
    menu();
}

/* Allows user to search for a password entry based on website */
void searchWebsite() {
    char website[50];
    printf("Please enter the website you want to search for: ");
    scanf("%s", website);
    bool found = false;
    for(int i=0; i<numPasswords; i++) {
        if(strcmp(passwords[i].website, website) == 0) {
            printf("Website: %s\nUsername: %s\nPassword: %s\n\n", passwords[i].website, passwords[i].username, passwords[i].password);
            found = true;
            break;
        }
    }
    if(!found) {
        printf("Sorry, no password found for %s\n\n", website);
    }   
    menu(); 
}

/* Allows user to change the password for a website */
void changePassword() {
    char website[50];
    printf("Please enter the website you want to change the password for: ");
    scanf("%s", website);
    bool found = false;
    for(int i=0; i<numPasswords; i++) {
        if(strcmp(passwords[i].website, website) == 0) {
            printf("Please enter the new password: ");
            scanf("%s", passwords[i].password);
            found = true;
            printf("\nPassword changed successfully!\n\n");
            break;
        }
    }
    if(!found) {
        printf("Sorry, no password found for %s\n\n", website);
    }   
    menu(); 
}

/* Allows user to delete a password entry */
void deleteEntry() {
    char website[50];
    printf("Please enter the website you want to delete the password for: ");
    scanf("%s", website);
    bool found = false;
    for(int i=0; i<numPasswords; i++) {
        if(strcmp(passwords[i].website, website) == 0) {
            for(int j=i; j<numPasswords-1; j++) {
                passwords[j] = passwords[j+1];
            }
            numPasswords--;
            found = true;
            printf("\nPassword deleted successfully!\n\n");
            break;
        }
    }
    if(!found) {
        printf("Sorry, no password found for %s\n\n", website);
    }   
    menu();
}

/* Generates a random password and copies it to clipboard */
void generatePassword() {
    char symbols[10] = "#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    char password[50] = "";
    int length, numSymbols, numNumbers;
    printf("Please enter the length of the password: ");
    scanf("%d", &length);
    printf("Please enter the number of symbols (e.g. %c): ", symbols[0]);
    scanf("%d", &numSymbols);
    printf("Please enter the number of numbers: ");
    scanf("%d", &numNumbers);
    int numLetters = length - numSymbols - numNumbers;
    for(int i=0; i<numSymbols; i++) {
        int index = rand() % strlen(symbols);
        password[i] = symbols[index];
    }
    for(int i=0; i<numNumbers; i++) {
        int n = rand() % 10;
        password[numSymbols + i] = n + '0';
    }
    for(int i=0; i<numLetters; i++) {
        int n;
        if(numSymbols > 0 && numNumbers > 0) {
            n = rand() % 52;
        } else {
            n = rand() % 26;
        }
        if(n < 26) {
            password[numSymbols + numNumbers + i] = 'a' + n;
        } else {
            password[numSymbols + numNumbers + i] = 'A' + (n - 26);
        }
    }
    printf("Generated Password: %s\n\n", password);
    menu();
}

/* Displays menu and accepts user input */
void menu() {
    char choice;
    printf("Please select an option:\n\n");
    printf("1. Add a new password\n");
    printf("2. View all passwords\n");
    printf("3. Search for a password\n");
    printf("4. Change password\n");
    printf("5. Delete a password\n");
    printf("6. Generate random password\n");
    printf("7. Exit\n\n");
    printf("Choice: ");
    scanf(" %c", &choice);
    switch(choice) {
        case '1':
            addPasswordEntry();
            break;
        case '2':
            viewAll();
            break;
        case '3':
            searchWebsite();
            break;
        case '4':
            changePassword();
            break;
        case '5':
            deleteEntry();
            break;
        case '6':
            generatePassword();
            break;
        case '7':
            printf("Bye!\n");
            break;
        default:
            printf("Invalid choice! Try again.\n\n");
            menu();
    }   
}