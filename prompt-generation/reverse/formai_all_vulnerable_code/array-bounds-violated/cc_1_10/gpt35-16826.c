//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_INPUT 50

// function prototypes
void printIntro();
void printRoom(int roomNum);
void movePlayer(int *roomNum, char *direction);
void takeItem(int *roomNum, char *item, int *inventory);
void useItem(int *roomNum, char *item, int *inventory);
void printInventory(int *inventory);
void printHelp();

int main(){

    int roomNum = 1;
    int inventory[10] = {0}; // player's inventory, all items start at 0
    char input[MAX_INPUT];
    char *token;

    printIntro();
    printRoom(roomNum);

    while(1){

        printf("\n> ");
        fgets(input, MAX_INPUT, stdin);

        // remove newline character from input
        if(input[strlen(input)-1] == '\n'){
            input[strlen(input)-1] = '\0';
        }

        // tokenize input and get first word
        token = strtok(input, " ");

        // convert first word to lowercase
        for(int i=0; token[i]; i++){
            token[i] = tolower(token[i]);
        }

        if(strcmp(token, "quit") == 0){
            printf("Goodbye!\n");
            break;
        }
        else if(strcmp(token, "go") == 0){
            token = strtok(NULL, " ");
            movePlayer(&roomNum, token);
            printRoom(roomNum);
        }
        else if(strcmp(token, "take") == 0){
            token = strtok(NULL, " ");
            takeItem(&roomNum, token, inventory);
        }
        else if(strcmp(token, "use") == 0){
            token = strtok(NULL, " ");
            useItem(&roomNum, token, inventory);
        }
        else if(strcmp(token, "inventory") == 0){
            printInventory(inventory);
        }
        else if(strcmp(token, "help") == 0){
            printHelp();
        }
        else{
            printf("I don't understand that command. Type 'help' for a list of commands.\n");
        }
    }

    return 0;
}

void printIntro(){
    printf("Welcome to the peaceful adventure game!\n");
    printf("You find yourself in a peaceful forest with nothing but the clothes on your back.\n");
    printf("Your goal is to explore the forest and find the hidden treasure.\n");
    printf("Type 'help' for a list of commands.\n\n");
}

void printRoom(int roomNum){

    switch(roomNum){
        case 1:
            printf("You are in a clearing surrounded by trees.\n");
            printf("You see a path to the east. There is a rock nearby.\n");
            break;
        case 2:
            printf("You are on a path in the woods.\n");
            printf("You see a clearing to the west and a stream to the east.\n");
            break;
        case 3:
            printf("You are standing next to a stream.\n");
            printf("You see a path to the west and a bridge to the east.\n");
            break;
        case 4:
            printf("You are on a bridge overlooking a deep ravine.\n");
            printf("You see a path to the west and a cave to the east.\n");
            break;
        case 5:
            printf("You are standing at the entrance to a dark cave.\n");
            printf("The air is musty and you hear strange noises coming from inside.\n");
            break;
        case 6:
            printf("You have found the treasure!\n");
            printf("Congratulations, you have won the game!\n");
            exit(0);
            break;
        default:
            printf("Error: invalid room number.\n");
            exit(1);
    }

}

void movePlayer(int *roomNum, char *direction){

    if(strcmp(direction, "east") == 0){
        switch(*roomNum){
            case 1:
                *roomNum = 2;
                break;
            case 2:
                *roomNum = 3;
                break;
            case 3:
                *roomNum = 4;
                break;
            case 4:
                *roomNum = 5;
                break;
            default:
                printf("You can't go that way.\n");
                return;
        }
        printf("You move to the east.\n");
    }
    else if(strcmp(direction, "west") == 0){
        switch(*roomNum){
            case 2:
                *roomNum = 1;
                break;
            case 3:
                *roomNum = 2;
                break;
            case 4:
                *roomNum = 3;
                break;
            default:
                printf("You can't go that way.\n");
                return;
        }
        printf("You move to the west.\n");
    }
    else{
        printf("You can't go that way.\n");
        return;
    }

}

void takeItem(int *roomNum, char *item, int *inventory){

    if(strcmp(item, "rock") == 0){
        if(*roomNum != 1){
            printf("There is no rock here.\n");
            return;
        }
        if(inventory[0] == 1){
            printf("You already have the rock.\n");
            return;
        }
        inventory[0] = 1;
        printf("You take the rock.\n");
    }
    else{
        printf("There is no %s here.\n", item);
        return;
    }

}

void useItem(int *roomNum, char *item, int *inventory){

    if(strcmp(item, "rock") == 0){
        if(*roomNum != 5){
            printf("You can't use that here.\n");
            return;
        }
        if(inventory[0] != 1){
            printf("You don't have the rock.\n");
            return;
        }
        printf("You use the rock to break open the treasure chest.\n");
        *roomNum = 6;
    }
    else{
        printf("You can't use that here.\n");
        return;
    }

}

void printInventory(int *inventory){

    int itemCount = 0;

    printf("Inventory:\n");
    printf("----------\n");

    for(int i=0; i<10; i++){
        if(inventory[i] == 1){
            itemCount++;
            switch(i){
                case 0:
                    printf("rock\n");
                    break;
                default:
                    printf("Unknown item\n");
            }
        }
    }

    if(itemCount == 0){
        printf("Your inventory is empty.\n");
    }

}

void printHelp(){

    printf("Commands:\n");
    printf("---------\n");
    printf("go [direction] - Move in a direction (north, south, east, west)\n");
    printf("take [item] - Pick up an item\n");
    printf("use [item] - Use an item\n");
    printf("inventory - View your inventory\n");
    printf("help - View this help message again\n");
    printf("quit - Quit the game\n");

}