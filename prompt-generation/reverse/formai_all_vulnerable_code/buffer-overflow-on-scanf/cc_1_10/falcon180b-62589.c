//Falcon-180B DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 100

struct Password {
    char *username;
    char *password;
    int length;
};

void generatePassword(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[length] = '\0';
}

int comparePasswords(const void *a, const void *b) {
    const struct Password *p1 = a;
    const struct Password *p2 = b;

    return strcmp(p1->password, p2->password);
}

int main() {
    int i, j;
    char input[MAX_PASSWORD_LENGTH];
    struct Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    printf("Enter a username: ");
    scanf("%s", input);

    printf("Enter the number of passwords you want to generate: ");
    scanf("%d", &numPasswords);

    for (i = 0; i < numPasswords; i++) {
        printf("Enter the length of password %d: ", i + 1);
        scanf("%d", &passwords[i].length);

        passwords[i].username = strdup(input);
        generatePassword(passwords[i].password, passwords[i].length);
    }

    qsort(passwords, numPasswords, sizeof(struct Password), comparePasswords);

    printf("Passwords generated for %s:\n", input);
    for (i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }

    for (i = 0; i < numPasswords; i++) {
        free(passwords[i].username);
        free(passwords[i].password);
    }

    return 0;
}