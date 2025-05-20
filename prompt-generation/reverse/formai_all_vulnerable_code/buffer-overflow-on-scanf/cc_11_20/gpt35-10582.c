//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Declaring global variables for terminal, checkin and baggage handling systems
int numConveyors = 0, numTerminals = 0, numCheckins = 0;
bool *isTerminalFree, *isCheckinFree, *isBaggageHandlingFree;

//Structure to hold conveyor data
struct Conveyor{
    int id;
    int start;
    int end;
};

//Structure to hold terminal data
struct Terminal{
    int id;
    int checkinId;  //ID of check-in desk assigned to this terminal
    int conveyorId; //ID of conveyor assigned to this terminal
    int waitTime;   //Time this terminal has been waiting for bags
};

//Structure to hold checkin data
struct CheckinDesk{
    int id;
    int terminalId; //ID of terminal assigned to this check-in desk
    bool isFree;    //Whether this desk is free
};

//Function to simulate baggage handling system
void simulateBaggageHandling(struct Conveyor conveyors[], struct Terminal terminals[], struct CheckinDesk checkins[], int numPassengers){
    isTerminalFree = malloc(numTerminals * sizeof(bool));
    isCheckinFree = malloc(numCheckins * sizeof(bool));
    isBaggageHandlingFree = malloc(numConveyors * sizeof(bool));
    
    //Initializing all systems to be free initially
    for(int i = 0; i < numTerminals; i++){
        isTerminalFree[i] = true;
    }
    for(int i = 0; i < numCheckins; i++){
        isCheckinFree[i] = true;
    }
    for(int i = 0; i < numConveyors; i++){
        isBaggageHandlingFree[i] = true;
    }
    
    //Loop for simulating bag arrival and handling
    for(int i = 0; i < numPassengers; i++){
        printf("Passenger %d has arrived with their baggage.\n", i+1);
        int conveyorId = -1;
        int terminalId = -1;
        int checkinId = -1;
        int waitTime = -1;
        
        //Finding free conveyor
        for(int j = 0; j < numConveyors; j++){
            if(isBaggageHandlingFree[j]){
                conveyorId = j;
                isBaggageHandlingFree[j] = false;
                break;
            }
        }
        if(conveyorId == -1){
            printf("No free conveyor available. Bags of Passenger %d cannot be transported.\n", i+1);
            continue;
        }
        
        //Finding free terminal
        for(int j = 0; j < numTerminals; j++){
            if(isTerminalFree[j]){
                terminalId = j;
                isTerminalFree[j] = false;
                break;
            }
        }
        if(terminalId == -1){
            printf("No free terminal available. Bags of Passenger %d cannot be transported.\n", i+1);
            isBaggageHandlingFree[conveyorId] = true;
            continue;
        }
        
        //Finding free check-in desk
        for(int j = 0; j < numCheckins; j++){
            if(isCheckinFree[j]){
                checkinId = j;
                isCheckinFree[j] = false;
                break;
            }
        }
        if(checkinId == -1){
            printf("No free check-in desk available. Bags of Passenger %d cannot be transported.\n", i+1);
            isBaggageHandlingFree[conveyorId] = true;
            isTerminalFree[terminalId] = true;
            continue;
        }
        
        //Assigning terminal, check-in desk and wait time to passenger and terminal
        waitTime = rand() % 20;
        terminals[terminalId].waitTime += waitTime;
        terminals[terminalId].checkinId = checkinId;
        terminals[terminalId].conveyorId = conveyorId;
        checkins[checkinId].isFree = false;
        checkins[checkinId].terminalId = terminalId;
        
        printf("Bags of Passenger %d assigned to Conveyor %c. Assigned Terminal: %c. Assigned Check-in Desk: %c. Wait Time: %d\n", 
                i+1, 'A'+conveyorId, 'A'+terminalId, 'A'+checkinId, waitTime);
    }
    
    //Loop for simulating baggage transport and check-in
    for(int i = 0; i < numTerminals; i++){
        while(!isTerminalFree[i]){
            int conveyorId = terminals[i].conveyorId;
            int checkinId = terminals[i].checkinId;
            int waitTime = terminals[i].waitTime;
            
            //Check if conveyor is free
            if(!isBaggageHandlingFree[conveyorId]){
                waitTime--;
                terminals[i].waitTime = waitTime;
                
                //Check if bags are at check-in desk
                if(waitTime == 0){
                    isTerminalFree[i] = true;
                    isCheckinFree[checkinId] = true;
                    isBaggageHandlingFree[conveyorId] = true;
                    checkins[checkinId].isFree = true;
                    printf("Bags assigned to Terminal %c are now at Check-in Desk %c.\n", 'A'+i, 'A'+checkinId);
                }
            }
        }
    }
    
    printf("All Passengers have checked in their luggage successfully.\n");
    
    //Freeing up memory
    free(isTerminalFree);
    free(isCheckinFree);
    free(isBaggageHandlingFree);
}

int main(){
    printf("Enter the number of conveyors: ");
    scanf("%d", &numConveyors);
    
    //Creating conveyors
    struct Conveyor conveyors[numConveyors];
    for(int i = 0; i < numConveyors; i++){
        conveyors[i].id = i;
        printf("Enter the starting terminal ID of Conveyor %c: ", 'A'+i);
        scanf("%d", &conveyors[i].start);
        printf("Enter the ending terminal ID of Conveyor %c: ", 'A'+i);
        scanf("%d", &conveyors[i].end);
    }
    
    printf("Enter the number of terminals: ");
    scanf("%d", &numTerminals);
    
    //Creating terminals
    struct Terminal terminals[numTerminals];
    for(int i = 0; i < numTerminals; i++){
        terminals[i].id = i;
        terminals[i].checkinId = -1;
        terminals[i].conveyorId = -1;
        terminals[i].waitTime = 0;
    }
    
    printf("Enter the number of check-in desks: ");
    scanf("%d", &numCheckins);
    
    //Creating check-in desks
    struct CheckinDesk checkins[numCheckins];
    for(int i = 0; i < numCheckins; i++){
        checkins[i].id = i;
        checkins[i].isFree = true;
        checkins[i].terminalId = -1;
    }
    
    int numPassengers;
    printf("Enter the total number of passengers: ");
    scanf("%d", &numPassengers);
    
    printf("\nSimulating baggage handling...\n");
    simulateBaggageHandling(conveyors, terminals, checkins, numPassengers);
    
    return 0;
}