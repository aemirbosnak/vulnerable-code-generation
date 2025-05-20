//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up random numbers
    srand(time(NULL));
    int ghost = rand() % 2;
    int candle = rand() % 2;
    int door = rand() % 2;
    int room, answer;
    
    // Print game introduction
    printf("Welcome to the haunted house!\n");
    printf("You are in a dark room with one door and a candle.\n");
    
    // Ask the user for input
    printf("Do you want to light the candle? (1 = Yes, 0 = No)\n");
    scanf("%d", &answer);
    
    // Set the candle based on user input
    if(answer == 1) {
        candle = 1;
        printf("You lit the candle, illuminating the room.\n");
    } else {
        candle = 0;
        printf("You decided not to light the candle and are in complete darkness.\n");
    }
    
    // Ask the user for input
    printf("Do you want to open the door? (1 = Yes, 0 = No)\n");
    scanf("%d", &answer);
    
    // Set the door based on user input
    if(answer == 1) {
        door = 1;
        printf("You opened the door and walked into another room.\n");
    } else {
        door = 0;
        printf("You decided not to open the door and remain in the same room.\n");
    }
    
    // Set up the next room
    room = rand() % 2;
    
    // Check if the user encountered a ghost
    if(room == ghost) {
        printf("You encountered a ghost and died.\n");
        return 0;
    }
    
    // Ask the user for input
    printf("Do you want to light the candle in the new room? (1 = Yes, 0 = No)\n");
    scanf("%d", &answer);
    
    // Set the candle based on user input
    if(answer == 1) {
        candle = 1;
        printf("You lit the candle, illuminating the new room.\n");
    } else {
        candle = 0;
        printf("You decided not to light the candle and are in complete darkness.\n");
    }
    
    // Ask the user for input
    printf("Do you want to open the door in the new room? (1 = Yes, 0 = No)\n");
    scanf("%d", &answer);
    
    // Set the door based on user input
    if(answer == 1) {
        door = 1;
        printf("You opened the door and walked into another room.\n");
    } else {
        door = 0;
        printf("You decided not to open the door and remain in the same room.\n");
    }
    
    // Set up the next room
    room = rand() % 2;
    
    // Check if the user encountered a ghost
    if(room == ghost) {
        printf("You encountered a ghost and died.\n");
        return 0;
    }
    
    // Check if the user made it to the end
    if(room == 1 && door == 1 && candle == 1) {
        printf("Congratulations! You made it through the haunted house.\n");
        return 0;
    }
    
    // Print game over message
    printf("You made it to the end, but did not meet the requirements. Game over.\n");
    
    return 0;
}