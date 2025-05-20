//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASS_LEN 8 //Minimum length for password
#define MAX_PASS_LEN 20 //Maximum length for password

int main() {
    char password[MAX_PASS_LEN+1]; //+1 for null terminator
    int pass_len; //Length of the password entered
    int i, has_upper=0, has_lower=0, has_digit=0, has_special=0; //Initialize boolean variables
    
    printf("Enter password (between %d and %d characters):\n", MIN_PASS_LEN, MAX_PASS_LEN);
    fgets(password, MAX_PASS_LEN+1, stdin); //Get input from user
    
    //Remove newline character at the end of password
    if(password[strlen(password)-1] == '\n') {
        password[strlen(password)-1] = '\0';
    }
    
    pass_len = strlen(password); //Get actual length of password
    
    //Check if password meets minimum length requirement
    if(pass_len < MIN_PASS_LEN) {
        printf("Password too short. Minimum length is %d characters.\n", MIN_PASS_LEN);
        return 0;
    }
    
    //Check if password exceeds maximum length
    if(pass_len > MAX_PASS_LEN) {
        printf("Password too long. Maximum length is %d characters.\n", MAX_PASS_LEN);
        return 0;
    }
    
    //Iterate through each character of the password to check for required elements
    for(i=0; i<pass_len; i++) {
        if(isupper(password[i])) { //Check for uppercase letter
            has_upper = 1;
        }
        else if(islower(password[i])) { //Check for lowercase letter
            has_lower = 1;
        }
        else if(isdigit(password[i])) { //Check for numeric digit
            has_digit = 1;
        }
        else if(!isalnum(password[i])) { //Check for non-alphanumeric character
            has_special = 1;
        }
    }
    
    //Check if password contains all required elements
    if(has_upper && has_lower && has_digit && has_special) {
        printf("Password meets all requirements.\n");
    }
    else {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one numeric digit, and one special character.\n");
    }
    
    return 0;
}