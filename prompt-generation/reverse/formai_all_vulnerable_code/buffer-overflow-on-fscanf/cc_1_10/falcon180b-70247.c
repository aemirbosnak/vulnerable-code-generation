//Falcon-180B DATASET v1.0 Category: Password management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 16

typedef struct {
    char username[32];
    char password[PASSWORD_LENGTH];
} password_t;

void generate_password(char *password) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i = 0;

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[i] = '\0';
}

int main() {
    FILE *passwords_file;
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char filename[32];
    char password[PASSWORD_LENGTH];

    printf("Enter the filename for the password file: ");
    scanf("%s", filename);

    passwords_file = fopen(filename, "r");

    if (passwords_file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    while (fscanf(passwords_file, "%s %s", passwords[num_passwords].username, passwords[num_passwords].password)!= EOF) {
        num_passwords++;
    }

    fclose(passwords_file);

    printf("Enter the username: ");
    scanf("%s", password);

    int found = 0;

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, password) == 0) {
            printf("Password: %s\n", passwords[i].password);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Password not found.\n");
    }

    return 0;
}