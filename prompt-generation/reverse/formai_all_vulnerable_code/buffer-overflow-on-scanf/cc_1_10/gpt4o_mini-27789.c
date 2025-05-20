//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

void entrance();
void kitchen();
void library();
void hallway();
void win();
void lose();

int main() {
    printf("Welcome to the Mystery of the Lost Artifact!\n");
    printf("You find yourself in the entrance of a spooky mansion...\n");
    entrance();
    return 0;
}

void entrance() {
    char choice[20];
    printf("You can go to the (k)itchen or the (l)ibrary. What will you do? ");
    scanf("%s", choice);

    if (strcmp(choice, "k") == 0) {
        kitchen();
    } else if (strcmp(choice, "l") == 0) {
        library();
    } else {
        printf("That's not a valid option. Please try again.\n");
        entrance();
    }
}

void kitchen() {
    char choice[20];
    printf("You are in the kitchen. It's dark and you hear strange noises.\n");
    printf("You can go back to the (e)ntrance or explore the (h)allway. What will you do? ");
    scanf("%s", choice);

    if (strcmp(choice, "e") == 0) {
        entrance();
    } else if (strcmp(choice, "h") == 0) {
        hallway();
    } else {
        printf("That's not a valid option. Please try again.\n");
        kitchen();
    }
}

void library() {
    char choice[20];
    printf("You are in a dusty library filled with ancient books.\n");
    printf("You can go back to the (e)ntrance or study the mysterious (b)ook. What will you do? ");
    scanf("%s", choice);

    if (strcmp(choice, "e") == 0) {
        entrance();
    } else if (strcmp(choice, "b") == 0) {
        printf("As you study the book, a ghost appears and scares you to death!\n");
        lose();
    } else {
        printf("That's not a valid option. Please try again.\n");
        library();
    }
}

void hallway() {
    char choice[20];
    printf("You are now in a long, eerie hallway. There are doors on either side.\n");
    printf("You can go back to the (k)itchen or open the (d)oor to the secret room. What will you do? ");
    scanf("%s", choice);

    if (strcmp(choice, "k") == 0) {
        kitchen();
    } else if (strcmp(choice, "d") == 0) {
        win();
    } else {
        printf("That's not a valid option. Please try again.\n");
        hallway();
    }
}

void win() {
    printf("Congratulations! You found the lost artifact in the secret room!\n");
    printf("You win the game! Thank you for playing!\n");
    exit(0);
}

void lose() {
    printf("Game over. You have lost.\n");
    printf("Better luck next time!\n");
    exit(0);
}