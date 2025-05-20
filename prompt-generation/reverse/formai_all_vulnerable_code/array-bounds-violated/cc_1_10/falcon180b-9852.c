//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 20 //Maximum number of vehicles
#define DELAY 300 //Delay between two successive vehicles

int front,rear,count=0; //Initializing front,rear and count

struct vehicle{
    int no; //Vehicle number
    int x,y; //Position of vehicle
    int direction; //Direction of vehicle(1 for right,0 for left)
}v[MAX];

void create_vehicle(int no,int x,int y,int direction){
    count++; //Increase count of vehicles by 1
    v[count].no=no; //Assign vehicle number
    v[count].x=x; //Assign position in x-axis
    v[count].y=y; //Assign position in y-axis
    v[count].direction=direction; //Assign direction of vehicle
}

void move_vehicle(int i){
    int x,y;
    x=v[i].x; //Store current position of vehicle
    y=v[i].y;
    if(v[i].direction==1){ //If vehicle is moving right
        x+=1; //Move vehicle one step right
    }
    else{
        x-=1; //Move vehicle one step left
    }
    if(x>=0 && x<=9){ //Check if vehicle has reached end of road
        v[i].x=x; //Update position of vehicle
        v[i].y=y;
        printf("\nVehicle %d has reached the end of the road\n",v[i].no);
    }
}

void main(){
    int i,j,choice;
    srand(time(NULL)); //Seed for random number generator
    system("clear"); //Clear console
    printf("\nWelcome to the Traffic Flow Simulation Program!\n");
    printf("\nEnter the number of vehicles you want to simulate (between 1 and 20): ");
    scanf("%d",&count); //Get number of vehicles from user
    for(i=1;i<=count;i++){ //Loop to create vehicles
        create_vehicle(i,0,0,1); //Create vehicle at starting position
    }
    printf("\nThe vehicles have started moving...\n");
    for(i=0;i<count;i++){ //Loop to move vehicles
        j=rand()%DELAY; //Random delay between two successive vehicles
        sleep(j); //Delay for j milliseconds
        move_vehicle(i); //Move vehicle
    }
    printf("\nAll vehicles have reached the end of the road.\n");
    printf("\nPress 1 to exit.\n");
    scanf("%d",&choice); //Get choice from user
    if(choice!=1){
        main(); //Recursive call to main function
    }
}