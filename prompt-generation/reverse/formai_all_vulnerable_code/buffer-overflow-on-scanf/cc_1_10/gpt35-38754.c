//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Struct to represent a Baggage 
typedef struct Baggage{
    int weight;
    int destinationTerminal;
} Baggage;

// Function to add Baggage to the airport system
void addBaggage(Baggage* baggage, int numOfBaggage){
    for (int i=0; i<numOfBaggage; i++){
        printf("Enter weight of Baggage %d: ", i+1);
        scanf("%d", &(baggage+i)->weight);

        printf("Enter the destination Terminal of Baggage %d: ", i+1);
        scanf("%d", &(baggage+i)->destinationTerminal);
    }
}

// Function to sort the Baggage by destination Terminal
void sortBaggageByDestination(Baggage* baggage, int numOfBaggage){
    Baggage temp;
    for (int i=1; i<numOfBaggage; i++){
        for (int j=0; j<numOfBaggage-i; j++){
            if ((baggage+j)->destinationTerminal > (baggage+j+1)->destinationTerminal){
                temp = *(baggage+j);
                *(baggage+j) = *(baggage+j+1);
                *(baggage+j+1) = temp;
            }
        }
    }
}

// Function to display the information of all Baggage
void displayBaggageInfo(Baggage* baggage, int numOfBaggage){
    printf("\nBaggage Information:\n");
    for (int i=0; i<numOfBaggage; i++){
        printf("Baggage %d:\n", i+1);
        printf("Weight: %d kg\n", (baggage+i)->weight);
        printf("Destination Terminal: %d\n\n", (baggage+i)->destinationTerminal);
    }
}

// Main function
int main(){
    int numOfBaggage;
    printf("Enter number of baggage: ");
    scanf("%d", &numOfBaggage);

    Baggage* baggage = (Baggage*) malloc(numOfBaggage * sizeof(Baggage));
    if (baggage == NULL){
        printf("Memory allocation failed!\n");
        return 0;
    }

    addBaggage(baggage, numOfBaggage);
    sortBaggageByDestination(baggage, numOfBaggage);
    displayBaggageInfo(baggage, numOfBaggage);

    free(baggage);
    return 0;
}