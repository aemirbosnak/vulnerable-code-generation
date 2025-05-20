//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {CIRCLE, RECTANGLE, TRIANGLE} ShapeType;

typedef struct {
    ShapeType type;
    char name[30];
    union {
        struct {
            float radius;
        } circle;
        
        struct {
            float length;
            float width;
        } rectangle;

        struct {
            float base;
            float height;
        } triangle;
    };
} Shape;

Shape* shapes[100];
int shape_count = 0;

void add_circle(const char* name, float radius) {
    if(shape_count >= 100) {
        printf("Database is full!\n");
        return;
    }
    Shape* new_shape = (Shape*)malloc(sizeof(Shape));
    new_shape->type = CIRCLE;
    strcpy(new_shape->name, name);
    new_shape->circle.radius = radius;
    shapes[shape_count++] = new_shape;
}

void add_rectangle(const char* name, float length, float width) {
    if(shape_count >= 100) {
        printf("Database is full!\n");
        return;
    }
    Shape* new_shape = (Shape*)malloc(sizeof(Shape));
    new_shape->type = RECTANGLE;
    strcpy(new_shape->name, name);
    new_shape->rectangle.length = length;
    new_shape->rectangle.width = width;
    shapes[shape_count++] = new_shape;
}

void add_triangle(const char* name, float base, float height) {
    if(shape_count >= 100) {
        printf("Database is full!\n");
        return;
    }
    Shape* new_shape = (Shape*)malloc(sizeof(Shape));
    new_shape->type = TRIANGLE;
    strcpy(new_shape->name, name);
    new_shape->triangle.base = base;
    new_shape->triangle.height = height;
    shapes[shape_count++] = new_shape;
}

void display_shapes() {
    for(int i = 0; i < shape_count; ++i) {
        Shape* shape = shapes[i];
        printf("Shape %d: %s, Type: ", i + 1, shape->name);
        switch(shape->type) {
            case CIRCLE:
                printf("Circle, Radius: %.2f\n", shape->circle.radius);
                break;
            case RECTANGLE:
                printf("Rectangle, Length: %.2f, Width: %.2f\n", shape->rectangle.length, shape->rectangle.width);
                break;
            case TRIANGLE:
                printf("Triangle, Base: %.2f, Height: %.2f\n", shape->triangle.base, shape->triangle.height);
                break;
        }
    }
}

void free_shapes() {
    for(int i = 0; i < shape_count; ++i) {
        free(shapes[i]);
    }
}

int main() {
    int choice;
    char name[30];
    float a, b;
    
    do {
        printf("\nShape Database Menu:\n");
        printf("1. Add Circle\n");
        printf("2. Add Rectangle\n");
        printf("3. Add Triangle\n");
        printf("4. Display Shapes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Circle Name: ");
                scanf("%s", name);
                printf("Enter Circle Radius: ");
                scanf("%f", &a);
                add_circle(name, a);
                break;
            case 2:
                printf("Enter Rectangle Name: ");
                scanf("%s", name);
                printf("Enter Rectangle Length and Width: ");
                scanf("%f %f", &a, &b);
                add_rectangle(name, a, b);
                break;
            case 3:
                printf("Enter Triangle Name: ");
                scanf("%s", name);
                printf("Enter Triangle Base and Height: ");
                scanf("%f %f", &a, &b);
                add_triangle(name, a, b);
                break;
            case 4:
                display_shapes();
                break;
            case 5:
                free_shapes();
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}