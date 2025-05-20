//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_FLOORS 20
#define MAX_ELEVATORS 4

int floors[MAX_FLOORS]; // stores number of people at each floor
int current_positions[MAX_ELEVATORS]; // stores current position of each elevator (0 index based)
int max_people[MAX_ELEVATORS]; // stores max people capacity of each elevator
int current_people[MAX_ELEVATORS]; // stores current number of people in each elevator
int go_to[MAX_ELEVATORS]; // stores the requested destination floor for each elevator

void initialize() {
    memset(floors, 0, sizeof(floors));
    memset(max_people, 0, sizeof(max_people));
    memset(current_people, 0, sizeof(current_people));
    memset(current_positions, 0, sizeof(current_positions));
    memset(go_to, -1, sizeof(go_to));
}

void print_state() {
    printf("Number of people at each floor: ");
    for(int i=0; i<MAX_FLOORS; i++) {
        printf("%d ", floors[i]);
    }
    
    printf("\nCurrent position of each elevator: ");
    for(int i=0; i<MAX_ELEVATORS; i++) {
        printf("%d ", current_positions[i]);
    }
    
    printf("\nMax people capacity of each elevator: ");
    for(int i=0; i<MAX_ELEVATORS; i++) {
        printf("%d ", max_people[i]);
    }
    
    printf("\nCurrent number of people in each elevator: ");
    for(int i=0; i<MAX_ELEVATORS; i++) {
        printf("%d ", current_people[i]);
    }
    
    printf("\nRequested destination floor for each elevator: ");
    for(int i=0; i<MAX_ELEVATORS; i++) {
        printf("%d ", go_to[i]);
    }
    printf("\n\n");
}

int choose_elevator(int floor, int num_people) {
    int closest_elevator = -1;
    int min_distance = MAX_FLOORS; // initialize to max distance possible
    
    for(int i=0; i<MAX_ELEVATORS; i++) {
        // if elevator is not at a floor, skip it
        if(current_positions[i] == -1) {
            continue;
        }
        
        // calculate Euclidean distance between elevator and the floor
        int distance = abs(current_positions[i] - floor);
        
        if(current_people[i] + num_people <= max_people[i]) {
            // if elevator has enough space for the people and elevator is closer than current closest
            if(distance < min_distance) {
                min_distance = distance;
                closest_elevator = i;
            }
        }
    }
    
    return closest_elevator;
}

void move_elevators() {
    for(int i=0; i<MAX_ELEVATORS; i++) {
        // if elevator is not at a floor, skip it
        if(current_positions[i] == -1) {
            continue;
        }
        
        // if elevator has reached its destination, stop and let people off
        if(current_positions[i] == go_to[i]) {
            printf("Elevator %d has reached destination floor %d. %d people got off.\n", i+1, go_to[i]+1, current_people[i]);
            floors[go_to[i]] += current_people[i]; // add number of people who got off to the floor
            current_people[i] = 0;
            go_to[i] = -1; // reset go_to to -1 since elevator has no destination
            continue;
        }
        
        // if elevator is moving up
        if(current_positions[i] < go_to[i]) {
            current_positions[i]++;
            printf("Elevator %d moved up to floor %d\n", i+1, current_positions[i]+1);
        }
        // if elevator is moving down
        else if(current_positions[i] > go_to[i]) {
            current_positions[i]--;
            printf("Elevator %d moved down to floor %d\n", i+1, current_positions[i]+1);
        }
    }
}

int main() {
    initialize(); // initialize all arrays to default values
    
    printf("Welcome to our elevator system!\n\n");
    
    // keep running until user enters 'quit'
    char input[10];
    while(1) {
        printf("Enter command (add, request, move, state, quit): ");
        scanf("%s", input);
        
        for(int i=0; i<strlen(input); i++) {
            input[i] = tolower(input[i]); // convert input to lowercase to simplify checking
        }
        
        if(strcmp(input, "add") == 0) {
            int elevator_num, capacity;
            printf("Enter elevator number (1-%d) and capacity: ", MAX_ELEVATORS);
            scanf("%d %d", &elevator_num, &capacity);
            
            if(elevator_num < 1 || elevator_num > MAX_ELEVATORS) {
                printf("Invalid elevator number. Please try again.\n");
                continue;
            }
            
            if(capacity <= 0 || capacity > 10) {
                printf("Invalid capacity. Please enter a value between 1 and 10.\n");
                continue;
            }
            
            max_people[elevator_num-1] = capacity;
            current_positions[elevator_num-1] = 0; // set elevator to ground floor
            printf("Elevator %d added with capacity %d.\n", elevator_num, capacity);
        }
        else if(strcmp(input, "request") == 0) {
            int floor_num, num_people;
            printf("Enter floor number (1-%d) and number of people: ", MAX_FLOORS);
            scanf("%d %d", &floor_num, &num_people);
            
            if(floor_num < 1 || floor_num > MAX_FLOORS) {
                printf("Invalid floor number. Please try again.\n");
                continue;
            }
            
            if(num_people <= 0 || num_people > 10) {
                printf("Invalid number of people. Please enter a value between 1 and 10.\n");
                continue;
            }
            
            int elevator_num = choose_elevator(floor_num-1, num_people);
            if(elevator_num == -1) {
                printf("No elevator is available to accommodate your request.\n");
                continue;
            }
            
            floors[floor_num-1] += num_people; // add the number of people to the floor
            current_people[elevator_num] += num_people; // add the number of people to the elevator
            go_to[elevator_num] = floor_num-1; // set elevator destination to the requested floor
            printf("%d people are now in Elevator %d, which is heading to floor %d.\n", num_people, elevator_num+1, floor_num);
        }
        else if(strcmp(input, "move") == 0) {
            move_elevators();
        }
        else if(strcmp(input, "state") == 0) {
            print_state();
        }
        else if(strcmp(input, "quit") == 0) {
            printf("Thanks for using our elevator system!\n");
            break;
        }
        else {
            printf("Invalid command. Please try again.\n");
        }
    }
    
    return 0;
}