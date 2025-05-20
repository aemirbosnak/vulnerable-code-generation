//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: grateful
#include<stdio.h>
#include<string.h>
#include<time.h>

int main(){
   // Variable definitions
   char command[50];
   time_t current_time;
   int drone_x, drone_y, drone_z;
   int remote_x, remote_y, remote_z;
   int distance, altitude, speed;
   int battery_life = 100;
   
   // Initialization
   drone_x = drone_y = drone_z = 0;
   remote_x = remote_y = remote_z = 0;

   printf("Welcome to C Drone Remote Control Program!\n");
   printf("Battery Life: %d%%\n", battery_life);

   // Main loop
   while(1){

      // Get user command
      printf("Enter command: ");
      scanf("%s", command);

      // Process command
      if(strcmp(command, "up") == 0){
         printf("Raising drone...\n");
         drone_z++;
         current_time = time(NULL);
         printf("Time: %s", ctime(&current_time));
      }
      else if(strcmp(command, "down") == 0){
         printf("Lowering drone...\n");
         drone_z--;
         current_time = time(NULL);
         printf("Time: %s", ctime(&current_time));
      }
      else if(strcmp(command, "left") == 0){
         printf("Moving drone left...\n");
         drone_x--;
         current_time = time(NULL);
         printf("Time: %s", ctime(&current_time));
      }
      else if(strcmp(command, "right") == 0){
         printf("Moving drone right...\n");
         drone_x++;
         current_time = time(NULL);
         printf("Time: %s", ctime(&current_time));
      }
      else if(strcmp(command, "forward") == 0){
         printf("Moving drone forward...\n");
         drone_y++;
         current_time = time(NULL);
         printf("Time: %s", ctime(&current_time));
      }
      else if(strcmp(command, "backward") == 0){
         printf("Moving drone backward...\n");
         drone_y--;
         current_time = time(NULL);
         printf("Time: %s", ctime(&current_time));
      }
      else if(strcmp(command, "takeoff") == 0){
         printf("Initiating takeoff...\n");
         altitude = drone_z;
         speed = 5;
         current_time = time(NULL);
         printf("Time: %s", ctime(&current_time));
      }
      else if(strcmp(command, "land") == 0){
         printf("Initiating landing...\n");
         drone_z = 0;
         altitude = 0;
         speed = 0;
         current_time = time(NULL);
         printf("Time: %s", ctime(&current_time));
      }
      else if(strcmp(command, "status") == 0){
         printf("Drone Status:\n");
         printf("Position: (%d, %d, %d)\n", drone_x, drone_y, drone_z);
         printf("Altitude: %d\n", altitude);
         printf("Battery Life: %d%%\n", battery_life);
         printf("Speed: %d m/s\n", speed);
         current_time = time(NULL);
         printf("Time: %s", ctime(&current_time));
      }
      else if(strcmp(command, "quit") == 0){
         printf("Exiting program...\n");
         break;
      }
      else{
         printf("Invalid command! Try again.\n");
      }

      // Check battery life
      battery_life--;
      if(battery_life == 0){
         printf("Battery life depleted! Initiating emergency landing.\n");
         drone_z = 0;
         altitude = 0;
         speed = 0;
         current_time = time(NULL);
         printf("Time: %s", ctime(&current_time));
         break;
      }
   }

   return 0;
}