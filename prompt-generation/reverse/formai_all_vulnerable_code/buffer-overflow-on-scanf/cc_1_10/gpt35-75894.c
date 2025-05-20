//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mind-bending
#include<stdio.h>
#include<string.h>

// Function to check the password strength
int check_password_strength(char* password){

    int length = strlen(password);
    int score = 0;
    int lower_count = 0;
    int upper_count = 0;
    int digit_count = 0;
    int special_count = 0;

    // Loop through the password to check for different characters
    for(int i = 0; i < length; i++){

        // Check for lowercase characters
        if(password[i] >= 'a' && password[i] <= 'z'){
            lower_count++;
        }
        // Check for uppercase characters
        else if(password[i] >= 'A' && password[i] <= 'Z'){
            upper_count++;
        }
        // Check for digits
        else if(password[i] >= '0' && password[i] <= '9'){
            digit_count++;
        }
        // Check for special characters
        else{
            special_count++;
        }

    }

    // Calculate the score based on the number and types of characters
    score = length*10 + lower_count*5 + upper_count*5 + digit_count*10 + special_count*15;

    // Return the password strength score
    return score;

}

int main(){

    char password[100];

    // Get password from the user
    printf("Enter the password to check its strength: ");
    scanf("%s", password);

    // Check the password strength
    int strength_score = check_password_strength(password);

    // Check if the password is very weak
    if(strength_score < 50){
        printf("\nYour password is very weak! Try again with a stronger password.\n");
    }
    // Check if the password is weak
    else if(strength_score >= 50 && strength_score < 100){
        printf("\nYour password is weak. Try adding some numbers and special characters to make it stronger.\n");
    }
    // Check if the password is moderate
    else if(strength_score >= 100 && strength_score < 200){
        printf("\nYour password is moderate. Try adding some uppercase letters and special characters to make it stronger.\n");
    }
    // Check if the password is strong
    else if(strength_score >= 200 && strength_score < 300){
        printf("\nYour password is strong. Keep it up!\n");
    }
    // Check if the password is very strong
    else{
        printf("\nYour password is very strong! Well done!\n");
    }

    return 0;

}