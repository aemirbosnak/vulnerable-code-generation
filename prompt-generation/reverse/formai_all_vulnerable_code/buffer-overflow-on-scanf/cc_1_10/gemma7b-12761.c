//Gemma-7B DATASET v1.0 Category: Password management ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    int strength;
} Password;

void generate_password(Password *passwords, int i) {
    passwords[i].name = malloc(20);
    passwords[i].password = malloc(20);
    passwords[i].strength = rand() % 3 + 1;

    printf("Enter the name of the password: ");
    scanf("%s", passwords[i].name);

    printf("Enter the password: ");
    scanf("%s", passwords[i].password);

    passwords[i].strength = calculate_password_strength(passwords[i].password);
}

int calculate_password_strength(char *password) {
    int strength = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            strength++;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            strength++;
        } else if (password[i] >= '0' && password[i] <= '9') {
            strength++;
        } else if (password[i] == '$' || password[i] == '#' || password[i] == '%') {
            strength++;
        }
    }

    return strength;
}

int main() {
    Password passwords[MAX_PASSWORDS];

    for (int i = 0; i < MAX_PASSWORDS; i++) {
        generate_password(passwords, i);
    }

    for (int i = 0; i < MAX_PASSWORDS; i++) {
        printf("Name: %s, Password: %s, Strength: %d\n", passwords[i].name, passwords[i].password, passwords[i].strength);
    }

    return 0;
}