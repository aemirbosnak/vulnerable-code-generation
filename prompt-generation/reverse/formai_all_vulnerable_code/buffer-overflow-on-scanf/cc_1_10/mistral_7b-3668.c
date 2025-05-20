//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SHAPES 5

typedef struct {
    char name[20];
    char shape;
    int points;
} Shape;

Shape shapes[MAX_SHAPES] = {
    {"Triangle", 'T', 10},
    {"Square", 'S', 15},
    {"Circle", 'C', 5},
    {"Star", '*', 20},
    {"Heart", 'H', 12}
};

void displayShape(Shape shape) {
    printf("%c\n", shape.shape);
}

void displayActivity(Shape shape) {
    printf("%s\n", shape.name);
}

int main() {
    int userInput, totalPoints = 0;
    Shape selectedShape;

    while (1) {
        printf("Select a shape to earn fitness points (Enter 0 to quit):\n");
        for (int i = 0; i < MAX_SHAPES; i++) {
            printf("%d. %s - %c - %d points\n", i+1, shapes[i].name, shapes[i].shape, shapes[i].points);
        }
        scanf("%d", &userInput);

        if (userInput == 0) {
            break;
        }

        selectedShape = shapes[userInput-1];
        totalPoints += selectedShape.points;
        displayShape(selectedShape);
        displayActivity(selectedShape);
        printf("You have earned %d fitness points.\n", totalPoints);
    }

    printf("Your total fitness points: %d\n", totalPoints);
    return 0;
}