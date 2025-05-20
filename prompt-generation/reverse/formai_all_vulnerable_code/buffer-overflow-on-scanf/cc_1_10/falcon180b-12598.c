//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 32

// Function prototypes
void generate_password(char *password, int length);
int is_valid_password(const char *password);

int main() {
    char password[PASSWORD_MAX_LENGTH + 1] = {0};
    int length = 0;

    // Prompt user for password length
    while (length < PASSWORD_MIN_LENGTH || length > PASSWORD_MAX_LENGTH) {
        printf("Enter password length (between %d and %d): ", PASSWORD_MIN_LENGTH, PASSWORD_MAX_LENGTH);
        scanf("%d", &length);
    }

    // Generate password
    generate_password(password, length);

    // Print password
    printf("Your password is: %s\n", password);

    return 0;
}

void generate_password(char *password, int length) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+~`|}{[]\:;?><,./-=";
    int chars_length = strlen(chars);

    // Initialize password with random characters
    for (int i = 0; i < length; ++i) {
        password[i] = chars[rand() % chars_length];
    }

    // Shuffle password
    for (int i = 0; i < length; ++i) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

int is_valid_password(const char *password) {
    const int MIN_LOWER = 1;
    const int MIN_UPPER = 1;
    const int MIN_DIGIT = 1;
    const int MIN_SPECIAL = 1;

    int lower = 0;
    int upper = 0;
    int digit = 0;
    int special = 0;

    for (int i = 0; i < strlen(password); ++i) {
        if (isalnum(password[i])) {
            if (isupper(password[i])) {
                upper = 1;
            } else if (islower(password[i])) {
                lower = 1;
            }
        } else if (isdigit(password[i])) {
            digit = 1;
        } else {
            special = 1;
        }
    }

    return lower && upper && digit && special;
}