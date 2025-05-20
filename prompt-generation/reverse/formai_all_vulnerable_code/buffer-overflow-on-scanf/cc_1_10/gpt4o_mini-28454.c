//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 5

typedef struct {
    int current_floor;
    bool is_moving_up;
} Elevator;

void move_elevator(Elevator *elevator, int destination);
void display_elevator(Elevator *elevator);
void show_status(Elevator *elevator, const char *occupant);
void romance_in_elevator(Elevator *elevator, char *romantic_message);

int main() {
    Elevator romeo_juliet_elevator = {0, false};
    int destination;
    
    printf("Welcome to the Elevator of Love!\n");
    printf("Ah, sweet displays of affection! The elevator awaits!\n");
    while (1) {
        display_elevator(&romeo_juliet_elevator);
        printf("Select a floor (0 - 4) or -1 to exit: ");
        scanf("%d", &destination);
        
        if (destination == -1) {
            printf("Love's journey concludes here. Farewell!\n");
            break;
        } else if (destination < 0 || destination >= MAX_FLOORS) {
            printf("Alas! A floor beyond our realm! Please choose again.\n");
            continue;
        }
        
        move_elevator(&romeo_juliet_elevator, destination);
        romance_in_elevator(&romeo_juliet_elevator, "Oh, Romeo! My heart doth fly on wings of fate.");
        sleep(2); // Delay to mimic romantic pause
    }
    
    return 0;
}

void move_elevator(Elevator *elevator, int destination) {
    printf("The elevator dost ascend from floor %d...\n", elevator->current_floor);
    if (destination > elevator->current_floor) {
        elevator->is_moving_up = true;
        while (elevator->current_floor < destination) {
            elevator->current_floor++;
            sleep(1);
            display_elevator(elevator);
        }
    } else if (destination < elevator->current_floor) {
        elevator->is_moving_up = false;
        while (elevator->current_floor > destination) {
            elevator->current_floor--;
            sleep(1);
            display_elevator(elevator);
        }
    }
    printf("The elevator hath reached floor %d!\n", elevator->current_floor);
}

void display_elevator(Elevator *elevator) {
    printf("Current Floor: %d | Moving: %s\n", elevator->current_floor, elevator->is_moving_up ? "Upward" : "Downward");
}

void show_status(Elevator *elevator, const char *occupant) {
    printf("%s stands gracefully in the elevator, awaiting fate's calling...\n", occupant);
}

void romance_in_elevator(Elevator *elevator, char *romantic_message) {
    printf("In the silence of the lift, the air drips with sentiment:\n");
    printf("\"%s\"\n", romantic_message);
    printf("The hearts of Romeo and Juliet do beat in unison...\n");
}