//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[50];
    int lowercase = 0;
    int uppercase = 0;
    int digits = 0;
    int special = 0;
    int length;
    int score = 0;

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < 8){
        printf("Password is too short, must be at least 8 characters.\n");
    }
    else
    {
        for(int i = 0; i < length; i++)
        {
            if(islower(password[i])){
                lowercase = 1;
            }
            else if(isupper(password[i])){
                uppercase = 1;
            }
            else if(isdigit(password[i])){
                digits = 1;
            }
            else if(!isalnum(password[i])){
                special = 1;
            }
        }

        if (lowercase == 0){
            printf("Password must contain at least one lowercase letter.\n");
        }
        else {
            score++;
        }

        if (uppercase == 0){
            printf("Password must contain at least one uppercase letter.\n");
        }
        else {
            score++;
        }

        if (digits == 0){
            printf("Password must contain at least one digit.\n");
        }
        else {
            score++;
        }

        if (special == 0){
            printf("Password must contain at least one special character.\n");
        }
        else {
            score++;
        }

        if(score == 4)
        {
            printf("Password strength: Strong\n");
        }
        else if(score == 3)
        {
            printf("Password strength: Medium\n");
        }
        else if(score == 2)
        {
            printf("Password strength: Weak\n");
        }
        else
        {
            printf("Password does not meet minimum requirements.\n");
        }
    }
    return 0;
}