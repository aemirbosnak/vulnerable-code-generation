//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char password[50];
    int length, upper=0, lower=0, digit=0, special=0, score=0;
    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter your password:\n");
    scanf("%s", password);

    length = strlen(password);
    for(int i=0; i<length; i++){
        if(isupper(password[i])){ // Check for uppercase letters
            upper++;
        }
        else if(islower(password[i])){ // Check for lowercase letters
            lower++;
        }
        else if(isdigit(password[i])){ // Check for digits
            digit++;
        }
        else{ // Check for special characters
            special++;
        }
    }

    // Calculate Password Score
    score += length * 4; // Add points for length
    if(upper > 0){ // Add points for uppercase letters
        score += (length-upper) * 2;
    }
    if(lower > 0){ // Add points for lowercase letters
        score += (length-lower) * 2;
    }
    if(digit > 0){ // Add points for digits
        score += digit * 4;
    }
    if(special > 0){ // Add points for special characters
        score += special * 6;
    }

    printf("\nYour password scored: %d\n", score);
    if(score >= 100){ // Password is very strong
        printf("Your password is very strong! Keep it up!\n");
    }
    else if(score >= 80){ // Password is strong
        printf("Your password is strong, but there is still room for improvement!\n");
    }
    else if(score >= 60){ // Password is ok
        printf("Your password is ok, but you should consider making it stronger!\n");
    }
    else{ // Password is weak
        printf("Your password is weak, please consider making it stronger!\n");
    }

    return 0;
}