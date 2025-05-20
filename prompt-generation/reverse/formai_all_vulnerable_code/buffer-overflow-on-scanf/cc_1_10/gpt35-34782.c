//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: safe
#include<stdio.h>
#include<stdlib.h>

#define MAX 100
 
int n, top = -1;
int stack[MAX];
int floorNum = 0, currentFloor = 0, destFloor = 0, dir = 1, passengers = 0;

char * direction(int);
void push(int s);
int pop();

int main(){
    printf("\nEnter the number of floors in the building: ");
    scanf("%d", &n);
    printf("\nEnter the starting floor: ");
    scanf("%d", &currentFloor);
    printf("\nEnter the destination floor: ");
    scanf("%d", &destFloor);
    dir = (destFloor > currentFloor) ? 1 : -1;
    printf("\nThe elevator is currently on floor %d and will move %s towards floor %d\n", currentFloor, direction(dir), destFloor);
 
    while(currentFloor != destFloor){
        if(top == -1){
            printf("\nThe elevator is currently on floor %d", currentFloor);
            printf("\nNo one wants to get on at this floor. ");
 
            if(destFloor > currentFloor){
                printf("\nThe elevator is moving up to floor %d", ++currentFloor);
            }else{
                printf("\nThe elevator is moving down to floor %d", --currentFloor);
            }
            continue;
        }
        
        printf("\nThe elevator is currently on floor %d", currentFloor);
        printf("\n%d passengers want to get on at this floor. ", top+1);
 
        if(destFloor > currentFloor){
            printf("\nThe elevator is moving up to floor %d", ++currentFloor);
        }else{
            printf("\nThe elevator is moving down to floor %d", --currentFloor);
        }
 
        int i;
        for(i=0;i<=top;i++){
            if(stack[i]==currentFloor){
                passengers++;
            }else{
                push(stack[i]);
            }
        }
        printf("\n%d passengers getting off at floor %d", passengers,currentFloor);
        passengers = 0;
    }
    printf("\nThe elevator has reached the destination floor %d\n", destFloor);
    return 0;
}
 
//Function to return the direction of the elevator
char* direction(int dir){
    return (dir == 1) ? "up" : "down";
}
 
//Function to push the desired floor of people who are waiting for the elevator
void push(int s){
    if(top == MAX-1){
        printf("\nStack overflow");
        exit(1);
    }else{
        stack[++top] = s;
    }
}
 
//Function to pop the desired floor of people who have reached their destination
int pop(){
    if(top == -1){
        printf("\nStack underflow");
        exit(1);
    }else{
        return stack[top--];
    }
}