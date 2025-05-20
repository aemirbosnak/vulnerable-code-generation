//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: irregular
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// Function to check if the given password is strong or not
void password_strength(char* password){

    //Initialising variables to represent number of characters in the password belonging to each category
    int upper = 0, lower = 0, digit = 0, special = 0;
    int strength_score = 0;

    //Iterating through the password string to count number of characters in each category
    for(int i = 0; i < strlen(password); i++){
        if(isupper(password[i]))
            upper++;
        else if(islower(password[i]))
            lower++;
        else if(isdigit(password[i]))
            digit++;
        else
            special++;
    }

    //Assigning strength score based on the number of characters from each category
    if(upper >= 1 && lower >= 1 && digit >= 1 && special >= 1)
        strength_score = 4;
    else if(upper >= 1 && lower >= 1 && digit >= 1)
        strength_score = 3;
    else if(upper >= 1 && lower >= 1)
        strength_score = 2;
    else
        strength_score = 1;

    //Printing the strength score and corresponding message
    switch(strength_score){
        case 1:
            printf("The password strength is weak. Please try again with a stronger password.\n");
            break;
        case 2:
            printf("The password strength is moderate. We recommend using a stronger password.\n");
            break;
        case 3:
            printf("The password strength is strong. Good job!\n");
            break;
        case 4:
            printf("The password strength is extremely strong. You have chosen a very secure password!\n");
            break;
        default:
            printf("Invalid strength score! Something went wrong.\n");
    }
}

//Driver function to fetch password from user and call the password_strength function
int main(){
    char password[100];
    printf("Please enter your password:\n");
    scanf("%s", password);
    password_strength(password);
    return 0;
}