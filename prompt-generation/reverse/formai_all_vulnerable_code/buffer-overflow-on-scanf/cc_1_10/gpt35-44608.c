//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char question[100];
    printf("Welcome to the automated fortune teller! I am here to help solve your mysteries.\n");
    printf("But first, what is your question? Ask me anything!\n");
    printf("Please enter your question here: ");
    scanf("%[^\n]", question);

    srand(time(NULL));
    int randomNum = rand() % 5;

    switch (randomNum)
    {
        case 0:
            printf("Ah, a mystery for me to solve. Let me see...\n");
            printf("It appears that the answer to your question is elementary, my dear Watson. %c You already know the answer deep within you. Trust your intuition.\n", 34);
            break;

        case 1:
            printf("Interesting question, indeed. Let me use my analytical skills to solve it...\n");
            printf("The answer to your question lies in the clues around you. Open your eyes and observe your surroundings. You'll find what you seek. %c\n", 33);
            break;

        case 2:
            printf("Ah, a conundrum. Let me think...\n");
            printf("The answer to your question is hidden in the details. Look closely and you'll discover what you've been seeking. %c\n", 63);
            break;

        case 3:
            printf("A mystery that needs my expertise to solve. Let's see...\n");
            printf("The answer to your question is elusive, but don't give up. Keep searching and you'll find what you're looking for. %c\n", 33);
            break;

        case 4:
            printf("A mystery that needs solving. Let me deduce...\n");
            printf("The answer to your question is simple, my dear Watson. You just need to take a step back and look at the bigger picture. %c\n", 58);
            break;

        default:
            printf("Hmm, something seems to have gone wrong. Try asking your question again later. Goodbye!\n");
            return 1;
    }

    printf("Thank you for using the automated fortune teller. I hope my deduction was helpful. Farewell!\n");
    return 0;
}