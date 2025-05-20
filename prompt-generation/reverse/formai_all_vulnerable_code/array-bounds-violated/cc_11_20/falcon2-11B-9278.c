//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* bingoBoard[5][5];
    char* bingoCards[100];

    int currentBingoCard = 0;
    int currentBingoBoard = 0;
    int currentBingoNumber = 0;
    int currentBingoCardWinner = 0;

    while (1)
    {
        printf("Current Bingo Card: %d\n", currentBingoCard);
        printf("Current Bingo Board: %d\n", currentBingoBoard);
        printf("Current Bingo Number: %d\n", currentBingoNumber);

        printf("Enter 'B' to pick a Bingo Board\n");
        printf("Enter 'N' to draw a Bingo Number\n");
        printf("Enter 'S' to select a Bingo Card\n");
        printf("Enter 'Q' to quit\n");
        char choice = getchar();

        if (choice == 'B')
        {
            printf("Select a Bingo Board (1-5): ");
            scanf("%d", &currentBingoBoard);

            if (currentBingoBoard > 5 || currentBingoBoard < 1)
            {
                printf("Invalid choice, try again\n");
            }
            else
            {
                for (int i = 0; i < 5; i++)
                {
                    printf("Enter a Bingo Number (1-75): ");
                    scanf("%d", &bingoBoard[currentBingoBoard][i]);

                    if (bingoBoard[currentBingoBoard][i] > 75 || bingoBoard[currentBingoBoard][i] < 1)
                    {
                        printf("Invalid choice, try again\n");
                    }
                }
            }
        }
        else if (choice == 'N')
        {
            printf("Enter a Bingo Number (1-75): ");
            scanf("%d", &currentBingoNumber);

            if (currentBingoNumber > 75 || currentBingoNumber < 1)
            {
                printf("Invalid choice, try again\n");
            }
            else
            {
                printf("Bingo Number: %d\n", currentBingoNumber);
                printf("Update Bingo Board? (Y/N): ");
                char updateBoard = getchar();

                if (updateBoard == 'Y')
                {
                    printf("Current Bingo Board: %d\n", currentBingoBoard);
                    printf("Enter a Bingo Number (1-75): ");
                    scanf("%d", &bingoCards[currentBingoCard]);

                    if (bingoCards[currentBingoCard] > 75 || bingoCards[currentBingoCard] < 1)
                    {
                        printf("Invalid choice, try again\n");
                    }
                }
            }
        }
        else if (choice == 'S')
        {
            printf("Select a Bingo Card (1-100): ");
            scanf("%d", &currentBingoCard);

            if (currentBingoCard > 100 || currentBingoCard < 1)
            {
                printf("Invalid choice, try again\n");
            }
            else
            {
                printf("Bingo Card: %d\n", currentBingoCard);
            }
        }
        else if (choice == 'Q')
        {
            break;
        }
        else
        {
            printf("Invalid choice, try again\n");
        }
    }

    return 0;
}