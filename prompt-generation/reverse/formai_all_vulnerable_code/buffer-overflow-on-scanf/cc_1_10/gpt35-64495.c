//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clearScreen() {
    system("clear||cls");
}

void pressEnterToContinue() {
    printf("\nPress enter to continue...");
    while (getchar() != '\n');
}

void displayIntro() {
    clearScreen();
    printf("You find yourself in a dark room, not knowing how you got here.\n");
    printf("You cannot see anything around you and there is complete silence.\n");
    printf("You feel a sense of danger and the need to escape this place as soon as possible.\n");
    pressEnterToContinue();
}

void displayOptionMenu(char* options[], int size) {
    int i;
    printf("\nChoose an option below:\n");
    for (i = 0; i < size; i++) {
        printf("%d: %s\n", i+1, options[i]);
    }
    printf("Choice: ");
}

int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

int main() {
    srand(time(0));
    char playerName[50];
    int choice;
    const int numOfRooms = 5;
    int currentRoom = 1;
    int keyFound = 0;
    int escapeAttempts = 0;
    int roomVisited[numOfRooms];
    int i;
    for (i = 0; i < numOfRooms; i++) {
        roomVisited[i] = 0;
    }
    char* options[] = {"Look around the room", "Try to open the door", "Sit down and wait", "Quit game"};
    printf("Welcome to ESCAPE!\n");
    printf("Enter your name: ");
    fgets(playerName, sizeof(playerName), stdin);
    playerName[strlen(playerName) - 1] = '\0';
    displayIntro();
    while (currentRoom <= numOfRooms) {
        clearScreen();
        printf("You are in room %d\n", currentRoom);
        if (roomVisited[currentRoom-1]) {
            printf("You have been in this room before.\n");
        }
        else {
            roomVisited[currentRoom-1] = 1;
        }
        switch (currentRoom) {
            case 1:
                if (keyFound) {
                    printf("You have already found the key in this room.\n");
                }
                else {
                    printf("You cannot see anything around you, it is too dark.\n");
                    printf("However, you stumble upon a table and feel something metallic.\n");
                    printf("Upon further inspection, you realize it is a key!\n");
                    keyFound = 1;
                }
                displayOptionMenu(options, 4);
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        printf("There is nothing else to see in this room.\n");
                        break;
                    case 2:
                        if (keyFound) {
                            printf("You use the key you found to unlock the door.\n");
                            currentRoom++;
                        }
                        else {
                            printf("The door is locked and you do not have the key.\n");
                            printf("You need to find a way to escape this room.\n");
                        }
                        break;
                    case 3:
                        printf("You sit down and wait for some time, hoping that someone will come to rescue you.\n");
                        escapeAttempts++;
                        break;
                    case 4:
                        printf("Thank you for playing ESCAPE! Goodbye!\n");
                        return 0;
                    default:
                        printf("Invalid choice, please try again.\n");
                }
                break;
            case 2:
                printf("You enter a room with four doors leading to different directions.\n");
                displayOptionMenu(options, 4);
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        printf("There are no objects of interest in this room.\n");
                        break;
                    case 2:
                        printf("The door seems to be stuck and you cannot open it.\n");
                        printf("You need to find another way.\n");
                        break;
                    case 3:
                        printf("You sit down and wait, hoping that someone will come to rescue you.\n");
                        escapeAttempts++;
                        break;
                    case 4:
                        printf("Thank you for playing ESCAPE! Goodbye!\n");
                        return 0;
                    default:
                        printf("Invalid choice, please try again.\n");
                }
                currentRoom++;
                break;
            case 3:
                printf("The door behind you shuts instantly, as soon as you enter the room.\n");
                printf("There are two doors in front of you, which one do you choose?\n");
                pressEnterToContinue();
                printf("As soon as you open the left door, you hear a loud noise behind you.\n");
                printf("Do you:\n");
                char* options1[] = {"Turn around and look", "Keep moving forward"};
                displayOptionMenu(options1, 2);
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You see a shadow of a creature behind you, you need to keep moving forward!\n");
                }
                else if (choice == 2) {
                    printf("You escape the creature, but the door locks behind you, trapping you in this room.\n");
                    escapeAttempts++;
                }
                currentRoom++;
                break;
            case 4:
                printf("You enter a room and can hear the sound of running water somewhere inside.\n");
                printf("There is also a switch on the wall.\n");
                char* options2[] = {"Flip the switch", "Do not flip the switch"};
                displayOptionMenu(options2, 2);
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("As soon as you flip the switch, the room starts filling up with water!\n");
                    printf("You need to find a way out of the room before it is too late!\n");
                }
                else if (choice == 2) {
                    printf("The door behind you shuts, trapping you in this room!\n");
                    escapeAttempts++;
                }
                currentRoom++;
                break;
            case 5:
                printf("You enter a room that looks like a laboratory.\n");
                printf("There is a scientist working on something, who seems startled to see you enter.\n");
                printf("He quickly hides something in his pocket and signals you to keep quiet.\n");
                printf("Do you:\n");
                char* options3[] = {"Ask him what he is working on", "Ignore him and try to find a way out"};
                displayOptionMenu(options3, 2);
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("The scientist tells you that he is working on a time machine.\n");
                    printf("He believes that he can get you out of this place, but needs your help.\n");
                    printf("He hands you a few items and gives you instructions on how to activate the machine.\n");
                    printf("You try to activate the machine and close your eyes, hoping for the best...\n");
                    printf("\n\n\nCongrats! You escaped! Thanks for playing ESCAPE!\n\n\n");
                    pressEnterToContinue();
                    return 0;
                }
                else if (choice == 2) {
                    printf("The scientist signals you towards the door and you escape successfully!\n");
                }
                currentRoom++;
                break;
        }
    }
    if (!keyFound) {
        printf("You failed to find the key and are now trapped in this room forever!\n");
    }
    else {
        printf("You ran out of escape attempts and are now trapped in this room forever!\n");
    }
    printf("Thank you for playing ESCAPE! Goodbye!\n");
    return 0;
}