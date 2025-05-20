//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int floor;
    int destination;
}elevator;

void elevator_move(elevator* e, int floors){
    if(e->floor == e->destination){
        return;
    }
    if(e->floor < e->destination && (e->floor+1)%floors == e->destination){
        e->floor++;
    }
    else if(e->floor > e->destination && (e->floor-1)%floors == e->destination){
        e->floor--;
    }
    else{
        return;
    }
    printf("Elevator moving from floor %d to floor %d\n", e->floor, e->destination);
}

void elevator_stop(elevator* e){
    printf("Elevator stopped at floor %d\n", e->floor);
}

void elevator_request(elevator* e, int floor){
    if(floor < 0 || floor >= 10){
        printf("Invalid floor number\n");
        return;
    }
    if(floor == e->floor){
        printf("You are already on floor %d\n", floor);
        return;
    }
    if(floor == e->destination){
        printf("Elevator already going to floor %d\n", floor);
        return;
    }
    e->destination = floor;
    printf("Elevator going to floor %d\n", floor);
}

int main(){
    elevator e;
    e.floor = 0;
    e.destination = 0;
    int choice;
    while(1){
        printf("1. Request elevator\n");
        printf("2. Move elevator\n");
        printf("3. Stop elevator\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter floor number: ");
                scanf("%d", &e.destination);
                elevator_request(&e, e.destination);
                break;
            case 2:
                elevator_move(&e, 10);
                break;
            case 3:
                elevator_stop(&e);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}