//FormAI DATASET v1.0 Category: Game ; Style: creative
#include<stdio.h>

void displayTitle(void);
void displayMenu(void);
void startGame(void);

int main()
{
    displayTitle();
    displayMenu();
    startGame();
    return 0;
}

void displayTitle(void)
{
    printf("\n===============================");
    printf("\n   Welcome to the Treasure Hunt!");
    printf("\n===============================\n");
}

void displayMenu(void)
{
    printf("\nYou find yourself in a dark forest. You must collect all the treasures you can find!");
    printf("\n\nChoose an option to navigate:");
    printf("\n1) Move North");
    printf("\n2) Move South");
    printf("\n3) Move East");
    printf("\n4) Move West");
    printf("\n5) Quit game");
}

void startGame(void)
{
    int playerX = 5, playerY = 5, treasuresFound=0, treasureX, treasureY;
    int isGameOver = 0, menuChoice;

    printf("\n\nYou start at location (%d,%d)...\n\n", playerX, playerY);
  
    while(!isGameOver)
    {
       treasureX = (rand() % 10);
       treasureY = (rand() % 10);
       
       if(treasureX == playerX && treasureY == playerY)
       {
           treasuresFound++;
           printf("\nYou found a treasure! You now have %d treasures...", treasuresFound);
       }
       
       displayMenu();
       printf("\n\nEnter your choice: ");
       scanf("%d", &menuChoice);
       
       switch(menuChoice)
       {
           case 1:
                playerY--;
                printf("\nMoving north...");
                break;
           case 2:
                playerY++;
                printf("\nMoving south...");
                break;
           case 3:
                playerX++;
                printf("\nMoving east...");
                break;
           case 4:
                playerX--;
                printf("\nMoving west...");
                break;
           case 5:
                printf("\nQuitting game...");
                isGameOver = 1;
                break;
           default:
                printf("\nInvalid choice, try again.");
                break;
       }
       
       if(playerX < 0 || playerY < 0 || playerX > 9 || playerY > 9)
       {
           printf("\nYou have left the game area. Game over!");
           isGameOver = 1;
       }
       
       if(treasuresFound == 5)
       {
           printf("\nCongratulations, you found all the treasures!");
           isGameOver = 1;
       }
    }
}