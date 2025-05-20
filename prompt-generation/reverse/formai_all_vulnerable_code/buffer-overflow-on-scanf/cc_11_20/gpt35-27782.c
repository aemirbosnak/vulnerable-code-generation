//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() 
{
    char password[100];
    int i, len, score=0, uc=0, lc=0, digits=0, spchar=0;

    printf("Enter your password: ");
    scanf("%s",password);

    len = strlen(password);
    if(len<8)
    {
        printf("\nPassword must be at least 8 characters long.\n");
        return 0;
    }

    for(i=0; i<len; i++)
    {
        if(password[i]>='A' && password[i]<='Z')
            uc++;
        if(password[i]>='a' && password[i]<='z')
            lc++;
        if(password[i]>='0' && password[i]<='9')
            digits++;
        if(password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='%' || password[i]=='&')
            spchar++;
    }

    score = uc*2 + lc*2 + digits*3 + spchar*5;

    printf("\nPassword Strength Report\n");
    printf("------------------------\n");

    if(score <= 25)
        printf("Score    : %d (Weak)\n", score);
    else if(score <= 50)
        printf("Score    : %d (Medium)\n", score);
    else if(score <= 75)
        printf("Score    : %d (Strong)\n", score);
    else
        printf("Score    : %d (Very Strong)\n", score);

    printf("Length   : %d\n", len);
    printf("Uppercase: %d\n", uc);
    printf("Lowercase: %d\n", lc);
    printf("Digits   : %d\n", digits);
    printf("Special  : %d\n", spchar);

    return 0;
}