//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

int main()
{
    char password[25];
    int length, upper=0, lower=0, digit=0, special=0, strength=0;

    printf("Enter the password: ");
    scanf("%s",password);

    length = strlen(password);

    for(int i=0; i<length; i++) {
        
        // Upper case characters check
        if(password[i]>=65 && password[i]<=90) {
            upper = 1;
            strength++;
        }
        
        // Lower case characters check
        if(password[i]>=97 && password[i]<=122) {
            lower = 1;
            strength++;
        }
        
        // Digit check
        if(password[i]>=48 && password[i]<=57) {
            digit = 1;
            strength++;
        }
        
        // Special characters check
        if(password[i]>=33 && password[i]<=47 || password[i]>=58 && password[i]<=64) {
            special = 1;
            strength++;
        }
    }

    if(length < 8 || length >20) {
        printf("Weak Password: Password should be between 8 to 20 characters long\n");
    }
    else if(upper==0 || lower==0 || digit==0 || special==0) {
        printf("Medium Password: Password should contain at least one Upper case, one Lower case, one digit and one special character\n");
    }
    else {
        printf("Strong Password: The password you entered is strong enough!\n");
    }

    return 0;
}