//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function prototype declaration
int levelOne();
int levelTwo();
int levelThree();
int levelFour();
int levelFive();

int main(){
    int choice;
    printf("\nWelcome to Mind-Bending Adventure Game!\n");
    printf("\nObjective: Reach the final level to escape the game!");
    printf("\nYou are stuck in a strange world with no memory of how you got there.\n");
    printf("\nYou see 5 doors in front of you.\n");
    printf("\nChoose wisely which door to enter to proceed through the game.\n");
    while (1) {
        printf("\nLevel 1:");
        printf("\nChoose door 1, 2, 3, 4, or 5 to enter: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                levelOne();
                break;
            case 2:
                printf("\nYou enter door 2 and find a small creature who challenges you to a riddle. Unfortunately, you fail to answer the riddle and the creature attacks you. GAME OVER");
                exit(1);
            case 3:
                printf("\nYou enter door 3 and find a water trap. You manage to swim through the trap but lose precious time. You go back to level 1 and try again.");
                continue;
            case 4:
                printf("\nYou enter door 4 and find yourself on a different planet, unable to find your way back. GAME OVER.");
                exit(1);
            case 5:
                printf("\nYou enter door 5 and find yourself in a room filled with mirrors. You see someone else in the room and follow them. You proceed to level 2!\n");
                levelTwo();
                break;
            default:
                printf("\nInvalid choice. Please choose between doors 1, 2, 3, 4, or 5.");
                break;
        }
    }
    return 0;
}

int levelOne() {
    int choice;
    printf("\nYou enter door 1 and find yourself in a room with 4 doors!");
    printf("\nChoose your next door wisely...\n");
    while (1) {
        printf("\nLevel 1.2:");
        printf("\nChoose door 1, 2, 3, or 4 to enter: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("\nYou enter door 1 and find a locked room. You don't have the key. You go back to level 1.1.");
                continue;
            case 2:
                printf("\nYou enter door 2 and find yourself in a maze. You lose your way and go back to level 1!");
                continue;
            case 3:
                printf("\nYou enter door 3 and find a set of stairs heading down. You go down to level 2!");
                levelTwo();
                break;
            case 4:
                printf("\nYou enter door 4 and find yourself in a room filled with poisonous gas. You start feeling dizzy and fall unconscious. GAME OVER.");
                exit(1);
            default:
                printf("\nInvalid choice. Please choose between doors 1, 2, 3, or 4.");
                break;
        }
    }
    return 0;
}

int levelTwo() {
    int choice;
    printf("\nWelcome to Level 2!");
    printf("\nYou find yourself in a room filled with strange artifacts.");
    printf("\nYou see a note on the wall that reads:\n");
    printf("\n'Hop on one leg and say the words, \"Escape this room\"'");
    printf("\nWhat do you do?\n");
    while (1) {
        printf("\nLevel 2:");
        printf("\nDo you hop (y/n)? ");
        getchar(); //to avoid skipping scanf()
        char response = getchar();
        if (response == 'y') {
            printf("\nYou hop on one leg and say the words, \"Escape this room\"");
            printf("\nThe room starts to shake and a secret passage opens. You proceed to level 3!\n");
            levelThree();
        } else if (response == 'n') {
            printf("\nYou don't hop and say the words, but nothing happens. Please try again.");
            continue;
        } else {
            printf("\nInvalid response. Please enter either y/n.");
            continue;
        }
    }
    return 0;
}

int levelThree() {
    int num1 = rand() % 10 + 1; 
    int num2 = rand() % 10 + 1;
    int sum = num1 + num2;
    int choice;
    printf("\nWelcome to Level 3!");
    printf("\nYou enter a room with two doors marked with numbers.");
    printf("\nA voice says:\n");
    printf("\n'Answer this math question correctly to proceed.\n");
    printf("\n What is %d + %d?\n", num1, num2);
    while (1) {
        printf("\nLevel 3:");
        printf("\nEnter your answer: ");
        scanf("%d", &choice);
        if (choice == sum) {
            printf("\nYou answer the question correctly and the next door opens. You proceed to level 4!\n");
            levelFour();
        } else {
            printf("\nYou answer the question incorrectly. You are teleported back to level 2. Try again!");
            levelTwo();
        }
    }
    return 0;
}

int levelFour() {
    int secretcode;
    printf("\nWelcome to Level 4!");
    printf("\nYou find yourself trapped in a dark room.");
    printf("\nYou see a safe in the corner of the room with a note that says:\n");
    printf("\n'Enter the correct 4-digit code to unlock the safe and escape the room.'\n");
    while (1) {
        printf("\nLevel 4:");
        printf("\nEnter the code: ");
        scanf("%d",&secretcode);
        if (secretcode == 1234) {
            printf("\nYou enter the correct code and the safe opens. You find a key that opens the door to level 5!\n");
            levelFive();
        } else {
            printf("\nYou enter the wrong code. The safe locks and you can't try again. GAME OVER");
            exit(1);
        }
    }
    return 0;
}

int levelFive() {
    printf("\nWelcome to Level 5!");
    printf("\nYou enter a bright room and see a figure in the distance.");
    printf("\nThe figure approaches you and says:\n");
    printf("\n'Congratulations. You have made it through the game.'\n");
    printf("\n'You are now free to leave this world and return to your own.'\n");
    printf("\nThe figure disappears and you wake up in your bed. You realise it was all just a dream...or was it?\n");
    exit(1);
    return 0;
}