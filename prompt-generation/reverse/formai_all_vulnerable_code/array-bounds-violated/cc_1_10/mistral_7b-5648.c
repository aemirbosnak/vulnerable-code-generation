//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_TRIES 3
#define PATTERN_SIZE 5

// Function prototypes
int check_length(char *password);
int check_complexity(char *password);
int check_pattern(char *password);
void print_hint(void);

int main() {
    char password[MIN_LENGTH + 1];
    int tries = 0;

    srand(time(NULL));

    printf("Welcome to Zorg's Enchanted Password Puzzler!\n");
    print_hint();

    while (strcmp(password, "zorg") != 0 && tries < MAX_TRIES) {
        printf("\nPlease enter your password: ");
        fgets(password, sizeof(password), stdin);

        password[strcspn(password, "\n")] = '\0';

        int strength = 0;
        int length_ok = check_length(password);
        int complexity_ok = check_complexity(password);
        int pattern_ok = check_pattern(password);

        if (length_ok && complexity_ok && pattern_ok) {
            strength = 3;
            printf("\nCongratulations! Your password is strong.\n");
        } else {
            tries++;
            if (tries < MAX_TRIES) {
                printf("\nPassword not strong enough. Please try again.\n");
            } else {
                printf("\nSorry, you have reached the maximum number of tries.\n");
            }
        }

        if (strength > 0) {
            printf("Strength: %s\n", (strength == 3) ? "Strong" : "Moderate");
        }
    }

    return 0;
}

int check_length(char *password) {
    if (strlen(password) < MIN_LENGTH) {
        return 0;
    }

    return 1;
}

int check_complexity(char *password) {
    int complexity = 0;

    int uppercase = 0, lowercase = 0, digit = 0, special = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) {
            uppercase++;
        } else if (islower(password[i])) {
            lowercase++;
        } else if (isdigit(password[i])) {
            digit++;
        } else {
            special++;
        }
    }

    if (uppercase > 0 && lowercase > 0 && digit > 0 && special > 0) {
        complexity = 3;
    } else if (uppercase > 0 || lowercase > 0 || digit > 0 || special > 0) {
        complexity = 2;
    }

    return complexity;
}

int check_pattern(char *password) {
    char pattern[PATTERN_SIZE];

    for (int i = 0; i < PATTERN_SIZE; i++) {
        pattern[i] = '?' + rand() % 26;
    }

    int pattern_found = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] == pattern[password[i] % PATTERN_SIZE]) {
            pattern_found = 1;
            break;
        }
    }

    return pattern_found;
}

void print_hint() {
    printf("\nHint: A strong password contains at least one uppercase letter,\n");
    printf("      at least one lowercase letter,\n");
    printf("      at least one digit,\n");
    printf("      and at least one special character!\n");
    printf("      Additionally, avoid using common words or phrases.\n");
}