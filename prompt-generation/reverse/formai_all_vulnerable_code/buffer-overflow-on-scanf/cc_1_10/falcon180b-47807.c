//Falcon-180B DATASET v1.0 Category: Password management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} password_t;

void generate_password(char *password, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";
    int i, j;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[length] = '\0';
}

int main() {
    int num_passwords;
    char filename[MAX_PASSWORD_LENGTH];
    FILE *file;
    password_t passwords[MAX_PASSWORDS];

    printf("Enter the number of passwords to generate: ");
    scanf("%d", &num_passwords);

    printf("Enter the filename to save the passwords to: ");
    scanf("%s", filename);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    for (int i = 0; i < num_passwords; i++) {
        int length = rand() % MAX_PASSWORD_LENGTH + 8;
        char password[MAX_PASSWORD_LENGTH];

        generate_password(password, length);

        passwords[i].length = length;
        strcpy(passwords[i].password, password);

        fprintf(file, "Password %d: %s\n", i + 1, password);
    }

    fclose(file);

    printf("Passwords saved to file.\n");

    return 0;
}