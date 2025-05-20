//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void start_game();
void room_one();
void room_two();
void room_three();
void game_over();
void play_again();

int main() {
    start_game();
    return 0;
}

void start_game() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You enter a dark, empty room. You can see three doors - one to the left, one straight ahead and one to the right.\n");
    printf("Which door do you choose? (L)eft, (S)traight or (R)ight?\n");

    char choice[10];
    scanf("%s", choice);

    if (strcmp(choice, "L") == 0) {
        room_one();
    } else if (strcmp(choice, "S") == 0) {
        room_two();
    } else if (strcmp(choice, "R") == 0) {
        room_three();
    } else {
        start_game();
    }
}

void room_one() {
    printf("You entered the left room and found a key on the table. Do you (T)ake the key or leave it there and continue to (E)xit?\n");

    char choice[10];
    scanf("%s", choice);

    if (strcmp(choice, "T") == 0) {
        printf("You took the key and proceed to the exit.\n");
        printf("Congratulations! You escaped the room!\n");
        play_again();
    } else if(strcmp(choice, "E") == 0) {
        printf("You decided to leave the key and continue to the exit.\n");
        printf("Congratulations! You escaped the room!\n");
        play_again();
    } else {
        room_one();
    }
}

void room_two() {
    printf("You entered the straight room and found a creature blocking your path.\n");
    printf("Do you (F)ight the creature or (R)un back to the starting room?\n");

    char choice[10];
    scanf("%s", choice);

    if (strcmp(choice, "F") == 0) {
        printf("Good job! You defeated the creature and found a note on the ground.\n");
        printf("The note says 'The exit is two rooms away from the left room.'\n");
        printf("Do you continue to the (L)eft room or go to the (R)ight room?\n");

        char choice_two[10];
        scanf("%s", choice_two);

        if (strcmp(choice_two, "L") == 0) {
            room_one();
        } else if (strcmp(choice_two, "R") == 0) {
            room_three();
        } else {
            room_two();
        }
    } else if (strcmp(choice, "R") == 0) {
        start_game();
    } else {
        room_two();
    }
}

void room_three() {
    printf("You entered the right room and it's full of traps.\n");
    printf("Do you (C)arefully navigate through the traps or (R)un back to the starting room?\n");

    char choice[10];
    scanf("%s", choice);

    if (strcmp(choice, "C") == 0) {
        printf("You carefully navigate through the traps and found a door.\n");
        printf("You tried to open the door but found it locked.\n");
        printf("Do you use the key you found in the left room (U)se or go back to the starting room and (S)tart over?\n");

        char choice_two[10];
        scanf("%s", choice_two);

        if (strcmp(choice_two, "U") == 0) {
            printf("Congratulations! You found the exit and escaped the room!\n");
            play_again();
        } else {
            start_game();
        }
    } else if (strcmp(choice, "R") == 0) {
        start_game();
    } else {
        room_three();
    }
}

void game_over() {
    printf("Game over! You died. Do you want to (P)lay again or (Q)uit?\n");

    char choice[10];
    scanf("%s", choice);

    if (strcmp(choice, "P") == 0) {
        start_game();
    } else if (strcmp(choice, "Q") == 0) {
        printf("Thanks for playing!\n");
        exit(0);
    } else {
        game_over();
    }
}

void play_again() {
    printf("Do you want to (P)lay again or (Q)uit?\n");

    char choice[10];
    scanf("%s", choice);

    if (strcmp(choice, "P") == 0) {
        start_game();
    } else if (strcmp(choice, "Q") == 0) {
        printf("Thanks for playing!\n");
        exit(0);
    } else {
        play_again();
    }
}