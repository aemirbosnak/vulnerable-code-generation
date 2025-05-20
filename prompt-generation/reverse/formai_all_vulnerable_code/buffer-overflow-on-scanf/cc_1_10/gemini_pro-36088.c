//GEMINI-pro DATASET v1.0 Category: Password management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char *password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Password limit reached\n");
        return;
    }
    
    strcpy(passwords[numPasswords].password, password);
    passwords[numPasswords].length = strlen(password);
    numPasswords++;
}

void removePassword(char *password) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].password, password) == 0) {
            for (int j = i; j < numPasswords - 1; j++) {
                passwords[j] = passwords[j+1];
            }
            numPasswords--;
            break;
        }
    }
}

void printPasswords() {
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\n", passwords[i].password);
    }
}

int main() {
    char input[100];
    char password[MAX_PASSWORD_LENGTH];
    
    while (1) {
        printf("Enter a command (add, remove, print, quit): ");
        scanf("%s", input);
        
        if (strcmp(input, "add") == 0) {
            printf("Enter a password: ");
            scanf("%s", password);
            addPassword(password);
        } else if (strcmp(input, "remove") == 0) {
            printf("Enter a password to remove: ");
            scanf("%s", password);
            removePassword(password);
        } else if (strcmp(input, "print") == 0) {
            printPasswords();
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    
    return 0;
}