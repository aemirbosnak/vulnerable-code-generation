//FormAI DATASET v1.0 Category: Arithmetic ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("What's up? I am your friendly calculator!\n");
    printf("Hold on to your seat because I am about to blow your mind with some arithmetic awesomeness!\n");

    int a,b,c;
    float d;
    char op, choice;

    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter another number: ");
    scanf("%d", &b);

    printf("Choose an operation (+, -, *, /): ");
    scanf(" %c", &op);

    switch(op)
    {
        case '+':
        c= a+b;
        printf("%d + %d = %d\n", a,b,c);
        break;

        case '-':
        c= a-b;
        printf("%d - %d = %d\n", a,b,c);
        break;

        case '*':
        c= a*b;
        printf("%d * %d = %d\n", a,b,c);
        break;

        case '/':
        d= (float)a/b;
        printf("%d / %d = %.2f\n", a,b,d);
        break;

        default:
        printf("Whoops, you entered an incorrect operation. Try again!\n");
        break;

    }

    printf("Be honest, that was pretty awesome wasn't it? Want to play again? (Y/N): ");
    scanf(" %c", &choice);

    if(choice == 'Y' || choice == 'y')
    {
        printf("Let's do it again!\n");
    }
    else if(choice == 'N' || choice == 'n')
    {
        printf("Aww man, already done? You know where to find me if you want to play again!\n");
    }
    else
    {
        printf("I am sorry, I don't understand what you mean. But let's play again anyway!\n");
    }

    return 0;
}