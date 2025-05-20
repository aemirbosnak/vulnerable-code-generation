//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void printOpening();
void printIntro();
void printHelm();
void printNav();
void printSensors();
void printEngineering();
void printEnding();
void printFinalMessage();

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Initialize variables
    int distance = rand() % 500;
    int oxygenLevel = rand() % 100;
    int shieldLevel = rand() % 100;
    int resources = rand() % 100;
    int choice;

    // Print the opening message
    printOpening();

    // Print the introduction
    printIntro();

    // Ask the player for their choice
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    // Print the appropriate screen based on the choice
    switch (choice) {
        case 1:
            printHelm();
            break;
        case 2:
            printNav();
            break;
        case 3:
            printSensors();
            break;
        case 4:
            printEngineering();
            break;
        case 5:
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    // Print the ending message
    printEnding();

    // Print the final message
    printFinalMessage();

    return 0;
}

void printOpening()
{
    printf("\n            Romeo and Juliet Space Adventure             \n");
    printf("========================================================\n\n");
    printf("Welcome to the Romeo and Juliet Space Adventure!\n");
    printf("Our story takes place in the year 2478, in a distant galaxy.\n");
    printf("You have been selected to lead a mission to explore a new planet.\n");
    printf("Your mission is to collect data on the planet and bring it back to Earth for analysis.\n\n");
}

void printIntro()
{
    printf("After several months of travel, you arrive at your destination.\n");
    printf("The planet seems to be uninhabited, but there are signs of a previous civilization.\n");
    printf("You begin collecting data when suddenly your ship is hit by an asteroid!\n");
    printf("You must make some quick decisions to save your crew and complete the mission.\n\n");
    printf("What do you do?\n");
    printf("1. Take control of the helm and try to dodge the asteroid.\n");
    printf("2. Check the navigation system to see if there is a safer route.\n");
    printf("3. Use the sensors to scan the asteroid and look for weak points.\n");
    printf("4. Head to engineering to try and reinforce the ship's shields.\n");
    printf("5. Do nothing and hope for the best.\n\n");
}

void printHelm()
{
    printf("You take control of the helm and try to dodge the asteroid.\n");
    printf("You are able to avoid it, but you lose some resources in the process.\n");
    printf("Your crew is impressed with your piloting skills.\n");
    printf("However, when you return to collecting data, you notice that the planet's atmosphere is starting to affect your oxygen levels.\n");
}

void printNav()
{
    printf("You check the navigation system and find a safer route.\n");
    printf("You avoid the asteroid and continue collecting data.\n");
    printf("Your crew is grateful for your quick thinking.\n");
    printf("However, as you continue exploring, you notice that the planet's magnetic field is interfering with your sensors.\n");
}

void printSensors()
{
    printf("You use the sensors to scan the asteroid and find a weak point.\n");
    printf("You are able to destroy it and continue collecting data.\n");
    printf("Your crew is impressed with your resourcefulness.\n");
    printf("However, as you continue exploring, you notice that the planet's magnetic field is interfering with your sensors.\n");
}

void printEngineering()
{
    printf("You head to engineering and try to reinforce the ship's shields.\n");
    printf("You are successful and your crew is impressed.\n");
    printf("However, as you return to collecting data, you notice that the planet's atmosphere is starting to affect your oxygen levels.\n");
}

void printEnding()
{
    printf("After several hours of exploring, you have collected all the data you need.\n");
    printf("However, you notice that your ship's resources are running low and you'll need to head back to Earth soon.\n");
    printf("You make the necessary preparations and head back.\n\n");
    printf("As you enter Earth's atmosphere, you notice that the ship's shields are starting to fail.\n");
    printf("You must make a quick decision to save your crew.\n\n");
    printf("What do you do?\n");
    printf("1. Try to land the ship as quickly as possible.\n");
    printf("2. Use the remaining resources to reinforce the shields.\n");
    printf("3. Activate the emergency beacon and wait for rescue.\n\n");
}

void printFinalMessage()
{
    printf("You survived the Romeo and Juliet Space Adventure!\n");
    printf("Your crew was impressed with your decision making skills and you were hailed as a hero.\n");
    printf("However, there is still much to explore in the galaxy.\n");
    printf("Will you take on another mission?\n");
}