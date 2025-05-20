//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_PLAYERS 4

char canvas[HEIGHT][WIDTH];
int player_count = 0;

void initialize_canvas() {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            canvas[i][j] = '.';
}

void display_canvas() {
    printf("Canvas:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void paint_pixel(int player_id, int x, int y, char color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[y][x] = color;
        printf("Player %d painted pixel at (%d, %d) with color '%c'.\n", player_id + 1, x, y, color);
    } else {
        printf("Error: Coordinates (%d, %d) out of bounds.\n", x, y);
    }
}

void get_player_input(int player_id) {
    int x, y;
    char color;

    printf("Player %d, enter coordinates (x y) to paint (0-%d for x, 0-%d for y): ", player_id + 1, WIDTH - 1, HEIGHT - 1);
    scanf("%d %d", &x, &y);
    printf("Player %d, enter color character: ", player_id + 1);
    scanf(" %c", &color);  // The space before %c ignores any leftover whitespace
    paint_pixel(player_id, x, y, color);
}

int main() {
    printf("Welcome to the Multiplayer Pixel Art Generator!\n");
    
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &player_count);
    if (player_count < 1 || player_count > MAX_PLAYERS) {
        printf("Invalid number of players! Exiting.\n");
        return 1;
    }

    initialize_canvas();
    
    int rounds = 5;  // Number of rounds each player will get to play
    for (int round = 0; round < rounds; round++) {
        for (int i = 0; i < player_count; i++) {
            display_canvas();
            get_player_input(i);
            sleep(1); // Adding a small delay for better UX
        }
    }

    printf("Final Canvas:\n");
    display_canvas();
    printf("Thank you for playing!\n");
    
    return 0;
}