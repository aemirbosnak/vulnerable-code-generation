//FormAI DATASET v1.0 Category: Smart home automation ; Style: systematic
#include <stdio.h>

// Function to control lights
void controlLights(int status) {
   if(status == 0) {
       printf("Lights turned off\n");
   } else if (status == 1) {
       printf("Lights turned on\n");
   } else {
       printf("Invalid input\n");
   }
}

// Function to control thermostat
void controlThermostat(int temperature) {
   if(temperature <= 10) {
       printf("Thermostat turned on, heating to %d degrees Celsius\n", temperature);
   } else if (temperature >= 30) {
       printf("Thermostat turned on, cooling to %d degrees Celsius\n", temperature);
   } else {
       printf("Temperature is within range, no changes made\n");
   }
}

// Function to control security
void controlSecurity(int status) {
   if(status == 0) {
       printf("Security system deactivated\n");
   } else if (status == 1) {
       printf("Security system activated\n");
   } else {
       printf("Invalid input\n");
   }
}

int main() {
   int lights, temperature, security;
   printf("Welcome to Smart Home Automation\n");
   printf("Please select an option:\n");
   printf("1. Control lights\n");
   printf("2. Control thermostat\n");
   printf("3. Control security\n");

   int option;
   scanf("%d", &option);

   switch(option) {
       case 1:
           printf("Please enter the status of lights (0 for off, 1 for on):\n");
           scanf("%d", &lights);
           controlLights(lights);
           break;
       case 2:
           printf("Please enter the desired temperature (in Celsius):\n");
           scanf("%d", &temperature);
           controlThermostat(temperature);
           break;
       case 3:
           printf("Please enter the status of security system (0 for off, 1 for on):\n");
           scanf("%d", &security);
           controlSecurity(security);
           break;
       default:
           printf("Invalid option selected\n");
   }
   
   return 0;
}