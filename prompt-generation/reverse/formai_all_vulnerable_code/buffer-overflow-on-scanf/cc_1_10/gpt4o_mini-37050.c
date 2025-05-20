//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

void print_welcome_message() {
    printf("=========================================\n");
    printf("      Welcome to the Password Vault     \n");
    printf("=========================================\n");
    printf("In a world where data breaches lurk,\n");
    printf("Your password is your strongest shield.\n");
    printf("Let us craft a formidable password today!\n\n");
}

void print_strength_feedback(int strength) {
    switch(strength) {
        case 0:
            printf("Your password is very weak. Try again!\n");
            break;
        case 1:
            printf("Your password is weak. Consider adding more variety.\n");
            break;
        case 2:
            printf("Your password is medium strength. It could be stronger!\n");
            break;
        case 3:
            printf("Your password is strong! Well done!\n");
            break;
        case 4:
            printf("Your password is very strong! You are a true guardian of your secrets!\n");
            break;
    }
}

int check_password_strength(const char* password) {
    int length = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        return 0; // Very weak
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) has_upper = 1;
        else if (islower(password[i])) has_lower = 1;
        else if (isdigit(password[i])) has_digit = 1;
        else if (ispunct(password[i])) has_special = 1;
    }

    int strength = 0;
    if (has_upper) strength++;
    if (has_lower) strength++;
    if (has_digit) strength++;
    if (has_special) strength++;

    return strength; // Return 0-4 based on the strength criteria
}

int main() {
    char password[100];

    print_welcome_message();

    printf("Enter your new password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);
    print_strength_feedback(strength);

    printf("\nRemember, a strong password is your first line of defense in this digital world. \n");
    printf("Keep it safe, and may your secrets remain yours!\n");

    return 0;
}