//FormAI DATASET v1.0 Category: Game ; Style: happy
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Welcome to the Happy Game!\n\n");

    int score = 0;
    char choice;

    do 
    {
        printf("Your current score is: %d\n", score);
        printf("Choose your next move:\n");
        printf("a) Jump\n");
        printf("b) Dance\n");
        printf("c) Sing\n");
        printf("d) Smile\n");
        printf("e) Quit game\n\n");

        scanf(" %c", &choice);

        switch(choice) 
        {
            case 'a':
                printf("You jumped and gained 10 points!\n");
                score += 10;
                break;
            case 'b':
                printf("You danced and gained 8 points!\n");
                score += 8;
                break;
            case 'c':
                printf("You sang and gained 12 points!\n");
                score += 12;
                break;
            case 'd':
                printf("You smiled and gained 5 points!\n");
                score += 5;
                break;
            case 'e':
                printf("Thanks for playing the Happy Game!\n\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }

        if (score >= 50) 
        {
            printf("Congratulations! You won the Happy Game with a score of %d!\n", score);
            exit(0);
        }

    } while (choice != 'e');

    return 0;
}