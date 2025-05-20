//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void delay(int time) {
#ifdef _WIN32
    Sleep(time);
#else
    usleep(time * 1000);
#endif
}

int main(void) {
    char name[20];
    char choice[10];
    char input[10];
    int health = 100;
    bool hasKey = false;
    bool gameOver = false;
    
    clearScreen();
    printf("Welcome to Cryptic Escape! \n");
    delay(1000);
    printf("You find yourself in a dark room. You have no idea how you got here.\n");
    printf("There's a door in front of you. What would you like to do? (open/look around/wait)\n");
    
    while (!gameOver) {
        scanf("%s", choice);
        
        if (strcmp(choice, "open") == 0) {
            if (hasKey) {
                clearScreen();
                printf("You use the key to unlock the door. You escape the room and breathe a sigh of relief.\n");
                printf("Congratulations, you have escaped Cryptic Escape!\n");
                gameOver = true;
            } else {
                printf("The door is locked. You need a key to unlock it.\n");
                delay(1000);
            }
        } else if (strcmp(choice, "look") == 0) {
            clearScreen();
            printf("You look around the room. There's not much to see.\n");
            printf("There's a loose floorboard near the center of the room. What would you like to do? (lift/leave)\n");

            scanf("%s", input);
            
            if (strcmp(input, "lift") == 0) {
                printf("You lift the floorboard and find a key!\n");
                hasKey = true;
                delay(1000);
            } else if (strcmp(input, "leave") == 0) {
                printf("You decide to leave the loose floorboard alone for now.\n");
                delay(1000);
            }
        } else if (strcmp(choice, "wait") == 0) {
            clearScreen();
            printf("You wait around for a few minutes. Nothing happens.\n");
            health -= 10;
            printf("You feel weaker.\n");
            if (health <= 0) {
                clearScreen();
                printf("You died of starvation.\n");
                delay(1000);
                printf("Game Over.\n");
                gameOver = true;
            }
            delay(1000);
            printf("There's a door in front of you. What would you like to do? (open/look around/wait)\n");
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
    
    return 0;
}