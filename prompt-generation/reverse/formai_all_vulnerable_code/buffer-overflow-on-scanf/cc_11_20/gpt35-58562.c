//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char playAgain = 'y';
    srand(time(0)); // initialize random seed
    
    while(playAgain == 'y')
    {
        printf("\n\n\n");
        printf("|-------------------------------------------------------|\n");
        printf("| _____                 _                              |\n");
        printf("|/  __ \\               | |                             |\n");
        printf("|   /  \\/ __ _ _ __ ___| |__   ___ _ __                |\n");
        printf("|   |    / _` | '__/ __| '_ \\ / _ \\ '__|               |\n");
        printf("|   \\__/\\ (_| | | | (__| | | |  __/ |                  |\n");
        printf("|\\_____/\__,_|_|  \\___|_| |_|\\___|_|                  |\n");
        printf("|                                                       |\n");
        printf("|                       FORTUNE TELLER                  |\n");
        printf("|-------------------------------------------------------|\n");
      
        printf("\nThink of a question and I will tell you your fortune.\n");
        printf("Press Enter to continue...");
        getchar(); // wait for user input
        
        // generate random number between 1 and 10
        int fortune = (rand() % 10) + 1;
        
        // display fortune based on random number
        switch(fortune)
        {
            case 1:
                printf("\nYour future looks bright. You will soon find success.\n");
                break;
            case 2:
                printf("\nYou need to be patient. Your reward will come in time.\n");
                break;
            case 3:
                printf("\nBe careful who you trust. Someone close to you is not what they appear to be.\n");
                break;
            case 4:
                printf("\nChange is in the air. Embrace it, and you will find happiness.\n");
                break;
            case 5:
                printf("\nYou will face a difficult decision. Trust your instincts and you will make the right choice.\n");
                break;
            case 6:
                printf("\nYour hard work will pay off. Keep pushing forward.\n");
                break;
            case 7:
                printf("\nYou are about to embark on a great adventure. Embrace the unknown.\n");
                break;
            case 8:
                printf("\nYou will soon meet someone special. Keep your heart open.\n");
                break;
            case 9:
                printf("\nYour past mistakes will come back to haunt you. Learn from them, and move on.\n");
                break;
		    case 10:
			    printf("\nYour luck will change soon. Keep your eyes open for new opportunities.\n");
			    break;
        }
        
        printf("\n\nWould you like to play again? (y/n) ");
        scanf(" %c", &playAgain);

    }

    return 0;
}