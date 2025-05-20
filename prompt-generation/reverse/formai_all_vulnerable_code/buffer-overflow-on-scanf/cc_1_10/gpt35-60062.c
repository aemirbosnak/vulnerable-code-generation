//FormAI DATASET v1.0 Category: Robot movement control ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

struct robot{
    int x, y;
    char direction;
};

void move_forward(struct robot* bot);
void turn_left(struct robot* bot);
void turn_right(struct robot* bot);
void display_position(struct robot* bot);

int main(){
    struct robot bot;
    bot.x = 1;
    bot.y = 1;
    bot.direction = 'n'; //'n' for north, 'e' for east, 's' for south, 'w' for west
    
    while(1){
        char option;
        printf("\nChoose an option:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Display current position\n");
        printf("5. Quit\n");
        printf("Your choice: ");
        scanf("%c", &option);//taking the user input
        
        switch(option){
            case '1': move_forward(&bot); break;//calling the move_forward function
            case '2': turn_left(&bot); break;//calling the turn_left function
            case '3': turn_right(&bot); break;//calling the turn_right function
            case '4': display_position(&bot); break;//calling the display_position function
            case '5': exit(0);
            default: printf("Invalid option\n");
        }
    }
}

void move_forward(struct robot* bot){
    switch(bot->direction){
        case 'n': bot->y++; break;
        case 'e': bot->x++; break;
        case 's': bot->y--; break;
        case 'w': bot->x--; break;
    }
    printf("Moved one step forward in %c direction\n", bot->direction);
}

void turn_left(struct robot* bot){
    switch(bot->direction){
        case 'n': bot->direction = 'w'; break;
        case 'e': bot->direction = 'n'; break;
        case 's': bot->direction = 'e'; break;
        case 'w': bot->direction = 's'; break;
    }
    printf("Turned left, now facing %c\n", bot->direction);
}

void turn_right(struct robot* bot){
    switch(bot->direction){
        case 'n': bot->direction = 'e'; break;
        case 'e': bot->direction = 's'; break;
        case 's': bot->direction = 'w'; break;
        case 'w': bot->direction = 'n'; break;
    }
    printf("Turned right, now facing %c\n", bot->direction);
}

void display_position(struct robot* bot){
    printf("Current position: (%d, %d), facing %c\n", bot->x, bot->y, bot->direction);
}