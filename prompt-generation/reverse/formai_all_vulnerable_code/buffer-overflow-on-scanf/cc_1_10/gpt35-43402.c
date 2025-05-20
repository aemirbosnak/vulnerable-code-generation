//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greeting(){
    printf("Welcome to The Calm Adventure Game!\n");
    printf("You are now lost in the middle of a peaceful forest.\n");
    printf("Your objective is to find the exit from the forest.\n");
    printf("You can type 'help' any time for assistance.\n");
}

void help(){
    printf("To navigate through the forest, use the following commands: \n");
    printf("'north' or 'n' to move to the north\n");
    printf("'south' or 's' to move to the south\n");
    printf("'east' or 'e' to move to the east\n");
    printf("'west' or 'w' to move to the west\n");
    printf("Type 'exit' or 'q' to end the game.\n");
}

int valid_direction(char* direction){
    return strcmp(direction, "north") == 0 
    || strcmp(direction, "n") == 0 
    || strcmp(direction, "south") == 0 
    || strcmp(direction, "s") == 0 
    || strcmp(direction, "east") == 0 
    || strcmp(direction, "e") == 0
    || strcmp(direction, "west") == 0 
    || strcmp(direction, "w") == 0;
}

void handle_input(char* input, int* x, int* y){
    if(strcmp(input, "help")==0){
        help();
    }
    else if(strcmp(input, "north")==0 || strcmp(input, "n")==0){
        *y+=1;
    }
    else if(strcmp(input, "south")==0 || strcmp(input, "s")==0){
        *y-=1;
    }
    else if(strcmp(input, "east")==0 || strcmp(input, "e")==0){
        *x+=1;
    }
    else if(strcmp(input, "west")==0 || strcmp(input, "w")==0){
        *x-=1;
    }
    else if(strcmp(input, "exit")==0 || strcmp(input, "q")==0){
        printf("Thank you for playing The Calm Adventure Game!\n");
        exit(0);
    }
    else{
        printf("Invalid command. Type 'help' for assistance.\n");
    }
}

void check_for_exit(int x, int y){
    if(x == 5 && y == 5){
        printf("Congratulations! You found the exit!\n");
        exit(0);
    }
}

void game_loop(){
    int x=0, y=0;
    char input[50];
    while(1){
        printf("Your current position is: (%d, %d)\n", x, y);
        printf("Enter your command: ");
        scanf("%s", input);
        if(!valid_direction(input)){
            handle_input(input, &x, &y);
            check_for_exit(x, y);
        }
        else{
            printf("Invalid command. Type 'help' for assistance.\n");
        }
    }
}

int main(){
    greeting();
    game_loop();
    return 0;
}