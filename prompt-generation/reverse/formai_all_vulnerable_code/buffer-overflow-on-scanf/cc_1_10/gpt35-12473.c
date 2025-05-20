//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

void intro();
void enter_house();
void explore_room(int room_number);
void fight_ghost();
void flee();
void end_game();

bool has_key = false;
bool has_sword = false;
bool has_fought_ghost = false;
int current_room = 1;

int main() {
    srand(time(NULL));
    intro();
    enter_house();
    return 0;
}

void intro() {
    printf("In fair Verona, where we lay our scene,\n");
    printf("There is a haunted mansion, spooky and serene.\n");
    printf("The Capulets and Montagues have long left this place,\n");
    printf("But their spirits still haunt the halls with their grace.\n");
    printf("You, dear adventurer, have decided to take a chance,\n");
    printf("And enter this haunted mansion with swords and stance.\n");
    printf("Beware, for the ghosts and ghouls will not let you leave,\n");
    printf("Unless you have defeated them and retrieved what they thieve.\n");
    printf("Enter if you dare, but be warned of your fate,\n");
    printf("For this haunted mansion has many secrets to contemplate.\n\n");
}

void enter_house() {
    char answer[10];
    printf("You stand before the entrance, will you enter the house? (yes/no)");
    scanf("%s", answer);
    if (strcmp(answer, "yes") == 0) {
        printf("You enter the house, the door creaks and squeals,\n");
        printf("The hairs at the back of your neck stand on end with chills.\n");
        printf("You see a long hallway, with many doors to explore,\n");
        printf("But which door should you choose, what lies behind each door?\n");
        explore_room(current_room);
    } else {
        printf("You chicken out and leave the haunted mansion. Game over!");
        end_game();
    }
}

void explore_room(int room_number) {
    printf("You enter room %d, a chill running down your spine,\n", room_number);
    if (room_number == 1) {
        printf("You see a key on a table, will you pick it up? (yes/no)");
        char answer[10];
        scanf("%s", answer);
        if (strcmp(answer, "yes") == 0) {
            printf("You pick up the key, it vibes with energy,\n");
            printf("You feel that it may unlock a door with synergy.\n");
            has_key = true;
        } else {
            printf("You leave the key behind, perhaps you will regret,\n");
            printf("If you need it later, it will be too late to fret.\n");
        }
    } else if (room_number == 2) {
        printf("You see a ghostly figure, it glares at you with hate,\n");
        printf("It charges towards you, are you ready to fight or flee with fate?\n");
        fight_ghost();
    }  else if (room_number == 3) {
        printf("You see a sword on the floor, will you pick it up? (yes/no)");
        char answer[10];
        scanf("%s", answer);
        if (strcmp(answer, "yes") == 0) {
            printf("You pick up the sword, it shines with clarity,\n");
            printf("You feel that it will help you fight with dexterity.\n");
            has_sword = true;
        } else {
            printf("You leave the sword behind, hoping you will not need to fight,\n");
            printf("But remember, the ghosts and ghouls will not let you leave without a plight.\n");
        }
    } else if (room_number == 4) {
        printf("You see a locked door, will you use the key? (yes/no)");
        char answer[10];
        scanf("%s", answer);
        if (strcmp(answer, "yes") == 0) {
            if (has_key) {
                printf("You unlock the door and find a treasure chest,\n");
                printf("You open it and find gold and jewels, may you feel blessed.\n");
                end_game();
            } else {
                printf("You do not have the key, you cannot unlock the door,\n");
                printf("You must find it or perhaps explore some more.\n");
            }
        } else {
            printf("You leave the door alone, thinking it might be locked,\n");
            printf("But do not forget, to win this game, you must be unblocked.\n");
        }
    } else {
        printf("You are lost in the mansion, with nowhere to go,\n");
        printf("You must find your way out, before the ghosts make you their foe.\n");
    }
    if (room_number != 4) {
        int next_room = rand() % 5 + 1;
        while (next_room == room_number) {
            next_room = rand() % 5 + 1;
        }
        printf("You leave room %d and enter room %d,\n", room_number, next_room);
        current_room = next_room;
        explore_room(current_room);
    }
}

void fight_ghost() {
    if (has_fought_ghost) {
        printf("You have already fought the ghost, there is no point in fighting again.\n");
        printf("If you encounter it again, use your sword or flee, my friend.\n");
        return;
    }

    printf("The ghost charges towards you, with a deafening roar,\n");
    if (has_sword) {
        printf("You pull out your sword and fight with valour,\n");
        printf("You defeat the ghost, it vanishes with a shudder,\n");
        printf("You feel accomplished, and your confidence has become much bolder.\n");
        has_fought_ghost = true;
    } else {
        printf("You try to fight the ghost, but your fists are too frail,\n");
        printf("The ghost overpowers you, and you start to flail.\n");
        flee();
    }
}

void flee() {
    printf("You try to run away, your heart racing like a drum,\n");
    printf("But the ghosts are too fast, and soon you become numb.\n");
    printf("You have failed to escape, and the ghosts are the victors.\n");
    end_game();
}

void end_game() {
    printf("\nThank you for playing!\n");
    exit(0);
}