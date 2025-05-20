//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

struct resistor {
   float value;
   float current;
   float voltage;
};

int main() {

   struct resistor r1, r2, r3;
   float totalVoltage = 20.0;
   float totalCurrent;
   float totalResistance;

   printf("Enter the value of the first resistor: ");
   scanf("%f", &r1.value);

   printf("Enter the value of the second resistor: ");
   scanf("%f", &r2.value);

   printf("Enter the value of the third resistor: ");
   scanf("%f", &r3.value);

   totalResistance = r1.value + r2.value + r3.value;

   totalCurrent = totalVoltage / totalResistance;

   r1.current = totalCurrent;
   r1.voltage = r1.current * r1.value;

   r2.current = totalCurrent;
   r2.voltage = r2.current * r2.value;

   r3.current = totalCurrent;
   r3.voltage = r3.current * r3.value;

   printf("\n\nResult:\n\n");
   printf("Total Voltage: %.2f\n", totalVoltage);
   printf("Total Current: %.2f\n", totalCurrent);
   printf("Total Resistance: %.2f\n", totalResistance);
   printf("Value of Resistor 1: %.2f\n", r1.value);
   printf("Current through Resistor 1: %.2f\n", r1.current);
   printf("Voltage across Resistor 1: %.2f\n", r1.voltage);
   printf("Value of Resistor 2: %.2f\n", r2.value);
   printf("Current through Resistor 2: %.2f\n", r2.current);
   printf("Voltage across Resistor 2: %.2f\n", r2.voltage);
   printf("Value of Resistor 3: %.2f\n", r3.value);
   printf("Current through Resistor 3: %.2f\n", r3.current);
   printf("Voltage across Resistor 3: %.2f\n", r3.voltage);

   return 0;
}