//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void clear() {
    system("clear"); // clears terminal window
}

void pause() {
    printf("\nPress enter to continue...");
    getchar(); // waits for user input
}

void intro() {
    printf("Welcome to The Lost Island!\n");
    printf("You are searching for a valuable treasure on a deserted island.\n");
    printf("You have heard that the treasure is guarded by dangerous creatures.\n");
    printf("Are you brave enough to find the treasure?\n\n");
    pause();
}

void firstScene() {
    clear();
    printf("You find yourself on a sandy beach, surrounded by dense jungle.\n");
    printf("You can hear strange noises coming from the jungle.\n");
    printf("What do you want to do?\n\n");
    printf("1. Head into the jungle\n");
    printf("2. Stay on the beach\n\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You enter the jungle.\n");
            pause();
            break;
        case 2:
            printf("You decide to stay on the beach.\n");
            pause();
            break;
        default:
            printf("Invalid choice. Try again.\n");
            pause();
            firstScene(); // recursion to start again
            break;
    }
}

void secondScene() {
    clear();
    printf("You walk deeper into the jungle and come across a river.\n");
    printf("The river water looks clear and inviting, but you're not sure if it's safe to drink.\n");
    printf("What do you want to do?\n\n");
    printf("1. Drink from the river\n");
    printf("2. Follow the river\n");
    printf("3. Ignore the river and continue into the jungle\n\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You take a sip of the water and feel instantly refreshed.\n");
            pause();
            break;
        case 2:
            printf("You follow the river and come across a waterfall.\n");
            pause();
            break;
        case 3:
            printf("You decide to ignore the river and venture further into the jungle.\n");
            pause();
            break;
        default:
            printf("Invalid choice. Try again.\n");
            pause();
            secondScene(); // recursion to start again
            break;
    }
}

void thirdScene() {
    clear();
    printf("You arrive at the entrance of a dark and ominous cave.\n");
    printf("You can hear strange noises coming from inside.\n");
    printf("What do you want to do?\n\n");
    printf("1. Enter the cave\n");
    printf("2. Go back and find another way\n\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You cautiously step inside the cave.\n");
            pause();
            break;
        case 2:
            printf("You decide to go back and find another way.\n");
            pause();
            break;
        default:
            printf("Invalid choice. Try again.\n");
            pause();
            thirdScene(); // recursion to start again
            break;
    }
}

void fourthScene() {
    clear();
    printf("You find yourself in a large chamber, filled with shining treasure and dangerous creatures!\n");
    printf("What do you want to do?\n\n");
    printf("1. Grab as much treasure as you can and run!\n");
    printf("2. Fight the creatures and take the treasure!\n");
    printf("3. Ignore the treasure and find a way out of the cave\n\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You stuff your pockets with as much treasure as you can carry and run out of the cave!\n");
            pause();
            break;
        case 2:
            printf("You fight bravely against the creatures and emerge victorious!\nYou collect the treasure and make your way out of the cave.\n");
            pause();
            break;
        case 3:
            printf("You decide not to risk your life for treasure and find a way out of the cave.\n");
            pause();
            break;
        default:
            printf("Invalid choice. Try again.\n");
            pause();
            fourthScene(); // recursion to start again
            break;
    }
}

void gameOver() {
    clear();
    printf("Game over. You have failed to find the treasure.\n");
    pause();
    exit(EXIT_SUCCESS);
}

void win() {
    clear();
    printf("Congratulations, you have found the treasure and completed the game!\n");
    pause();
    exit(EXIT_SUCCESS);
}

int main() {
    intro();
    firstScene();
    secondScene();
    thirdScene();
    fourthScene();
    win(); // finish the game successfully
    return 0;
}