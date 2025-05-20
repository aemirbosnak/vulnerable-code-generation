//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_PASSWORD_LENGTH 20

/* Function to count the number of digits in the password */
int count_digits(char password[]) {
    int count=0;
    for(int i=0;i<strlen(password);i++){
        if(isdigit(password[i])){
            count++;
        }
    }
    return count;
}

/* Function to count the number of upper case letters in the password */
int count_uppercase(char password[]) {
    int count=0;
    for(int i=0;i<strlen(password);i++){
        if(isupper(password[i])){
            count++;
        }
    }
    return count;
}

/* Function to count the number of lower case letters in the password */
int count_lowercase(char password[]) {
    int count=0;
    for(int i=0;i<strlen(password);i++){
        if(islower(password[i])){
            count++;
        }
    }
    return count;
}

/* Function to check if the password contains any special characters */
int check_special(char password[]) {
    for(int i=0;i<strlen(password);i++){
        if(!isdigit(password[i]) && !isalpha(password[i])){
            return 1;
        }
    }
    return 0;
}

/* Main function */
int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length, num_digits, num_upper, num_lower, special;
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);
    num_digits = count_digits(password);
    num_upper = count_uppercase(password);
    num_lower = count_lowercase(password);
    special = check_special(password);
    printf("\nPassword Strength:\n");
    if(length < 8) {
        printf("Password is too short!\n");
    }
    else if(length >= 8 && length <= 10 && (num_lower+num_upper+num_digits)>=8 && special==1) {
        printf("Weak Password\n");
    }
    else if(length >= 8 && length <= 10 && (num_lower+num_upper+num_digits)>=8 && special==0) {
        printf("Moderate Password\n");
    }
    else if(length >= 11 && length <= 15 && (num_lower+num_upper+num_digits)>=10 && special==1){
        printf("Moderate Password\n");
    }
    else if(length >= 11 && length <= 15 && (num_lower+num_upper+num_digits)>=10 && special==0) {
        printf("Strong Password\n");
    }
    else {
        printf("Very Strong Password\n");
    }
    return 0;
}