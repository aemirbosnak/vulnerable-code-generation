//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to check if a character is a digit
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// function to check if a character is a letter
int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// function to check if a character is a special character
int is_special(char c) {
    return !is_digit(c) && !is_letter(c);
}

// function to calculate the entropy of the password
double entropy(char* password, int len) {
    double H = 0.0;
    int count[256] = {0};
    
    for(int i = 0; i < len; i++) {
        count[(int)password[i]]++;
    }
    
    for(int i = 0; i < 256; i++) {
        if(count[i] > 0) {
            double p = (double)count[i] / len;
            H -= p * log2(p);
        }
    }
    
    return H;
}

// main function
int main() {
    
    // get password input from user
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    
    int len = strlen(password);
    int digits = 0;
    int letters = 0;
    int uppercase = 0;
    int lowercase = 0;
    int specials = 0;
    
    // count the number of digits, letters, uppercase letters, lowercase letters, and special characters
    for(int i = 0; i < len; i++) {
        if(is_digit(password[i])) {
            digits++;
        }
        if(is_letter(password[i])) {
            letters++;
            if(isupper(password[i])) {
                uppercase++;
            }
            if(islower(password[i])) {
                lowercase++;
            }
        }
        if(is_special(password[i])) {
            specials++;
        }
    }
    
    // calculate the entropy of the password
    double H = entropy(password, len);

    // output the results of the password strength checker
    printf("Password length: %d\n", len);
    printf("Number of digits: %d\n", digits);
    printf("Number of letters: %d\n", letters);
    printf("Number of uppercase letters: %d\n", uppercase);
    printf("Number of lowercase letters: %d\n", lowercase);
    printf("Number of special characters: %d\n", specials);
    printf("Password entropy: %.2f bits\n", H);

    // determine the strength of the password based on its entropy
    if(H < 18) {
        printf("Weak password\n");
    }
    else if(H < 30) {
        printf("Moderate password\n");
    }
    else {
        printf("Strong password\n");
    }
    
    return 0;
}