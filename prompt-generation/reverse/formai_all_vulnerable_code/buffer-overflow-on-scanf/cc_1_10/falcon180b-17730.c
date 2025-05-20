//Falcon-180B DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100

struct password {
    char *username;
    char *password;
    int length;
};

void generate_password(char *password, int length) {
    const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;
    for (i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[length] = '\0';
}

int compare_passwords(const void *a, const void *b) {
    const struct password *p1 = a;
    const struct password *p2 = b;
    return strcmp(p1->username, p2->username);
}

int main() {
    int num_passwords;
    printf("Enter the number of passwords to generate: ");
    scanf("%d", &num_passwords);

    struct password passwords[MAX_PASSWORDS];
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("Enter username for password %d: ", i + 1);
        char username[50];
        scanf("%s", username);

        printf("Enter desired password length for %s: ", username);
        int length;
        scanf("%d", &length);

        generate_password(passwords[i].password, length);
        passwords[i].username = strdup(username);
        passwords[i].length = length;
    }

    qsort(passwords, num_passwords, sizeof(struct password), compare_passwords);

    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\nLength: %d\n\n", passwords[i].username, passwords[i].password, passwords[i].length);
    }

    return 0;
}