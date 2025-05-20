//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
int countLowerCase(char* password);
int countUpperCase(char* password);
int countDigits(char* password);
int countSpecialChar(char* password);

int main(){

    char password[50];
    int length, upperCaseCount = 0, lowerCaseCount = 0, digitCount = 0, specialCharCount = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    if (length < 8){
        printf("Password length must be atleast 8 characters long\n");
    }
    else {
        lowerCaseCount = countLowerCase(password);
        upperCaseCount = countUpperCase(password);
        digitCount = countDigits(password);
        specialCharCount = countSpecialChar(password);

        if (lowerCaseCount == 0){
            printf("Password must contain atleast one lowercase letter\n");
        }

        if (upperCaseCount == 0){
            printf("Password must contain atleast one uppercase letter\n");
        }

        if (digitCount == 0){
            printf("Password must contain atleast one digit\n");
        }

        if (specialCharCount == 0){
            printf("Password must contain atleast one special character\n");
        }

        if (lowerCaseCount > 0 && upperCaseCount > 0 && digitCount > 0 && specialCharCount > 0){
            printf("Password is strong!\n");
        }
    }

    return 0;
}

// Function to count number of lowercase characters in a string
int countLowerCase(char* password){
    int i, count = 0;

    for (i = 0; i < strlen(password); i++){
        if (islower(password[i])){
            count++;
        }
    }

    return count;
}

// Function to count number of uppercase characters in a string
int countUpperCase(char* password){
    int i, count = 0;

    for (i = 0; i < strlen(password); i++){
        if (isupper(password[i])){
            count++;
        }
    }

    return count;
}

// Function to count number of digits in a string
int countDigits(char* password){
    int i, count = 0;

    for (i = 0; i < strlen(password); i++){
        if (isdigit(password[i])){
            count++;
        }
    }

    return count;
}

// Function to count number of special characters in a string
int countSpecialChar(char* password){
    int i, count = 0;

    for (i = 0; i < strlen(password); i++){
        if (!isalnum(password[i])){
            count++;
        }
    }

    return count;
}