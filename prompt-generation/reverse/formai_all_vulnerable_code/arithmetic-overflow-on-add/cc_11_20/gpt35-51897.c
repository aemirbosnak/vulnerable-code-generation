//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int length, upper, lower, digit, special, score = 0;
    char password[50];

    printf("Enter a password: ");
    fgets(password, 50, stdin); //Get password from user
    length = strlen(password) - 1; //Remove newline character from password

    for(int i = 0; i < length; i++){
        if(isupper(password[i]))
            upper++; //Increase upper case counter
        else if(islower(password[i]))
            lower++; //Increase lower case counter
        else if(isdigit(password[i]))
            digit++; //Increase digit counter
        else if(!isalnum(password[i]))
            special++; //Increase special character counter
    }

    if(length < 8){ //Password is too short
        printf("Password must be at least 8 characters long.\n");
    }
    else{
        score += 10; //Add 10 points to score for minimum length
        if(upper > 0)
            score += 10; //Add 10 points for at least one upper case letter
        if(lower > 0)
            score += 10; //Add 10 points for at least one lower case letter
        if(digit > 0)
            score += 10; //Add 10 points for at least one digit
        if(special > 0)
            score += 10; //Add 10 points for at least one special character

        //Determine password strength based on score
        if(score < 30)
            printf("Weak password.\n");
        else if(score < 50)
            printf("Moderate password.\n");
        else if(score < 70)
            printf("Strong password.\n");
        else
            printf("Very strong password.\n");
    }

    return 0;
}