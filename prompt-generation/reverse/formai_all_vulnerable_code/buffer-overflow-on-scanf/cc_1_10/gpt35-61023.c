//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Romeo and Juliet
// Romeo and Juliet Circuit Simulator

#include <stdio.h>

// Define the circuit components
typedef struct {
    int voltage;
    int resistance;
    int current;
} Component;

// Define the circuit variables
Component component1, component2, component3;
int total_voltage;

// Function to calculate the current through each component
void calculate_current() {
    // Calculate the current through component 1
    component1.current = total_voltage / component1.resistance;
    
    // Calculate the current through component 2
    component2.current = total_voltage / component2.resistance;
    
    // Calculate the current through component 3
    component3.current = total_voltage / component3.resistance;
}

int main() {
    // Set the initial values for the components
    component1.voltage = 0;
    component1.resistance = 5;
    component2.voltage = 0;
    component2.resistance = 10;
    component3.voltage = 0;
    component3.resistance = 15;
    
    // Ask Romeo for the total voltage
    printf("Romeo: My dearest Juliet, what is the total voltage of our circuit?\n");
    scanf("%d", &total_voltage);
    
    // Calculate the current through each component
    calculate_current();
    
    // Tell Romeo and Juliet the results
    printf("Juliet: My beloved Romeo, the current through component 1 is %d amps.\n", component1.current);
    printf("Romeo: My darling Juliet, the current through component 2 is %d amps.\n", component2.current);
    printf("Juliet: My sweet Romeo, the current through component 3 is %d amps.\n", component3.current);
    
    return 0;
}