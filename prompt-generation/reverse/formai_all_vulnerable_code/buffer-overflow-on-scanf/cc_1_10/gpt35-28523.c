//FormAI DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_PASSWORDS 10

typedef struct {
    char name[MAX_LENGTH];
    char password[MAX_LENGTH];
} Password;

Password passwordList[MAX_PASSWORDS];
int passwordCount = 0;

void addPassword(char name[], char password[]);
void viewPassword(char name[]);
void listPasswords();

int main() {
    int choice = 0;
    char name[MAX_LENGTH];
    char password[MAX_LENGTH];

    while(choice != 4) {
        printf("\nWelcome to Happy Password Manager!\n");
        printf("1. Add a password\n");
        printf("2. View a password\n");
        printf("3. List all passwords\n");
        printf("4. Quit\n");

        printf("\nWhat would you like to do? ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nWhat website or application is this password for? ");
                scanf("%s", name);
                printf("What is the password? ");
                scanf("%s", password);
                addPassword(name, password);
                printf("\nPassword added successfully!\n");
                break;
            case 2:
                printf("\nWhich password would you like to view? ");
                scanf("%s", name);
                viewPassword(name);
                break;
            case 3:
                listPasswords();
                break;
            case 4:
                printf("\nThank you for using Happy Password Manager!\n");
                break;
            default:
                printf("\nI'm sorry, I didn't understand that. Please try again.\n");
                break;
        }
    }

    return 0;
}

void addPassword(char name[], char password[]) {
    if(passwordCount >= MAX_PASSWORDS) {
        printf("\nI'm sorry, you have reached the maximum number of passwords.\n");
    } else {
        Password newPassword;
        strcpy(newPassword.name, name);
        strcpy(newPassword.password, password);
        passwordList[passwordCount] = newPassword;
        passwordCount++;
    }
}

void viewPassword(char name[]) {
    int found = 0;

    for(int i = 0; i < passwordCount; i++) {
        if(strcmp(passwordList[i].name, name) == 0) {
            printf("\nHere is the password for %s: %s\n", passwordList[i].name, passwordList[i].password);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nI'm sorry, I could not find a password for %s\n", name);
    }
}

void listPasswords() {
    if(passwordCount == 0) {
        printf("\nYou haven't added any passwords yet!\n");
    } else {
        printf("\nHere are all of your passwords:\n");
        for(int i = 0; i < passwordCount; i++) {
            printf("%s: %s\n", passwordList[i].name, passwordList[i].password);
        }
    }
}