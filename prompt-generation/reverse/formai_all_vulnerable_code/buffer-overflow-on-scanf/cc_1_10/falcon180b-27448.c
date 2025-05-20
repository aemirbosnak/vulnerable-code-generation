//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 32

#define PASSWORD_LOWER_CASE 1
#define PASSWORD_UPPER_CASE 2
#define PASSWORD_NUMBER 4
#define PASSWORD_SPECIAL_CHAR 8

#define PASSWORD_WEAK 1
#define PASSWORD_MEDIUM 2
#define PASSWORD_STRONG 3
#define PASSWORD_VERY_STRONG 4

int get_password_strength(const char *password);

int main()
{
    char password[PASSWORD_MAX_LENGTH + 1] = {0};

    printf("Enter a password: ");
    scanf("%s", password);

    int password_strength = get_password_strength(password);

    switch(password_strength)
    {
        case PASSWORD_WEAK:
            printf("Weak password\n");
            break;
        case PASSWORD_MEDIUM:
            printf("Medium password\n");
            break;
        case PASSWORD_STRONG:
            printf("Strong password\n");
            break;
        case PASSWORD_VERY_STRONG:
            printf("Very strong password\n");
            break;
    }

    return 0;
}

int get_password_strength(const char *password)
{
    int length = strlen(password);

    if(length < PASSWORD_MIN_LENGTH || length > PASSWORD_MAX_LENGTH)
        return PASSWORD_WEAK;

    int has_lower_case = 0;
    int has_upper_case = 0;
    int has_number = 0;
    int has_special_char = 0;

    for(int i = 0; i < length; i++)
    {
        char c = tolower(password[i]);

        if(isalpha(c))
        {
            if(isupper(c))
                has_upper_case = 1;
            else
                has_lower_case = 1;
        }
        else if(isdigit(c))
            has_number = 1;
        else if(!isalnum(c))
            has_special_char = 1;
    }

    int strength = PASSWORD_WEAK;

    if(has_lower_case && has_upper_case)
        strength = PASSWORD_MEDIUM;

    if(has_number)
        strength += PASSWORD_NUMBER;

    if(has_special_char)
        strength += PASSWORD_SPECIAL_CHAR;

    return strength;
}