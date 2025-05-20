//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(NULL)); //Seed to ensure random numbers based on current time

    int foundKey = 0; //Variable to check if player has found the key
    int playerChoice = 0; //Variable to store player choice
    int doors[3] = {0, 0, 0}; //Array to store door contents (0: Empty, 1: Monster, 2: Key)
    int playerDoor; //Variable to store player's chosen door
    int monsterDoor; //Variable to store monster's door
    int keyDoor; //Variable to store door containing key
    int i;
    int playerScore = 0; //Variable to count number of times player escapes the monster and finds the key

    printf("\nWelcome to the Haunted House Simulator! Your objective is to find the key and escape from the monster.\n");

    do{
        keyDoor = rand() % 3; //Randomly assign a door for the key
        for (i=0;i<3;i++){
            if (i==keyDoor){
                doors[i]=2;
            }
            else{
                doors[i]=1;
            }
        }

        monsterDoor = rand() % 3; //Randomly assign a door for the monster

        do{
            playerDoor = rand() % 3; //Randomly assign a door for the player

            if (playerDoor == monsterDoor){
                printf("\nYou have encountered the monster! Game over.\n");
                printf("Your final score is: %d\n", playerScore);
                return 0;
            }
            else {
                printf("\nYou have chosen door %d.\n", playerDoor+1);
                printf("Door %d contains a monster.\n", monsterDoor+1);
                printf("Door %d contains: \n", keyDoor+1);
                if (doors[keyDoor] == 0){
                    printf("A pile of bones.\n");
                }
                else{
                    printf("A golden key!\n");
                }

                do{
                    printf("\nWould you like to open another door? (1 for Yes, 2 for No): ");
                    scanf("%d", &playerChoice);

                    if (playerChoice != 1 && playerChoice != 2){
                        printf("\nInvalid input. Please enter 1 for Yes or 2 for No.\n");
                    }

                    else if (playerChoice == 1){
                        for (i=0;i<3;i++){
                            if (i != playerDoor && i != monsterDoor){
                                printf("\nDoor %d contains: \n", i+1);
                                if (doors[i] == 0){
                                    printf("A pile of bones.\n");
                                }
                                else if (doors[i] == 1){
                                    printf("A scary monster!\n");
                                }
                                else{
                                    printf("The golden key!\n");
                                }
                            }
                        }
                    }

                    else if (playerChoice == 2){
                        if (doors[keyDoor] == 2 && foundKey == 0){
                            foundKey = 1;
                            printf("\nCongratulations! You have found the key!\n");
                        }
                        else if (doors[keyDoor] == 2 && foundKey == 1){
                            printf("\nYou have already found the key behind door %d. Try another door.\n", keyDoor+1);
                        }
                        else{
                            printf("\nThere is no key behind this door. Look somewhere else.\n");
                        }
                    }
                } while (playerChoice != 2);
            }
        } while (playerDoor != monsterDoor);

        playerScore++; //Increment score if player escapes monster and finds key
        printf("\nCongratulations! You have escaped the monster and found the key!\n");
        printf("Your current score is: %d\n", playerScore);
    } while (1);
    return 0;
}