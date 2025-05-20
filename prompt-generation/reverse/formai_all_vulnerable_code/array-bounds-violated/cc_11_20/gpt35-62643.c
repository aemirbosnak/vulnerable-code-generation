//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20

int main()
{
    char password[MAX_PASSWORD_LENGTH+1];
    int i, password_length, has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special_char = 0;

    printf("Enter a password (max %d characters) : ", MAX_PASSWORD_LENGTH);
    fgets(password, MAX_PASSWORD_LENGTH+1, stdin);

    // Removing newline character from the end of the string
    if(password[strlen(password)-1] == '\n') {
        password[strlen(password)-1] = '\0';
    }

    password_length = strlen(password);

    if(password_length < 8) {
        printf("Password is too short\n");
    }

    for(i=0; i<password_length; i++) {
        if(isupper(password[i])) {
            has_uppercase = 1;
        }
        else if(islower(password[i])) {
            has_lowercase = 1;
        }
        else if(isdigit(password[i])) {
            has_digit = 1;
        }
        else if(!isspace(password[i])) {
            has_special_char = 1;
        }       
    }

    if(!has_uppercase) {
        printf("Password must contain at least one uppercase letter\n");
    }

    if(!has_lowercase) {
        printf("Password must contain at least one lowercase letter\n");
    }

    if(!has_digit) {
        printf("Password must contain at least one digit\n");
    }

    if(!has_special_char) {
        printf("Password must contain at least one special character\n");
    }

    if(has_uppercase && has_lowercase && has_digit && has_special_char && password_length >= 8) {
        printf("Strong password\n");
    }

    return 0;
}