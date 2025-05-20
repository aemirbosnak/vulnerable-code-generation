//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the love fortunes of Romeo and Juliet!\n\n");

    // initializing variables
    int num, lovePoints = 0;
    char input;

    // the first love fortune
    printf("Choose a number between 1-5: ");
    scanf("%d", &num);

    if(num == 1)
    {
        printf("Your first love is one that will be truly passionate and unforgettable!\n\n");
        lovePoints += 10;
    }
    else if(num == 2)
    {
        printf("You will fall in love with someone who is your perfect match!\n\n");
        lovePoints += 7;
    }
    else if(num == 3)
    {
        printf("Your love life will be tumultuous, but oh so exhilarating!\n\n");
        lovePoints += 5;
    }
    else if(num == 4)
    {
        printf("You will find love in the most unexpected place!\n\n");
        lovePoints += 3;
    }
    else if(num == 5)
    {
        printf("Your first love will sadly not last, but it will teach you valuable life lessons.\n\n");
        lovePoints += 1;
    }
    else
    {
        printf("Please choose a number between 1-5.\n\n");
    }

    // the second love fortune
    printf("Choose a letter between A-E: ");
    scanf(" %c", &input);

    if(input == 'A' || input == 'a')
    {
        printf("Your love will be met with great resistance, but you will triumph in the end!\n\n");
        lovePoints += 8;
    }
    else if(input == 'B' || input == 'b')
    {
        printf("Your love will require great sacrifice, but it will be worth it in the end!\n\n");
        lovePoints += 6;
    }
    else if(input == 'C' || input == 'c')
    {
        printf("Your love will be a constant rollercoaster, but it will make life all the more exciting!\n\n");
        lovePoints += 4;
    }
    else if(input == 'D' || input == 'd')
    {
        printf("Your love will be easy and carefree, just like a summer breeze!\n\n");
        lovePoints += 2;
    }
    else if(input == 'E' || input == 'e')
    {
        printf("Your love will be a passionate flame that will eventually burn out.\n\n");
        lovePoints += 1;
    }
    else
    {
        printf("Please choose a letter between A-E.\n\n");
    }

    // the third love fortune
    srand(time(0));
    num = rand() % 100 + 1;

    if(num >= 1 && num <= 25)
    {
        printf("Your love will come from someone you already know!\n\n");
        lovePoints += 7;
    }
    else if(num >= 26 && num <= 50)
    {
        printf("Your love will come from someone you will meet while on a journey!\n\n");
        lovePoints += 4;
    }
    else if(num >= 51 && num <= 75)
    {
        printf("Your love will come from someone you will meet in a crowded place!\n\n");
        lovePoints += 3;
    }
    else if(num >= 76 && num <= 90)
    {
        printf("Your love will come from someone who is also your friend!\n\n");
        lovePoints += 5;
    }
    else if(num >= 91 && num <= 100)
    {
        printf("Your love will come from someone who is a complete stranger!\n\n");
        lovePoints += 2;
    }

    // the final love fortune
    printf("Choose a number between 1-10: ");
    scanf("%d", &num);

    if(num == 1)
    {
        printf("Your love will be met with tragedy, but it will be an epic tale for all to remember!\n\n");
        lovePoints += 10;
    }
    else if(num == 2)
    {
        printf("Your love will be a long and winding road, but ultimately it will end in happiness!\n\n");
        lovePoints += 8;
    }
    else if(num == 3)
    {
        printf("Your love will be filled with drama, but it will be worth the ride!\n\n");
        lovePoints += 6;
    }
    else if(num == 4)
    {
        printf("Your love will be unconventional, but that's what makes it all the more special!\n\n");
        lovePoints += 7;
    }
    else if(num == 5)
    {
        printf("Your love will be pure and innocent, just like a fairytale.\n\n");
        lovePoints += 5;
    }
    else if(num == 6)
    {
        printf("Your love will be a whirlwind romance that will leave you breathless!\n\n");
        lovePoints += 8;
    }
    else if(num == 7)
    {
        printf("Your love will be a slow burn, but it will be well worth the wait!\n\n");
        lovePoints += 6;
    }
    else if(num == 8)
    {
        printf("Your love will be a tantalizing game of cat and mouse!\n\n");
        lovePoints += 9;
    }
    else if(num == 9)
    {
        printf("Your love will be forbidden, but that won't stop you from pursuing it!\n\n");
        lovePoints += 10;
    }
    else if(num == 10)
    {
        printf("Your love will be a sweet and simple affair that will last a lifetime!\n\n");
        lovePoints += 4;
    }
    else
    {
        printf("Please choose a number between 1-10.\n\n");
    }

    // generating the final love score
    printf("Your love score is: %d\n\n", lovePoints);

    // giving advice based on love score
    if(lovePoints >= 30)
    {
        printf("You are destined for a grand and epic love story! Take risks and follow your heart!\n");
    }
    else if(lovePoints >= 20 && lovePoints < 30)
    {
        printf("Your love may have some obstacles, but with perseverance and determination, you will find happiness!\n");
    }
    else if(lovePoints >= 10 && lovePoints < 20)
    {
        printf("Your love life may not be easy, but it will be a journey filled with valuable life lessons.\n");
    }
    else
    {
        printf("Your love life may not be what you were hoping for, but don't give up hope just yet!\n");
    }

    return 0;
}