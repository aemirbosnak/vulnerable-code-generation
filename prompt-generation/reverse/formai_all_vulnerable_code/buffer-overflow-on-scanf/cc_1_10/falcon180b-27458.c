//Falcon-180B DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

void generate_password(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int compare_passwords(const void* a, const void* b) {
    const Password* p1 = (const Password*)a;
    const Password* p2 = (const Password*)b;

    return strcmp(p1->name, p2->name);
}

int main() {
    int num_passwords = 0;
    Password passwords[MAX_PASSWORDS];

    while (num_passwords < MAX_PASSWORDS) {
        printf("Enter website name (or press enter to finish): ");
        char name[MAX_PASSWORD_LENGTH];
        fgets(name, MAX_PASSWORD_LENGTH, stdin);

        if (name[0] == '\0') {
            break;
        }

        printf("Enter password length: ");
        int length;
        scanf("%d", &length);

        generate_password(passwords[num_passwords].password, length);
        strcpy(passwords[num_passwords].name, name);
        passwords[num_passwords].length = length;

        num_passwords++;
    }

    qsort(passwords, num_passwords, sizeof(Password), compare_passwords);

    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }

    return 0;
}