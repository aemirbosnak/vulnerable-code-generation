//FormAI DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// define maximum number of attempts for creating password
#define MAX_ATTEMPTS 3

// function to check if entered password is strong or not
int isPasswordValid(char* password) {
    int isUpper = 0, isLower = 0, isDigit = 0, isSpecial = 0;
    int len = strlen(password);
    for(int i=0;i<len;i++) {
        if(password[i]>='A' && password[i]<='Z') isUpper = 1;
        else if(password[i]>='a' && password[i]<='z') isLower = 1;
        else if(password[i]>='0' && password[i]<='9') isDigit = 1;
        else isSpecial = 1;
    }
    return (len>=8 && isUpper && isLower && isDigit && isSpecial); // return 1 if password is strong
}

int main() {
    // define file pointer
    FILE *fptr;
    // open file for writing passwords
    fptr = fopen("passwords.txt", "a");
    if(fptr == NULL) {
        printf("Unable to create file!\n");
        exit(1);
    }

    // define variables to store user inputs
    char username[50], password[50], confirmPassword[50];
    // variable to keep track of number of attempts
    int attempts = 0;
    // flag to keep track if the passwords match
    int isMatch = 0;

    // get username and password from user input
    printf("Enter username: ");
    scanf("%s", username);
    while(attempts<MAX_ATTEMPTS) {
        printf("Enter a password (must be at least 8 characters and contain at least one uppercase letter, one lowercase letter, one digit, and one special character): ");
        scanf("%s", password);
        printf("Confirm password: ");
        scanf("%s", confirmPassword);
        if(strcmp(password, confirmPassword) == 0) {
            if(isPasswordValid(password)) {
                fprintf(fptr, "%s %s\n", username, password); // save username and password to file
                printf("Password saved successfully!\n");
                isMatch = 1;
                break;
            } else {
                printf("Invalid password! Please try again.\n");
            }
        } else {
            printf("Passwords entered do not match! Please try again.\n");
        }
        attempts++;
    }
    if(!isMatch) printf("Maximum number of attempts reached. Password not saved.\n");

    // close file pointer
    fclose(fptr);

    return 0;
}