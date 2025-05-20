//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen(void);
void askQuestion(void);
void fortuneTeller(void);

int main()
{
    char ans;

    do
    {
        clearScreen();
        
        printf("           Welcome to the Automated Fortune Teller!            \n");
        printf(" -------------------------------------------------------------\n\n");
        
        askQuestion();
        fortuneTeller();
        
        printf("\nWould you like to ask another question (y/n)? ");
        scanf("%s", &ans);
        
    } while (ans == 'y' || ans == 'Y');
    
    printf("\nThank you for using the Automated Fortune Teller.\n\n");
    
    return 0;
}

void clearScreen(void)
{
    // clears the console screen by printing a bunch of new lines
    int i;
    for (i = 0; i < 50; i++)
    {
        printf("\n");
    }
}

void askQuestion(void)
{
    printf("Please ask your question...\n");
}

void fortuneTeller(void)
{
    char *fortunes[10] = {
        "It is certain",
        "Without a doubt",
        "You may rely on it",
        "Yes, definitely",
        "It is decidedly so",
        "As I see it, yes",
        "Most likely",
        "Outlook good",
        "Yes",
        "Signs point to yes"
    };
    
    srand(time(NULL)); // seed the random number generator with the current time

    printf("\nThinking...\n\n");

    int randNum = rand() % 10; // generates a random number between 0 and 9
    printf("Answer: %s\n", fortunes[randNum]);
}