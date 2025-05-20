//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int taskNumber = 1; //global variable to keep track of tasks
char choice; //to store user's input choice
char playerName[50]; //to store player's name

void task(); //function to generate new task
void printInfo(); //function to print player's information
void explore(); //function to explore the game
void gameWin(); //function to end the game when player wins

int main()
{    
    printf("Welcome to the text-based adventure game!\n");
    printf("What is your name? ");    
    fgets(playerName, sizeof(playerName), stdin);
    playerName[strlen(playerName) - 1] = '\0';
    printf("Hello %s! Your adventure begins now.\n", playerName);

    printInfo(); //display initial player's information

    while(1)
    {
        printf("\nChoose your action:\n");
        printf("1. Explore\n");
        printf("2. Tasks\n");
        printf("3. Quit\n");
        printf("-> ");
        scanf("%c", &choice);
        getchar();

        switch(choice)
        {
            case '1': //explore the game
                explore();
                break;
            case '2': //tasks
                task();
                break;
            case '3': //quit the game
                printf("Thanks for playing the game!\n");
                exit(0);
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }
    }
}

void task()
{
    printf("\nTasks:\n");
    switch(taskNumber)
    {
        case 1:
            printf("1. Find a key to unlock the door.\n");
            break;
        case 2:
            printf("2. Collect 5 gems.\n");
            break;
        case 3:
            printf("3. Solve the puzzle to enter the next room.\n");
            break;
        case 4:
            printf("4. Defeat the boss to win the game.\n");
            break;
        default:
            printf("No more tasks available at the moment.\n");
    }
}

void printInfo()
{
    time_t currentTime;
    time(&currentTime); //get current time

    printf("\nPlayer's information:\n");
    printf("Name: %s\n", playerName);
    printf("Current task: %d\n", taskNumber);
    printf("Time: %s", ctime(&currentTime));
}

void explore()
{
    printf("\nYou are exploring the game...\n");
    printf("You found a treasure chest!\n");
    printf("Do you want to open it? (y/n) ");
    scanf("%c", &choice);
    getchar();
    if(choice == 'y')
    {
        printf("You got a gem!\n");
    }
    else if(choice == 'n')
    {
        printf("You continue exploring...\n");
    }
    else
    {
        printf("Invalid input. Please try again.\n");
    }
}

void gameWin()
{
    printf("\nCongratulations %s, you have won the game!\n", playerName);
    exit(0);
}