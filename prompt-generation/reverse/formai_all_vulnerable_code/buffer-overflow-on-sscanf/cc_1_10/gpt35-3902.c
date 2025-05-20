//FormAI DATASET v1.0 Category: Error handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHAPE_BOX 0
#define SHAPE_SPHERE 1
#define SHAPE_CYLINDER 2

typedef struct {
    int type;
    float radius;
    float height;
    float length;
    float width;
} shape;

void print_error(char* error_message) {
    printf("Error: %s\n", error_message);
    exit(EXIT_FAILURE);
}

void create_box(shape* s, float length, float width, float height) {
    if(length <= 0 || width <= 0 || height <= 0) {
        print_error("Invalid box dimensions");
    }
    s->type = SHAPE_BOX;
    s->length = length;
    s->width = width;
    s->height = height;
}

void create_sphere(shape* s, float radius) {
    if(radius <= 0) {
        print_error("Invalid sphere radius");
    }
    s->type = SHAPE_SPHERE;
    s->radius = radius;
}

void create_cylinder(shape* s, float radius, float height) {
    if(radius <= 0 || height <= 0) {
        print_error("Invalid cylinder dimensions");
    }
    s->type = SHAPE_CYLINDER;
    s->radius = radius;
    s->height = height;
}

void print_shape(shape* s) {
    switch(s->type) {
        case SHAPE_BOX:
            printf("Box: Length=%.2f Width=%.2f Height=%.2f\n", s->length, s->width, s->height);
            break;
        case SHAPE_SPHERE:
            printf("Sphere: Radius=%.2f\n", s->radius);
            break;
        case SHAPE_CYLINDER:
            printf("Cylinder: Radius=%.2f Height=%.2f\n", s->radius, s->height);
            break;
        default:
            print_error("Invalid shape type");
    }
}

int main() {
    char input[100];
    float length, width, height, radius;
    shape s;
    while(1) {
        printf("Enter shape type ('box', 'sphere', 'cylinder') or 'exit': ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "exit") == 0) {
            break;
        }
        if(strcmp(input, "box") == 0) {
            printf("Enter length, width, and height separated by spaces: ");
            fgets(input, sizeof(input), stdin);
            if(sscanf(input, "%f %f %f", &length, &width, &height) == 3) {
                create_box(&s, length, width, height);
                print_shape(&s);
            } else {
                print_error("Invalid input");
            }
        } else if(strcmp(input, "sphere") == 0) {
            printf("Enter radius: ");
            fgets(input, sizeof(input), stdin);
            if(sscanf(input, "%f", &radius) == 1) {
                create_sphere(&s, radius);
                print_shape(&s);
            } else {
                print_error("Invalid input");
            }
        } else if(strcmp(input, "cylinder") == 0) {
            printf("Enter radius and height separated by a space: ");
            fgets(input, sizeof(input), stdin);
            if(sscanf(input, "%f %f", &radius, &height) == 2) {
                create_cylinder(&s, radius, height);
                print_shape(&s);
            } else {
                print_error("Invalid input");
            }
        } else {
            print_error("Invalid shape type");
        }
    }
    return 0;
}