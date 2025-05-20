//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_password_strength(char* password);

int main(void) {
    char password[100];
    int strength;

    printf("Enter your password: ");
    scanf("%s", password);

    strength = check_password_strength(password);

    switch(strength) {
        case 0: 
            printf("\nYour password is weak\n");
            break;
        case 1:
            printf("\nYour password is moderate\n");
            break;
        case 2:
            printf("\nYour password is strong\n");
            break;
        default:
            printf("\nInvalid password\n");
    }
    
    return 0;
}

int check_password_strength(char* password) {
    int length = strlen(password), lowercase = 0, uppercase = 0, digit = 0, special = 0;

    if(length < 8) {
        return 0; // weak password
    }

    for(int i = 0; i < length; i++) {
        if(islower(password[i])) {
            lowercase++;
        } else if(isupper(password[i])) {
            uppercase++;
        } else if(isdigit(password[i])) {
            digit++;
        } else {
            special++;
        }
    }

    if(lowercase > 0 && uppercase > 0 && digit > 0 && special > 0) {
        return 2; // strong password
    } else if(lowercase > 0 && uppercase > 0 && digit > 0) {
        return 1; // moderate password
    } else {
        return 0; // weak password
    }
}