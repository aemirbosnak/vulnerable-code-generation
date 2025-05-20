//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: genious
#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    int length, upper = 0, lower = 0, digits = 0, symbols = 0, strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for(int i = 0; i < length; i++) {       
        if(password[i] >= 'A' && password[i] <= 'Z') {
            upper++;
        } else if(password[i] >= 'a' && password[i] <= 'z') {
            lower++;
        } else if(password[i] >= '0' && password[i] <= '9') {
            digits++;
        } else {
            symbols++;
        }
    }

    if(length < 8 || upper < 2 || lower < 2 || digits < 2 || symbols < 2) {
        strength = 0;
    } else if (length < 12 || upper < 3 || lower < 3 || digits < 3 || symbols < 3) {
        strength = 1;
    } else if (length < 16) {
        strength = 2;
    } else {
        strength = 3;
    }

    switch(strength) {
        case 0:
            printf("Your password is weak. Please include at least 8 characters, 2 uppercase letters, 2 lowercase letters, 2 digits, and 2 symbols.\n");
            break;
        case 1:
            printf("Your password is moderate but can be improved. Please include at least 12 characters, 3 uppercase letters, 3 lowercase letters, 3 digits, and 3 symbols.\n");
            break;
        case 2:
            printf("Your password is strong but can be improved. Please include at least 16 characters and more symbols, digits, uppercase, and lowercase letters to make it even stronger.\n");
            break;
        case 3:
            printf("Your password is very strong. Good job!\n");
            break;
        default:
            printf("Invalid password. Please enter a valid one.\n");
    }

    return 0;
}