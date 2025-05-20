//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the password contains atleast one uppercase character
int check_uppercase(char* password) {
    int len = strlen(password);
    for(int i=0; i<len; i++) {
        if(isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains atleast one lowercase character
int check_lowercase(char* password) {
    int len = strlen(password);
    for(int i=0; i<len; i++) {
        if(islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains atleast one digit
int check_digit(char* password) {
    int len = strlen(password);
    for(int i=0; i<len; i++) {
        if(isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains atleast one special character
int check_special(char* password) {
    int len = strlen(password);
    for(int i=0; i<len; i++) {
        if(!isalnum(password[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char password[50];

    printf("Enter the password: ");
    scanf("%s", password);

    int length = strlen(password);
    int score = 0;

    if(length < 8) {
        printf("Password is too short\n");
    } 
    else {
        // Check for different password criteria
        if(check_uppercase(password)) {
            score += 5;
        }
        if(check_lowercase(password)) {
            score += 5;
        }
        if(check_digit(password)) {
            score += 5;
        }
        if(check_special(password)) {
            score += 5;
        }

        // Check if password contains only alphabets or numbers
        if(isalpha(password[0]) && isalpha(password[length-1])) {
            printf("Score: %d (Weak)\n", score);
        }
        else if(isdigit(password[0]) && isdigit(password[length-1])) {
            printf("Score: %d (Weak)\n", score);
        }
        else {
            printf("Score: %d (Strong)\n", score);
        }
    }
    return 0;
}