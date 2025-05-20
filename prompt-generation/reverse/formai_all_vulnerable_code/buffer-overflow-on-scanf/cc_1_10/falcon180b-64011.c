//Falcon-180B DATASET v1.0 Category: Password management ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

struct Password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void addPassword(struct Password passwords[], int numPasswords) {
    printf("Enter the name of the password: ");
    scanf("%s", passwords[numPasswords].name);
    printf("Enter the password: ");
    scanf("%s", passwords[numPasswords].password);
    numPasswords++;
}

void displayPasswords(struct Password passwords[], int numPasswords) {
    printf("Name\t\t\tPassword\n");
    for(int i=0; i<numPasswords; i++) {
        printf("%s\t\t\t%s\n", passwords[i].name, passwords[i].password);
    }
}

void searchPassword(struct Password passwords[], int numPasswords) {
    char searchName[MAX_PASSWORD_LENGTH];
    printf("Enter the name to search: ");
    scanf("%s", searchName);
    for(int i=0; i<numPasswords; i++) {
        if(strcmp(searchName, passwords[i].name) == 0) {
            printf("Password found: %s\n", passwords[i].password);
            return;
        }
    }
    printf("Password not found.\n");
}

int main() {
    struct Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    while(1) {
        printf("1. Add password\n2. Display passwords\n3. Search password\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(numPasswords >= MAX_PASSWORDS) {
                    printf("Password limit reached.\n");
                } else {
                    addPassword(passwords, numPasswords);
                }
                break;
            case 2:
                if(numPasswords == 0) {
                    printf("No passwords added.\n");
                } else {
                    displayPasswords(passwords, numPasswords);
                }
                break;
            case 3:
                if(numPasswords == 0) {
                    printf("No passwords added.\n");
                } else {
                    searchPassword(passwords, numPasswords);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}