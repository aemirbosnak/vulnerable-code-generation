//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char name[20];
    int age, lucky_num, fortune_num, choice;
    time_t t;
    srand((unsigned) time(&t));
    printf("Welcome to the Automated Fortune Teller. \n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your lucky number: ");
    scanf("%d", &lucky_num);
    printf("\nThank you, %s. Your fortune is being generated...\n\n", name);
    printf("Press enter to reveal your fortune...\n");
    getchar();

    fortune_num = rand() % 10 + 1;

    switch(fortune_num)
    {
        case 1:
            printf("Your lucky number, %d, will bring you good fortune. \n", lucky_num);
            break;

        case 2:
            printf("A great opportunity is coming your way, %s. Keep your eyes open! \n", name);
            break;

        case 3:
            printf("Don't be afraid to take risks, %s. You will be rewarded. \n", name);
            break;

        case 4:
            printf("Your hard work will pay off soon, %s. Keep pushing! \n", name);
            break;

        case 5:
            printf("Be kind to those around you and good things will come your way. \n");
            break;

        case 6:
            printf("You will soon receive unexpected news that will change your life, %s. \n", name);
            break;

        case 7:
            printf("Take some time for yourself today, %s. Relax and recharge. \n", name);
            break;

        case 8:
            printf("Financial stability is on the horizon, %s. A windfall is coming your way. \n", name);
            break;

        case 9:
            printf("The people you surround yourself with will have a huge impact on your future, %s. Choose wisely. \n", name);
            break;

        case 10:
            printf("Be thankful for what you have and more blessings will come your way, %s. \n", name);
            break;
    }

    printf("\nWould you like to generate another fortune? Press 1 for Yes or 2 for No: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        main();
    }
    else
    {
        printf("\nThank you for using the Automated Fortune Teller. Have a great day, %s!\n", name);
    }

    return 0;
}