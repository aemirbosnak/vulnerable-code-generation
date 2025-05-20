//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main() {
   int orientation = 0; // 0 = North, 1 = East, 2 = South, 3 = West
   int altitude = 0; // in meters
   int speed = 0; // in kph
   char batteryStatus; // 'F' - Full, 'H' - Half, 'L' - Low
   int signalStrength = 100; // in percentage

   printf("Welcome to your Drone Remote Control!\n\n");

   // Main loop
   while(1) {
      // Display current status of the drone
      printf("Orientation: %d\n", orientation);
      printf("Altitude: %d meters\n", altitude);
      printf("Speed: %d kph\n", speed);
      printf("Battery status: %c\n", batteryStatus);
      printf("Signal strength: %d%%\n\n", signalStrength);

      // Get input from user
      char input;
      printf("Enter command (W - forward, A - left, S - backward, D - right, U - up, N - down, B - check battery, Q - quit): ");
      scanf("%c", &input);

      // Parse input
      switch(input) {
         case 'W':
            printf("Moving forward...\n");
            break;
         case 'A':
            printf("Turning left...\n");
            orientation--;
            if(orientation < 0) {
               orientation = 3;
            }
            break;
         case 'S':
            printf("Moving backward...\n");
            break;
         case 'D':
            printf("Turning right...\n");
            orientation++;
            if(orientation > 3) {
               orientation = 0;
            }
            break;
         case 'U':
            printf("Going up...\n");
            altitude++;
            break;
         case 'N':
            printf("Going down...\n");
            altitude--;
            if(altitude < 0) {
               altitude = 0;
            }
            break;
         case 'B':
            if(batteryStatus == 'F') {
               printf("Battery is full.\n");
            } else if(batteryStatus == 'H') {
               printf("Battery is half full.\n");
            } else if(batteryStatus == 'L') {
               printf("Battery is low.\n");
            }
            break;
         case 'Q':
            printf("Exiting drone control...\n");
            exit(0);
            break;
         default:
            printf("Invalid command.\n");
            break;
      }

      // Update speed based on orientation and altitude
      if(altitude >= 50) {
         speed = 80;
      } else if(altitude >= 20) {
         speed = 50;
      } else {
         speed = 30;
      }

      if(orientation == 0 || orientation == 2) {
         // moving in North/South direction
         if(speed == 80) {
            signalStrength = 80;
         } else if(speed == 50) {
            signalStrength = 60;
         } else {
            signalStrength = 40;
         }
      } else {
         // moving in East/West direction
         if(speed == 80) {
            signalStrength = 70;
         } else if(speed == 50) {
            signalStrength = 50;
         } else {
            signalStrength = 30;
         }
      }

      // Update battery status
      if(altitude >= 100 && speed == 80) {
         batteryStatus = 'L';
      } else if(altitude >= 50 || speed == 80) {
         batteryStatus = 'H';
      } else {
         batteryStatus = 'F';
      }

      // Wait for 1 second before next loop
      sleep(1);
   }

   return 0;
}