//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main() {
    char password[50];
    printf("Enter a password: ");
    scanf("%s", password);

    int length = strlen(password);
    int upper_case = 0;
    int lower_case = 0;
    int digits = 0;
    int special_chars = 0;

    for(int i=0; i<length; i++) {
        char c = password[i];
        if(c >= 'A' && c <= 'Z') {
            upper_case++;
        } else if(c >= 'a' && c <= 'z') {
            lower_case++;
        } else if(c >= '0' && c <= '9') {
            digits++;
        } else if(c == '#' || c == '@' || c == '!' || c == '$' || c == '%') {
            special_chars++;
        }
    }

    printf("Analyzing password...\n");

    if(length < 8) {
        printf("Insufficient length.\n");
        printf("Please use at least 8 characters for a strong password.\n");
    } else if(upper_case < 1) {
        printf("Lacking uppercase letters.\n");
        printf("Include at least one uppercase letter for a strong password.\n");
    } else if(lower_case < 1) {
        printf("Lacking lowercase letters.\n");
        printf("Include at least one lowercase letter for a strong password.\n");
    } else if(digits < 1) {
        printf("Lacking digits.\n");
        printf("Use at least one digit for a strong password.\n");
    } else if(special_chars < 1) {
        printf("Lacking special characters.\n");
        printf("Use at least one of the following special characters: #, @, !, $, or %% for a strong password.\n");
    } else {
        printf("Password strength is strong.\n");
        printf("You have a strong password. Good job!\n");
    }

    return 0;
}