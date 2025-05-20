//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 5
#define IMAGE_WIDTH 10
#define IMAGE_HEIGHT 10
#define WATERMARK_SIZE 10

char image[IMAGE_HEIGHT][IMAGE_WIDTH + 1]; // +1 for null terminator
char watermarks[MAX_PLAYERS][WATERMARK_SIZE + 1];
int player_count = 0;

void initialize_image() {
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            image[i][j] = '.';
        }
        image[i][IMAGE_WIDTH] = '\0'; // null terminate each row
    }
}

void display_image() {
    printf("Current Image:\n");
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        printf("%s\n", image[i]);
    }
    printf("\n");
}

void embed_watermark(const char *watermark, int player_index) {
    int position = player_index % (IMAGE_WIDTH * IMAGE_HEIGHT);
    int x = position / IMAGE_WIDTH;
    int y = position % IMAGE_WIDTH;

    for (int i = 0; i < strlen(watermark); i++) {
        if (x < IMAGE_HEIGHT && y < IMAGE_WIDTH) {
            image[x][y] = watermark[i]; // embed watermark character
            y++;
            if (y >= IMAGE_WIDTH) {
                y = 0; // move to next row
                x++;
            }
        }
    }
}

void extract_watermark() {
    printf("Extracted Watermarks:\n");
    for (int i = 0; i < player_count; i++) {
        printf("Player %d: %s\n", i + 1, watermarks[i]);
    }
}

void handle_player_input() {
    char watermark[WATERMARK_SIZE + 1];
    while (player_count < MAX_PLAYERS) {
        printf("Enter watermark for Player %d (max %d chars): ", player_count + 1, WATERMARK_SIZE);
        scanf("%s", watermark);
        
        strncpy(watermarks[player_count], watermark, WATERMARK_SIZE);
        watermarks[player_count][WATERMARK_SIZE] = '\0'; // null terminate
        embed_watermark(watermarks[player_count], player_count);
        player_count++;

        display_image();
        extract_watermark();
    }
}

int main() {
    initialize_image();
    handle_player_input();
    return 0;
}