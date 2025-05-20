//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomCards(int numCards, int cards[][5]){
    int bingoNums[75], selectedIndex, i, j;
    srand(time(0)); // Seed the random number generator

    // Initialize the bingo number pool
    for(i = 0; i < 75; i++){
        bingoNums[i] = i+1;
    }

    // Shuffle the bingo number pool
    for(i = 0; i < 74; i++){
        selectedIndex = i + rand() / (RAND_MAX / (75-i) + 1);
        int temp = bingoNums[i];
        bingoNums[i] = bingoNums[selectedIndex];
        bingoNums[selectedIndex] = temp;
    }

    // Fill in the cards with the shuffled bingo numbers
    for(i = 0; i < numCards; i++){
        for(j = 0; j < 5; j++){
            cards[i][j] = bingoNums[5*j + rand() % 5];
        }
    }
}

void printCards(int numCards, int cards[][5]){
    int i, j;

    for(i = 0; i < numCards; i++){
        printf("Card %d:\n", i+1);
        for(j = 0; j < 5; j++){
            printf("%2d ", cards[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int card[][5], int numCalled, int numCards){
    int i, j, calledColumn[5] = {0}, calledRow[5] = {0}, diag1 = 0, diag2 = 0;

    // Check for bingo in a row or column
    for(i = 0; i < numCards; i++){
        for(j = 0; j < 5; j++){

            if(card[i][j] == numCalled){
                calledColumn[j] = 1;
                calledRow[i] = 1;
            }
        }
    }

    // Check for bingo in a diagonal
    for(i = 0; i < 5; i++){
        if(card[i][i] == numCalled){
            diag1 = 1;
        }
        if(card[i][4-i] == numCalled){
            diag2 = 1;
        }
    }

    // Check if the player has won
    if(diag1 + diag2 + calledRow[0] + calledRow[1] + calledRow[2] + calledRow[3] + calledRow[4] + calledColumn[0] + calledColumn[1] + calledColumn[2] + calledColumn[3] + calledColumn[4] >= 5){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int numCards, numCalled, cards[4][5] = {0}, i, gameOver = 0, winnerIndex = -1;
    char playAgain = 'Y';
    srand(time(0)); // Seed the random number generator

    printf("Let's play Bingo!\n");

    while(playAgain == 'Y'){

        printf("How many cards do you want to play with? (1-4): ");
        scanf("%d", &numCards);

        while(numCards < 1 || numCards > 4){
            printf("Invalid number of cards. Please enter a number between 1 and 4: ");
            scanf("%d", &numCards);
        }

        // Generate random cards for the player
        generateRandomCards(numCards, cards);

        // Print out the cards
        printf("\nHere are your cards:\n");
        printCards(numCards, cards);

        // Draw numbers and check if the player has won
        while(!gameOver){
            printf("\nEnter the next number (1-75): ");
            scanf("%d", &numCalled);

            while(numCalled < 1 || numCalled > 75){
                printf("Invalid number. Please enter a number between 1 and 75: ");
                scanf("%d", &numCalled);
            }

            // Check the player's cards for a match and update game status
            for(i = 0; i < numCards; i++){
                if(checkWin(cards, numCalled, numCards) && winnerIndex == -1){
                    printf("\nCongratulations! You have won Bingo on Card %d!\n", i+1);
                    winnerIndex = i;
                    gameOver = 1;
                    break;
                }
            }

            printf("\nCalling number %d...\n", numCalled);
        }

        // Ask the player if they want to play again
        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);

        while(playAgain != 'Y' && playAgain != 'N'){
            printf("Invalid input. Please enter Y or N: ");
            scanf(" %c", &playAgain);
        }

        if(playAgain == 'Y'){
            // Reset the game status if the player wants to play again
            gameOver = 0;
            winnerIndex = -1;
            printf("\n");
        }
    }

    printf("\nThanks for playing!\n");

    return 0;
}