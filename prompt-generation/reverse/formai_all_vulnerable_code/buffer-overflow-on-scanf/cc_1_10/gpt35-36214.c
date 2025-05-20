//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define shape-shifting functions
void dino(int year);
void knight(int year);
void pirate(int year);
void ninja(int year);

int main()
{
    // Declare variables 
    int year;
    char shape[15];
    
    // Get user input for year and shape
    printf("Enter a year: ");
    scanf("%d", &year);
    printf("Enter a shape (dino, knight, pirate, ninja): ");
    scanf("%s", shape);
    
    // Determine which shape-shifting function to call based on user input
    if(strcmp(shape, "dino") == 0)
        dino(year);
    else if(strcmp(shape, "knight") == 0)
        knight(year);
    else if(strcmp(shape, "pirate") == 0)
        pirate(year);
    else if(strcmp(shape, "ninja") == 0)
        ninja(year);
    else
        printf("Invalid shape entered.\n");
        
    return 0;
}

// Function that transforms user into a dinosaur
void dino(int year)
{
    printf("\nWelcome to the land of the dinosaurs!\n\n");
    
    // Calculate how many millions of years ago the user has traveled
    int age = 2019 - year;
    int millions = age/1000000;
    
    // Print out relevant information about the time period
    printf("You have traveled back in time approximately %d million years.\n", millions);
    printf("The climate is warm and humid, and there are lush forests everywhere.\n");
    printf("You see all kinds of interesting creatures, including the mighty T-Rex!\n");
}

// Function that transforms user into a knight
void knight(int year)
{
    printf("\nWelcome to the age of chivalry!\n\n");

    // Print out relevant information about the time period
    printf("You have traveled back in time to the year %d.\n", year);
    printf("The air is thick with the scent of horses and iron.\n");
    printf("You see knights in shining armor galloping about and fighting for honor and glory.\n");
}

// Function that transforms user into a pirate
void pirate(int year)
{
    printf("\nWelcome aboard, matey!\n\n");    

    // Calculate how far back the user has traveled in time
    int age = 2019 - year;
    
    // Print out relevant information about the time period
    printf("You have traveled back in time approximately %d years.\n", age);
    printf("The salty sea air fills your nostrils as you gaze upon the deck of a mighty pirate ship.\n");
    printf("You see the Jolly Roger flying high and the ship is manned by a fierce crew of scallywags!\n");
}

// Function that transforms user into a ninja
void ninja(int year)
{
    printf("\nWelcome to feudal Japan!\n\n");

    // Print out relevant information about the time period
    printf("You have traveled back in time to the year %d.\n", year);
    printf("You find yourself in the midst of a war-torn land ruled by shoguns and their armies.\n");
    printf("But you have been trained in the ways of the ninja, and you are prepared to face any challenge!\n");
}