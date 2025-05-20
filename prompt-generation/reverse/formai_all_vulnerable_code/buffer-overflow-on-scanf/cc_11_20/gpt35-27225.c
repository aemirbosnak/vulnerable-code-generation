//FormAI DATASET v1.0 Category: Smart home automation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   int living_room_lights = 0;
   int bedroom_lights = 0;
   int kitchen_lights = 0;
   int garage_door = 0;
   int alarm_system = 0;
   
   while(1) {
      char command[50];
      printf("Enter a command: ");
      scanf("%s", command);
      if(strcmp(command, "living_room_lights_on") == 0) {
         living_room_lights = 1;
         printf("Living room lights are now on.\n");
      }
      else if(strcmp(command, "living_room_lights_off") == 0) {
         living_room_lights = 0;
         printf("Living room lights are now off.\n");
      }
      else if(strcmp(command, "bedroom_lights_on") == 0) {
         bedroom_lights = 1;
         printf("Bedroom lights are now on.\n");
      }
      else if(strcmp(command, "bedroom_lights_off") == 0) {
         bedroom_lights = 0;
         printf("Bedroom lights are now off.\n");
      }
      else if(strcmp(command, "kitchen_lights_on") == 0) {
         kitchen_lights = 1;
         printf("Kitchen lights are now on.\n");
      }
      else if(strcmp(command, "kitchen_lights_off") == 0) {
         kitchen_lights = 0;
         printf("Kitchen lights are now off.\n");
      }
      
      else if(strcmp(command, "garage_door_open") == 0) {
         garage_door = 1;
         printf("Garage door is now open.\n");
      }
      else if(strcmp(command, "garage_door_close") == 0) {
         garage_door = 0;
         printf("Garage door is now closed.\n");
      }
      else if(strcmp(command, "alarm_system_arm") == 0) {
         alarm_system = 1;
         printf("Alarm system is now armed.\n");
      }
      else if(strcmp(command, "alarm_system_disarm") == 0) {
         alarm_system = 0;
         printf("Alarm system is now disarmed.\n");
      }
      else if(strcmp(command, "help") == 0) {
         printf("Available commands: \n");
         printf("living_room_lights_on\n");
         printf("living_room_lights_off\n");
         printf("bedroom_lights_on\n");
         printf("bedroom_lights_off\n");
         printf("kitchen_lights_on\n");
         printf("kitchen_lights_off\n");
         printf("garage_door_open\n");
         printf("garage_door_close\n");
         printf("alarm_system_arm\n");
         printf("alarm_system_disarm\n");
         printf("help\n");
      }
      else if(strcmp(command, "exit") == 0) {
         break;
      }
      else {
         printf("Invalid command. Type 'help' for a list of available commands.\n");
      }
   }
   return 0;
}