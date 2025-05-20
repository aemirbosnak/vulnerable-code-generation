//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_LENGTH 8    // Minimum password length
#define MAX_LENGTH 16   // Maximum password length
#define MIN_DIGITS 2    // Minimum number of digits
#define MIN_UPPER 1    // Minimum number of uppercase letters

/********** Function Prototypes **********/

int check_length(char *password);
int check_digits(char *password);
int check_uppercase(char *password);
int check_lowercase(char *password);
int check_symbols(char *password);

/********** Main Function **********/

int main(){
    char password[MAX_LENGTH+1];    // Password should not exceed MAX_LENGTH characters
    int score = 0;                  // Password strength score

    // Prompt user for password input
    printf("Enter password: ");
    scanf("%s", password);

    // Check password for length, digits, uppercase letters, lowercase letters, and symbols
    score += check_length(password);
    score += check_digits(password);
    score += check_uppercase(password);
    score += check_lowercase(password);
    score += check_symbols(password);

    // Output password strength score
    switch (score) {
        case 0: printf("Password strength: Very Weak\n"); break;
        case 1: printf("Password strength: Weak\n"); break;
        case 2: printf("Password strength: Fair\n"); break;
        case 3: printf("Password strength: Strong\n"); break;
        case 4: printf("Password strength: Very Strong\n"); break;
        default: printf("Error calculating password strength."); break;
    }
    return 0;
}

/********** Sub-Functions **********/

// Function to check password length
int check_length(char *password){
    int length = strlen(password);
    if (length < MIN_LENGTH){
        printf("Password length must be at least %d characters.\n", MIN_LENGTH);
        return 0;
    }
    else if (length > MAX_LENGTH){
        printf("Password length must be at most %d characters.\n", MAX_LENGTH);
        return 0;
    }
    else{
        return 1;
    }
}

// Function to check number of digits in password
int check_digits(char *password){
    int count = 0;
    for (int i = 0; i < strlen(password); i++){
        if (isdigit(password[i])){
            count++;
        }
    }
    if (count < MIN_DIGITS){
        printf("Password must contain at least %d digits.\n", MIN_DIGITS);
        return 0;
    }
    else{
        return 1;
    }
}

// Function to check number of uppercase letters in password
int check_uppercase(char *password){
    int count = 0;
    for (int i = 0; i < strlen(password); i++){
        if (isupper(password[i])){
            count++;
        }
    }
    if (count < MIN_UPPER){
        printf("Password must contain at least %d uppercase letters.\n", MIN_UPPER);
        return 0;
    }
    else{
        return 1;
    }
}

// Function to check number of lowercase letters in password
int check_lowercase(char *password){
    int count = 0;
    for (int i = 0; i < strlen(password); i++){
        if (islower(password[i])){
            count++;
        }
    }
    if (count == strlen(password)){
        printf("Password must contain at least 1 uppercase letter.\n");
        return 0;
    }
    else{
        return 1;
    }
}

// Function to check for symbols in password
int check_symbols(char *password){
    int count = 0;
    for (int i = 0; i < strlen(password); i++){
        if (!isalnum(password[i])){
            count++;
        }
    }
    if (count == strlen(password)){
        printf("Password must contain at least 1 symbol.\n");
        return 0;
    }
    else{
        return 1;
    }
}