//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void printIntro();
int getChoice();
int randomEvent();
void doorCreak();
void footsteps();
void whispers();
void scream();

int main() {
    // initialize random seed
    srand(time(NULL));
    
    // print introduction
    printIntro();
    
    // get user's choice
    int choice = getChoice();
    
    // perform random events
    switch(choice) {
        case 1:
            doorCreak();
            break;
        case 2:
            footsteps();
            break;
        case 3:
            whispers();
            break;
        case 4:
            scream();
            break;
        default:
            printf("Invalid choice. Exiting program.\n");
            return 0;
    }
    
    return 0;
}

// function to print introduction
void printIntro() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Choose an option to experience a random event:\n");
    printf("1. Open a creaky door\n");
    printf("2. Hear footsteps\n");
    printf("3. Listen to whispers\n");
    printf("4. Hear a bloodcurdling scream\n");
}

// function to get user's choice
int getChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to generate random number for events
int randomEvent() {
    int event = rand() % 4 + 1; // generate random number between 1-4
    return event;
}

// function for opening creaky door event
void doorCreak() {
    printf("You open the door...\n");
    int event = randomEvent();
    if(event == 1) {
        printf("...and it creaks loudly. You jump in fear.\n");
    } else {
        printf("...and it doesn't make a sound. You breathe a sigh of relief.\n");
    }
}

// function for hearing footsteps event
void footsteps() {
    printf("You hear footsteps approaching...\n");
    int event = randomEvent();
    if(event == 1) {
        printf("...and they stop right outside the door. You freeze in terror.\n");
    } else {
        printf("...and they fade away. You start to feel a little more calm.\n");
    }
}

// function for listening to whispers event
void whispers() {
    printf("You hear whispers in the distance...\n");
    int event = randomEvent();
    if(event == 1) {
        printf("...and they grow louder. You can't make out what they're saying.\n");
    } else {
        printf("...and they fade away. You're not sure if you're relieved or disappointed.\n");
    }
}

// function for hearing bloodcurdling scream event
void scream() {
    printf("You hear a bloodcurdling scream...\n");
    int event = randomEvent();
    if(event == 1) {
        printf("...and it sounds like it's coming from right behind you. You scream too.\n");
    } else {
        printf("...and it fades away. You're not sure if it was a real scream or just in your head.\n");
    }
}