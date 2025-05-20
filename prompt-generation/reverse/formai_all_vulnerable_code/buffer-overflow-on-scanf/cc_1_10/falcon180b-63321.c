//Falcon-180B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100

typedef struct {
    char username[50];
    char password[50];
} Password;

void generatePassword(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;
    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[i] = '\0';
}

int main() {
    char filename[50];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File does not exist.\n");
        exit(1);
    }

    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    while (fscanf(fp, "%s %s", passwords[numPasswords].username, passwords[numPasswords].password)!= EOF) {
        numPasswords++;
    }

    fclose(fp);

    printf("Enter the username: ");
    scanf("%s", passwords[0].username);

    printf("Enter the password length: ");
    int length;
    scanf("%d", &length);

    generatePassword(passwords[0].password, length);

    printf("Your new password is: %s\n", passwords[0].password);

    FILE* fw = fopen(filename, "w");
    if (fw == NULL) {
        printf("Failed to write to file.\n");
        exit(1);
    }

    for (int i = 0; i < numPasswords; i++) {
        fprintf(fw, "%s %s\n", passwords[i].username, passwords[i].password);
    }

    fclose(fw);

    printf("Password updated successfully.\n");

    return 0;
}