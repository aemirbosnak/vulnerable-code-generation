//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 50

int main() {
   int speed = 0;
   int distance_travelled = 0;
   int fuel_level = 100;
   int x_coordinate = 0, y_coordinate = 0;
   int direction = 0;     // 0 for North, 1 for East, 2 for South, 3 for West

   srand(time(NULL));     // Seed the random number generator

   printf("Welcome to the Remote Control Vehicle Simulation Program!\n");

   while(1) {
      // Output information about the vehicle status
      printf("Speed: %d mph\n", speed);
      printf("Distance travelled: %d miles\n", distance_travelled);
      printf("Fuel level: %d%%\n", fuel_level);
      printf("Vehicle location: (%d, %d)\n\n", x_coordinate, y_coordinate);

      // Check if the user wants to exit
      printf("Enter 'exit' to terminate the program: ");
      char input[10];
      scanf("%s", input);
      if (strcmp(input, "exit") == 0) {
         printf("\nProgram terminated.\n");
         break;
      }

      // Generate a random speed change
      int speed_change = rand() % 21 - 10;     // Generate a random number between -10 and 10
      speed += speed_change;
      
      // Limit the speed to the maximum
      if (speed > MAX_SPEED) speed = MAX_SPEED;
      if (speed < 0) speed = 0;

      // Calculate the distance travelled at the current speed
      int distance_travelled_this_iteration = speed * 10; // Distance is speed times time interval
      distance_travelled += distance_travelled_this_iteration;

      // Consume fuel based on distance travelled and speed
      int fuel_consumption = distance_travelled_this_iteration * speed / MAX_SPEED / 5;
      fuel_level -= fuel_consumption;
      if (fuel_level < 0) fuel_level = 0;

      // Calculate the new location of the vehicle based on the current speed and direction
      switch(direction) {
         case 0: y_coordinate += speed; break;     // Move North
         case 1: x_coordinate += speed; break;     // Move East
         case 2: y_coordinate -= speed; break;     // Move South
         case 3: x_coordinate -= speed; break;     // Move West
      }

      // Ask the user to change direction
      printf("Enter a direction (n/e/s/w): ");
      char direction_input;
      scanf(" %c", &direction_input);
      switch(direction_input) {
         case 'n': direction = 0; break;   // North
         case 'e': direction = 1; break;   // East
         case 's': direction = 2; break;   // South
         case 'w': direction = 3; break;   // West
      }
   }

   return 0;
}