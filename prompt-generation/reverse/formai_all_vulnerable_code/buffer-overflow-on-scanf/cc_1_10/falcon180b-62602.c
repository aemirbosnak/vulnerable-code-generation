//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_PASSWORD_COMPLEXITY 4
#define PASSWORD_COMPLEXITY_LEVELS 3

enum password_complexity {
    LOW,
    MEDIUM,
    HIGH
};

typedef struct {
    char *name;
    enum password_complexity level;
} password_complexity_t;

static password_complexity_t password_complexity_levels[] = {
    {"LOW", LOW},
    {"MEDIUM", MEDIUM},
    {"HIGH", HIGH}
};

static char *password_complexity_strings[] = {
    "abcdefghijklmnopqrstuvwxyz",
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~"
};

static char *generate_password(int length, enum password_complexity complexity) {
    char *password = malloc(length + 1);
    if (password == NULL) {
        fprintf(stderr, "Could not allocate memory for password.\n");
        exit(EXIT_FAILURE);
    }

    char *complexity_string = password_complexity_strings[complexity];
    for (int i = 0; i < length; i++) {
        password[i] = complexity_string[rand() % strlen(complexity_string)];
    }
    password[length] = '\0';

    return password;
}

int main() {
    srand(time(NULL));

    int password_length;
    enum password_complexity password_complexity;

    printf("Enter password length (1-%d): ", MAX_PASSWORD_LENGTH);
    scanf("%d", &password_length);

    printf("Enter password complexity (LOW, MEDIUM, or HIGH): ");
    while (true) {
        char input[100];
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "LOW\n") == 0) {
            password_complexity = LOW;
            break;
        } else if (strcmp(input, "MEDIUM\n") == 0) {
            password_complexity = MEDIUM;
            break;
        } else if (strcmp(input, "HIGH\n") == 0) {
            password_complexity = HIGH;
            break;
        } else {
            printf("Invalid password complexity. Please try again.\n");
        }
    }

    char *password = generate_password(password_length, password_complexity);
    printf("Generated password: %s\n", password);

    free(password);
    return 0;
}