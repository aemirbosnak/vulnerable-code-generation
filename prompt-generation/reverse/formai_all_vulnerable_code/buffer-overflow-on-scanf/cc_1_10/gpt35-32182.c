//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void print_instructions();
void print_room_description(int room);
void print_room_options(int room, int flashlight);
int enter_room(int room, int flashlight);
void end_game(int flashlight);

int main()
{
    srand(time(NULL)); // Seed the random number generator
    
    int flashlight = 0; // Player starts without flashlight
    int current_room = 0; // Player starts in room 0 (entrance)
    int game_over = 0; // Variable to keep track of game status
    
    printf("Welcome to the Haunted House Simulator!\n");
    print_instructions();
    
    while (!game_over)
    {
        print_room_description(current_room); 
        print_room_options(current_room, flashlight);
        current_room = enter_room(current_room, flashlight);
        
        // Check flashlight status and end game if necessary
        if (current_room == -1)
            end_game(flashlight); 
        else if (current_room == -2)
            flashlight = 1; // Player found flashlight
        else if (current_room == -3)
            game_over = 1; // Player escaped haunted house
    }
    
    return 0;
}

void print_instructions()
{
    printf("You have entered a haunted house!\n");
    printf("Explore the rooms and try to find a way out.\n");
    printf("Beware of ghosts and other spooky surprises!\n\n");
}

void print_room_description(int room)
{
    switch(room)
    {
        case 0:
            printf("You are in the entrance of the haunted house.\n");
            break;
        case 1:
            printf("You are in a dark hallway. You hear strange noises.\n");
            break;
        case 2:
            printf("You are in a dusty library. Books are stacked everywhere.\n");
            break;
        case 3:
            printf("You are in a creepy bedroom. The furniture is covered in cobwebs.\n");
            break;
        case 4:
            printf("You are in a kitchen. Old pots and pans clutter the counters.\n");
            break;
        case 5:
            printf("You are in a basement. The stairs creak as you descend.\n");
            break;
        case 6:
            printf("You have found a flashlight! This will help you navigate the dark.\n");
            break;
        default:
            printf("Error: Invalid room number.\n");
            break;
    }
}

void print_room_options(int room, int flashlight)
{
    printf("Options:\n");
    
    switch(room)
    {
        case 0:
            printf("1) Go to hallway.\n");
            printf("2) Go to library.\n");
            break;
        case 1:
            printf("1) Go to entrance.\n");
            printf("2) Go to bedroom.\n");
            if (flashlight)
                printf("3) Search for something useful.\n");
            break;
        case 2:
            printf("1) Go to entrance.\n");
            printf("2) Go to kitchen.\n");
            break;
        case 3:
            printf("1) Go to hallway.\n");
            if (flashlight)
                printf("2) Search for something useful.\n");
            break;
        case 4:
            printf("1) Go to hallway.\n");
            if (flashlight)
                printf("2) Search for something useful.\n");
            break;
        case 5:
            printf("1) Go to basement exit.\n");
            if (flashlight)
                printf("2) Search for something useful.\n");
            break;
        case 6:
            printf("1) Go to kitchen.\n");
            break;
        default:
            printf("Error: Invalid room number.\n");
            break;
    }
    
    printf("Enter your choice: ");
}

int enter_room(int room, int flashlight)
{
    int choice;
    
    scanf("%d", &choice);
    printf("\n");
    
    switch(room)
    {
        case 0:
            if (choice == 1)
                return 1;
            else if (choice == 2)
                return 2;
            else
                printf("Invalid choice.\n");
            break;
        case 1:
            if (choice == 1)
                return 0;
            else if (choice == 2)
                return 3;
            else if ((choice == 3) && (flashlight))
                return -2; // Found flashlight
            else
                printf("Invalid choice.\n");
            break;
        case 2:
            if (choice == 1)
                return 0;
            else if (choice == 2)
                return 4;
            else
                printf("Invalid choice.\n");
            break;
        case 3:
            if (choice == 1)
                return 1;
            else if ((choice == 2) && (flashlight))
                return -3; // Escaped the house
            else
                printf("Invalid choice.\n");
            break;
        case 4:
            if (choice == 1)
                return 1;
            else if ((choice == 2) && (flashlight))
                return -1; // Game over, encountered a ghost
            else
                printf("Invalid choice.\n");
            break;
        case 5:
            if (choice == 1)
                return 0;
            else if ((choice == 2) && (flashlight))
                return 6; // Found flashlight
            else
                printf("Invalid choice.\n");
            break;
        case 6:
            if (choice == 1)
                return 4;
            else
                printf("Invalid choice.\n");
            break;
        default:
            printf("Error: Invalid room number.\n");
            break;
    }
    
    return room;
}

void end_game(int flashlight)
{
    if (flashlight)
        printf("You have found a way out of the haunted house!\n");
    else
        printf("You were eaten by a ghost. Better luck next time!\n");
}