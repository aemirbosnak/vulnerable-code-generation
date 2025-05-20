//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPTIONS 4
#define MAX_MESSAGE_LENGTH 256

typedef struct {
    char question[MAX_MESSAGE_LENGTH];
    char options[MAX_OPTIONS][MAX_MESSAGE_LENGTH];
    int correctOption; 
} Room;

Room rooms[] = {
    {"You are standing at the entrance of a decrepit haunted house. What do you wish to do?", 
        {"Enter the house", "Walk away", "Call for help", "Inspect the surroundings"}, 0},
    {"You step inside and hear a distant laugh echoing. You see three doors. Which door do you choose?", 
        {"Door 1 - The shadowy one", "Door 2 - The one with the flickering light", "Door 3 - The one covered with cobwebs", "Leave the house"}, 1},
    {"Inside the door, there's a ghostly figure dancing. What action do you take?", 
        {"Dance with it", "Scream", "Run back", "Take a picture"}, 0},
    {"You and the ghost are dancing, the floor creaks ominously. Suddenly, the lights go out! What do you do?", 
        {"Wait and listen", "Shout for help", "Try to find a light", "Jump up and down"}, 2},
    {"You find a flashlight. It's dim but functional. You see two paths, one to the basement, one to the attic. Which do you take?", 
        {"Go to the basement", "Go to the attic", "Stay here", "Exit the house"}, 1},
    {"In the attic, you find a mirror that shows dark reflections of your worst fears. How do you react?", 
        {"Touch the mirror", "Cover it", "Break it", "Flee back"}, 2},
    {"You shattered the mirror but now the reflections spill out and surround you! What do you do?", 
        {"Face them head-on", "Run for the stairs", "Attempt to reason with them", "Scream loudly"}, 0},
    {"These were your unresolved fears - they vanish after you confront them. Do you want to explore more?", 
        {"Yes, deeper into the house", "No, I want to leave", "Look for hidden treasure", "Call a friend"}, 1}
};

int currentRoom = 0;

void displayRoom() {
    printf("\n%s\n", rooms[currentRoom].question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d: %s\n", i + 1, rooms[currentRoom].options[i]);
    }
}

int getInput() {
    int choice;
    printf("Enter your choice (1-%d): ", MAX_OPTIONS);
    scanf("%d", &choice);
    
    if (choice < 1 || choice > MAX_OPTIONS) {
        printf("Invalid choice! Try again.\n");
        return getInput();
    }

    return choice - 1; 
}

void transitionToNextRoom(int choice) {
    if (choice == rooms[currentRoom].correctOption) {
        currentRoom++;
        if (currentRoom >= sizeof(rooms)/sizeof(Room)) {
            printf("\nYou've reached the end of the haunted house safely. Congratulations!\n");
            exit(0);
        } 
    } else {
        printf("\nThe house has swallowed you whole! Game Over!\n");
        exit(0);
    }
}

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    srand(time(0)); 

    while (1) {
        displayRoom();
        int choice = getInput();
        transitionToNextRoom(choice);
    }

    return 0;
}