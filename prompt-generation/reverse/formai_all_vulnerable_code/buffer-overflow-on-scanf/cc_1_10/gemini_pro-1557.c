//GEMINI-pro DATASET v1.0 Category: Educational ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Declare fair maiden's name
    char maidenName[20];

    // Welcome knight to the kingdom
    printf("\nWelcome, noble knight, to the kingdom of Codevalia!\n\n");

    // Ask for the fair maiden's name
    printf("May I inquire the name of the fair maiden who holds thy heart?\n");
    scanf("%s", maidenName);

    // Declare and initialize the knight's quest
    int questProgress = 0;
    int questComplete = 3;

    // Embark on the quest to win the maiden's favor
    while (questProgress < questComplete)
    {
        // Present the knight with three trials
        printf("\nTo win the maiden's hand, thou must complete three trials:\n");
        printf("1. Slay the mighty dragon\n");
        printf("2. Rescue the fair maiden from the evil sorcerer's tower\n");
        printf("3. Answer the riddle of the wise old hermit\n");

        // Ask the knight to choose a trial
        int trialChoice;
        printf("\nWhich trial dost thou choose, brave knight?\n");
        scanf("%d", &trialChoice);

        // Embark on the chosen trial
        switch (trialChoice)
        {
        case 1:
            // Battle the dragon
            printf("\nThou hast chosen to slay the mighty dragon.\n");
            questProgress++;
            break;
        case 2:
            // Rescue the fair maiden
            printf("\nThou hast chosen to rescue the fair maiden from the evil sorcerer's tower.\n");
            questProgress++;
            break;
        case 3:
            // Answer the riddle
            printf("\nThou hast chosen to answer the riddle of the wise old hermit.\n");
            questProgress++;
            break;
        default:
            // Invalid choice
            printf("\nInvalid choice, brave knight.\n");
            break;
        }
    }

    // Check if the knight has completed the quest
    if (questProgress == questComplete)
    {
        // The knight has won the maiden's favor
        printf("\nCongratulations, brave knight! Thou hast completed the quest and won the maiden's favor!\n");
        printf("May thy love for %s be eternal!\n", maidenName);
    }
    else
    {
        // The knight has failed the quest
        printf("\nAlack and alas, brave knight! Thou hast failed the quest.\n");
        printf("Mayhaps thou shouldst seek another maiden more suited to thy abilities.\n");
    }

    // Farewell the knight
    printf("\nFarewell, noble knight. May thy journey be filled with adventure and glory!\n\n");

    return 0;
}