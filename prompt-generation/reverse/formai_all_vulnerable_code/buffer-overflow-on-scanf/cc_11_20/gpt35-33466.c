//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char name[20];
    printf("Hello, what is your name?\n");
    scanf("%s", name);

    int lucky_num;
    printf("Pick a number between 1 and 10:\n");
    scanf("%d", &lucky_num);

    char color[10];
    printf("Choose a color (red, blue, or green):\n");
    scanf("%s", color);

    int rand_num;
    srand(time(NULL));
    rand_num = rand() % 3;

    char fortune[100];
    if (strcmp(color, "red") == 0)
    {
        switch (rand_num)
        {
            case 0:
                strcpy(fortune, "You will soon meet someone who will change your life forever.");
                break;
            case 1:
                strcpy(fortune, "Your lucky number is indeed lucky, as it will bring abundance into your life.");
                break;
            case 2:
                strcpy(fortune, "You will face a challenge in the near future, but you will come out stronger on the other side.");
                break;
            default:
                break;
        }
    }
    else if (strcmp(color, "blue") == 0)
    {
        switch (rand_num)
        {
            case 0:
                strcpy(fortune, "You have been feeling lost, but you will soon find your way.");
                break;
            case 1:
                strcpy(fortune, "Your lucky number is a sign of good things to come.");
                break;
            case 2:
                strcpy(fortune, "You will find something valuable that you thought was lost forever.");
                break;
            default:
                break;
        }
    }
    else if (strcmp(color, "green") == 0)
    {
        switch (rand_num)
        {
            case 0:
                strcpy(fortune, "You will find success in your professional life.");
                break;
            case 1:
                strcpy(fortune, "Your lucky number is a sign of wealth and prosperity.");
                break;
            case 2:
                strcpy(fortune, "You will soon embark on an adventure that will change your perspective.");
                break;
            default:
                break;
        }
    }

    printf("\n%s's fortune:\n%s\n", name, fortune);

    return 0;
}