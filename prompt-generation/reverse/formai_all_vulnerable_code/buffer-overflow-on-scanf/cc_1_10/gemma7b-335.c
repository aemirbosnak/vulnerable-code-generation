//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_BALLS 50

typedef struct Ball
{
    int number;
    struct Ball* next;
} Ball;

Ball* createBall(int number)
{
    Ball* newBall = (Ball*)malloc(sizeof(Ball));
    newBall->number = number;
    newBall->next = NULL;
    return newBall;
}

void addBall(Ball* head, int number)
{
    Ball* newBall = createBall(number);
    if (head == NULL)
    {
        head = newBall;
    }
    else
    {
        head->next = newBall;
        head = newBall;
    }
}

void playBingo(Ball* head)
{
    int i, number, winning = 0;
    printf("Enter numbers (separate with commas): ");
    scanf("%d,", &number);

    for (i = 0; i < MAX_NUM_BALLS && number != -1; i++)
    {
        if (head->number == number)
        {
            printf("Bingo! You won!\n");
            winning = 1;
            break;
        }
        head = head->next;
        scanf("%d,", &number);
    }

    if (!winning)
    {
        printf("Sorry, you lost.\n");
    }
}

int main()
{
    Ball* head = NULL;

    // Add some balls to the list
    addBall(head, 1);
    addBall(head, 2);
    addBall(head, 3);
    addBall(head, 4);
    addBall(head, 5);

    // Play bingo
    playBingo(head);

    return 0;
}