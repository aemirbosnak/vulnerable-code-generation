//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to check password strength
int password_strength(char *password)
{
    int length = strlen(password); //get length of password
    int upperCount = 0, lowerCount = 0, digitCount = 0, specialCharCount = 0;
    int strength = 0;

    // loop through password characters
    for(int i=0; i<length; i++){
        if(isupper(password[i])){ //check if uppercase character
            upperCount++;
        } else if(islower(password[i])){ //check if lowercase character
            lowerCount++;
        } else if(isdigit(password[i])){ //check if digit
            digitCount++;
        } else { //must be a special character
            specialCharCount++;
        }
    }

    //check for password strength
    if(length < 8) { //if password is less than 8 characters
        printf("Password is too short. Please make it at least 8 characters long.\n");
    } else if(lowerCount == 0){ //if there are no lowercase characters
        printf("Please include at least one lowercase letter in your password.\n");
    } else if(upperCount == 0){ //if there are no uppercase characters
        printf("Please include at least one uppercase letter in your password.\n");
    } else if(digitCount == 0){ //if there are no digits
        printf("Please include at least one digit in your password.\n");
    } else if(specialCharCount == 0){ //if there are no special characters
        printf("Please include at least one special character in your password.\n");
    } else { //password is strong
        printf("Congratulations, your password is strong!\n");
        strength = 1;
    }

    return strength; //return whether password is strong or not
}

int main(){
    char password[50]; //declare password variable

    //ask user to enter password
    printf("Please enter your password:\n");
    scanf("%s", password);

    //check password strength
    int password_strength_result = password_strength(password);

    //if password is not strong, ask user to enter password again
    while (password_strength_result == 0){
        printf("Please enter a stronger password:\n");
        scanf("%s", password);
        password_strength_result = password_strength(password); //check new password strength
    }

    return 0;
}