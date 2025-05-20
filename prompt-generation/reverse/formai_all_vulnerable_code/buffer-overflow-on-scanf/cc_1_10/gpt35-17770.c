//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char password[100]; // array to store password
    int length, uppercase = 0, lowercase = 0, digit = 0, special = 0; // variables to store password qualities
    int i; // counter variable for loops
 
    // get password input from user
    printf("Enter Password: ");
    scanf("%s", password);
 
    length = strlen(password); // get length of password
        
    if (length < 8) { // password length must be at least 8 characters
        printf("Password must be at least 8 characters long.\n");
        exit(EXIT_FAILURE);
    }
    
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) { // check for uppercase characters
            uppercase++;
        }
        else if (islower(password[i])) { // check for lowercase characters
            lowercase++;
        }
        else if (isdigit(password[i])) { // check for digits
            digit++;
        }
        else { // check for special characters
            special++;
        }
    }
    
    // password must contain at least one uppercase and one lowercase letter
    if (uppercase == 0 || lowercase == 0) {
        printf("Password must contain at least one uppercase and one lowercase letter.\n");
        exit(EXIT_FAILURE);
    }
    
    // password must contain at least one digit and one special character
    if (digit == 0 || special == 0) {
        printf("Password must contain at least one digit and one special character.\n");
        exit(EXIT_FAILURE);
    }
    
    // password is strong
    printf("Password is strong!\n");
    return 0;
}