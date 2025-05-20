//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: high level of detail
#include <stdio.h> 

int main() 
{ 
    char password[50];  // Declare a character array to store password
    int hasUppercase = 0;  // Declare a variable to check if there's at least one uppercase letter
    int hasLowercase = 0;  // Declare a variable to check if there's at least one lowercase letter
    int hasDigit = 0;  // Declare a variable to check if there's at least one digit
    int hasSpecialChar = 0;  // Declare a variable to check if there's at least one special character
    int length = 0;  // Declare a variable to store length of password

    // Ask for user input
    printf("Enter password: "); 
    scanf("%s", password); 

    // Calculate length of password
    length = strlen(password);

    // Check if password meets length requirement
    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 1;  // Program exits with error code 1
    }

    // Check for different character types in password
    for (int i = 0; i < length; i++) {
        if (isupper(password[i]))
            hasUppercase = 1;
        else if (islower(password[i]))
            hasLowercase = 1;
        else if (isdigit(password[i]))
            hasDigit = 1;
        else if (!isalnum(password[i]))
            hasSpecialChar = 1;
    }

    // Check if password meets complexity requirements
    if (hasUppercase == 0) {
        printf("Password must contain at least one uppercase letter.\n");
        return 1;  // Program exits with error code 1
    }
    else if (hasLowercase == 0) {
        printf("Password must contain at least one lowercase letter.\n");
        return 1;  // Program exits with error code 1
    }
    else if (hasDigit == 0) {
        printf("Password must contain at least one digit.\n");
        return 1;  // Program exits with error code 1
    }
    else if (hasSpecialChar == 0) {
        printf("Password must contain at least one special character.\n");
        return 1;  // Program exits with error code 1
    }

    // Password meets all requirements
    printf("Password meets all requirements.\n");

    return 0;  // Program exits with success code 0
}