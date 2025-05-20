//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, i;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check for minimum length
    if (length < 8) {
        printf("Weak: Password must be at least 8 characters long.\n");
        return 0;
    }

    // Check for uppercase letters
    int has_uppercase = 0;
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }
    if (!has_uppercase) {
        printf("Weak: Password must contain at least one uppercase letter.\n");
        return 0;
    }

    // Check for lowercase letters
    int has_lowercase = 0;
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }
    if (!has_lowercase) {
        printf("Weak: Password must contain at least one lowercase letter.\n");
        return 0;
    }

    // Check for numbers
    int has_number = 0;
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_number = 1;
            break;
        }
    }
    if (!has_number) {
        printf("Weak: Password must contain at least one number.\n");
        return 0;
    }

    // Check for special characters
    int has_special = 0;
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special = 1;
            break;
        }
    }
    if (!has_special) {
        printf("Weak: Password must contain at least one special character.\n");
        return 0;
    }

    // Check for dictionary words
    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 0;
    }
    char word[100];
    while (fscanf(dictionary, "%s", word)!= EOF) {
        if (strcmp(password, word) == 0) {
            printf("Weak: Password is a common dictionary word.\n");
            fclose(dictionary);
            return 0;
        }
    }
    fclose(dictionary);

    // Password is strong
    printf("Strong: Your password is strong.\n");
    return 0;
}