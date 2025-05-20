//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

typedef struct {
    char name[MAX_SIZE];
    int shape;
} ShapeShifter;

void changeShape(ShapeShifter *ss, int newShape) {
    switch(ss->shape) {
        case 1:
            strcpy(ss->name, "Sphere");
            break;
        case 2:
            strcpy(ss->name, "Cube");
            break;
        case 3:
            strcpy(ss->name, "Cylinder");
            break;
        default:
            printf("Invalid shape! Shape should be 1, 2 or 3.\n");
            exit(1);
    }

    ss->shape = newShape;

    switch(ss->shape) {
        case 1:
            printf("%s is now a Sphere.\n", ss->name);
            break;
        case 2:
            printf("%s is now a Cube.\n", ss->name);
            break;
        case 3:
            printf("%s is now a Cylinder.\n", ss->name);
            break;
        default:
            printf("Error: Invalid shape!\n");
            exit(1);
    }
}

int main() {
    ShapeShifter ss;
    int shape;

    printf("Enter name: ");
    scanf("%s", ss.name);

    printf("Enter initial shape (1 for Sphere, 2 for Cube, 3 for Cylinder): ");
    scanf("%d", &shape);

    strcpy(ss.name, "Unknown");
    ss.shape = shape;

    changeShape(&ss, 5); // Intended error

    printf("\nName: %s, Shape: %d\n", ss.name, ss.shape);

    return 0;
}