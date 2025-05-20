//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PASS_LENGTH 255

typedef struct Password {
    char *password;
    int strength;
} Password;

int main() {
    char password[MAX_PASS_LENGTH];
    int pass_length;
    Password password_obj;

    printf("Welcome to the Mystical Password Oracle!\n");
    printf("Please enter your desired password: ");

    pass_length = getpass(password);

    password_obj.password = malloc(pass_length + 1);
    strcpy(password_obj.password, password);

    password_obj.strength = calculate_password_strength(password_obj.password);

    switch (password_obj.strength) {
        case 0:
            printf("Your password is as weak as a spider's web.\n");
            break;
        case 1:
            printf("Your password is as strong as a bicycle lock.\n");
            break;
        case 2:
            printf("Your password is as secure as a fortress.\n");
            break;
        case 3:
            printf("Your password is as impenetrable as a dragon's hoard.\n");
            break;
        default:
            printf("Error: Invalid password strength.\n");
            break;
    }

    free(password_obj.password);

    return 0;
}

int calculate_password_strength(char *password) {
    int strength = 0;
    int i;

    for (i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i]) || islower(password[i]) || isdigit(password[i]) || password[i] == '$') {
            strength++;
        }
    }

    return strength;
}