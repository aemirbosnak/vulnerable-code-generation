//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

// Define some structures for our spooky characters
typedef struct {
    char name[20];
    int scare_level;
    char description[100];
} Ghost;

typedef struct {
    char name[20];
    int health;
    int attack;
} Monster;

// Create some haunting entities
Ghost my_ghost = {"Creepy Carl", 8, "A tall, gaunt figure with glowing eyes and a menacing grin."};
Monster the_zombie = {"Freddy Flesh", 10, 3};

// Function to randomly select a spooky entity to appear
void pick_scary_thing() {
    int roll_dice = rand() % 2;

    if (roll_dice) {
        printf("\n%s appears!\n", my_ghost.name);
        printf("%s\n", my_ghost.description);
        my_ghost.scare_level += 2;
    } else {
        printf("\n%s rises from the grave!\n", the_zombie.name);
        printf("A stinky, decaying creature with %d hit points and %d attack points.\n", the_zombie.health, the_zombie.attack);
        the_zombie.attack += 2;
    }
}

// Main function to simulate a haunted house experience
int main() {
    int age;
    char response;

    // Set up the haunted house environment
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are %d years old and entering the haunted house at your own risk.\n", &age);

    // Run the simulation until the user decides to leave
    while (1) {
        pick_scary_thing();
        printf("\nDo you want to continue (Y/N)? ");
        scanf("%c", &response);

        // Convert the user's response to uppercase for easier comparison
        response = toupper(response);

        // If the user wants to leave, exit the simulation
        if (response == 'N') {
            printf("You have left the Haunted House Simulator.\n");
            break;
        }

        // If the user wants to continue, roll some dice to see if they encounter another scary thing
        int roll_dice = rand() % 3;

        if (roll_dice) {
            printf("You managed to avoid any further scares.\n");
        } else {
            printf("Another scary thing appears!\n");
            pick_scary_thing();
        }
    }

    return 0;
}