//FormAI DATASET v1.0 Category: Smart home automation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   int light = 0;
   int temperature = 70;
   int humidity = 50;

   printf("Welcome to Sherlock's Smart Home Automation System!\n");

   while(1) {
       printf("Please enter your desired temperature (in Fahrenheit): ");
       scanf("%d", &temperature);

       if(temperature < 60) {
           printf("It's too cold! Turning on the heater.\n");
       } else if(temperature > 80) {
           printf("It's too hot! Turning on the AC.\n");
       } else {
           printf("The temperature is just right.\n");
       }

       printf("Please enter your desired humidity (in percentage): ");
       scanf("%d", &humidity);

       if(humidity < 40) {
           printf("It's too dry! Turning on the humidifier.\n");
       } else if(humidity > 60) {
           printf("It's too humid! Turning on the dehumidifier.\n");
       } else {
           printf("The humidity is just right.\n");
       }

       char input[100];
       printf("\nWould you like to turn on the lights? (y/n): ");
       scanf("%s", input);

       if(strcmp(input, "y") == 0) {
           light = 1;
           printf("Turning on the lights.\n");
       } else {
           light = 0;
           printf("Turning off the lights.\n");
       }

       printf("\nWould you like to exit the program? (y/n): ");
       scanf("%s", input);

       if(strcmp(input, "y") == 0) {
           printf("Goodbye!\n");
           exit(0);
       }
   }

   return 0;
}