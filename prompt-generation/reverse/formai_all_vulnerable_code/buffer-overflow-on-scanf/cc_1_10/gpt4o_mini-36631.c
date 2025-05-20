//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SHAPES 100
#define NAME_LENGTH 20

typedef enum { CIRCLE, RECTANGLE, TRIANGLE } ShapeType;

typedef struct {
    ShapeType type;
    char name[NAME_LENGTH];
    union {
        struct {
            float radius;
        } circle;
        struct {
            float width;
            float height;
        } rectangle;
        struct {
            float base;
            float height;
        } triangle;
    } dimensions;
} Shape;

Shape shapes[MAX_SHAPES];
int shapeCount = 0;

void displayMenu() {
    printf("\nShape Database Menu:\n");
    printf("1. Add Shape\n");
    printf("2. View Shapes\n");
    printf("3. Delete Shape\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void addShape() {
    if (shapeCount >= MAX_SHAPES) {
        printf("Shape database is full!\n");
        return;
    }

    printf("Enter shape name: ");
    scanf("%s", shapes[shapeCount].name);
    
    printf("Select shape type (0: Circle, 1: Rectangle, 2: Triangle): ");
    int type;
    scanf("%d", &type);
    shapes[shapeCount].type = type;

    switch (type) {
        case CIRCLE:
            printf("Enter radius: ");
            scanf("%f", &shapes[shapeCount].dimensions.circle.radius);
            break;
        case RECTANGLE:
            printf("Enter width and height: ");
            scanf("%f %f", &shapes[shapeCount].dimensions.rectangle.width, &shapes[shapeCount].dimensions.rectangle.height);
            break;
        case TRIANGLE:
            printf("Enter base and height: ");
            scanf("%f %f", &shapes[shapeCount].dimensions.triangle.base, &shapes[shapeCount].dimensions.triangle.height);
            break;
        default:
            printf("Invalid shape type!\n");
            return;
    }
    
    shapeCount++;
    printf("Shape added successfully!\n");
}

void viewShapes() {
    if (shapeCount == 0) {
        printf("No shapes in the database.\n");
        return;
    }
    
    printf("\nList of Shapes:\n");
    for (int i = 0; i < shapeCount; i++) {
        printf("Shape %d: %s\n", i + 1, shapes[i].name);
        switch (shapes[i].type) {
            case CIRCLE:
                printf("Type: Circle, Radius: %.2f\n", shapes[i].dimensions.circle.radius);
                break;
            case RECTANGLE:
                printf("Type: Rectangle, Width: %.2f, Height: %.2f\n", shapes[i].dimensions.rectangle.width, shapes[i].dimensions.rectangle.height);
                break;
            case TRIANGLE:
                printf("Type: Triangle, Base: %.2f, Height: %.2f\n", shapes[i].dimensions.triangle.base, shapes[i].dimensions.triangle.height);
                break;
        }
    }
}

void deleteShape() {
    if (shapeCount == 0) {
        printf("No shapes to delete.\n");
        return;
    }

    printf("Enter the index of the shape to delete (1 to %d): ", shapeCount);
    int index;
    scanf("%d", &index);
    
    if (index < 1 || index > shapeCount) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < shapeCount - 1; i++) {
        shapes[i] = shapes[i + 1];
    }
    shapeCount--;
    
    printf("Shape deleted successfully!\n");
}

int main() {
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addShape();
                break;
            case 2:
                viewShapes();
                break;
            case 3:
                deleteShape();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}