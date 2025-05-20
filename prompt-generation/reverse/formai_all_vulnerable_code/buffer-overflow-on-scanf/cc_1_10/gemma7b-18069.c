//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void predict_future(int);

int main()
{
    time_t t;
    srand(time(&t));

    int choice;
    printf("Would you like to have your future predicted? (1/2): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        predict_future(1);
    }
    else if (choice == 2)
    {
        predict_future(2);
    }
    else
    {
        printf("Invalid input.\n");
    }

    return 0;
}

void predict_future(int choice)
{
    int number_of_cards = rand() % 3 + 1;
    int cards[number_of_cards];

    for (int i = 0; i < number_of_cards; i++)
    {
        cards[i] = rand() % 5 + 1;
    }

    switch (choice)
    {
        case 1:
            printf("Your future is bright, my dear. You will find love and happiness.\n");
            break;
        case 2:
            printf("Your future is filled with possibilities. You will achieve great things and make a name for yourself.\n");
            break;
    }

    printf("The cards drawn were: ");
    for (int i = 0; i < number_of_cards; i++)
    {
        printf("%d ", cards[i]);
    }

    printf("\n");
}