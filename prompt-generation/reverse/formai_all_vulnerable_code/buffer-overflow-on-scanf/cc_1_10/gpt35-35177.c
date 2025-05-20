//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void move(int* x, int* y){
    printf("Enter your move direction: ");
    char move_dir;
    scanf(" %c", &move_dir);

    switch(move_dir){
        case 'w': --*y; break;
        case 's': ++*y; break;
        case 'a': --*x; break;
        case 'd': ++*x; break;
        default: printf("Invalid move!\n");
    }
}

void print_map(int x, int y, int map_size){
    for(int i=0;i<map_size;++i){
        for(int j=0;j<map_size;++j){
            if(i == x && j == y){
                printf("X ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

int main(){
    int map_size = 10;
    int player_x = rand() % map_size;
    int player_y = rand() % map_size;

    printf("Welcome to Procedural Space Adventure!\n");
    printf("You must navigate through the galaxy to find the lost artifact.\n");
    printf("You will start at a random point in a %d x %d map.\n", map_size, map_size);
    printf("Your location is marked with an X.\n");
    printf("WASD keys will move your character in the respective direction.\n");
    printf("Good luck adventurer!\n");
    
    int artifact_x = rand() % map_size;
    int artifact_y = rand() % map_size;
    
    while(1){
        print_map(player_x, player_y, map_size);
        move(&player_x, &player_y);
        if(player_x == artifact_x && player_y == artifact_y){
            printf("Congratulations, you have found the lost artifact!\n");
            break;
        }
    }
}