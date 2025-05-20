//Falcon-180B DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[50];
    char password[50];
} Password;

void generate_password(char *password, int length) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }

    password[length] = '\0';
}

int compare_passwords(const void *a, const void *b) {
    return strcmp(*(Password **)a, *(Password **)b);
}

void print_password_list(Password *passwords, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    Password *passwords = malloc(MAX_PASSWORDS * sizeof(Password));
    int count = 0;

    while (count < MAX_PASSWORDS) {
        printf("Enter website name: ");
        scanf("%s", passwords[count].name);

        printf("Enter password length (1-50): ");
        int length = rand() % 50 + 1;

        generate_password(passwords[count].password, length);

        printf("Password for %s: %s\n\n", passwords[count].name, passwords[count].password);

        count++;
    }

    qsort(passwords, count, sizeof(Password), compare_passwords);

    printf("\nPassword list:\n");
    print_password_list(passwords, count);

    free(passwords);

    return 0;
}