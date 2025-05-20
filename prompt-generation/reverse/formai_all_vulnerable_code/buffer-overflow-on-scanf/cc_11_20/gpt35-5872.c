//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: immersive
#include <stdio.h>
#include <string.h>

/* Function to check the strength of the password */
int check_strength(char password[]) {
    int length = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    
    /* Iterate through the password and check for its strength */
    for(int i = 0; i < length; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            has_upper = 1;
        }
        if(password[i] >= 'a' && password[i] <= 'z') {
            has_lower = 1;
        }
        if(password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
        }
        if((password[i] >= '!' && password[i] <= '/') ||
           (password[i] >= ':' && password[i] <= '@') ||
           (password[i] >= '[' && password[i] <= '`') ||
           (password[i] >= '{' && password[i] <= '~')) {
            has_special = 1;
        }
    }
    
    /* Check the strength of the password based on the conditions */
    if(length < 8) {
        return 0;
    }
    else if(length >= 8 && length <= 12) {
        if(has_upper && has_lower && has_digit) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if(has_upper && has_lower && has_digit && has_special) {
            return 2;
        }
        else {
            return 1;
        }
    }
}

/* Main function to test the password strength checker */
int main() {
    char password[50];
    int strength;
    
    /* Take the input from the user */
    printf("Enter the password: ");
    scanf("%s", password);
    
    /* Check the strength and display the appropriate message */
    strength = check_strength(password);
    if(strength == 0) {
        printf("Password is weak. It should be of minimum 8 characters.\n");
    }
    else if(strength == 1) {
        printf("Password is moderate. It should contain atleast one uppercase character, one lowercase character and one digit.\n");
    }
    else {
        printf("Password is strong. It should contain atleast one uppercase character, one lowercase character, one digit and one special character.\n");
    }
    
    return 0;
}