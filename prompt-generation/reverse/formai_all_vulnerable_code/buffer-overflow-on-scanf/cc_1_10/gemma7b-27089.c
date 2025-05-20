//Gemma-7B DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    int strength;
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int i, j, k, password_count = 0;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = NULL;
        passwords[i].password = NULL;
        passwords[i].strength = 0;
    }

    printf("Enter the number of passwords you want to manage: ");
    scanf("%d", &k);

    for (i = 0; i < k; i++) {
        passwords[password_count].name = malloc(20);
        printf("Enter the name of the password: ");
        scanf("%s", passwords[password_count].name);

        passwords[password_count].password = malloc(50);
        printf("Enter the password: ");
        scanf("%s", passwords[password_count].password);

        passwords[password_count].strength = calculate_strength(passwords[password_count].password);
        password_count++;
    }

    printf("Here is a list of your passwords:\n");
    for (i = 0; i < password_count; i++) {
        printf("Name: %s\n", passwords[i].name);
        printf("Password: %s\n", passwords[i].password);
        printf("Strength: %d\n", passwords[i].strength);
        printf("\n");
    }

    return 0;
}

int calculate_strength(char *password) {
    int strength = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i]) || islower(password[i]) || isdigit(password[i])) {
            strength++;
        }
    }

    return strength;
}