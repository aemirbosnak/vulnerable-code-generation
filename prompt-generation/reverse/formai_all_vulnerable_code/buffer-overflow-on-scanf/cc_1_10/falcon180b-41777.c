//Falcon-180B DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

struct password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void generate_password(char *password, int length) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+~`|}{[]\:;?><,./-=";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }

    password[length] = '\0';
}

int compare_passwords(const void *a, const void *b) {
    const struct password *p1 = a;
    const struct password *p2 = b;

    return strcmp(p1->name, p2->name);
}

int main() {
    int num_passwords;
    struct password passwords[MAX_PASSWORDS];
    int i;

    printf("Enter the number of passwords to generate: ");
    scanf("%d", &num_passwords);

    for (i = 0; i < num_passwords; i++) {
        printf("Enter the name for password %d: ", i + 1);
        scanf("%s", passwords[i].name);

        generate_password(passwords[i].password, MAX_PASSWORD_LENGTH);

        printf("Password for %s: %s\n", passwords[i].name, passwords[i].password);
    }

    qsort(passwords, num_passwords, sizeof(struct password), compare_passwords);

    for (i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }

    return 0;
}