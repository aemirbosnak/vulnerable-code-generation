//GEMINI-pro DATASET v1.0 Category: Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_SUSPECTS 10
#define MAX_WEAPONS 10
#define MAX_ROOMS 10

// Data structures
typedef struct {
    char name[20];
    int present;
} Suspect;

typedef struct {
    char name[20];
    int used;
} Weapon;

typedef struct {
    char name[20];
    int visited;
} Room;

// Global variables
Suspect suspects[MAX_SUSPECTS];
Weapon weapons[MAX_WEAPONS];
Room rooms[MAX_ROOMS];

// Function prototypes
void initializeGame();
void printSuspects();
void printWeapons();
void printRooms();
void playGame();

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the game
    initializeGame();

    // Play the game
    playGame();

    return 0;
}

// Function to initialize the game
void initializeGame() {
    // Initialize the suspects
    strcpy(suspects[0].name, "Colonel Mustard");
    suspects[0].present = 1;
    strcpy(suspects[1].name, "Miss Scarlett");
    suspects[1].present = 1;
    strcpy(suspects[2].name, "Professor Plum");
    suspects[2].present = 1;
    strcpy(suspects[3].name, "Mrs. White");
    suspects[3].present = 1;
    strcpy(suspects[4].name, "Mr. Green");
    suspects[4].present = 1;
    strcpy(suspects[5].name, "Mrs. Peacock");
    suspects[5].present = 1;

    // Initialize the weapons
    strcpy(weapons[0].name, "Candlestick");
    weapons[0].used = 0;
    strcpy(weapons[1].name, "Dagger");
    weapons[1].used = 0;
    strcpy(weapons[2].name, "Lead pipe");
    weapons[2].used = 0;
    strcpy(weapons[3].name, "Revolver");
    weapons[3].used = 0;
    strcpy(weapons[4].name, "Rope");
    weapons[4].used = 0;
    strcpy(weapons[5].name, "Wrench");
    weapons[5].used = 0;

    // Initialize the rooms
    strcpy(rooms[0].name, "Hall");
    rooms[0].visited = 0;
    strcpy(rooms[1].name, "Lounge");
    rooms[1].visited = 0;
    strcpy(rooms[2].name, "Dining Room");
    rooms[2].visited = 0;
    strcpy(rooms[3].name, "Kitchen");
    rooms[3].visited = 0;
    strcpy(rooms[4].name, "Ballroom");
    rooms[4].visited = 0;
    strcpy(rooms[5].name, "Conservatory");
    rooms[5].visited = 0;
    strcpy(rooms[6].name, "Billiard Room");
    rooms[6].visited = 0;
    strcpy(rooms[7].name, "Library");
    rooms[7].visited = 0;
    strcpy(rooms[8].name, "Study");
    rooms[8].visited = 0;
    strcpy(rooms[9].name, "Hall");
    rooms[9].visited = 0;
}

// Function to print the suspects
void printSuspects() {
    printf("Suspects:\n");
    for (int i = 0; i < MAX_SUSPECTS; i++) {
        printf("%d. %s\n", i + 1, suspects[i].name);
    }
}

// Function to print the weapons
void printWeapons() {
    printf("Weapons:\n");
    for (int i = 0; i < MAX_WEAPONS; i++) {
        printf("%d. %s\n", i + 1, weapons[i].name);
    }
}

// Function to print the rooms
void printRooms() {
    printf("Rooms:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("%d. %s\n", i + 1, rooms[i].name);
    }
}

// Function to play the game
void playGame() {
    // Print the suspects, weapons, and rooms
    printSuspects();
    printWeapons();
    printRooms();

    // Get the player's input
    int suspect, weapon, room;
    printf("Enter the number of the suspect (1-%d): ", MAX_SUSPECTS);
    scanf("%d", &suspect);
    printf("Enter the number of the weapon (1-%d): ", MAX_WEAPONS);
    scanf("%d", &weapon);
    printf("Enter the number of the room (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);

    // Check if the player's input is valid
    if (suspect < 1 || suspect > MAX_SUSPECTS || weapon < 1 || weapon > MAX_WEAPONS || room < 1 || room > MAX_ROOMS) {
        printf("Invalid input. Please try again.\n");
        return;
    }

    // Check if the player's guess is correct
    if (suspects[suspect - 1].present == 1 && weapons[weapon - 1].used == 1 && rooms[room - 1].visited == 1) {
        printf("Congratulations! You have solved the case.\n");
    } else {
        printf("Sorry, your guess is incorrect. Please try again.\n");
    }
}