//FormAI DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 50

struct Password {
    char website[50];
    char username[50];
    char password[50];
};

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void encryptPassword(char* password) {
    // simple Caesar cipher encryption
    int key = 3;
    for (int i = 0; i < strlen(password); i++) {
        if (isalpha(password[i])) {
            password[i] = (password[i] - 'a' + key) % 26 + 'a';
        }
    }
}

void decryptPassword(char* password) {
    // simple Caesar cipher decryption
    int key = 3;
    for (int i = 0; i < strlen(password); i++) {
        if (isalpha(password[i])) {
            password[i] = (password[i] - 'a' - key + 26) % 26 + 'a';
        }
    }
}

void printPasswords(struct Password *passwords, int numPasswords) {
    printf("\n%s\t%s\t%s\n", "Website", "Username", "Password");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t%s\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

void addPassword(struct Password *passwords, int *numPasswords) {
    printf("\nEnter website: ");
    scanf("%s", passwords[*numPasswords].website);
    clearInputBuffer();

    printf("Enter username: ");
    scanf("%s", passwords[*numPasswords].username);
    clearInputBuffer();

    printf("Enter password: ");
    scanf("%s", passwords[*numPasswords].password);
    encryptPassword(passwords[*numPasswords].password);

    printf("\nPassword added successfully!\n");

    (*numPasswords)++;
}

void updatePassword(struct Password *passwords, int numPasswords) {
    char website[50];
    printf("\nEnter website for which to update password: ");
    scanf("%s", website);
    clearInputBuffer();

    int passwordIndex = -1;
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            passwordIndex = i;
            break;
        }
    }

    if (passwordIndex == -1) {
        printf("No matching website found.\n");
    } else {
        printf("Enter new password: ");
        scanf("%s", passwords[passwordIndex].password);
        encryptPassword(passwords[passwordIndex].password);

        printf("\nPassword for website %s updated successfully!\n", website);
    }
}

void deletePassword(struct Password *passwords, int *numPasswords) {
    char website[50];
    printf("\nEnter website for which to delete password: ");
    scanf("%s", website);
    clearInputBuffer();

    int passwordIndex = -1;
    for (int i = 0; i < *numPasswords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            passwordIndex = i;
            break;
        }
    }

    if (passwordIndex == -1) {
        printf("No matching website found.\n");
    } else {
        for (int i = passwordIndex; i < *numPasswords - 1; i++) {
            passwords[i] = passwords[i + 1];
        }
        (*numPasswords)--;
        printf("\nPassword for website %s deleted successfully!\n", website);
    }
}

int main() {
    struct Password passwords[100];
    int numPasswords = 0;
    char choice;
    do {
        printf("\nPassword Manager\n");
        printf("1. Print passwords\n");
        printf("2. Add password\n");
        printf("3. Update password\n");
        printf("4. Delete password\n");
        printf("5. Quit\n");
        printf("Enter choice (1-5): ");
        scanf("%c", &choice);
        clearInputBuffer();

        switch (choice) {
            case '1':
                printPasswords(passwords, numPasswords);
                break;
            case '2':
                addPassword(passwords, &numPasswords);
                break;
            case '3':
                updatePassword(passwords, numPasswords);
                break;
            case '4':
                deletePassword(passwords, &numPasswords);
                break;
            case '5':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != '5');

    return 0;
}