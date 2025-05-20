//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int choice,i,j;
    char name[50];
    time_t t;
    struct tm *now;

    printf("Welcome to the Space Adventure!\n");

    srand(time(NULL));
    t=time(NULL);
    now=localtime(&t);

    printf("What is your name, %s?\n",now->tm_hour%12? "astronaut" : "astronautress");
    scanf("%s",name);

    printf("You are %s, a brave space explorer on a mission to discover new planets.\n",name);

    while(1)
    {
        printf("\n");
        printf("1. Explore new planet\n");
        printf("2. Return to base\n");
        printf("3. Save game\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\n");
                printf("You have landed on a new planet.\n");
                printf("The planet is ");

                for(i=0;i<10;i++)
                {
                    j=rand()%3;
                    switch(j)
                    {
                        case 0:
                            printf("red and rocky\n");
                            break;
                        case 1:
                            printf("green and lush\n");
                            break;
                        case 2:
                            printf("blue and watery\n");
                            break;
                    }
                }

                printf("\n");
                printf("Do you want to explore further? (y/n): ");
                scanf(" %c",&choice);

                if(choice=='y'||choice=='Y')
                {
                    printf("\n");
                    printf("You discover a strange alien artifact.\n");
                    printf("Do you take it with you? (y/n): ");
                    scanf(" %c",&choice);

                    if(choice=='y'||choice=='Y')
                    {
                        printf("\n");
                        printf("You have acquired the alien artifact.\n");
                    }
                    else
                    {
                        printf("\n");
                        printf("You leave the artifact behind and return to your ship.\n");
                    }
                }
                else
                {
                    printf("\n");
                    printf("You return to your ship and prepare for departure.\n");
                }
                break;

            case 2:
                printf("\n");
                printf("You return to your base safely.\n");
                printf("Your mission was a success!\n");
                break;

            case 3:
                printf("\n");
                printf("Game saved.\n");
                break;

            case 4:
                printf("\n");
                printf("Thanks for playing!\n");
                exit(0);

            default:
                printf("\n");
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}