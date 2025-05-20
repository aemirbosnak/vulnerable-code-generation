//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    int age;
    int yes_no;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Let's start with some basic information.\n");

    printf("What is your name?\n");
    scanf("%s", name);

    printf("How old are you?\n");
    scanf("%d", &age);

    srand(time(NULL));

    printf("%s, let me see into your future...\n", name);

    while(1)
    {
        printf("Do you want to know your fortune?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d", &yes_no);

        if(yes_no == 1)
        {
            int random_num = rand() % 10 + 1;

            switch(random_num)
            {
                case 1:
                    printf("You will meet someone special today!\n");
                    break;
                case 2:
                    printf("You will be successful in your next venture.\n");
                    break;
                case 3:
                    printf("Your hard work will pay off soon.\n");
                    break;
                case 4:
                    printf("A surprise is waiting for you at home.\n");
                    break;
                case 5:
                    printf("Your creativity will lead to a new opportunity.\n");
                    break;
                case 6:
                    printf("Be careful of an unexpected expense.\n");
                    break;
                case 7:
                    printf("Your health will improve.\n");
                    break;
                case 8:
                    printf("You will receive good news from a friend.\n");
                    break;
                case 9:
                    printf("You will travel to a new place soon.\n");
                    break;
                case 10:
                    printf("Your love life will improve.\n");
                    break;
            }
        }
        else if(yes_no == 2)
        {
            printf("Okay, come back again when you're ready!\n");
            break;
        }
        else
        {
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}