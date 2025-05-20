//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    
    char password[100];
    int length, uppercase_count=0, lowercase_count=0, digit_count=0, special_count=0, strength_score=0;
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);

    for (int i=0; i<length; i++) {
        if (isupper(password[i])) 
            uppercase_count++;
        else if (islower(password[i]))
            lowercase_count++;
        else if (isdigit(password[i]))
            digit_count++;
        else
            special_count++;
    }

    if (length >= 8)
        strength_score++;
    if (uppercase_count > 0)
        strength_score++;
    if (lowercase_count > 0)
        strength_score++;
    if (digit_count > 0)
        strength_score++;
    if (special_count > 0)
        strength_score++;

    printf("Password Strength: ");
    switch(strength_score) {
        case 0:
        case 1:
            printf("Weak\n");
            break;
        case 2:
            printf("Moderate\n");
            break;
        case 3:
        case 4:
            printf("Strong\n");
            break;
        case 5:
            printf("Extremely strong\n");
            break;
        default:
            printf("Error\n");
    }

    return 0;
}