//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_PLAYERS 4
#define MAX_SHAPES 3

typedef enum { CIRCLE, SQUARE, TRIANGLE } ShapeType;

typedef struct {
    ShapeType type;
    double value1; // For circle: radius; For square: side; For triangle: base
    double value2; // For triangle: height
} Shape;

void generateShape(Shape* shape) {
    shape->type = rand() % MAX_SHAPES;
    switch (shape->type) {
    case CIRCLE:
        shape->value1 = (rand() % 100) + 1; // radius between 1 and 100
        shape->value2 = 0; // No second value needed for circle
        break;
    case SQUARE:
        shape->value1 = (rand() % 100) + 1; // side between 1 and 100
        shape->value2 = 0; // No second value needed for square
        break;
    case TRIANGLE:
        shape->value1 = (rand() % 100) + 1; // base between 1 and 100
        shape->value2 = (rand() % 100) + 1; // height between 1 and 100
        break;
    }
}

double calculateArea(Shape* shape) {
    switch (shape->type) {
    case CIRCLE:
        return M_PI * shape->value1 * shape->value1; // Area of circle
    case SQUARE:
        return shape->value1 * shape->value1; // Area of square
    case TRIANGLE:
        return 0.5 * shape->value1 * shape->value2; // Area of triangle
    default:
        return 0;
    }
}

void playRound(int playerCount) {
    Shape shape;
    generateShape(&shape);
    double area = calculateArea(&shape);
    double guess;
    printf("\nNew Round! Calculate the area of the shape:\n");
    
    switch (shape.type) {
    case CIRCLE:
        printf("Shape: Circle with radius %.2f\n", shape.value1);
        break;
    case SQUARE:
        printf("Shape: Square with side %.2f\n", shape.value1);
        break;
    case TRIANGLE:
        printf("Shape: Triangle with base %.2f and height %.2f\n", shape.value1, shape.value2);
        break;
    }
    
    for (int i = 0; i < playerCount; i++) {
        printf("Player %d, enter your guess for the area: ", i + 1);
        scanf("%lf", &guess);
        if (fabs(guess - area) < 0.01) {
            printf("Player %d guessed correctly!\n", i + 1);
        } else {
            printf("Player %d guessed wrong. The correct area is %.2f\n", i + 1, area);
        }
    }
}

int main() {
    srand(time(NULL));
    int playerCount;

    printf("Welcome to the Geometric Area Guessing Game!\n");
    printf("Enter number of players (2 to %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);

    if (playerCount < 2 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting the game.\n");
        return 1;
    }

    for (int round = 1; round <= 5; round++) {
        printf("\n--- Round %d ---\n", round);
        playRound(playerCount);
    }

    printf("\nGame Over! Thanks for playing.\n");
    return 0;
}