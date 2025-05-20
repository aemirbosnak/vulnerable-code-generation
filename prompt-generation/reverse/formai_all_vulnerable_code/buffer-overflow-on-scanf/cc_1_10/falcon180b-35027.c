//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the game introduction
void print_introduction() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to find the legendary treasure!\n");
    printf("Are you ready to begin your journey? (y/n)");
}

// Function to generate a random number between min and max
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the current room description
void print_room_description(int room_number) {
    switch (room_number) {
        case 1:
            printf("You are in a dark and damp cave. You can hear the sound of dripping water echoing through the walls.\n");
            break;
        case 2:
            printf("You have entered a large chamber filled with glittering jewels and gold coins. The treasure is within your reach!\n");
            break;
        default:
            printf("You are in an empty room.\n");
            break;
    }
}

// Function to move the player to a new room
void move_to_new_room(int *current_room, int *treasure_room) {
    int new_room = generate_random_number(1, 3);

    if (new_room == *treasure_room) {
        printf("Congratulations! You have found the treasure!\n");
        exit(0);
    } else {
        *current_room = new_room;
    }
}

// Main function
int main() {
    srand(time(NULL));

    int current_room = 1;
    int treasure_room = generate_random_number(1, 3);

    print_introduction();
    scanf("%c", &current_room);

    while (current_room!= treasure_room) {
        print_room_description(current_room);
        move_to_new_room(&current_room, &treasure_room);
    }

    return 0;
}