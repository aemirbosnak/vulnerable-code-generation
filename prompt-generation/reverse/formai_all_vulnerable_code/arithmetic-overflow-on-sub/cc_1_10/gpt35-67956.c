//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: modular
#include<stdio.h>
#include<stdlib.h>

// Defining the constants
#define maxFloor 10
#define minFloor 1
#define capacityOfElevator 10

// Defining the structure for person
struct Person{
    int personID;
    int startFloor;
    int endFloor;
    int weight;
};

// Defining the structure for elevator
struct Elevator{
    int currentFloor;
    int currentWeight;
    int totalPersons;
};

// Defining the functions
void enterPersonDetails(struct Person*, int);
void elevatorOperations(struct Elevator, struct Person*, int);

int main(){
    struct Person person[capacityOfElevator];
    struct Elevator elevator;
    int noOfPersons;

    printf("Enter the number of persons (Capacity of elevator is 10 only): ");
    scanf("%d",&noOfPersons);
    if(noOfPersons>capacityOfElevator){
        printf("Elevator capacity is maximum %d. Please enter a valid number of persons.\n",capacityOfElevator);
        exit(0);
    }

    enterPersonDetails(person,noOfPersons);
    elevator.currentFloor = minFloor;
    elevator.currentWeight = 0;
    elevator.totalPersons = noOfPersons;

    // Calling the elevator operation function
    elevatorOperations(elevator,person,noOfPersons);

    return 0;
}

// Defining the function to enter person details
void enterPersonDetails(struct Person *person,int noOfPersons){
    printf("Enter the details for each person -\n");
    for(int i=0;i<noOfPersons;i++){
        person[i].personID = i+1;
        printf("Enter the starting floor for person %d: ",i+1);
        scanf("%d",&person[i].startFloor);
        printf("Enter the ending floor for person %d: ",i+1);
        scanf("%d",&person[i].endFloor);
        printf("Enter the weight for person %d: ",i+1);
        scanf("%d",&person[i].weight);
    }
}

// Defining the function for elevator operations
void elevatorOperations(struct Elevator elevator, struct Person *person, int noOfPersons){
    int totalWeight=0;
    printf("\n********************************************************\n");
    printf("\t\tWelcome to the Elevator\n");
    printf("********************************************************\n\n");
    printf("Elevator is at Floor %d, maximum floor is at level %d & minimum floor is at level %d.\n",elevator.currentFloor,maxFloor,minFloor);

    while(elevator.totalPersons){
        int nextFloor=0;
        printf("\nEnter the next floor: ");
        scanf("%d",&nextFloor);
        if(nextFloor>maxFloor || nextFloor<minFloor){
            printf("\nInvalid floor entered. Please enter a valid floor.\n");
            continue;
        }

        // Checking if the elevator is going up or down
        if(nextFloor>elevator.currentFloor){
            totalWeight=0;
            // Calculating the total weight for all persons in the elevator
            for(int i=0;i<noOfPersons;i++){
                if(person[i].startFloor == elevator.currentFloor){
                    totalWeight = totalWeight + person[i].weight;
                }
            }
            // Checking if the maximum capacity of elevator is reached
            if((totalWeight+elevator.currentWeight)>capacityOfElevator){
                printf("\nElevator capacity exceeded. Please reduce the weight.\n");
                continue;
            }
            elevator.currentFloor = nextFloor;
            elevator.currentWeight = elevator.currentWeight + totalWeight;
            printf("\nElevator moving up from Floor %d to Floor %d.\n",elevator.currentFloor-totalWeight,nextFloor);
            elevator.totalPersons = elevator.totalPersons - 1;
            printf("Total weight in the elevator is %d & number of persons in the elevator are %d\n",elevator.currentWeight,elevator.totalPersons);
        }
        else if(nextFloor<elevator.currentFloor){
            totalWeight=0;
            for(int i=0;i<noOfPersons;i++){
                if(person[i].endFloor == elevator.currentFloor){
                    totalWeight = totalWeight + person[i].weight;
                }
            }
            if((totalWeight+elevator.currentWeight)>capacityOfElevator){
                printf("\nElevator capacity exceeded. Please reduce the weight.\n");
                continue;
            }
            elevator.currentFloor = nextFloor;
            elevator.currentWeight = elevator.currentWeight + totalWeight;
            printf("\nElevator moving down from Floor %d to Floor %d.\n",elevator.currentFloor+totalWeight,nextFloor);
            elevator.totalPersons = elevator.totalPersons - 1;
            printf("Total weight in the elevator is %d & number of persons in the elevator are %d\n",elevator.currentWeight,elevator.totalPersons);
        }
        else{
            printf("\nElevator is already at Floor %d.\n",elevator.currentFloor);
        }
    }
    printf("\nAll persons have been dropped off at their respective floors.\n");
}