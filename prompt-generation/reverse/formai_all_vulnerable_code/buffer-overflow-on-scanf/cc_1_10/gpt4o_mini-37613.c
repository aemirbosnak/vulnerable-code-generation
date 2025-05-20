//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    CAR,
    BOAT,
    PLANE,
    SHAPE_COUNT
} Shape;

const char *shape_names[SHAPE_COUNT] = {"Car", "Boat", "Plane"};

typedef struct {
    Shape current_shape;
    float speed; // Speed in m/s
} Vehicle;

void initialize_vehicle(Vehicle *v) {
    v->current_shape = CAR;
    v->speed = 0.0;
    printf("Vehicle initialized as %s.\n", shape_names[v->current_shape]);
}

void change_shape(Vehicle *v, Shape new_shape) {
    v->current_shape = new_shape;
    printf("Vehicle shape changed to %s.\n", shape_names[v->current_shape]);
}

void set_speed(Vehicle *v, float new_speed) {
    v->speed = new_speed;
    printf("Vehicle speed set to %.2f m/s.\n", v->speed);
}

void move(Vehicle *v) {
    switch(v->current_shape) {
        case CAR:
            printf("The %s is driving at %.2f m/s.\n", shape_names[v->current_shape], v->speed);
            break;
        case BOAT:
            printf("The %s is sailing at %.2f m/s.\n", shape_names[v->current_shape], v->speed);
            break;
        case PLANE:
            printf("The %s is flying at %.2f m/s.\n", shape_names[v->current_shape], v->speed);
            break;
        default:
            printf("Unknown shape!\n");
    }
}

void display_menu() {
    printf("\nSelect your vehicle shape:\n");
    for(int i = 0; i < SHAPE_COUNT; i++) {
        printf("%d: %s\n", i, shape_names[i]);
    }
    printf("Enter your choice (0-%d): ", SHAPE_COUNT - 1);
}

int main() {
    Vehicle vehicle;
    initialize_vehicle(&vehicle);

    int choice;
    while(1) {
        display_menu();
        scanf("%d", &choice);
        
        if(choice < 0 || choice >= SHAPE_COUNT) {
            printf("Invalid choice. Try again.\n");
            continue;
        }
        
        change_shape(&vehicle, (Shape)choice);
        
        float speed;
        printf("Enter speed for the %s: ", shape_names[choice]);
        scanf("%f", &speed);
        set_speed(&vehicle, speed);

        move(&vehicle);

        char continue_choice;
        printf("Do you want to change the shape again? (y/n): ");
        scanf(" %c", &continue_choice);
        if(continue_choice != 'y') {
            break;
        }
    }

    printf("Simulation ended. Thank you for playing!\n");
    return 0;
}