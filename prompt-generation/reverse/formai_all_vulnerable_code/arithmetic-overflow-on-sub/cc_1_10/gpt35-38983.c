//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: careful
#include<stdio.h>

void upDirection(int[], int, int);
void downDirection(int[], int, int);
void moveElevator(int[],int, int, int);
void printStatus(int[],int);

int main()
{
    int currentFloor = 0, totalFloors, choice, passengers, direction;
    printf("Enter the number of floors in the building: ");
    scanf("%d",&totalFloors);
    int floors[totalFloors];

    for(int i=0;i<totalFloors;i++)
    {
        floors[i]=0;
    }

    do{
        printf("\nEnter your choice:\n");
        printf("1. Call the Elevator\n");
        printf("2. Move Elevator\n");
        printf("3. Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the number of passengers waiting: ");
                scanf("%d",&passengers);
                printf("Enter the direction of elevator needed (1-up / 0-down): ");
                scanf("%d",&direction);
                if(direction==1)
                upDirection(floors,totalFloors,passengers);
                else
                downDirection(floors,totalFloors,passengers);
                break;
            case 2:
                if(currentFloor<0 || currentFloor>=totalFloors){
                printf("Invalid current floor. Elevator must be at some floor.\n");
                }
                else{
                    moveElevator(floors,currentFloor,totalFloors,direction);
                    printf("\nElevator arrived at %d floor\n", currentFloor+1);
                    printStatus(floors,totalFloors);
                }
                break;
            case 3:
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while(choice!=3);
    return 0;
}

void upDirection(int floors[], int totalFloors, int passengers){
    int floor;
    printf("Enter your current floor (1-%d)",totalFloors);
    scanf("%d",&floor);
    if(floors[floor-1] != 0 || floor>totalFloors){
        printf("Invalid input or floor not empty. Please try again.\n");
        upDirection(floors,totalFloors,passengers);
    }
    else{
        floors[floor-1] = passengers;
    }
}

void downDirection(int floors[], int totalFloors, int passengers){
    int floor;
    printf("Enter your current floor (1-%d)",totalFloors);
    scanf("%d",&floor);
    if(floors[floor-1] != 0 || floor<=0){
        printf("Invalid input or floor not empty. Please try again.\n");
        downDirection(floors,totalFloors,passengers);
    }
    else{
        floors[floor-1] = passengers;
    }
}

void moveElevator(int floors[],int currentFloor, int totalFloors, int direction){
    if(direction == 1){
        for(int i=currentFloor;i<totalFloors;i++){
            if(floors[i]!=0)
            floors[i] = 0;
            currentFloor = i;
        }
        direction = 0;
    }
    else{
        for(int i=currentFloor;i>=0;i--){
            if(floors[i]!=0)
            floors[i] = 0;
            currentFloor = i;
        }
        direction = 1;
    }
    return;
}

void printStatus(int floors[],int totalFloors){
    printf("Floor-wise status of passengers:\n");
    for(int i=totalFloors-1;i>=0;i--){
        printf("Floor %d: %d passengers\n", i+1, floors[i]);
    }
}