//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: high level of detail
#include<stdio.h>
#include<string.h>

int main() {
    char password[20]; // Declare the password string array that can store up to 20 characters
    int length, uppercase_count = 0, lowercase_count = 0, digit_count = 0, special_char_count = 0;

    printf("Enter a password: ");
    scanf("%s", password);
    
    length = strlen(password); // Find the length of password

    if (length < 8) { // If length is less than 8 characters
        printf("Password length is too short. Minimum length is 8 characters.\n");
        return 0; // Exit the program
    }

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') { // If character is uppercase
            uppercase_count++;
        } 
        else if (password[i] >= 'a' && password[i] <= 'z') { // If character is lowercase
            lowercase_count++;
        } 
        else if (password[i] >= '0' && password[i] <= '9') { // If character is digit
            digit_count++;
        } 
        else { // If character is special character
            special_char_count++;
        }
    }

    if (uppercase_count < 1) { // If there's no uppercase character
        printf("Password must contain at least one uppercase character.\n");
    }

    if (lowercase_count < 1) { // If there's no lowercase character
        printf("Password must contain at least one lowercase character.\n");
    }

    if (digit_count < 1) { // If there's no digits
        printf("Password must contain at least one digit.\n");
    }

    if (special_char_count < 1) { // If there's no special characters
        printf("Password must contain at least one special character.\n");
    }

    if (uppercase_count >= 1 && lowercase_count >= 1 && digit_count >= 1 && special_char_count >= 1) { // If the password meet all the criteria
        printf("Password is strong!\n");
    }

    return 0; // Exit the program
}