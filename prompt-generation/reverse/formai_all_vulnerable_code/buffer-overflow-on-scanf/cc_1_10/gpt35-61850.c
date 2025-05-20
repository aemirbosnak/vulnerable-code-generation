//FormAI DATASET v1.0 Category: Memory Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void emptyBuffer();
void shuffleArray(int* arr, int size);
int getCard(int* arr, int index, char *label);
int getValidInput(int lower, int upper);

int main()
{
    srand(time(NULL));
    int n = getValidInput(2, MAX_SIZE / 2); //takes the number of unique cards to create
    int m = n * 2; //total number of cards

    int cards[m];
    char labels[m][10]; //max 10 character labels

    printf("\nMemory Game - Find the matching pairs of cards\n");
    printf("\nInstructions:");
    printf("\n\t- There are %d unique cards that you need to find a match for", n);
    printf("\n\t- Cards are represented by numbers from 1-%d", n);
    printf("\n\t- The numbers are only revealed when a card is chosen");
    printf("\n\t- Choose two cards and see if they match");
    printf("\n\t- If the cards match, they remain revealed");
    printf("\n\t- If they do not, they are turned back over");
    printf("\n\t- The game ends when all cards are matched\n\n");

    //create the unique set of cards
    for (int i = 0; i < n; i++)
    {
        cards[i] = i + 1;
        sprintf(labels[i], "Card %d", i + 1);
    }

    //copy the unique set of cards
    for (int i = n; i < m; i++)
    {
        cards[i] = cards[i - n];
        sprintf(labels[i], "Card %d", cards[i]);
    }

    shuffleArray(cards, m);

    int revealed[m];
    for (int i = 0; i < m; i++)
        revealed[i] = 0;

    int count = 0;
    int prevCard = -1;
    int guess1, guess2;
    while (count < m)
    {
        printf("Choose a card (1-%d): ", m);
        guess1 = getValidInput(1, m) - 1;
        while (revealed[guess1] > 0)
        {
            printf("Card already revealed. Choose another card (1-%d): ", m);
            guess1 = getValidInput(1, m) - 1;
        }

        revealed[guess1]++;

        printf("\t%s: %d\n", labels[guess1], cards[guess1]);

        if (prevCard == -1)
        {
            prevCard = guess1;
        }
        else
        {
            if (cards[prevCard] == cards[guess1])
            {
                printf("\nMatch found!\n\n");
                revealed[prevCard]++;
                count += 2;
            }
            else
            {
                printf("\nNo match found. Try again!\n\n");
                emptyBuffer();
                printf("Choose another card (1-%d): ", m);
                guess2 = getValidInput(1, m) - 1;
                while (revealed[guess2] > 0)
                {
                    printf("Card already revealed. Choose another card (1-%d): ", m);
                    guess2 = getValidInput(1, m) - 1;
                }
                revealed[guess2]++;
                printf("\t%s: %d\n", labels[guess2], cards[guess2]);
                if (cards[prevCard] == cards[guess2])
                {
                    printf("\nMatch found!\n\n");
                    revealed[prevCard]++;
                    count += 2;
                }
                else
                {
                    printf("\nNo match found. Next turn!\n\n");
                }
                prevCard = guess2;
            }
            emptyBuffer();
        }

        //check if all cards have been revealed
        if (count >= m)
        {
            printf("\nCongratulations! You have matched all cards\n");
        }
    }
    return 0;
}

void emptyBuffer()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void shuffleArray(int* arr, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int getCard(int* arr, int index, char* label)
{
    printf("\t%s: ", label);
    return arr[index];
}

int getValidInput(int lower, int upper)
{
    int input;
    do
    {
        printf("Enter choice (%d-%d): ", lower, upper);
        scanf("%d", &input);
        if (input < lower || input > upper)
        {
            printf("Invalid choice. Try again.\n");
        }
    } while (input < lower || input > upper);
    emptyBuffer();
    return input;
}