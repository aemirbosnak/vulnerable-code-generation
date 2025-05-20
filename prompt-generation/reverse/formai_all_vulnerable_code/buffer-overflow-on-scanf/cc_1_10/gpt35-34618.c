//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntro(){
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing in front of a spooky mansion. Do you go inside?\n");
}

int playGame(){
    int currentRoom = 1;
    int moveCount = 0;
    srand(time(NULL)); //initialize random number generator

    while(1){
        printf("You are in the ");
        switch(currentRoom){
            case 1: printf("entryway.\n");
                    break;
            case 2: printf("living room.\n");
                    break;
            case 3: printf("kitchen.\n");
                    break;
            case 4: printf("bedroom.\n");
                    break;
        }
        printf("Which direction do you want to move?\n");
        printf("1. North\n2. East\n3. South\n4. West\n");
        int choice = getChoice();

        //randomly choose a room to move to
        int newRoom = (rand() % 4) + 1;

        //check if the new room is the same as the current room
        while(newRoom == currentRoom){
            newRoom = (rand() % 4) + 1;
        }

        //check if the player chose the correct direction to move in
        if(choice == getDirection(currentRoom, newRoom)){
            printf("You move to the next room.\n");
            currentRoom = newRoom;
            moveCount++;
            if(currentRoom == 4){
                printf("Congratulations! You found the treasure in %d moves.\n", moveCount);
                return 1;
            }
        } else {
            printf("Sorry, that direction is incorrect. Try again.\n");
        }
    }
}

int getChoice(){
    int choice;
    scanf("%d", &choice);
    while(choice < 1 || choice > 4){
        printf("Invalid input. Please choose a number between 1 and 4.\n");
        scanf("%d", &choice);
    }
    return choice;
}

int getDirection(int currentRoom, int newRoom){
    if(currentRoom == 1 && newRoom == 2){
        return 1;
    } else if(currentRoom == 2 && newRoom == 3){
        return 2;
    } else if(currentRoom == 3 && newRoom == 4){
        return 3;
    } else if(currentRoom == 4 && newRoom == 3){
        return 4;
    } else if(currentRoom == 3 && newRoom == 2){
        return 1;
    } else if(currentRoom == 2 && newRoom == 1){
        return 4;
    } else if(currentRoom == 4 && newRoom == 3){
        return 3;
    } else if(currentRoom == 3 && newRoom == 2){
        return 2;
    } else {
        return 0;
    }
}

int main(){
    printIntro();
    playGame();
    printf("Thanks for playing!\n");
    return 0;
}