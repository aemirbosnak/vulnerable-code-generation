//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: systematic
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

/*
* Function that checks if the password contains alphabets
*/

bool containsAlphabets(char* password) {
    for(int i = 0; i < strlen(password); i++) {
        if(isalpha(password[i])) {
            return true;
        }
    }
    return false;
}

/*
* Function that checks if the password contains digits
*/

bool containsDigits(char* password) {
    for(int i = 0; i < strlen(password); i++) {
        if(isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

/*
* Function that checks if the password contains special characters
*/

bool containsSpecialCharacters(char* password) {
    for(int i = 0; i < strlen(password); i++) {
        if(!isalpha(password[i]) && !isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

/*
 * Function that checks if the password is too short or too long
 */

bool isLengthValid(char* password) {
    if(strlen(password)<8 || strlen(password)>20) {
        return false;
    }
    return true;
}

/*
 * Function to check the strength of the password
 */

char* checkPasswordStrength(char* password) {
    bool alphabets = containsAlphabets(password);
    bool digits = containsDigits(password);
    bool specialCharacters = containsSpecialCharacters(password);
    bool lengthValid = isLengthValid(password);
    
    if(lengthValid==false) {
        return "Password length should be between 8 and 20 characters";
    }
    if(alphabets==false) {
        return "Password must contain alphabets";
    }   
    if(digits==false) {
        return "Password must contain digits";
    }   
    if(specialCharacters==false) {
        return "Password must contain special characters";
    }
    
    return "Password is strong";
}

/*
 * Main function to run the program
 */

int main() {
    char password[100];
    
    printf("Enter a password to check its strength: ");
    scanf("%s", password);
    
    char* result = checkPasswordStrength(password);
    
    printf("%s\n", result);
    
    return 0;
}