//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed
    
    printf("Welcome to the Cyberpunk Haunted House Simulator!\n\n");
    printf("You are walking down a dark alley and come across an old, run-down building.\n");
    printf("As you approach it, the door creaks open and you can see a dim light coming from inside.\n\n");

    // Room 1 - Entrance
    int ghostChance = rand() % 10 + 1; // random chance of encountering a ghost
    printf("You find yourself in a dimly-lit entrance hall. ");
    if (ghostChance <= 2) { // 20% chance of encountering a ghost
        printf("Suddenly, a ghostly figure appears and rushes towards you! ");
        printf("You try to run but it's too late - the ghost has possessed you.\n");
        printf("GAME OVER\n");
        return 0;
    }
    else {
        printf("The room is empty except for a set of stairs leading up to the next floor.\n");
    }

    // Room 2 - Living Room
    printf("You climb the stairs and find yourself in a large living room. ");
    printf("The furniture is old and covered in dust, but the room is otherwise empty.\n");

    // Room 3 - Kitchen
    printf("As you leave the living room, you enter a small kitchen. ");
    printf("The cabinets are all open and the drawers are empty, but you notice something strange -\n");
    printf("there is a piece of paper on the counter, with the word HELP written on it.\n");
    printf("You hear a weird noise coming from behind the refrigerator. Do you investigate? (Y/N) ");
    char input;
    scanf(" %c", &input);
    if (input == 'Y' || input == 'y') {
        printf("You cautiously approach the refrigerator and slowly pull it away from the wall. ");
        printf("To your horror, you see a group of zombies staring back at you! ");
        printf("You quickly run back to the living room and barricade the door.\n");
    }
    else {
        printf("You decide not to investigate and leave the kitchen. ");
    }

    // Room 4 - Bedroom
    ghostChance = rand() % 10 + 1; // random chance of encountering a ghost
    printf("You climb another flight of stairs and arrive at a bedroom. ");
    if (ghostChance <= 4) { // 40% chance of encountering a ghost
        printf("As you step into the room, you feel a cold breeze and see a ghostly apparition! ");
        printf("You try to leave the room but the door slams shut and you're trapped with the ghost.\n");
        printf("GAME OVER\n");
        return 0;
    }
    else {
        printf("The room is empty except for a bed covered in cobwebs and dust.\n");
    }

    // Room 5 - Attic
    printf("You climb up to the attic and find a small, hidden room at the back. ");
    printf("Inside, you find a dusty old computer and a note that reads:\n");
    printf("WELCOME TO THE SIMULATOR! YOU ARE NOW TRAPPED IN A VIRTUAL REALITY WORLD.\n");
    printf("THE ONLY WAY TO ESCAPE IS TO WIN THE GAME BY FINDING THE HIDDEN KEY IN THE NEXT ROOM.\n\n");

    // Room 6 - Secret Room
    printf("You leave the hidden room and enter a dark hallway. ");
    printf("At the end of the hall, you see a faint light and hear a strange noise.\n");
    printf("As you approach the room, you see a shadowy figure standing in front of a large chest. ");
    printf("The figure turns around and reveals its true form - a demonic creature with razor-sharp claws!\n");
    printf("The only way to defeat the creature is to find the hidden key and open the chest.\n");
    printf("Do you have what it takes to win the game? (Y/N) ");
    scanf(" %c", &input);
    if (input == 'Y' || input == 'y') {
        printf("You search the room and find a hidden panel behind a painting. ");
        printf("Inside, you find the key and quickly make your way back to the chest. ");
        printf("You insert the key and the chest opens, revealing a bright light. ");
        printf("As you step into the light, you feel a strange sensation and suddenly find yourself outside the haunted house. ");
        printf("Congratulations, you have won the game!\n");
        return 0;
    }
    else {
        printf("You try to fight the creature, but it's too powerful. ");
        printf("The creature kills you and you become trapped in the virtual reality world forever.\n");
        printf("GAME OVER\n");
        return 0;
    }
}