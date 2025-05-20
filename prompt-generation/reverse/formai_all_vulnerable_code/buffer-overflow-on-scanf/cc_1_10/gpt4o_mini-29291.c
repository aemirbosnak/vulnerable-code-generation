//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PLAYERS 4
#define MAX_SHAPES 10

typedef struct {
    char name[50];
    int shapesCount;
    double areas[MAX_SHAPES];
} Player;

void calculateTriangleArea(Player *player) {
    double base, height;
    printf("%s, enter the base of the triangle: ", player->name);
    scanf("%lf", &base);
    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);
    player->areas[player->shapesCount] = 0.5 * base * height;
    player->shapesCount++;
    printf("Area of triangle: %.2f\n", player->areas[player->shapesCount - 1]);
}

void calculateRectangleArea(Player *player) {
    double length, width;
    printf("%s, enter the length of the rectangle: ", player->name);
    scanf("%lf", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &width);
    player->areas[player->shapesCount] = length * width;
    player->shapesCount++;
    printf("Area of rectangle: %.2f\n", player->areas[player->shapesCount - 1]);
}

void calculateCircleArea(Player *player) {
    double radius;
    printf("%s, enter the radius of the circle: ", player->name);
    scanf("%lf", &radius);
    player->areas[player->shapesCount] = M_PI * radius * radius;
    player->shapesCount++;
    printf("Area of circle: %.2f\n", player->areas[player->shapesCount - 1]);
}

void calculateAreas(Player *players, int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("\n%s, choose a shape to calculate area (1. Triangle 2. Rectangle 3. Circle): ", players[i].name);
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                calculateTriangleArea(&players[i]);
                break;
            case 2:
                calculateRectangleArea(&players[i]);
                break;
            case 3:
                calculateCircleArea(&players[i]);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                i--; // To repeat this player's turn
                break;
        }
    }
}

void displayResults(Player *players, int playerCount) {
    printf("\nFinal Results:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s calculated areas: ", players[i].name);
        for (int j = 0; j < players[i].shapesCount; j++) {
            printf("%.2f ", players[i].areas[j]);
        }
        printf("\n");
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    if (playerCount > MAX_PLAYERS) {
        printf("Too many players, setting to max %d.\n", MAX_PLAYERS);
        playerCount = MAX_PLAYERS;
    }

    for (int i = 0; i < playerCount; i++) {
        printf("Enter name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].shapesCount = 0;
    }

    calculateAreas(players, playerCount);
    displayResults(players, playerCount);

    return 0;
}