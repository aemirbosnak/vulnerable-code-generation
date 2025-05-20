//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

// Define the structure of a remote control vehicle
typedef struct{
    int x,y;  // Position of the vehicle
    int speed; // Speed of the vehicle
    int direction; // Direction of the vehicle (0=forward, 1=backward)
} Vehicle;

// Function to move the vehicle
void move(Vehicle* v){
    int dx,dy;
    if(v->direction==0){
        dx = v->speed;
        dy = 0;
    }
    else{
        dx = -v->speed;
        dy = 0;
    }
    v->x += dx;
    v->y += dy;
}

// Function to turn the vehicle
void turn(Vehicle* v){
    if(v->direction==0){
        v->direction = 1;
    }
    else{
        v->direction = 0;
    }
}

// Function to display the current state of the vehicle
void display(Vehicle v){
    printf("Vehicle at (%d,%d) moving %s with speed %d\n",v.x,v.y,v.direction?"backward":"forward",v.speed);
}

// Main function to simulate the remote control vehicle
int main(){
    Vehicle v;
    v.x = 0;
    v.y = 0;
    v.speed = 0;
    v.direction = 0;

    int choice;
    do{
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Display current state\n");
        printf("6. Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                v.speed = 5;
                break;
            case 2:
                v.speed = -5;
                break;
            case 3:
                turn(&v);
                break;
            case 4:
                turn(&v);
                break;
            case 5:
                display(v);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        move(&v);
    }while(1);

    return 0;
}