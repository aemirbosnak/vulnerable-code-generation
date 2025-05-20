//FormAI DATASET v1.0 Category: Data recovery tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

//Structure for storing essential player information
typedef struct {
    int playerId;
    char playerName[20];
    int playerScore;
} Player;

//Initialize players array with 4 players
Player players[4] = {
    {1, "Player 1", 0},
    {2, "Player 2", 0},
    {3, "Player 3", 0},
    {4, "Player 4", 0}
};

//Main function to start game
int main() {
    printf("Welcome to Data Recovery Tool!\n");

    //Loop through each player and ask for their input
    for(int i=0; i<4; i++) {
        printf("\n%s, it's your turn to recover data.\n", players[i].playerName);

        //Ask player to input the data they want to recover
        int dataToRecover;
        printf("Enter the data you want to recover: ");
        scanf("%d", &dataToRecover);

        //Simulate data recovery process through random function
        int recoveredData = rand() % 10 + 1;

        //If recovered data matches with player's desired data, they score a point
        if(dataToRecover == recoveredData) {
            players[i].playerScore++;
            printf("Congratulations %s! You recovered the data successfully.\n", players[i].playerName);
            printf("Your new score is %d.\n", players[i].playerScore);
        } else {
            printf("Sorry %s, the recovered data does not match your desired data.\n", players[i].playerName);
        }
    }

    //Display final scores of all players
    printf("\nGame over! Here are the final scores:\n");
    for(int i=0; i<4; i++) {
        printf("%s: %d\n", players[i].playerName, players[i].playerScore);
    }

    return 0;
}