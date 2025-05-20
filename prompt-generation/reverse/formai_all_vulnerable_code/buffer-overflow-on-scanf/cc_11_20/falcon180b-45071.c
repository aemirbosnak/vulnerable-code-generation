//Falcon-180B DATASET v1.0 Category: Table Game ; Style: random
#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 

int main()
{
    int num1, num2, num3, num4, num5, num6;
    int sum = 0;
    int count = 0;
    int i;
    int rand_num;
    int flag = 0;
    int choice;
    int user_num;
    int guess;
    int guess_count = 0;
    char play_again;

    srand(time(NULL));

    for(i=1;i<=6;i++)
    {
        rand_num = rand()%6 + 1;
        if(flag == 0)
        {
            num1 = rand_num;
            flag = 1;
        }
        else if(flag == 1)
        {
            num2 = rand_num;
            flag = 2;
        }
        else if(flag == 2)
        {
            num3 = rand_num;
            flag = 3;
        }
        else if(flag == 3)
        {
            num4 = rand_num;
            flag = 4;
        }
        else if(flag == 4)
        {
            num5 = rand_num;
            flag = 5;
        }
        else if(flag == 5)
        {
            num6 = rand_num;
            flag = 0;
        }
    }

    printf("The numbers are: %d %d %d %d %d %d\n", num1, num2, num3, num4, num5, num6);

    do
    {
        printf("Enter your choice of numbers (1-6): ");
        scanf("%d", &choice);

        if(choice == num1 || choice == num2 || choice == num3 || choice == num4 || choice == num5 || choice == num6)
        {
            sum += choice;
            count++;
        }
        else
        {
            printf("Invalid choice! Please try again.\n");
        }
    }while(count < 6);

    if(sum == 63)
    {
        printf("Congratulations! You win!\n");
    }
    else
    {
        printf("Sorry! You lose.\n");
    }

    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &play_again);

    if(play_again == 'y' || play_again == 'Y')
    {
        main();
    }
    else
    {
        printf("Thank you for playing!\n");
        exit(0);
    }

    return 0;
}