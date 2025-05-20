//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8

int main() {
    char password[100];
    int length, upper_case, lower_case, digits, special_chars, strength = 0;
    
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);
    
    if (length < MIN_PASSWORD_LENGTH) {
        printf("Password is too short. Minimum length should be %d\n", MIN_PASSWORD_LENGTH);
        return 1;   // exit with error
    }
    
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper_case++;
        }
        else if (islower(password[i])) {
            lower_case++;
        }
        else if (isdigit(password[i])) {
            digits++;
        }
        else {
            special_chars++;
        }
    }
    
    if (upper_case > 0) strength++;
    if (lower_case > 0) strength++;
    if (digits > 0) strength++;
    if (special_chars > 0) strength++;
    
    printf("Password strength: ");
    
    switch (strength) {
        case 1:
            printf("Weak");
            break;
        case 2:
            printf("Moderate");
            break;
        case 3:
            printf("Strong");
            break;
        case 4:
            printf("Very Strong");
            break;
    }
    
    return 0;   // exit successfully
}