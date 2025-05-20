//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void playGame()
{
    int num, guess, tries = 1;
    srand(time(0));
    num = rand() % 100 + 1;

    printf("\nGuess the number between 1 and 100\n");

    do{
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if(guess > num)
        {
            printf("Lower number please!\n");
        }
        else if(guess < num)
        {
            printf("Higher number please!\n");
        }
        else{
            printf("\nCongratulations! You guessed the number in %d tries.\n", tries);
        }
        tries++;
    }while(guess != num);

    return;
}

void showTopScorers()
{
    FILE *fp;
    char user[30];
    int score;

    fp = fopen("scorers.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("\n*********** TOP SCORERS ***********\n");

    while(fscanf(fp, "%s %d", user, &score) != EOF)
    {
        printf("%s - %d\n", user, score);
    }

    fclose(fp);

    return;
}

void addTopScorer(char *username, int score)
{
    FILE *fp;
    fp = fopen("scorers.txt", "a");

    if(fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fp, "%s %d\n", username, score);
    fclose(fp);

    return;
}

int main()
{
    char name[30];
    int option;

    printf("\n*********** GUESS THE NUMBER ***********\n");
    printf("\nEnter your name: ");
    scanf("%s", name);

    do{
        printf("\n\nSelect an option:\n");
        printf("1. Play Game\n");
        printf("2. Show Top Scorers\n");
        printf("3. Quit\n");

        scanf("%d", &option);

        switch(option)
        {
            case 1:
                playGame();
                break;
            case 2:
                showTopScorers();
                break;
            case 3:
                printf("\nThanks for playing. Goodbye!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }

    }while(option != 3);

    return 0;
}