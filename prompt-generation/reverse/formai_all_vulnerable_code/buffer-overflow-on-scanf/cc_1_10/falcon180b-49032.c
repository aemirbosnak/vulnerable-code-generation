//Falcon-180B DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

struct Password {
    char service[20];
    char username[20];
    char password[PASSWORD_LENGTH];
};

void generatePassword(char* password) {
    int i;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = rand() % 26 + 'a';
    }
    password[PASSWORD_LENGTH - 1] = '\0';
}

int main() {
    char filename[50];
    FILE *file;
    int numPasswords = 0;
    struct Password passwords[MAX_PASSWORDS];

    printf("Enter the name of the file to store passwords: ");
    scanf("%s", filename);

    file = fopen(filename, "a+");
    if (file == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    rewind(file);
    while (fscanf(file, "%s %s %s", passwords[numPasswords].service, passwords[numPasswords].username, passwords[numPasswords].password)!= EOF) {
        numPasswords++;
    }
    fclose(file);

    printf("\nEnter the name of the service: ");
    scanf("%s", passwords[numPasswords].service);
    printf("Enter the username: ");
    scanf("%s", passwords[numPasswords].username);

    generatePassword(passwords[numPasswords].password);
    printf("\nGenerated password: %s\n", passwords[numPasswords].password);

    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(file, "%s %s %s\n", passwords[numPasswords].service, passwords[numPasswords].username, passwords[numPasswords].password);
    fclose(file);

    return 0;
}