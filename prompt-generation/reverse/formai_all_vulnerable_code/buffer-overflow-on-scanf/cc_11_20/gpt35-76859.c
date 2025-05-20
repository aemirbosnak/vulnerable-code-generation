//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: introspective
// C Password Strength Checker

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, lowercase = 0, uppercase = 0, numbers = 0, symbols = 0, strength = 0;
    
    printf("Enter the password: ");
    scanf("%s", password);
    
    length = strlen(password);
    
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
        }
        else if (isupper(password[i])) {
            uppercase = 1;
        }
        else if (isdigit(password[i])) {
            numbers = 1;
        }
        else {
            symbols = 1;
        }
    }
    
    if (length < 8) {
        strength = 1;
    }
    else if (length < 12) {
        strength = 2;
    }
    else {
        strength = 3;
    }
    
    if (lowercase == 1 && uppercase == 1 && numbers == 1 && symbols == 1) {
        strength++;
    }
    
    switch (strength) {
        case 1:
            printf("The password strength is weak\n");
            break;
        case 2:
            printf("The password strength is moderate\n");
            break;
        case 3:
            printf("The password strength is strong\n");
            break;
        case 4:
            printf("The password strength is very strong\n");
            break;
        default:
            printf("Invalid Password\n");
    }
    
    return 0;
}