//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
 
int main() {
    int num_floors, num_elevators, num_people;
    int i, current_floor, target_floor, elevator, elevator_location, closest_elevator_status;
    int *elevator_status, *waiting_people, *target_floors, *num_people_in_elevator, *target_direction;
    int person_count = 0, max_people_in_elevator, time = 0, flag = 1;
 
    // Getting inputs from user
    printf("Enter the number of floors: ");
    scanf("%d", &num_floors);
 
    printf("Enter the number of elevators: ");
    scanf("%d", &num_elevators);
 
    printf("Enter the maximum number of people allowed in an elevator: ");
    scanf("%d", &max_people_in_elevator);
 
    printf("Enter the number of people: ");
    scanf("%d", &num_people);
 
    // Allocating memory to dynamic arrays
    elevator_status = (int*)malloc(num_elevators*sizeof(int));
    waiting_people = (int*)calloc(num_floors, sizeof(int));
    target_floors = (int*)malloc(num_people*sizeof(int));
    num_people_in_elevator = (int*)calloc(num_elevators, sizeof(int));
    target_direction = (int*)malloc(num_people*sizeof(int));
 
    // Initializing dynamic arrays
    for(i = 0; i < num_elevators; i++) {
        elevator_status[i] = 1;
    }
 
    for(i = 0; i < num_people; i++) {
        printf("Enter the source floor and target floor of person %d: ", i+1);
        scanf("%d %d", &current_floor, &target_floor);
        waiting_people[current_floor-1]++;
        target_floors[i] = target_floor-1;

        if(current_floor < target_floor) {
            target_direction[i] = 1; // Destination floor is above
        }
        else {
            target_direction[i] = -1; // Destination floor is below
        }
    }
 
    printf("\nTime: %d\n", time);
 
    // Starting simulation
    while(flag) {
        // Moving people from waiting floors to elevators if there is space and elevator is available
        for(i = 0; i < num_floors; i++) {
            while(waiting_people[i] > 0) {
                closest_elevator_status = num_floors;
 
                for(elevator = 0; elevator < num_elevators; elevator++) {
                    // Finding elevator with minimum distance from current floor
                    if(elevator_status[elevator] && abs(i-elevator_location) < closest_elevator_status) {
                        closest_elevator_status = abs(i-elevator_location);
                        elevator_status[elevator] = 0;
                        break;
                    }
                }
 
                // Adding person to elevator if there is space and elevator is available
                if(elevator < num_elevators && num_people_in_elevator[elevator] < max_people_in_elevator) {
                    waiting_people[i]--;
                    num_people_in_elevator[elevator]++;
                    printf("Person %d entered elevator %d at floor %d.\n", ++person_count, elevator+1, i+1);
                }
                else {
                    break;
                }
            }
        }
 
        // Moving elevators to target floors of people
        for(elevator = 0; elevator < num_elevators; elevator++) {
            if(elevator_status[elevator] == 0) {
                continue;
            }
 
            closest_elevator_status = 2*num_floors;
 
            for(i = 0; i < num_people; i++) {
                // Finding the target floor of the closest person in the same direction
                if(target_direction[i] == elevator_location-target_floors[i] && abs(elevator_location-target_floors[i]) < closest_elevator_status) {
                    closest_elevator_status = abs(elevator_location-target_floors[i]);
                    target_floor = target_floors[i];
                }
            }
 
            // Going to the closest target floor, opening doors and allowing people to exit
            if(closest_elevator_status != 2*num_floors) {
 
                if(elevator_location < target_floor) {
                    printf("Elevator %d going up to floor %d.\n", elevator+1, target_floor+1);
                }
                else {
                    printf("Elevator %d going down to floor %d.\n", elevator+1, target_floor+1);
                }
 
                while(elevator_location != target_floor) {
                    if(target_floor > elevator_location) {
                        elevator_location++;
                    }
                    else {
                        elevator_location--;
                    }
 
                    time++;
                    printf("Time: %d\n", time);
                }
 
                printf("Elevator %d reached floor %d.\n", elevator+1, target_floor+1);
 
                for(i = 0; i < num_people; i++) {
                    // Allowing people to exit
                    if(target_floor == target_floors[i] && target_direction[i] == elevator_location-target_floors[i]) {
                        num_people_in_elevator[elevator]--;
                        waiting_people[target_floor]++;
                        printf("Person %d exited elevator %d at floor %d.\n", i+1, elevator+1, elevator_location+1);
                    }
                }
 
                elevator_status[elevator] = 1;
            }
        }
 
        // Checking if simulation is complete
        flag = 0;
 
        for(i = 0; i < num_floors; i++) {
            if(waiting_people[i]) {
                flag = 1;
                break;
            }
        }
 
        for(i = 0; i < num_elevators; i++) {
            if(num_people_in_elevator[i] > 0) {
                flag = 1;
                break;
            }
        }
    }
 
    return 0;
}