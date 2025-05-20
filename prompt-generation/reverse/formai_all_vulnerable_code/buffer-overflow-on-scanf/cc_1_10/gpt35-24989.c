//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int randomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void wait(int seconds) {
    clock_t endWait;
    endWait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endWait) {}
}

void printSlowly(char* text, int speed) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        wait(speed);
    }
}

void enter() {
    printf("\nPress enter to continue...");
    getchar();
}

int main() {
    srand(time(NULL));
    printf("\n*** Welcome to the Haunted Mansion ***\n");
    enter();

    printf("\nYou are at the front entrance.\n");
    enter();

    printf("\nAs you enter, you hear spooky music playing in the background.\n");
    wait(2);
    printf("\nYou see a long hallway in front of you, and two doors on either side.\n");
    enter();

    int choice;
    do {
        printf("\nWhich way do you want to go?\n");
        printf("1. Proceed down the hallway.\n");
        printf("2. Enter the door on the left.\n");
        printf("3. Enter the door on the right.\n");
        printf("4. Quit the game.\n");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            int randomNum = randomNumber(1, 3);
            if (randomNum == 1) {
                printf("\nYou hear a loud scream coming from the end of the hallway.\n");
                wait(2);
                printf("\nYou cautiously move forward and realize the scream was just a recording.\n");
            } else if (randomNum == 2) {
                printf("\nYou feel a cold breeze coming towards you and your candle goes out.\n");
                wait(2);
                printf("\nYou hear heavy footsteps and feel a presence behind you.\n");
                wait(2);
                printf("\nSuddenly your candle relights, and the footsteps disappear.\n");
            } else {
                printf("\nYou trip over a loose floorboard and fall to the ground.\n");
                wait(2);
                printf("\nAs you stand up, you realize that the floor is covered in blood.\n");
            }
            enter();
        } else if (choice == 2) {
            printf("\nYou enter the door on the left.\n");
            wait(2);
            printf("\nYou see a spooky ghost floating towards you.\n");
            printf("\nWhat do you do? (1. Run, 2. Hide, 3. Confront the ghost)\n");
            scanf("%d", &choice);
            getchar();
            if (choice == 1) {
                printf("\nYou run away as fast as you can, but the ghost follows you.\n");
                wait(2);
                printf("\nYou end up back at the entrance of the mansion.\n");
            } else if (choice == 2) {
                printf("\nYou hide behind a nearby curtain, and the ghost vanishes.\n");
                wait(2);
                printf("\nYou see a key on the ground where the ghost was floating.\n");
            } else {
                printf("\nYou confront the ghost, and it tells you a riddle.\n");
                wait(2);
                printf("\nIf you answer the riddle correctly, you will be rewarded.\n");
                printf("\nWhat is always in front of you but can't be seen?\n");
                char answer[50];
                fgets(answer, 50, stdin);
                char correct[] = "future";
                if (strcasecmp(answer, correct) == 0) {
                    printf("\nThe ghost congratulates you and gives you a key.\n");
                } else {
                    printf("\nThe ghost disappears in disappointment.\n");
                }
            }
            enter();
        } else if (choice == 3) {
            printf("\nYou enter the door on the right.\n");
            wait(2);
            printf("\nYou see a room filled with creepy dolls.\n");
            printf("\nWhat do you do? (1. Ignore them and search the room, 2. Check out the dolls)\n");
            scanf("%d", &choice);
            getchar();
            if (choice == 1) {
                printf("\nYou search the room and find a diary.\n");
                wait(2);
                printf("\nAs you read through it, you learn about the history of the mansion.\n");
                printf("\nApparently a young girl who loved dolls lived here, but she disappeared mysteriously.\n");
            } else {
                printf("\nAs you approach the dolls, they suddenly start moving and talking.\n");
                wait(2);
                printf("\nYou realize that they are possessed.\n");
                printf("\nWhat do you do? (1. Run, 2. Try to communicate with them)\n");
                scanf("%d", &choice);
                getchar();
                if (choice == 1) {
                    printf("\nYou run away as fast as you can, but the dolls follow you.\n");
                    wait(2);
                    printf("\nYou end up back at the entrance of the mansion.\n");
                } else {
                    printf("\nYou start talking to the dolls, and they reveal their secrets to you.\n");
                    wait(2);
                    printf("\nThey tell you the location of a secret room in the mansion.\n");
                }
            }
            enter();
        } else if (choice != 4) {
            printf("\nInvalid choice. Try again.\n");
            enter();
        }
    } while (choice != 4);

    printf("\nThank you for playing the Haunted Mansion game!\n");
    return 0;
}