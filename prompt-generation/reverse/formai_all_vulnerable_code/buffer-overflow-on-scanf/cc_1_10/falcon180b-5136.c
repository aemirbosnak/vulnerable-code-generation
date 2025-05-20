//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8
#define NUMBER_OF_RULES 4

void checkPasswordStrength(char* password) {
    int length = strlen(password);
    int score = 0;
    int uppercase = 0;
    int lowercase = 0;
    int numbers = 0;
    int symbols = 0;

    // Check length
    if(length < MIN_PASSWORD_LENGTH) {
        printf("Password is too short.\n");
        return;
    }

    // Check uppercase
    for(int i=0; i<length; i++) {
        if(isupper(password[i])) {
            uppercase = 1;
        }
    }
    if(!uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return;
    }

    // Check lowercase
    for(int i=0; i<length; i++) {
        if(islower(password[i])) {
            lowercase = 1;
        }
    }
    if(!lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return;
    }

    // Check numbers
    for(int i=0; i<length; i++) {
        if(isdigit(password[i])) {
            numbers = 1;
        }
    }
    if(!numbers) {
        printf("Password must contain at least one number.\n");
        return;
    }

    // Check symbols
    for(int i=0; i<length; i++) {
        if(!isalnum(password[i])) {
            symbols = 1;
        }
    }
    if(!symbols) {
        printf("Password must contain at least one symbol.\n");
        return;
    }

    // Calculate score
    score = 0;
    if(uppercase) {
        score++;
    }
    if(lowercase) {
        score++;
    }
    if(numbers) {
        score++;
    }
    if(symbols) {
        score++;
    }

    // Print result
    printf("Password strength: ");
    for(int i=0; i<score; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);
    checkPasswordStrength(password);
    return 0;
}