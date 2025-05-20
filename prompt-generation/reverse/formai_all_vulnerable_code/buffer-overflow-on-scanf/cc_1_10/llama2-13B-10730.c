//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

struct password {
    char *username;
    char *password;
    int attempts;
};

int main() {
    struct password passwords[MAX_PASSWORDS] = {
        {"Alice", "secret", 0},
        {"Bob", "password", 0},
        {"Charlie", "123456", 0},
    };

    int chosen_password = -1;

    do {
        printf("Welcome to the Password Manager!\n");

        for (int i = 0; i < MAX_PASSWORDS; i++) {
            printf("Password %d: %s\n", i + 1, passwords[i].password);
        }

        printf("Enter the number of the password you want to access: ");
        scanf("%d", &chosen_password);

        if (chosen_password < 1 || chosen_password > MAX_PASSWORDS) {
            printf("Invalid password number. Please try again.\n");
            continue;
        }

        passwords[chosen_password - 1].attempts++;

        if (passwords[chosen_password - 1].attempts >= MAX_ATTEMPTS) {
            printf("Invalid password. Please try again.\n");
            passwords[chosen_password - 1].attempts = 0;
        }

        printf("Password %d: %s (%d attempt%s remaining)\n",
               chosen_password, passwords[chosen_password - 1].password,
               passwords[chosen_password - 1].attempts,
               passwords[chosen_password - 1].attempts == 1 ? " left" : "s left");

    } while (1);

    return 0;
}