//Falcon-180B DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

void generatePassword(Password *password) {
    int i;
    char ch;
    for (i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        do {
            ch = rand() % 26 + 'a';
        } while (strchr("abcdefghijklmnopqrstuvwxyz", ch) == NULL);
        strncat(password->password, &ch, 1);
    }
    password->length = i;
}

int main() {
    int numPasswords, i;
    char choice;
    Password passwords[MAX_PASSWORDS];

    printf("Enter the number of passwords you want to generate: ");
    scanf("%d", &numPasswords);

    for (i = 0; i < numPasswords; i++) {
        generatePassword(&passwords[i]);
        printf("Password %d: %s\n", i+1, passwords[i].password);
    }

    printf("Do you want to save the passwords to a file? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        FILE *fp;
        char filename[50];
        printf("Enter the filename: ");
        scanf("%s", filename);
        fp = fopen(filename, "w");

        if (fp == NULL) {
            printf("Error opening file.\n");
        } else {
            for (i = 0; i < numPasswords; i++) {
                fprintf(fp, "Password %d: %s\n", i+1, passwords[i].password);
            }
            fclose(fp);
        }
    }

    return 0;
}