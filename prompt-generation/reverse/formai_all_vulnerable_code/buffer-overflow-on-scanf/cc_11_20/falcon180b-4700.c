//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: intelligent
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define MAX 100

int main()
{
    char input[MAX];
    int choice,i;
    printf("Enter 1 for addition\n");
    printf("Enter 2 for subtraction\n");
    printf("Enter 3 for multiplication\n");
    printf("Enter 4 for division\n");
    scanf("%d",&choice);
    printf("Enter the first number:\n");
    scanf("%s",input);
    printf("Enter the second number:\n");
    scanf("%s",input);
    switch(choice)
    {
        case 1:
            {
                int sum=0;
                for(i=0;i<strlen(input);i++)
                {
                    if(isdigit(input[i]))
                    {
                        sum+=input[i]-'0';
                    }
                    else
                    {
                        printf("Invalid input\n");
                        exit(0);
                    }
                }
                printf("The sum is %d\n",sum);
                break;
            }
        case 2:
            {
                int diff=0;
                for(i=0;i<strlen(input);i++)
                {
                    if(isdigit(input[i]))
                    {
                        diff+=input[i]-'0';
                    }
                    else
                    {
                        printf("Invalid input\n");
                        exit(0);
                    }
                }
                printf("The difference is %d\n",diff);
                break;
            }
        case 3:
            {
                int prod=1;
                for(i=0;i<strlen(input);i++)
                {
                    if(isdigit(input[i]))
                    {
                        prod*=input[i]-'0';
                    }
                    else
                    {
                        printf("Invalid input\n");
                        exit(0);
                    }
                }
                printf("The product is %d\n",prod);
                break;
            }
        case 4:
            {
                int div=0,temp=0;
                for(i=0;i<strlen(input);i++)
                {
                    if(isdigit(input[i]))
                    {
                        temp=temp*10+(input[i]-'0');
                    }
                    else
                    {
                        printf("Invalid input\n");
                        exit(0);
                    }
                }
                if(temp==0)
                {
                    printf("Division by zero is not allowed\n");
                }
                else
                {
                    div=temp;
                }
                printf("The quotient is %d\n",div);
                break;
            }
        default:
            {
                printf("Invalid choice\n");
            }
    }
    return 0;
}