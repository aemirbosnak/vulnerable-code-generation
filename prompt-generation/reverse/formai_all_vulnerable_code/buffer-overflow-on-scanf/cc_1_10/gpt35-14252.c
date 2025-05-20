//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //seed for randomization
    srand(time(NULL));
    //initialize variables for game
    int roomNum = 1;
    int choice = 0;
    int monsterInRoom = 0;
    //generate random monster location
    int monsterLocation = rand() % 10 + 1;
    //game loop
    while(roomNum <= 10) {
        //check if monster is in room
        if(roomNum == monsterLocation) {
            monsterInRoom = 1;
        }
        else {
            monsterInRoom = 0;
        }
        //print room info
        printf("You are in room %d\n", roomNum);
        if(monsterInRoom) {
            printf("There is a monster in the room!\n");
        }
        printf("Choose your action:\n");
        printf("1. Move to the next room\n");
        printf("2. Try to escape the haunted house\n");
        //take user input
        scanf("%d", &choice);
        //process user input
        if(choice == 1) {
            roomNum++;
        }
        else if(choice == 2) {
            //check if monster is in room
            if(monsterInRoom) {
                printf("You can't escape the monster!\n");
            }
            else {
                //check if user has reached final room
                if(roomNum == 10) {
                    printf("Congratulations! You have successfully escaped the haunted house!\n");
                }
                else {
                    printf("You can't escape yet! Keep moving!\n");
                }
            }
        }
        else {
            printf("Invalid choice! Choose again.\n");
        }
    }
    return 0;
}