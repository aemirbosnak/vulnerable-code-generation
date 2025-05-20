//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: automated
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    char password[100];
    int length, i, upper, lower, digit, special;
    float strength;
    char *p;

    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);

    upper = lower = digit = special = 0;

    for(i = 0; i < length; i++)
    {
        if(isupper(password[i]))
            upper++;
        else if(islower(password[i]))
            lower++;
        else if(isdigit(password[i]))
            digit++;
        else if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '?')
            special++;
    }

    if(length < 8)
        printf("Password is too short\n");
    else
    {
        strength = 0;

        if(upper)
            strength += 1;

        if(lower)
            strength += 1;

        if(digit)
            strength += 1;

        if(special)
            strength += 1;

        printf("Password strength: %.2f\n", strength / 4 * 100);
    }

    return 0;
}