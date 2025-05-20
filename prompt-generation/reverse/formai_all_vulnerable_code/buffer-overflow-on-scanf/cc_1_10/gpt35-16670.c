//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Haunted House Simulator\n");
    printf("You find yourself standing in front of a mysterious old mansion.\n");
    printf("It's dark and creepy and you have a feeling that you should turn around and leave.\n");
    printf("But you are a brave soul, and you decide to enter the mansion and investigate.\n");
    printf("\n");

    // Room 1: Entrance
    printf("You enter the mansion and find yourself in a large entrance hall.\n");
    printf("It's dark and silent, but you can hear strange noises coming from the other rooms.\n");
    printf("You see three doors: one to your left, one to your right, and one straight ahead.\n");
    printf("Which door do you choose?\n");

    char input;
    scanf("%c", &input);

    if (input == 'l') {
        printf("You open the door to your left and step into a dark room.\n");
        // Room 2: Library
        printf("You find yourself in what appears to be a library.\n");
        printf("The shelves are filled with old books, and the room is musty and damp.\n");
        printf("You hear whispers and footsteps behind you, but when you turn around, no one is there.\n");
        printf("Suddenly, a book flies off the shelf and hits you in the back of the head!\n");
        printf("You quickly exit the room, feeling like someone or something is watching you.\n");
    } else if (input == 'r') {
        printf("You open the door to your right and step into a dimly lit room.\n");
        // Room 3: Dining Room
        printf("You find yourself in what appears to be a dining room.\n");
        printf("The table is set for a meal, with candles burning and plates of food.\n");
        printf("But when you look closer, you realize that the food is rotting and covered in maggots.\n");
        printf("Suddenly, the candles flicker and go out, and you hear laughter echoing through the room.\n");
        printf("You quickly exit the room, feeling like something is chasing you.\n");
    } else if (input == 's') {
        printf("You walk straight ahead and enter a large, grand room.\n");
        // Room 4: Ballroom
        printf("You find yourself in what appears to be a ballroom.\n");
        printf("The room is filled with beautiful chandeliers and elegant décor.\n");
        printf("But when you step onto the dance floor, you realize that the room is haunted.\n");
        printf("You see ghosts dancing around you, and you feel cold fingers touching you.\n");
        printf("You quickly exit the room, feeling like you barely escaped with your life.\n");
    } else {
        printf("You hesitate and do not enter any of the doors.\n");
        printf("You suddenly feel a cold breeze and the ground starts shaking.\n");
        printf("You realize that you are trapped in the house forever.\n");
        printf("You fall to the ground and succumb to the darkness.\n");
        exit(0); // End program
    }

    // Final room: Exit
    printf("\n");
    printf("You exit the mansion and feel relieved to be back outside.\n");
    printf("The sun starts to rise and the birds start singing.\n");
    printf("You realize that you survived the Haunted House Simulator, congratulations!\n");

    return 0;
}