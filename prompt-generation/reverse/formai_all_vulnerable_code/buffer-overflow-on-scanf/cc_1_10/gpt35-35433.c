//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to check if the password meets the criteria
int passwordStrengthChecker(char *password){

    // count variables for different character types
    int upperCount = 0;
    int lowerCount = 0;
    int digitCount = 0;
    int specialCount = 0;

    // check each character in the password
    for(int i=0; i<strlen(password); i++) {

        // check if the character is a uppercase letter
        if(isupper(password[i])) {
            upperCount++;
        }

        // check if the character is a lowercase letter
        if(islower(password[i])) {
            lowerCount++;
        }

        // check if the character is a digit
        if(isdigit(password[i])) {
            digitCount++;
        }

        // check if the character is a special character
        if(!isalnum(password[i])) {
            specialCount++;
        }
    }

    // calculate the total score for the password based on the criteria
    int totalScore = (upperCount * 2) + (lowerCount * 2) + (digitCount * 3) + (specialCount * 5);

    // check if the password meets the minimum score for strength
    if(totalScore >= 25) {
        return 1;
    } else {
        return 0;
    }
}

int main(){
    char password[100];

    printf("Enter your new password: ");
    scanf("%s", password);

    // check the strength of the password
    int isStrong = passwordStrengthChecker(password);

    // output appropriate message based on the result
    if(isStrong){
        printf("Your new password is strong!\n");
    } else {
        printf("Your new password does not meet the required strength criteria. Please try again.\n");
    }

    return 0;
}