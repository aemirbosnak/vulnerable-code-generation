//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

int main()
{
    char passwd[100];
    int len, a=0, b=0, c=0, d=0, score=0;
    printf("Enter password: ");
    scanf("%s",passwd);
    len=strlen(passwd);
    if(len==0)
    {
        printf("The password is empty.\n");
        return 0;
    }
    else if(len<6)
    {
        printf("The password is too short.\n");
        return 0;
    }
    else
    {
        for(int i=0;i<len;i++)
        {
            if(passwd[i]>='a' && passwd[i]<='z')
                a++;
            else if(passwd[i]>='A' && passwd[i]<='Z')
                b++;
            else if(passwd[i]>='0' && passwd[i]<='9')
                c++;
            else
                d++;
        }
        if(a>0 && b>0 && c>0 && d>0)
            score+=(len*10);
        if(a>0 && b>0)
            score+=5;
        if(c>0)
            score+=5;
        if(d>0)
            score+=5;
        if(len>=10)
            score+=5;
        switch(score)
        {
            case 100:
                printf("The password is extremely strong.\n");
                break;
            case 80:
                printf("The password is very strong.\n");
                break;
            case 60:
                printf("The password is strong.\n");
                break;
            case 40:
                printf("The password is weak.\n");
                break;
            default:
                printf("The password is very weak.\n");
                break;
        }
        return 0;
    }
}