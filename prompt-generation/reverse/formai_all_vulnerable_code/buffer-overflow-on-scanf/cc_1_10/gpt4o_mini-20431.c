//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int current_floor;
    int destination_floor;
} Elevator;

void display_elevator_status(Elevator *elevator);
void move_elevator(Elevator *elevator);
void enter_building(Elevator *elevator);
void farewell_scene();

int main() {
    Elevator romeo = {1, 0}; // Starts on floor 1
    Elevator juliet = {1, 0}; // Starts on floor 1
    int choice;

    printf("Welcome to the Montague & Capulet Building.\n");
    enter_building(&romeo);
    enter_building(&juliet);

    while (1) {
        printf("\nWhere dost thou wish to venture, dear Romeo? (Choose your fate)\n");
        printf("1 - Go to Juliet's balcony on floor 5\n");
        printf("2 - Return to thy room on floor 1\n");
        printf("3 - Ascend to the heavens on floor 10\n");
        printf("4 - Exit the simulation\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                romeo.destination_floor = 5; // To Juliet
                break;
            case 2:
                romeo.destination_floor = 1; // Room
                break;
            case 3:
                romeo.destination_floor = 10; // Heaven
                break;
            case 4:
                farewell_scene();
                exit(0);
            default:
                printf("Alas! That choice doth not exist.\n");
                continue;
        }

        move_elevator(&romeo);
        display_elevator_status(&romeo);
        
        // Assume Juliet makes her own choices but shares her location with Romeo
        juliet.destination_floor = 5; // Always waiting for Romeo at her balcony
        move_elevator(&juliet);
        display_elevator_status(&juliet);
        
        if (romeo.current_floor == juliet.current_floor) {
            printf("Oh, what light through yonder window breaks!\n");
            printf("Romeo and Juliet meet at floor %d!\n", romeo.current_floor);
            printf("Their hearts beat as one, love eternal.\n");
            break; // End the simulation on a romantic note
        }
    }

    return 0;
}

void display_elevator_status(Elevator *elevator) {
    printf("The elevator now stands on floor %d.\n", elevator->current_floor);
}

void move_elevator(Elevator *elevator) {
    int direction;

    printf("Whence doth the elevator move? \n");

    if (elevator->destination_floor > elevator->current_floor) {
        direction = 1; // Up
    } else if (elevator->destination_floor < elevator->current_floor) {
        direction = -1; // Down
    } else {
        return; // Already there
    }

    while (elevator->current_floor != elevator->destination_floor) {
        sleep(1); // Simulate time passing
        elevator->current_floor += direction; // Move the elevator
        printf("The elevator moves...\n");
    }
}

void enter_building(Elevator *elevator) {
    printf("With trembling hands, the lovers enter the building.\n");
    printf("What joy! They find themselves on floor %d.\n", elevator->current_floor);
}

void farewell_scene() {
    printf("The curtain falls as the star-crossed lovers find their peace...\n");
    printf("Farewell, dear friend. Love's story shall continue.\n");
}