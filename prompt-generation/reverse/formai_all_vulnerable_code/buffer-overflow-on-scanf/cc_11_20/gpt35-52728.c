//FormAI DATASET v1.0 Category: Password management ; Style: active
#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_PASS 50

int main(){

    // initialize password array
    char password[MAX_PASS];

    // initialize variables for strength of password
    int upper_case = 0;
    int lower_case = 0;
    int digit = 0;
    int special_char = 0;
    int length = 0;

    // loop for getting valid password
    while(1) {

        printf("Enter a strong password (must contain at least 1 uppercase letter, 1 lowercase letter, 1 digit, 1 special character and be at least 8 characters long): ");
        scanf("%s", password);

        // check length
        length = strlen(password);
        if(length < 8){
            printf("Password must be at least 8 characters long. ");
            continue;
        }

        // loop through password to check for other conditions
        for(int i = 0; i < length; i++){

            char curr_char = password[i];

            // check for uppercase
            if(isupper(curr_char)){
                upper_case = 1;
            }

            // check for lowercase
            if(islower(curr_char)){
                lower_case = 1;
            }

            // check for digits
            if(isdigit(curr_char)){
                digit = 1;
            }

            // check for special characters
            if(ispunct(curr_char) || isblank(curr_char)){
                special_char = 1;
            }
        }
        
        // check if all conditions are met
        if(upper_case == 1 && lower_case == 1 && digit == 1 && special_char == 1){
            printf("Password accepted. \n");
            break;
        }
        else{
            printf("Password must contain at least 1 uppercase letter, 1 lowercase letter, 1 digit, 1 special character. \n");
        }
    }

    return 0;
}