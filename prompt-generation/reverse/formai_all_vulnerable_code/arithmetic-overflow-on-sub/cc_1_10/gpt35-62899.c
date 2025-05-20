//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>

// function to generate n terms of Fibonacci sequence
void generateSequence(int n)
{
    int a = 0, b = 1, c;
    printf("Fibonacci Sequence: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

int main()
{
    int num, choice;
    // prompting the user to enter the number of terms to be generated
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &num);

    // prompting the user to choose the multiplayer mode
    printf("\nSelect a multiplayer mode: \n 1) Co-op mode \n 2) Competitive mode \n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\nYou have selected Co-op mode.\n");

        // generating the sequence
        generateSequence(num);

        // prompting the user to play again or exit
        printf("\nDo you want to play again? (Y/N): ");
        char playAgain;
        scanf(" %c", &playAgain);
        if (playAgain == 'Y' || playAgain == 'y')
        {
            main();
        }
        else
        {
            printf("\nThanks for playing!\n");
            return 0;
        }
    }
    else if (choice == 2)
    {
        printf("\nYou have selected Competitive mode.\n");
        int guess, count = 0, incorrect = 0;

        // generating the sequence
        generateSequence(num);

        // prompting the user to guess the next number in the sequence
        printf("\nGuess the next number in the Fibonacci sequence: ");
        scanf("%d", &guess);

        while (count < num - 1)
        {
            int a = 0, b = 1, c;
            for (int i = 0; i < count; i++)
            {
                c = a + b;
                a = b;
                b = c;
            }

            // checking if the user's guess is correct
            if (c == guess)
            {
                printf("\nCorrect guess!\n");
                count++;
                if (count < num - 1)
                {
                    printf("\nGuess the next number in the Fibonacci sequence: ");
                    scanf("%d", &guess);
                }
            }
            else
            {
                printf("\nIncorrect guess.\n");
                incorrect++;
                if (incorrect == 3)
                {
                    printf("\nYou have exceeded the number of allowed incorrect guesses. Game over.\n");
                    return 0;
                }
                else
                {
                    printf("\nGuess again: ");
                    scanf("%d", &guess);
                }
            }
        }

        printf("\nCongratulations, you have successfully completed the sequence!\n");

        // prompting the user to play again or exit
        printf("\nDo you want to play again? (Y/N): ");
        char playAgain;
        scanf(" %c", &playAgain);
        if (playAgain == 'Y' || playAgain == 'y')
        {
            main();
        }
        else
        {
            printf("\nThanks for playing!\n");
            return 0;
        }
    }
    else
    {
        printf("\nInvalid choice. Please select a valid choice.\n");
        main();
    }

    return 0;
}