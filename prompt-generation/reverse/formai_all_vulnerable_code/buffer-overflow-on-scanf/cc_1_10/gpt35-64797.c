//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random numbers
int generateRandomNumber(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

//Function to simulate player entering a room
void enterRoom(int roomNum) {
    printf("\nYou enter room %d...", roomNum);
    sleep(1);
    printf("\nThe door slams shut behind you and locks automatically.");
    sleep(1);
    printf("\nYou are trapped in this room.");
    sleep(1);
}

//Function to simulate player solving a puzzle
int solvePuzzle(int roomNum) {
    printf("\n\nYou look around the room and find a note on the wall with a puzzle written on it.");
    printf("\n\nSolve the puzzle to escape this room.");
    printf("\n\nPress enter when ready...");
    getchar();
    int num1 = generateRandomNumber(1, 10);
    int num2 = generateRandomNumber(1, 10);
    int result = num1 + num2;
    int userAnswer;
    printf("\n\nWhat is %d + %d?", num1, num2);
    scanf("%d", &userAnswer);
    if (userAnswer == result) {
        printf("\n\nCongratulations! You have solved the puzzle and escaped room %d.", roomNum);
        return 1;
    }
    else {
        printf("\n\nIncorrect! You are still trapped in room %d.", roomNum);
        return 0;
    }
}

int main() {
    srand(time(NULL));
    int roomNum = 1;
    int escapedRooms = 0;
    while (escapedRooms < 3) {
        enterRoom(roomNum);
        if (solvePuzzle(roomNum)) {
            escapedRooms++;
        }
        roomNum++;
    }
    printf("\n\nYou have successfully escaped the haunted house!");
    printf("\n\nPress enter to exit...");
    getchar();
    return 0;
}