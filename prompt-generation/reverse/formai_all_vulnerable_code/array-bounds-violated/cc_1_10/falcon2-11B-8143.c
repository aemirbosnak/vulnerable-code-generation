//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_ITEMS 10

typedef struct {
    int row;
    int col;
    char name[20];
    int quantity;
} item;

int main(int argc, char **argv) {
    srand(time(NULL));
    
    item items[MAX_ITEMS] = {
        {"Water", 100},
        {"Food", 50},
        {"Medicine", 20},
        {"Weapons", 10},
        {"Fuel", 5}
    };
    
    int rows = MAX_ROWS;
    int cols = MAX_COLS;
    int player_row, player_col;
    
    printf("Welcome to the post-apocalyptic wasteland!\n");
    printf("You have %d rows and %d columns to explore.\n", rows, cols);
    
    while (1) {
        printf("Where do you want to go? (row, col): ");
        scanf("%d,%d", &player_row, &player_col);
        
        if (player_row < 0 || player_row >= rows || player_col < 0 || player_col >= cols) {
            printf("Invalid position, try again.\n");
            continue;
        }
        
        if (items[player_row * cols + player_col].quantity > 0) {
            printf("You found %s!\n", items[player_row * cols + player_col].name);
            items[player_row * cols + player_col].quantity--;
            printf("You now have %d %s.\n", items[player_row * cols + player_col].quantity, items[player_row * cols + player_col].name);
        } else {
            printf("There is nothing here.\n");
        }
        
        printf("Do you want to continue exploring? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        
        if (choice!= 'y') {
            printf("Goodbye!\n");
            break;
        }
    }
    
    return 0;
}