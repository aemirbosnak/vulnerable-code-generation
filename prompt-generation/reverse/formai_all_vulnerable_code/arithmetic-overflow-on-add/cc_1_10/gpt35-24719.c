//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int numRooms = 5;
int currentRoom = 0;
int hasKey = 0;
int hasFlashlight = 0;
int hasBattery = 0;
int hasFoundSafe = 0;
int hasSolvedPuzzle = 0;

void textDelay(int seconds){
    clock_t timer;
    timer = clock() + seconds * CLOCKS_PER_SEC;
    while(clock() < timer);
}

void clearScreen(){
    system("clear");
}

void printTitle(){
    printf(" ___________________________\n");
    printf("|                           |\n");
    printf("|  H A U N T E D   H O U S E  |\n");
    printf("|___________________________|\n\n");
}

void printRoom(){
    clearScreen();
    printTitle();
    if(currentRoom == 0) printf("You are standing in the foyer. There are doors to the east and south.\n");
    if(currentRoom == 1) printf("You are standing in the dining room. There are doors to the north and south.\n");
    if(currentRoom == 2) printf("You are standing in the kitchen. There is a door to the west.\n");
    if(currentRoom == 3) printf("You are standing in the ballroom. There are doors to the east and south.\n");
    if(currentRoom == 4) printf("You are standing in the library. There is a door to the north.\n");
    printf("\n");
}

void move(){
    char direction;
    printf("Which direction would you like to go? (n, s, e, w): ");
    scanf(" %c", &direction);
    if(currentRoom == 0) if(direction == 's') currentRoom = 1;
    if(currentRoom == 0) if(direction == 'e') currentRoom = 3;
    if(currentRoom == 1) if(direction == 'n') currentRoom = 0;
    if(currentRoom == 1) if(direction == 's') currentRoom = 2;
    if(currentRoom == 2) if(direction == 'w') currentRoom = 1;
    if(currentRoom == 3) if(direction == 'e') currentRoom = 4;
    if(currentRoom == 3) if(direction == 's') currentRoom = 0;
    if(currentRoom == 4) if(direction == 'n') currentRoom = 3;
}

void search(){
    if(currentRoom == 1 && !hasKey){
        printf("You found a key!\n");
        hasKey = 1;
    } else if(currentRoom == 4 && !hasBattery){
        printf("You found a battery!\n");
        hasBattery = 1;
    } else if(currentRoom == 2 && !hasFlashlight){
        printf("You found a flashlight!\n");
        hasFlashlight = 1;
    } else {
        printf("There's nothing here.\n");
    }
}

void use(char item[]){
    if(currentRoom == 4 && hasKey && !hasFoundSafe){
        printf("You unlocked the safe with the key and found a puzzle piece!\n");
        hasFoundSafe = 1;
    } else if(strcmp(item, "flashlight")==0 && hasFlashlight && hasBattery && !hasSolvedPuzzle){
        printf("You turned on the flashlight and found a puzzle piece!\n");
        hasSolvedPuzzle = 1;
    } else if(strcmp(item, "puzzle")==0 && hasSolvedPuzzle){
        printf("You solved the puzzle and found the exit! Congratulations!\n");
        exit(0);
    } else {
        printf("You can't use that here.\n");
    }
}

int main(){
    srand(time(NULL));
    int ghostChance;
    printRoom();
    while(1){
        ghostChance = rand() % 10;
        if(ghostChance == 0){
            printf("Oh no! You were scared by a ghost and ran back to the foyer.\n");
            currentRoom = 0;
            hasFlashlight = 0;
            hasBattery = 0;
            hasFoundSafe = 0;
            hasSolvedPuzzle = 0;
        }
        printf("What would you like to do? (move, search, use): ");
        char choice[10];
        scanf(" %s", choice);
        if(strcmp(choice, "move")==0) move();
        if(strcmp(choice, "search")==0) search();
        if(strcmp(choice, "use")==0){
            printf("What item would you like to use? ");
            char item[20];
            scanf(" %s", item);
            use(item);
        }
        printRoom();
        textDelay(1);
    }
    return 0;
}