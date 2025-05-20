//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: detailed
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int strengthCheck(char*);

int main()
{
    char password[20];
    int strength;
    printf("Enter Password: ");
    scanf("%s", password);
    strength=strengthCheck(password);
    if(strncmp(password,"exit",4)==0)
    {
        printf("\nProgram Terminated\n\n");
        exit(0);
    }
    switch(strength)
    {
        case 1:
            printf("\nPassword is Weak\n\n");
            break;
        case 2:
            printf("\nPassword is Moderate\n\n");
            break;
        case 3:
            printf("\nPassword is Strong\n\n");
            break;
        default:
            printf("\nInvalid Password\n\n");
            break;
    }
    main();
    return 0;
}

int strengthCheck(char* password)
{
    int length=strlen(password);
    int has_lower=0,has_upper=0,has_digit=0,i,count=0;
    for(i=0;i<length;i++)
    {
        if(islower(password[i]))
            has_lower=1;
        if(isupper(password[i]))
            has_upper=1;
        if(isdigit(password[i]))
            has_digit=1;
        count++;
    }
    if(length<8)
        return 1; //weak password
    else if(has_lower==1 && has_upper==1 && has_digit==1 && count>=8 && count<=12)
        return 2; //moderate password
    else if(has_lower==1 && has_upper==1 && has_digit==1 && count>12)
        return 3; //strong password
    else
        return 0; //invalid password
}