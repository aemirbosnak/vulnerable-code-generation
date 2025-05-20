//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char playersName[50];
    int playersAge;
    int numberOfPlayers;
    int randomNumber;
    char inputYN;
    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller game!\n\n");
    
    // get the number of players
    printf("How many players are there? ");
    scanf("%d", &numberOfPlayers);
    
    // loop through each player
    for (int i = 0; i < numberOfPlayers; i++) {
        printf("\nPlayer %d, what is your name? ", i+1);
        scanf("%s", playersName);
        printf("Hello %s! How old are you? ", playersName);
        scanf("%d", &playersAge);
        
        // check if player is old enough to play
        if (playersAge >= 18) {
            printf("Great! You are old enough to play!\n");
            printf("Here is your fortune: \n");

            // generate random number for fortune
            randomNumber = rand() % 5;
            switch(randomNumber) {
                case 0:
                    printf("You will soon find true love.\n");
                    break;
                case 1:
                    printf("A financial windfall is coming your way.\n");
                    break;
                case 2:
                    printf("You will achieve great success in your career.\n");
                    break;
                case 3:
                    printf("You will travel to a new and exciting place soon.\n");
                    break;
                case 4:
                    printf("A new relationship will bring you great happiness.\n");
                    break;
            }

        } else {
            printf("Sorry %s, you are not old enough to play.\n", playersName);
            printf("You must be at least 18 years old to play.\n");
        }
    }
    
    // ask if players want to play again
    printf("\n");
    printf("Thank you for playing the Automated Fortune Teller game!\n");
    printf("Would you like to play again? (Y/N) ");
    scanf(" %c", &inputYN);
    inputYN = toupper(inputYN);
    
    // loop until valid input received
    while (inputYN != 'Y' && inputYN != 'N') {
        printf("Invalid input. Please enter Y or N: ");
        scanf(" %c", &inputYN);
        inputYN = toupper(inputYN);
    }

    if (inputYN == 'Y') {
        // play again
        main();
    } else {
        // quit game
        printf("\nExiting game. Goodbye!\n");
        return 0;
    }
}