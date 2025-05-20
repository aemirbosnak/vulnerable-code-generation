//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Claude Shannon
/*
This is a classical circuit simulator program in Claude Shannon style.
It simulates the behavior of simple circuits consisting of resistors and voltage sources connected in series or parallel arrangement.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_CIRCUIT_SIZE 100 // maximum number of circuit components that can be simulated

typedef struct {
   char type; // 'R' for resistor, 'V' for voltage source
   float value; // resistor resistance or voltage source voltage
} CircuitComponent;

int main() {
   CircuitComponent circuit[MAX_CIRCUIT_SIZE]; // array to store the circuit components
   int numComponents = 0; // number of components in the circuit
   bool validInput = true; // flag to indicate if the user input was valid
   
   // get user input for circuit components
   do {
      char typeInput;
      float valueInput;
      
      printf("Enter component type ('R' for resistor, 'V' for voltage source) and value (in ohms or volts), separated by a space: ");
      scanf("%c %f", &typeInput, &valueInput);
      
      // check if input is valid
      if (typeInput == 'R' && valueInput > 0) {
         circuit[numComponents].type = 'R';
         circuit[numComponents].value = valueInput;
         numComponents++;
      }
      else if (typeInput == 'V') {
         circuit[numComponents].type = 'V';
         circuit[numComponents].value = valueInput;
         numComponents++;
      }
      else {
         validInput = false;
      }
      
      // clear input buffer to prevent errors in next input
      getchar();
      
   } while (validInput && numComponents < MAX_CIRCUIT_SIZE);
   
   // simulate circuit behavior
   float totalResistance = 0;
   float totalVoltage = 0;
   for (int i = 0; i < numComponents; i++) {
      if (circuit[i].type == 'R') {
         totalResistance += circuit[i].value;
      }
      else if (circuit[i].type == 'V') {
         totalVoltage += circuit[i].value;
      }
   }
   float current = totalVoltage / totalResistance;
   printf("Total resistance: %.2f ohms\n", totalResistance);
   printf("Total voltage: %.2f volts\n", totalVoltage);
   printf("Current: %.2f amps\n", current);
   
   return 0;
}