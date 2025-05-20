//Falcon-180B DATASET v1.0 Category: Password management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

void generatePassword(Password *password, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[];:,.<>?";
    int charsetLength = strlen(charset);

    for (int i = 0; i < length; i++) {
        password->password[i] = charset[rand() % charsetLength];
    }
    password->length = length;
}

void savePasswords(Password passwords[], int numPasswords, FILE *file) {
    fprintf(file, "%d\n", numPasswords);

    for (int i = 0; i < numPasswords; i++) {
        fprintf(file, "%s %d\n", passwords[i].password, passwords[i].length);
    }
}

void loadPasswords(Password passwords[], int numPasswords, FILE *file) {
    int numSavedPasswords;

    fscanf(file, "%d", &numSavedPasswords);

    for (int i = 0; i < numSavedPasswords && i < numPasswords; i++) {
        fscanf(file, "%s %d", passwords[i].password, &passwords[i].length);
    }
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    printf("Enter number of passwords to generate: ");
    scanf("%d", &numPasswords);

    for (int i = 0; i < numPasswords; i++) {
        printf("Enter length for password %d: ", i + 1);
        scanf("%d", &passwords[i].length);
        generatePassword(&passwords[i], passwords[i].length);
        printf("Generated password: %s\n", passwords[i].password);
    }

    char fileName[50];
    printf("Enter filename to save passwords: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    savePasswords(passwords, numPasswords, file);

    fclose(file);

    printf("Passwords saved to file.\n");

    return 0;
}