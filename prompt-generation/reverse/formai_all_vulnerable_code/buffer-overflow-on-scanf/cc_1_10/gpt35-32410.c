//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 5

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    char name[20];
    Point location;
} Player;

int distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void print_map(Player *players, int num_players) {
    char map[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = '-';
            for (int k = 0; k < num_players; k++) {
                if (players[k].location.x == i && players[k].location.y == j) {
                    map[i][j] = k + '0';
                }
            }
        }
        printf("%s\n", map[i]);
    }
}

int main() {
    srand(time(0));
    
    int num_players;
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    while (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid input. Enter the number of players (1-%d): ", MAX_PLAYERS);
        scanf("%d", &num_players);
    }
    
    Player players[num_players];
    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", players[i].name);
        
        players[i].location.x = rand() % 10;
        players[i].location.y = rand() % 10;
    }
    
    printf("Game started!\n");
    printf("------------------\n");
    
    for (int i = 0; i < MAX_ROUNDS; i++) {
        printf("Round %d\n", i+1);
        
        for (int j = 0; j < num_players; j++) {
            printf("%s's turn: \n", players[j].name);
            
            Point target;
            printf("Enter the x-coordinate of your target location (0-9): ");
            scanf("%d", &target.x);
            while (target.x < 0 || target.x > 9) {
                printf("Invalid input. Enter the x-coordinate of your target location (0-9): ");
                scanf("%d", &target.x);
            }
            printf("Enter the y-coordinate of your target location (0-9): ");
            scanf("%d", &target.y);
            while (target.y < 0 || target.y > 9) {
                printf("Invalid input. Enter the y-coordinate of your target location (0-9): ");
                scanf("%d", &target.y);
            }
            
            int hit = false;
            for (int k = 0; k < num_players; k++) {
                if (k != j && distance(players[k].location, target) == 0) {
                    hit = true;
                }
            }
            if (hit) {
                printf("You hit a target!\n");
            } else {
                printf("You missed.\n");
            }
            
            players[j].location = target;
            printf("Current game map:\n");
            print_map(players, num_players);
            printf("------------------\n");
        }
    }
    
    printf("Game over.\n");
    
    return 0;
}