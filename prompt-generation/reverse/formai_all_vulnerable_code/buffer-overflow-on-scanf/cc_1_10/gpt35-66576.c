//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pause(int);
void scare(void);
int coin_flip(int);
void look_around(int *);

int main() {
    srand(time(NULL));
    int room = 1, choice;
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself standing in front of a spooky Victorian mansion.\n");
    pause(3);
    printf("Do you dare to enter?\n");
    printf("Press 1 to enter or 2 to chicken out: ");
    scanf("%d", &choice);
    if (choice == 2) {
        printf("You're not brave enough!\n");
        return 0;
    }
    printf("You enter the mansion, the door creaks shut behind you.\n");
    pause(3);
    printf("The first room you enter is dark and you can't see anything.\n");
    pause(3);
    look_around(&room);
}

void pause(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + (seconds * CLOCKS_PER_SEC));
}

void scare() {
    int face = coin_flip(2);
    if (face == 1) {
        printf("Suddenly, something jumps out at you!\n");
    } else {
        printf("You hear a loud noise in the distance.\n");
    }
}

int coin_flip(int num_sides) {
    return rand() % num_sides + 1;
}

void look_around(int *room) {
    int choice;
    printf("What do you want to do?\n");
    printf("Press 1 to turn on your flashlight, 2 to look for a light switch: ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You turn on your flashlight but it flickers and goes out.\n");
        scare();
    } else if (choice == 2) {
        printf("You find a light switch and turn on the lights.\n");
        pause(3);
        printf("You are standing in a dusty old bedroom.\n");
        printf("Press 1 to go through the door or 2 to look around: ");
        scanf("%d", &choice);
        if (choice == 1) {
            (*room)++;
            printf("You leave the bedroom and enter the hallway.\n");
            pause(3);
            look_around(room);
        } else if (choice == 2) {
            printf("You find a journal on the nightstand. You read the last entry:\n");
            printf("'The spirits are angry. We should never have disturbed them.'");
            printf("\nYou hear a faint whisper saying 'Get out'.\n");
            scare();
            look_around(room);
        }
    } else {
        printf("Invalid choice, try again.\n");
        look_around(room);
    }
}