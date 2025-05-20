//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(){

    char name[20];
    int choice = 0;
    int has_key = 0;
    int has_treasure = 0;
    int is_alive = 1;

    printf("Welcome to the Adventure Game!\n\n");
    printf("Please enter your name:\n");
    scanf("%s", name);
    clear_screen();

    printf("Hello, %s, and welcome to the game!\n\n", name);

    while(is_alive && choice != 3){
        printf("You are in a dark and mysterious dungeon.\n");
        printf("There are two doors in front of you.\n");
        printf("What do you do?\n\n");

        printf("1) Open the left door.\n");
        printf("2) Open the right door.\n");
        printf("3) Quit the game.\n");

        scanf("%d", &choice);
        clear_screen();

        if(choice == 1){
            printf("You open the left door and enter a room.\n");
            printf("You see a key on a table.\n");
            printf("What do you do?\n\n");

            printf("1) Take the key.\n");
            printf("2) Leave the key.\n");

            scanf("%d", &choice);
            clear_screen();

            if(choice == 1){
                printf("You take the key.\n");
                has_key = 1;
            } else {
                printf("You leave the key.\n");
            }

            printf("What do you do next?\n\n");
            printf("1) Leave the room.\n");
            printf("2) Open the right door.\n");
            printf("3) Quit the game.\n");

            scanf("%d", &choice);
            clear_screen();

            if(choice == 1){
                printf("You leave the room.\n");
            } else if(choice == 2){
                printf("You open the right door.\n");
            } else {
                is_alive = 0;
            }

        } else if(choice == 2){
            printf("You open the right door and enter a room.\n");
            printf("You see a treasure chest in the middle of the room.\n");
            printf("What do you do?\n\n");

            if(has_key){
                printf("1) Use the key to open the chest.\n");
            }
            
            printf("2) Leave the chest.\n");

            scanf("%d", &choice);
            clear_screen();

            if(choice == 1 && has_key){
                printf("You open the chest and find treasure!\n");
                has_treasure = 1;
            } else {
                printf("You leave the chest.\n");
            }

            printf("What do you do next?\n\n");
            printf("1) Leave the room.\n");
            printf("2) Open the left door.\n");
            printf("3) Quit the game.\n");

            scanf("%d", &choice);
            clear_screen();

            if(choice == 1){
                printf("You leave the room.\n");
            } else if(choice == 2){
                printf("You open the left door.\n");
            } else {
                is_alive = 0;
            }

        } else {
            is_alive = 0; // Quit the game
        }
    }

    printf("Game Over!\n");

    if(has_treasure){
        printf("Congratulations, %s! You won the game!\n", name);
    } else {
        printf("Better luck next time, %s.\n", name);
    }

    return 0;
}