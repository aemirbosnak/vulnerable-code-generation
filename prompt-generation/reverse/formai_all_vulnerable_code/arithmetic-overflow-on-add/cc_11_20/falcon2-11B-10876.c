//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main() {
    int red = 0, yellow = 0, green = 0;
    int players[2];
    int current_player = 0;
    int timer = 0;
    int score[2];
    char color;
    
    srand(time(NULL));
    
    while (1) {
        printf("Player 1, press 'R' to turn the light red, 'Y' to turn the light yellow, or 'G' to turn the light green.\n");
        scanf("%s", &color);
        players[current_player] = color;
        current_player = (current_player + 1) % 2;
        
        if (color == 'R') {
            red = 1;
        } else if (color == 'Y') {
            yellow = 1;
        } else if (color == 'G') {
            green = 1;
        }
        
        timer = (rand() % 10) + 1;
        
        printf("Timer: %d\n", timer);
        
        sleep(timer);
        
        if (red == 1 && yellow == 0 && green == 0) {
            printf("Traffic Light: RED\n");
            red = 0;
        } else if (yellow == 1 && red == 0 && green == 0) {
            printf("Traffic Light: YELLOW\n");
            yellow = 0;
        } else if (green == 1 && red == 0 && yellow == 0) {
            printf("Traffic Light: GREEN\n");
            green = 0;
        }
        
        for (int i = 0; i < 2; i++) {
            if (players[i] == 'R') {
                score[i]++;
            } else if (players[i] == 'Y') {
                score[i]++;
            } else if (players[i] == 'G') {
                score[i]++;
            }
        }
        
        printf("Player 1: %d\n", score[0]);
        printf("Player 2: %d\n", score[1]);
        
        if (score[0] == 3) {
            printf("Player 1 wins!\n");
            break;
        } else if (score[1] == 3) {
            printf("Player 2 wins!\n");
            break;
        }
    }
    
    return 0;
}