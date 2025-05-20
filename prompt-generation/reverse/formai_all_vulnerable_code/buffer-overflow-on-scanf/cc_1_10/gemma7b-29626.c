//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PASS_LENGTH 255

typedef struct {
    int strength;
    char message[256];
} password_strength_t;

password_strength_t check_password_strength(char *password) {
    password_strength_t strength_info;
    strength_info.strength = 0;
    strength_info.message[0] = '\0';

    if (strlen(password) < 8) {
        strcat(strength_info.message, "Password too short. ");
    } else if (strlen(password) > MAX_PASS_LENGTH) {
        strcat(strength_info.message, "Password too long. ");
    }

    if (!isalnum(password[0])) {
        strcat(strength_info.message, "Password must start with an alphanumeric character. ");
    }

    int has_number = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            has_number = 1;
        }
    }

    if (!has_number) {
        strcat(strength_info.message, "Password lacks numbers. ");
    }

    int has_special_character = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (ispunct(password[i])) {
            has_special_character = 1;
        }
    }

    if (!has_special_character) {
        strcat(strength_info.message, "Password lacks special characters. ");
    }

    switch (strength_info.strength) {
        case 0:
            strcat(strength_info.message, "Weak");
            break;
        case 1:
            strcat(strength_info.message, "Fair");
            break;
        case 2:
            strcat(strength_info.message, "Good");
            break;
        case 3:
            strcat(strength_info.message, "Strong");
            break;
    }

    return strength_info;
}

int main() {
    char password[MAX_PASS_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    password_strength_t strength_info = check_password_strength(password);

    printf("Password strength: %s\n", strength_info.message);

    return 0;
}