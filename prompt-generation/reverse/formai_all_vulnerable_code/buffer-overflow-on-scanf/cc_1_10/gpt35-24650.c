//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define GHOSTS 3
#define ROOMS 5

void printRoom(int room, int ghosts[]) {
    printf("\nYou have entered room %d.\n", room);
    if(!ghosts[room-1])
        printf("The room is empty and nothing is found.\n");
    else {
        printf("You have encountered a ghost!\n");
        ghosts[room-1]--;
        if(!ghosts[room-1]) 
            printf("You have defeated all the ghosts in this room.\n");
        else
            printf("There are still %d ghosts left in this room.\n", ghosts[room-1]);
    }
}

int main() {
    srand(time(0));

    int ghosts[ROOMS];
    for(int i=0; i<ROOMS; i++) 
        ghosts[i] = rand() % GHOSTS + 1;

    printf("Welcome to The Haunted House Simulator\n");
    printf("You will begin in a random room.\n");
    printf("There are %d rooms in total and %d ghosts spread throughout.\n\n", ROOMS, GHOSTS*ROOMS);

    int currentRoom = rand() % ROOMS + 1;
    char choice;
    do {
        printRoom(currentRoom, ghosts);
        printf("Which room would you like to go to? (Enter a number 1-%d or Q to quit): ", ROOMS);
        scanf(" %c", &choice);
        if(choice == 'q' || choice == 'Q')
            break;
        int newRoom = choice - '0';
        if(newRoom < 1 || newRoom > ROOMS) {
            printf("Invalid choice. Please enter a number 1-%d or Q to quit.\n", ROOMS);
            continue;
        }
        currentRoom = newRoom;
    } while(1);

    printf("\nThank you for playing The Haunted House Simulator!\n");
    return 0;
}