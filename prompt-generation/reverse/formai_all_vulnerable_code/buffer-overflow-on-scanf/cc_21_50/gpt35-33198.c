//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(NULL)); //initialize the random seed with system time
    int numFlights, numConveyors, maxBaggage, maxConveyors, maxWeight; //declaring variables

    printf("Enter the number of flights: ");
    scanf("%d", &numFlights); //getting number of flights from user

    printf("Enter the number of conveyors: ");
    scanf("%d", &numConveyors); //getting number of conveyors from user

    printf("Enter the maximum baggage per flight: ");
    scanf("%d", &maxBaggage); //getting maximum baggage per flight from user

    printf("Enter the maximum conveyors capacity: ");
    scanf("%d", &maxConveyors); //getting maximum conveyors capacity from user

    printf("Enter the maximum allowable weight for a single baggage: ");
    scanf("%d", &maxWeight); //getting maximum allowable weight for a single baggage from user

    int bagNumber = 1; //initialize bag number to 1
    int baggageArr[numFlights][maxBaggage]; //declare a 2D array to hold the baggage for each flight
    int bagWeight[numFlights][maxBaggage]; //declare a 2D array to hold the weight of baggage for each flight
    int conveyorArr[numConveyors][maxConveyors]; //declare a 2D array to hold the baggage on each conveyor
    int conCapacity[numConveyors]; //declare an array to hold the capacity of each conveyor
    int conWeight[numConveyors]; //declare an array to hold the current weight on each conveyor
    int i, j, k; //initialize for loop variables

    //initialize all elements in baggage array to -1
    for(i=0; i<numFlights; i++){
        for(j=0; j<maxBaggage; j++){
            baggageArr[i][j] = -1;
        }
    }

    //generate baggage for each flight randomly
    for(i=0; i<numFlights; i++){
        int numBags = rand() % maxBaggage + 1; //generate random number of bags for each flight
        printf("\nNumber of bags in Flight %d: %d\n", i+1, numBags);
        for(j=0; j<numBags; j++){
            int weight = rand() % maxWeight + 1; //generate random weight for each baggage
            if(weight <= maxWeight){
                baggageArr[i][j] = bagNumber;
                bagWeight[i][j] = weight;
                bagNumber++;
            }
        }
    }

    //initialize all elements in conveyor array to -1
    for(i=0; i<numConveyors; i++){
        for(j=0; j<maxConveyors; j++){
            conveyorArr[i][j] = -1;
        }
    }

    //initialize all elements in capacity and weight arrays for conveyors to 0
    for(i=0; i<numConveyors; i++){
        conCapacity[i] = maxConveyors;
        conWeight[i] = 0;
    }

    //simulate the baggage handling process
    printf("\nSimulation starts...\n\n");
    for(i=0; i<numFlights; i++){
        printf("\nFlight %d arrived:\n", i+1);
        for(j=0; j<maxBaggage; j++){
            int bag = baggageArr[i][j];
            int weight = bagWeight[i][j];
            if(bag != -1){ //check if baggage exists
                printf("\nBag %d with weight %d kg arrived at the airport\n", bag, weight);
                int conveyor = rand() % numConveyors; //generate random conveyor number for the baggage
                if(conWeight[conveyor] + weight <= maxConveyors){ //check if conveyor has capacity for baggage
                    for(k=0; k<maxConveyors; k++){
                        if(conveyorArr[conveyor][k] == -1){ //check if conveyor slot is empty
                            conveyorArr[conveyor][k] = bag; //place the baggage on conveyor
                            conWeight[conveyor] += weight; //update the weight on conveyor
                            printf("Bag %d with weight %d kg is now on conveyor %d\n", bag, weight, conveyor+1);
                            break;
                        }
                    }
                }
                else{
                    printf("Bag %d with weight %d kg could not be placed on conveyor %d due to capacity overload\n", bag, weight, conveyor+1);
                    int flag = 0;
                    for(k=0; k<numConveyors; k++){
                        if(k != conveyor && conWeight[k] + weight <= maxConveyors){ //check if other conveyors have capacity
                            for(int l=0; l<maxConveyors; l++){
                                if(conveyorArr[k][l] == -1){ //check if other conveyor slot is empty
                                    conveyorArr[k][l] = bag; //place baggage on other conveyor
                                    conWeight[k] += weight; //update the weight on other conveyor
                                    flag = 1;
                                    printf("Bag %d with weight %d kg is now on conveyor %d\n", bag, weight, k+1);
                                    break;
                                }
                            }
                        }
                        if(flag){
                            break;
                        }
                    }
                    if(!flag){
                        printf("Bag %d with weight %d kg could not be placed on any conveyor due to capacity overload\n", bag, weight);
                    }
                }
            }
        }
    }

    //display final status of conveyors
    printf("\nFinal status of conveyors:\n");
    for(i=0; i<numConveyors; i++){
        printf("\nConveyor %d: [ ", i+1);
        for(j=0; j<maxConveyors; j++){
            if(conveyorArr[i][j] != -1){
                printf("%d(%d) ", conveyorArr[i][j], bagWeight[conveyorArr[i][j]/100][conveyorArr[i][j]%100]);
            }
        }
        printf("]\nTotal weight on conveyor %d: %d kg\n", i+1, conWeight[i]);
    }

    return 0;
}