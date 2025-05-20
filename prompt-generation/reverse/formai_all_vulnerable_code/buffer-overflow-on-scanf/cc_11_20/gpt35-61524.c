//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: introspective
#include <stdio.h>
#include <string.h>

int main()
{
    char password[50];
    int length, i, lowercase, uppercase, digit, specialChar = 0;

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    for(i = 0; i < length; i++)
    {
        if(password[i] >= 'a' && password[i] <= 'z'){
            lowercase++;
        }
        else if(password[i] >= 'A' && password[i] <= 'Z'){
            uppercase++;
        }
        else if(password[i] >= '0' && password[i] <= '9'){
            digit++;
        }
        else{
            specialChar++;
        }
    }

    printf("Password length : %d\n", length);

    if(length >= 8){
        printf("Minimum password length met.\n");
    }
    else{
        printf("Minimum password length not met. Enter at least 8 characters.\n");
    }

    if(lowercase > 0 && uppercase > 0){
        printf("Password contains both lower and uppercase characters.\n");
    }
    else{
        printf("Password must contain both lower and uppercase characters.\n");
    }

    if(digit > 0){
        printf("Password contains digits.\n");
    }
    else{
        printf("Password must contain at least 1 digit.\n");
    }

    if(specialChar > 0){
        printf("Password contains special characters.\n");
    }
    else{
        printf("Password must contain at least 1 special character.\n");
    }

    return 0;
}