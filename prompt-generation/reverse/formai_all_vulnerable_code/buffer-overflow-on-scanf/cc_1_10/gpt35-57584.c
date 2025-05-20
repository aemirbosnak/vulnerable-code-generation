//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void intro();
void menu();
void startGame();
void playGame();
void endGame();
int generateRandomNumber(int minNum, int maxNum);
int calculateScore(int time);

int main()
{
    srand(time(0)); // generate random seed for RNG
    intro();
    menu();

    return 0;
}

// function to display intro text
void intro()
{
    printf("You are standing outside a haunted house.\n");
    printf("The house has a reputation for being cursed and filled with ghosts.\n");
    printf("You have been dared to enter and spend the night.\n\n");
    printf("Press enter to continue...\n");
    getchar();
}

// function to display menu options
void menu()
{
    int choice;
    printf("What would you like to do?\n");
    printf("1. Start game\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        startGame();
        break;
    case 2:
        printf("Goodbye!\n");
        exit(0);
    default:
        printf("Invalid choice! Try again.\n");
        menu();
        break;
    }
}

// function to start the game
void startGame()
{
    printf("You enter the haunted house and immediately feel a sense of dread.\n");
    printf("The door slams shut behind you and you realize you're trapped.\n");
    printf("You need to find a way out before the ghosts get you!\n");
    printf("Press enter to begin.\n");
    getchar(); // clear input buffer
    getchar(); // wait for enter key
    playGame();
}

// function to play the game
void playGame()
{
    time_t startTime, endTime;
    int timeTaken, score, roomNumber;
    printf("You find yourself in the first room.\n");

    startTime = time(0); // get current time
    roomNumber = 1; // starting room number

    while (1)
    {
        printf("What do you want to do?\n");
        printf("1. Search the room\n");
        printf("2. Move to the next room\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // generate random event
            switch (generateRandomNumber(1, 3))
            {
            case 1:
                printf("You found a key!\n");
                break;
            case 2:
                printf("You heard a ghostly whisper...\n");
                break;
            case 3:
                printf("You found nothing of interest.\n");
                break;
            }
            break;
        case 2:
            // move to next room
            roomNumber++;
            printf("You move to room %d.\n", roomNumber);

            // check if last room
            if (roomNumber == 10)
            {
                endTime = time(0); // get current time
                timeTaken = (int)difftime(endTime, startTime); // calculate time taken in seconds
                score = calculateScore(timeTaken);
                endGame(score);
            }

            break;
        case 3:
            // quit game
            printf("Are you sure you want to quit? (y/n) ");
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'y')
            {
                printf("Thanks for playing!\n");
                menu();
            }
            break;
        default:
            printf("Invalid choice! Try again.\n");
            break;
        }
    }
}

// function to end the game and display score
void endGame(int score)
{
    printf("Congratulations! You made it out of the haunted house!\n");
    printf("Your score is: %d\n", score);
    menu();
}

// function to generate random number between minNum and maxNum (inclusive)
int generateRandomNumber(int minNum, int maxNum)
{
    return (rand() % (maxNum - minNum + 1)) + minNum;
}

// function to calculate score based on time taken
int calculateScore(int time)
{
    return (100 - (time / 10));
}