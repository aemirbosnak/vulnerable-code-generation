//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: cheerful
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main() {
    char password[MAX_LENGTH];
    int length, i;
    
    printf("Welcome to the Password Strength Checker!\n");
    printf("Enter your password: ");
    scanf("%s", password);
    
    length = strlen(password);
    
    if (length < 8) {
        printf("Sorry, your password must be at least 8 characters long.\n");
        return 1;
    }
    
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special = 0;
    
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        }
        else if (islower(password[i])) {
            has_lowercase = 1;
        }
        else if (isdigit(password[i])) {
            has_number = 1;
        }
        else {
            has_special = 1;
        }
    }
    
    if (!has_uppercase ||!has_lowercase ||!has_number ||!has_special) {
        printf("Sorry, your password must contain at least one uppercase letter, one lowercase letter, one number, and one special character.\n");
        return 1;
    }
    
    printf("Congratulations, your password is strong!\n");
    return 0;
}