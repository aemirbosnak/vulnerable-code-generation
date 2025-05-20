//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8

#define LOWER_CASE_LETTERS "abcdefghijklmnopqrstuvwxyz"
#define UPPER_CASE_LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "0123456789"
#define SPECIAL_CHARACTERS "!@#$%^&*()_+-=[]{}|;:,.<>/?`~"

int main() {
    char password[MAX_PASSWORD_LENGTH+1];
    int length;
    int lowercase_count = 0;
    int uppercase_count = 0;
    int number_count = 0;
    int special_character_count = 0;

    srand(time(NULL));

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < MIN_PASSWORD_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
        return 1;
    }

    for (int i = 0; i < length; i++) {
        if (isalpha(password[i])) {
            if (islower(password[i])) {
                lowercase_count++;
            } else if (isupper(password[i])) {
                uppercase_count++;
            }
        } else if (isdigit(password[i])) {
            number_count++;
        } else if (strchr(SPECIAL_CHARACTERS, password[i])!= NULL) {
            special_character_count++;
        }
    }

    if (lowercase_count + uppercase_count + number_count + special_character_count <= 1) {
        printf("Password must contain at least two of the following: lowercase letter, uppercase letter, number, or special character.\n");
        return 1;
    }

    printf("Password strength: ");
    if (lowercase_count + uppercase_count + number_count + special_character_count == 2) {
        printf("Weak\n");
    } else if (lowercase_count + uppercase_count + number_count + special_character_count == 3) {
        printf("Moderate\n");
    } else {
        printf("Strong\n");
    }

    return 0;
}