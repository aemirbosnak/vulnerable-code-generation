//Falcon-180B DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char *name;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char *name, char *password) {
    passwords[numPasswords].name = strdup(name);
    passwords[numPasswords].password = strdup(password);
    numPasswords++;
}

int comparePasswords(const void *a, const void *b) {
    char *nameA = ((Password *)a)->name;
    char *nameB = ((Password *)b)->name;
    return strcmp(nameA, nameB);
}

void printPasswords() {
    qsort(passwords, numPasswords, sizeof(Password), comparePasswords);
    for (int i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    char input[100];
    while (1) {
        printf("Enter command (add/print/exit): ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", input);
            printf("Enter password: ");
            scanf("%s", input);
            addPassword(input, input);
        } else if (strcmp(input, "print") == 0) {
            printPasswords();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}