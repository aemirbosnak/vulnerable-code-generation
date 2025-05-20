//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
int choice(int min, int max);
void gameOver();
void win();
void game();

int main() {
    intro();
    game();
    return 0;
}

void intro() {
    printf("Welcome to the Secret Cave Adventure Game!\n\n");
    printf("In this game, you will have to make choices to navigate through the cave and find the treasure.\n");
    printf("Be careful, there are traps and dangerous creatures lurking around every corner.\n\n");
}

int choice(int min, int max) {
    int num;
    printf("Enter your choice (%d-%d): ", min, max);
    scanf("%d", &num);
    while (num < min || num > max) {
        printf("Invalid choice. Enter your choice (%d-%d): ", min, max);
        scanf("%d", &num);
    }
    return num;
}

void gameOver() {
    printf("\nGame Over. You have failed your mission.\n\n");
}

void win() {
    printf("\nCongratulations! You have found the treasure and completed your mission!\n\n");
}

void game() {
    srand(time(NULL));
    int room1 = rand() % 9 + 1;
    int room2 = rand() % 9 + 1;
    int room3 = rand() % 9 + 1;
    int treasure = rand() % 3 + 1;
    int picked_room;
    printf("You enter the cave and find yourself in a hallway with three doors.\n\n");
    printf("Behind one door is the treasure, behind the other two is death.\n\n");
    printf("Choose a door to enter (1-3): ");
    scanf("%d", &picked_room);
    while (picked_room < 1 || picked_room > 3) {
        printf("Invalid choice. Choose a door to enter (1-3): ");
        scanf("%d", &picked_room);
    }
    if (picked_room == treasure) {
        win();
        return;
    }
    printf("\nYou enter room %d and find yourself facing a monster!\n\n", picked_room);
    printf("1. Fight\n");
    printf("2. Attempt to escape\n");
    int action = choice(1, 2);
    if (action == 1) {
        printf("\nYou try to fight the monster, but it's too strong and you're killed.\n\n");
        gameOver();
        return;
    }
    printf("\nYou try to escape, but the monster catches you and kills you.\n\n");
    gameOver();
    return;
}