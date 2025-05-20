//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void delay(int ms)
{
    clock_t start = clock();
    while (clock() < start + ms);
}

int main()
{
    char genome[500], sequence[100], choice;
    int i, j, k, l, m, n, length, match, mismatches, gap, cost, score, highscore = 0;
    srand(time(NULL));

    printf("Welcome to the C Genome Sequencing Simulator!\n\n");

    do
    {
        printf("Enter your genome (maximum 500 characters): ");
        fgets(genome, sizeof(genome), stdin);
        length = strlen(genome) - 1;
        printf("\n");

        printf("What type of sequence would you like to generate?\n");
        printf("a. Random sequence\n");
        printf("b. Sequence with variations\n");
        printf("c. Manually input sequence\n\n");

        printf("Choose an option: ");
        scanf(" %c", &choice);
        printf("\n");

        switch (choice)
        {
        case 'a':
            for (i = 0; i < 100; i++)
            {
                sequence[i] = rand() % 4 + 'a';
            }
            sequence[i] = '\0';
            break;

        case 'b':
            printf("Enter percentage of variations (0-100): ");
            scanf("%d", &mismatches);
            mismatches = length * mismatches / 100;
            for (i = 0; i < length; i++)
            {
                sequence[i] = genome[i];
            }
            for (i = 0; i < mismatches; i++)
            {
                j = rand() % length;
                do
                {
                    k = rand() % 4 + 'a';
                } while (k == sequence[j]); 
                sequence[j] = k;
            }
            sequence[i] = '\0';
            break;

        case 'c':
            printf("Enter sequence (maximum 100 characters): ");
            getchar();
            fgets(sequence, sizeof(sequence), stdin);
            length = strlen(sequence) - 1;
            break;

        default:
            printf("Invalid choice.\n");
            exit(1);
        }

        printf("\nGenerating...\n\n");
        delay(1000);

        printf("Genome: %s\n", genome);
        printf("Sequence: %s\n\n", sequence);

        score = 0;
        for (i = 0; i < 401; i++)
        {
            cost = 0;
            for (j = 0; j < 100; j++)
            {
                match = (genome[i+j] == sequence[j]) ? 1 : -2;
                gap = -2;
                if (i > 0 && j > 0 && genome[i+j-1] == sequence[j-1] && genome[i+j] == sequence[j])
                {
                    cost = 1;
                }
                else if (i > 0 && genome[i+j-1] == sequence[j])
                {
                    cost = -1;
                }
                else if (j > 0 && genome[i+j] == sequence[j-1])
                {
                    cost = -1;
                }
                else
                {
                    cost = -2;
                }
                if (match + cost > gap)
                {
                    gap = match + cost;
                }
            }
            if (gap > 0)
            {
                score += gap;
            }
        }

        printf("Score: %d\n\n", score);
        if (score > highscore)
        {
            highscore = score;
            printf("New High Score!!!\n");
        }

        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y');

    printf("\nThanks for playing!\n");
    return 0;
}