//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: scalable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>

//Global variables
int num_floors = 10;  //Number of floors
int num_elevators = 3; //Number of elevators
int elev_pos[3] = { 0, 0, 0 };  //Current position of each elevator
bool elevator_dir[3] = { true, false, true }; //Direction of each elevator (up = true, down = false)
bool floor_req[10] = { false }; //Floor request flag for each floor (true = request, false = no request)
int max_capacity = 10; //Max capacity of each elevator
int floor_time = 5; //Time to travel between floors (in seconds)
int door_time = 2; //Time for doors to open/close (in seconds)
bool shutdown_req = false; //Flag to indicate shutdown requested

//Function to move elevator
void move_elevator(int eid) {
    //Move elevator up/down according to direction
    if (elevator_dir[eid]) {
        elev_pos[eid]++;
        printf("Elevator %d moving up to floor %d\n", eid, elev_pos[eid]);
    }
    else {
        elev_pos[eid]--;
        printf("Elevator %d moving down to floor %d\n", eid, elev_pos[eid]);
    }
}

//Function to check if elevator can pick up/drop off passengers at a floor
bool can_elevate(int eid, int floor) {
    //Check if elevator is at the floor
    if (elev_pos[eid] != floor) {
        return false;
    }
    //Check if elevator is going in the same direction as the floor request
    if ((elevator_dir[eid] && !floor_req[floor]) || (!elevator_dir[eid] && floor_req[floor])) {
        return false;
    }
    //Check if elevator has enough capacity
    //Add code here to check elevator current capacity
    return true;
}

//Function to pick up passengers at a floor
void pickup(int eid, int floor) {
    //Add code here to load/unload passengers
    printf("Elevator %d picking up passengers at floor %d\n", eid, floor);
    floor_req[floor] = false;
}

//Function to drop off passengers at a floor
void dropoff(int eid, int floor) {
    //Add code here to load/unload passengers
    printf("Elevator %d dropping off passengers at floor %d\n", eid, floor);
}

//Thread function to simulate elevator movement
void* elevator_thread(void* arg) {
    int eid = *(int*)arg;
    while (!shutdown_req) {
        //Check if elevator can pick up/drop off passengers at its current position
        if (can_elevate(eid, elev_pos[eid])) {
            dropoff(eid, elev_pos[eid]);
            pickup(eid, elev_pos[eid]);
            elevator_dir[eid] = !elevator_dir[eid]; //Change direction after pickup/dropoff
        }
        else {
            //Move elevator to next floor
            move_elevator(eid);
        }
        //Sleep for floor_time seconds
        sleep(floor_time);
    }
    printf("Elevator %d shutting down...\n", eid);
    pthread_exit(NULL);
}

int main() {
    //Create elevator threads
    pthread_t elevator[num_elevators];
    int eid[num_elevators];
    for (int i = 0; i < num_elevators; i++) {
        eid[i] = i;
        pthread_create(&elevator[i], NULL, elevator_thread, &eid[i]);
    }
    //Main loop to simulate floor requests
    while (true) {
        //Add code here to read floor requests from input
        int floor = rand() % num_floors; //Random floor request for demo purposes
        floor_req[floor] = true;
        printf("Floor %d requested\n", floor);
        //Sleep for door_time seconds to simulate elevator doors opening/closing
        sleep(door_time);
    }
    //Signal shutdown to elevator threads
    shutdown_req = true;
    //Join elevator threads
    for (int i = 0; i < num_elevators; i++) {
        pthread_join(elevator[i], NULL);
    }
    return 0;
}