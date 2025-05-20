//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of drones that can be controlled
#define MAX_DRONES 10

// Define the structure of a drone
typedef struct {
    char name[20];
    int battery;
    int altitude;
    int x_pos;
    int y_pos;
} Drone;

// Define the structure of a drone remote control
typedef struct {
    Drone drones[MAX_DRONES];
    int num_drones;
} RemoteControl;

// Function declarations
void create_drone(Drone *dr);
void add_drone(RemoteControl *rc);
void remove_drone(RemoteControl *rc);
void show_status(RemoteControl *rc);
void move_drone(RemoteControl *rc);
void land_drone(RemoteControl *rc);
void recharge_drone(RemoteControl *rc);

int main() {
    RemoteControl rc;
    rc.num_drones = 0;
    
    int choice;
    char menu[] = "DRONE REMOTE CONTROL MENU\n 1. Add Drone\n 2. Remove Drone\n 3. Show Status\n 4. Move Drone\n 5. Land Drone\n 6. Recharge Drone\n 7. Exit\nEnter your choice (1-7): ";
    
    do {
        printf("%s", menu);
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_drone(&rc);
                break;
            case 2:
                remove_drone(&rc);
                break;
            case 3:
                show_status(&rc);
                break;
            case 4:
                move_drone(&rc);
                break;
            case 5:
                land_drone(&rc);
                break;
            case 6:
                recharge_drone(&rc);
                break;
            case 7:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1-7.\n");
        }
    } while(choice != 7);
    
    return 0;
}

// Function to create a new drone
void create_drone(Drone *dr) {
    printf("Enter the name of the drone: ");
    scanf("%s", dr->name);
    dr->battery = 100;
    dr->altitude = 0;
    dr->x_pos = 0;
    dr->y_pos = 0;
}

// Function to add a drone to the remote control
void add_drone(RemoteControl *rc) {
    if(rc->num_drones < MAX_DRONES) {
        create_drone(&rc->drones[rc->num_drones]);
        rc->num_drones++;
    } else {
        printf("Maximum number of drones reached.\n");
    }
}

// Function to remove a drone from the remote control
void remove_drone(RemoteControl *rc) {
    int i, j;
    char name[20];
    
    printf("Enter the name of the drone to remove: ");
    scanf("%s", name);
    
    for(i = 0; i < rc->num_drones; i++) {
        if(strcmp(name, rc->drones[i].name) == 0) {
            // Drone found, remove it by shifting all drones after it one index to the left
            for(j = i; j < rc->num_drones - 1; j++) {
                rc->drones[j] = rc->drones[j+1];
            }
            
            // Decrease the number of drones by 1
            rc->num_drones--;
            
            printf("Drone %s removed.\n", name);
            
            return;
        }
    }
    
    printf("Drone %s not found.\n", name);
}

// Function to show the status of all drones in the remote control
void show_status(RemoteControl *rc) {
    int i;
    
    if(rc->num_drones == 0) {
        printf("No drones found.\n");
    } else {
        printf("%-10s %-10s %-10s %-10s %-10s\n", "Name", "Battery", "Altitude", "X Position", "Y Position");
        for(i = 0; i < rc->num_drones; i++) {
            printf("%-10s %-10d %-10d %-10d %-10d\n", rc->drones[i].name, rc->drones[i].battery, rc->drones[i].altitude, rc->drones[i].x_pos, rc->drones[i].y_pos);
        }
    }
}

// Function to move a drone
void move_drone(RemoteControl *rc) {
    int i;
    char name[20];
    int x_offset, y_offset;
    
    if(rc->num_drones == 0) {
        printf("No drones found.\n");
    } else {
        printf("Enter the name of the drone to move: ");
        scanf("%s", name);
        
        for(i = 0; i < rc->num_drones; i++) {
            if(strcmp(name, rc->drones[i].name) == 0) {
                printf("Enter the x offset (positive for right, negative for left) and y offset (positive for up, negative for down) to move the drone: ");
                scanf("%d %d", &x_offset, &y_offset);
                
                rc->drones[i].x_pos += x_offset;
                rc->drones[i].y_pos += y_offset;
                
                printf("Drone %s moved to position (%d,%d).\n", name, rc->drones[i].x_pos, rc->drones[i].y_pos);
                
                return;
            }
        }
        
        printf("Drone %s not found.\n", name);
    }
}

// Function to land a drone
void land_drone(RemoteControl *rc) {
    int i;
    char name[20];
    
    if(rc->num_drones == 0) {
        printf("No drones found.\n");
    } else {
        printf("Enter the name of the drone to land: ");
        scanf("%s", name);
        
        for(i = 0; i < rc->num_drones; i++) {
            if(strcmp(name, rc->drones[i].name) == 0) {
                rc->drones[i].altitude = 0;
                
                printf("Drone %s landed.\n", name);
                
                return;
            }
        }
        
        printf("Drone %s not found.\n", name);
    }
}

// Function to recharge a drone
void recharge_drone(RemoteControl *rc) {
    int i;
    char name[20];
    
    if(rc->num_drones == 0) {
        printf("No drones found.\n");
    } else {
        printf("Enter the name of the drone to recharge: ");
        scanf("%s", name);
        
        for(i = 0; i < rc->num_drones; i++) {
            if(strcmp(name, rc->drones[i].name) == 0) {
                rc->drones[i].battery = 100;
                
                printf("Drone %s recharged.\n", name);
                
                return;
            }
        }
        
        printf("Drone %s not found.\n", name);
    }
}