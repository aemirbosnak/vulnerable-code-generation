//Falcon-180B DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct password {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void generate_password(char *password, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[length] = '\0';
}

int main() {
    int num_passwords, i;
    struct password passwords[MAX_PASSWORDS];

    printf("Enter the number of passwords to generate: ");
    scanf("%d", &num_passwords);

    if (num_passwords > MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords is %d\n", MAX_PASSWORDS);
        return 1;
    }

    for (i = 0; i < num_passwords; i++) {
        printf("Enter the website for password %d: ", i + 1);
        scanf("%s", passwords[i].website);

        printf("Enter the username for password %d: ", i + 1);
        scanf("%s", passwords[i].username);

        generate_password(passwords[i].password, MAX_PASSWORD_LENGTH);

        printf("Password for %s:\n%s\n", passwords[i].website, passwords[i].password);
    }

    return 0;
}