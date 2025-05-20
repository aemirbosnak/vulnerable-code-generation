//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the automated fortune teller!\n");
    printf("Please enter your name:\n");

    char name[20];
    scanf("%s", name);

    time_t t;
    time(&t);
    srand((unsigned int)t);

    int fortune = rand() % 10;
    switch (fortune)
    {
        case 0:
            printf("Congratulations, %s! You will soon come into great wealth.\n", name);
            break;
        case 1:
            printf("I'm sorry, %s. You will experience a minor setback in the near future.\n", name);
            break;
        case 2:
            printf("%s, you will meet someone special in the coming days.\n", name);
            break;
        case 3:
            printf("You will have a successful career, %s.\n", name);
            break;
        case 4:
            printf("%s, beware of making any hasty decisions.\n", name);
            break;
        case 5:
            printf("You can expect to receive some good news soon, %s.\n", name);
            break;
        case 6:
            printf("%s, you will soon embark on an exciting adventure.\n", name);
            break;
        case 7:
            printf("A major life change is coming your way, %s.\n", name);
            break;
        case 8:
            printf("You will find great success in your creative endeavors, %s.\n", name);
            break;
        case 9:
            printf("%s, be sure to take time for self care in the coming days.\n", name);
            break;
    }

    return 0;
}