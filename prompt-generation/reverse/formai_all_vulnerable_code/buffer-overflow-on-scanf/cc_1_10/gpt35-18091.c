//FormAI DATASET v1.0 Category: Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to print game intro
void intro() {
    printf("Welcome to Escape the Castle!\n");
    printf("You find yourself trapped in a castle and must escape before the time runs out.\n");
    printf("There are various rooms with different challenges to overcome.\n");
    printf("To win the game, you must reach the exit before the timer hits zero!\n\n");
}

// Function to print the current room description
void description(int room) {
    switch(room) {
        case 1:
            printf("You are in the first room. The door behind you has shut, and there seems to be no way back.\n");
            printf("You see a table in front of you with three keys, but only one of them can open the door ahead.\n");
            break;
        case 2:
            printf("You are in the second room, which is dimly lit by torches. There is a riddle written on the wall with a clue to the next room.\n");
            printf("The riddle reads: 'I speak without a mouth and hear without ears. I have no body, but I come alive with wind. What am I?'\n");
            break;
        case 3:
            printf("You are in the third room, which is filled with traps and obstacles. You must be careful not to trigger them!\n");
            printf("There is a map on the wall that shows the safe path to the next room. Study it carefully!\n");
            break;
        case 4:
            printf("You are in the fourth room, which is completely dark. You can only see a faint glimpse of light coming from the other side.\n");
            printf("You must find a way to light up the room so that you can see the path ahead.\n");
            break;
        case 5:
            printf("You are in the final room! You can see the exit door and feel the cool breeze from the outside.\n");
            printf("But beware, the path to the door is filled with hidden obstacles. You must be quick and sharp to avoid them!\n");
            break;
    }
}

// Function to handle the first room challenge
int room1(int* keys) {
    printf("Which key will you use? Enter 1, 2 or 3: ");
    int choice;
    scanf("%d", &choice);
    if (choice == keys[rand() % 3]) {
        printf("You hear the door unlock, and you move on to the next room.\n\n");
        return 2;
    }
    else {
        printf("The key doesn't fit, and you hear a faint clicking sound. One of the traps has been activated!\n");
        printf("You feel a cold breeze behind you, and you realize that the only way out is forward.\n\n");
        return 3;
    }
}

// Function to handle the second room challenge
int room2() {
    char answer[20];
    printf("Enter your answer: ");
    scanf("%s", answer);
    if (strcmp(answer, "echo") == 0) {
        printf("You hear a click sound, and the door ahead opens. You move on to the next room.\n\n");
        return 4;
    }
    else {
        printf("The riddle remains unsolved, and you realize that you need to find another way to move forward.\n\n");
        return 1;
    }
}

// Function to handle the third room challenge
int room3() {
    printf("You see a series of traps and obstacles in front of you. You must cross the room without triggering them!\n");
    printf("Use the map on the wall to find the safe path. Remember, you have only one chance!\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice == 2) {
        printf("You managed to cross the room unscathed. You move on to the next room.\n\n");
        return 5;
    }
    else {
        printf("You trigger one of the traps, and you hear a loud noise coming from behind you.\n");
        printf("You realize that you must keep moving forward without looking back!\n\n");
        return 4;
    }
}

// Function to handle the fourth room challenge
int room4(int* light) {
    if (*light == 0) {
        printf("You find a torch on the ground and light it up. The room is now illuminated, and you see the path ahead.\n");
        *light = 1;
        return 5;
    }
    else {
        printf("You investigate the room, but you can't find any other light source. You realize that you must go back and find another way.\n\n");
        return 2;
    }
}

// Function to handle the final room challenge
void room5() {
    printf("You rush towards the door, dodging the hidden obstacles with all your might.\n");
    printf("You see the finish line and push the door open, feeling the fresh air of freedom kiss your skin.\n");
    printf("Congratulations! You have escaped the castle and won the game!\n");
}

int main() {
    srand(time(NULL));
    int room = 1;
    int keys[3] = {2, 1, 3};
    int light = 0;
    intro();
    int time_left = 300;
    while (time_left > 0 && room != 6) {
        printf("You have %d seconds left.\n\n", time_left);
        description(room);
        switch(room) {
            case 1:
                room = room1(keys);
                break;
            case 2:
                room = room2();
                break;
            case 3:
                room = room3();
                break;
            case 4:
                room = room4(&light);
                break;
            case 5:
                room5();
                room = 6;
                break;
        }
        time_left -= 30;
    }
    if (time_left <= 0) {
        printf("The time has run out, and you remain trapped in the castle. Better luck next time!\n");
    }
    return 0;
}