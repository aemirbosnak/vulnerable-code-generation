//Falcon2-11B DATASET v1.0 Category: Automated Fortune Teller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int r, c;
    srand(time(NULL));

    printf("Welcome to the automated fortune teller!\n");
    printf("Please answer the following questions:\n");
    printf("1. What is your name? ");
    scanf("%d", &r);
    printf("2. What is your favorite color? ");
    scanf("%d", &c);
    printf("3. What is your lucky number? ");
    scanf("%d", &r);
    printf("4. What is your favorite animal? ");
    scanf("%d", &c);
    printf("5. What is your lucky charm? ");
    scanf("%d", &r);
    printf("6. What is your favorite book? ");
    scanf("%d", &c);
    printf("7. What is your favorite food? ");
    scanf("%d", &r);
    printf("8. What is your favorite drink? ");
    scanf("%d", &c);

    int my_fortune = rand() % 100;

    if (my_fortune < 10)
    {
        printf("Your fortune is: You will have a great day!\n");
    }
    else if (my_fortune < 20)
    {
        printf("Your fortune is: You will meet a new friend today!\n");
    }
    else if (my_fortune < 30)
    {
        printf("Your fortune is: You will find something valuable.\n");
    }
    else if (my_fortune < 40)
    {
        printf("Your fortune is: You will receive good news.\n");
    }
    else if (my_fortune < 50)
    {
        printf("Your fortune is: You will have a successful day.\n");
    }
    else if (my_fortune < 60)
    {
        printf("Your fortune is: You will have a relaxing day.\n");
    }
    else if (my_fortune < 70)
    {
        printf("Your fortune is: You will receive a gift.\n");
    }
    else if (my_fortune < 80)
    {
        printf("Your fortune is: You will have a productive day.\n");
    }
    else if (my_fortune < 90)
    {
        printf("Your fortune is: You will have a creative day.\n");
    }
    else
    {
        printf("Your fortune is: You will have a lucky day!\n");
    }

    return 0;
}