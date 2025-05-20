//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20

void check_password_strength(char* password);

int main() {
    char password[MAX_LENGTH];
    
    printf("Enter your password: ");
    scanf("%s", password);

    check_password_strength(password);

    return 0;
}

void check_password_strength(char* password) {
    int length = strlen(password);
    
    if (length < 8) {
        printf("Weak: Password must be at least 8 characters long.\n");
        return;
    }
    
    int num_uppercase = 0;
    int num_lowercase = 0;
    int num_digits = 0;
    int num_special = 0;
    
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            num_uppercase++;
        } else if (islower(password[i])) {
            num_lowercase++;
        } else if (isdigit(password[i])) {
            num_digits++;
        } else if (isalpha(password[i])) {
            num_special++;
        }
    }
    
    if (num_uppercase < 1 || num_lowercase < 1 || num_digits < 1 || num_special < 1) {
        printf("Weak: Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        return;
    }
    
    printf("Strong: Password is strong enough.\n");
}