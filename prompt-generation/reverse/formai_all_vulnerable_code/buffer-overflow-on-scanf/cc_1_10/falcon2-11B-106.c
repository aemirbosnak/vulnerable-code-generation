//Falcon2-11B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 20

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    printf("Enter number of passwords to add: ");
    scanf("%d", &numPasswords);

    for (int i = 0; i < numPasswords; i++) {
        printf("Username: ");
        fgets(passwords[i].username, MAX_LENGTH, stdin);
        passwords[i].username[strcspn(passwords[i].username, "\n")] = '\0'; // remove trailing newline

        printf("Password: ");
        fgets(passwords[i].password, MAX_LENGTH, stdin);
        passwords[i].password[strcspn(passwords[i].password, "\n")] = '\0'; // remove trailing newline

        printf("\n");
    }

    printf("Enter username to search for: ");
    fgets(passwords[0].username, MAX_LENGTH, stdin);
    passwords[0].username[strcspn(passwords[0].username, "\n")] = '\0'; // remove trailing newline

    int found = 0;
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, passwords[0].username) == 0) {
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", passwords[i].password);
            found = 1;
        }
    }

    if (!found) {
        printf("Username not found.\n");
    }

    return 0;
}