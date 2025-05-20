//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function declarations
void checkPasswordStrength(const char *password);
void displayPoem(int strength);
void declareLove();

int main() {
    char password[128];

    declareLove();
    
    printf("O fair maiden or noble lord, submit thy password for evaluation:\n");
    printf("Enter your password: ");
    scanf("%s", password);
    
    checkPasswordStrength(password);
    
    return 0;
}

void declareLove() {
    printf("In fair Verona, where we lay our scene,\n");
    printf("A tale of love and passwords, yet unseen.\n\n");
}

void checkPasswordStrength(const char *password) {
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    // Check each character
    for (int i = 0; i < length; ++i) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else if (ispunct(password[i])) hasSpecial = 1;
    }

    // Evaluate strength
    int strength = 0;
    if (length >= 8) strength++;
    if (hasUpper) strength++;
    if (hasLower) strength++;
    if (hasDigit) strength++;
    if (hasSpecial) strength++;

    displayPoem(strength);
}

void displayPoem(int strength) {
    switch (strength) {
        case 0:
        case 1:
            printf("\nAlas! Thy password doth lack, it is weak and frail,\n");
            printf("In the wake of villains, surely it shall fail.\n");
            break;
        case 2:
            printf("\nThough thy password hath some might,\n");
            printf("Its strength is but dim, not worthy of a fight.\n");
            break;
        case 3:
            printf("\nA password bold dost thou present,\n");
            printf("With vigor and valor, all fears circumvent.\n");
            break;
        case 4:
            printf("\nOh, what a password! Stronger than the sword,\n");
            printf("Its mighty presence shall shield thee accord.\n");
            break;
        default:
            printf("\nInvalid strength assessment, alas!\n");
            break;
    }

    printf("In this sonnet of security, verily thou shall heed,\n");
    printf("Let not thy heart nor password falter, lest thee bleed.\n");
    printf("Be steadfast and wise, guard thee from dismay,\n");
    printf("For even in passwords, true love finds its way.\n");
}