//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

void generate_random_password(char *password, const int length);

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length;

    printf("Enter password length (between %d-%d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &length);

    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid length. Password length should be between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return -1;
    }

    generate_random_password(password, length);
    printf("Generated password: %s\n", password);

    return 0;
}

void generate_random_password(char *password, const int length) {
    int i, random_char;
    srand(time(NULL));

    for (i = 0; i < length; i++) {
        // Randomization for uppercase, lowercase, digits and special characters in the password.
        random_char = rand() % 4;

        switch (random_char) {
            case 0:
                password[i] = 'A' + rand() % 26; // uppercase letter
                break;
            case 1:
                password[i] = 'a' + rand() % 26; // lowercase letter
                break;
            case 2:
                password[i] = '0' + rand() % 10; // digit
                break;
            case 3:
                switch (rand() % 4) {
                    case 0:
                        password[i] = '!';
                        break;
                    case 1:
                        password[i] = '@';
                        break;
                    case 2:
                        password[i] = '#';
                        break;
                    case 3:
                        password[i] = '$';
                        break;
                }
                break;
        }
    }

    password[length] = '\0';
}