//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int fortune_num;
    char name[20];

    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Please enter your name: ");
    fgets(name, 20, stdin);

    printf("Hello, %s\n", name);
    printf("Choose a number between 1-5: ");
    scanf("%d", &fortune_num);

    //seed the random number generator
    srand(time(0));

    switch (fortune_num)
    {
        case 1:
            printf("\n%s, your future is looking bright!\n", name);
            break;
        case 2:
            printf("\n%s, beware of unexpected events in the coming days.\n", name);
            break;
        case 3:
            printf("\n%s, you will soon receive some unexpected good news!\n", name);
            break;
        case 4:
            printf("\n%s, a long lost friend will soon come back into your life.\n", name);
            break;
        case 5:
            printf("\n%s, in the next week something will happen that will change your life forever!\n", name);
            break;
        default:
            printf("\nInvalid number selected. Try again.\n");
            exit(0);
    }

    //generate a bonus message
    int bonus_num = rand() % 3;
    if (bonus_num == 0)
        printf("\nBonus message: Your lucky number is 7!\n");
    else if (bonus_num == 1)
        printf("\nBonus message: A loved one is thinking of you right now.\n");
    else
        printf("\nBonus message: A career change is in your near future.\n");

    printf("\nThank you for using the Automated Fortune Teller. Goodbye!\n");

    return 0;
}