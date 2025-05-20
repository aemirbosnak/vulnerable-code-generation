//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multiplayer
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 25

int check_password_strength(char password[]) {
    int i, len, lower = 0, upper = 0, digit = 0, special = 0;

    len = strlen(password);

    if (len < MIN_PASSWORD_LENGTH || len > MAX_PASSWORD_LENGTH) {
        return 0;
    }

    for (i = 0; i < len; i++) {
        if (islower(password[i])) {
            lower = 1;
        } else if (isupper(password[i])) {
            upper = 1;
        } else if (isdigit(password[i])) {
            digit = 1;
        } else {
            special = 1;
        }
    }

    if (lower + upper + digit + special < 3) {
        return 0;
    }

    return 1;
}

int main() {
    int num_players, i, j;
    char password[MAX_PASSWORD_LENGTH + 1];
    char names[10][MAX_PASSWORD_LENGTH + 1];
    int strengths[10];

    printf("Welcome to the Password Strength Checker!\n");
    printf("How many players are there? ");
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("\nPlayer %d: What is your name? ", i+1);
        scanf("%s", names[i]);

        printf("Hi %s, Please enter your password: ", names[i]);
        scanf("%s", password);

        strengths[i] = check_password_strength(password);

        if (strengths[i] == 1) {
            printf("Congratulations %s, your password is considered strong!\n", names[i]);
        } else {
            printf("Sorry %s, your password is not strong enough. Please try again.\n", names[i]);
        }
    }

    printf("\n\n----------- Password Strength Report -----------\n\n");

    for (i = 0; i < num_players; i++) {
        printf("Player %d: %s\n", i+1, names[i]);

        if (strengths[i] == 1) {
            printf("Password Strength: Strong\n");
        } else {
            printf("Password Strength: Weak\n");
            printf("Password: ");

            for (j = 0; j < strlen(password); j++) {
                printf("*");
            }

            printf("\n");
        }
    }

    return 0;
}