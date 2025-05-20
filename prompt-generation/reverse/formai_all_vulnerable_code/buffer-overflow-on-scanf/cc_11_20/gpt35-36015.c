//FormAI DATASET v1.0 Category: Smart home automation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   int temperature = 70;
   int humidity = 50;
   int light = 1;
   int security = 0;
   int music = 0;
    
   printf("Welcome to your smart home! \n");
   printf("Current temperature: %d degrees Fahrenheit. \n", temperature);
   printf("Current humidity: %d percent. \n", humidity);
   printf("Current light status: ");
   if(light == 1) {
      printf("On. \n");
   } else {
      printf("Off. \n");
   }
   printf("Current security status: ");
   if(security == 1) {
      printf("Enabled. \n");
   } else {
      printf("Disabled. \n");
   }
   printf("Current music status: ");
   if(music == 1) {
      printf("Playing. \n");
   } else {
      printf("Not playing. \n");
   }
   
   //main loop
   while(1) {
      char command[20];
      printf("Enter a command: ");
      scanf("%s", command);
      
      if(strcmp(command, "temperature") == 0) {
         printf("Current temperature: %d degrees Fahrenheit. \n", temperature);
      } else if(strcmp(command, "humidity") == 0) {
         printf("Current humidity: %d percent. \n", humidity);
      } else if(strcmp(command, "light on") == 0) {
         light = 1;
         printf("Lights turned on. \n");
      } else if(strcmp(command, "light off") == 0) {
         light = 0;
         printf("Lights turned off. \n");
      } else if(strcmp(command, "security on") == 0) {
         security = 1;
         printf("Security enabled. \n");
      } else if(strcmp(command, "security off") == 0) {
         security = 0;
         printf("Security disabled. \n");
      } else if(strcmp(command, "music on") == 0) {
         music = 1;
         printf("Music turned on. \n");
      } else if(strcmp(command, "music off") == 0) {
         music = 0;
         printf("Music turned off. \n");
      } else if(strcmp(command, "exit") == 0) {
         printf("Exiting program. \n");
         break;
      } else {
         printf("Invalid command. \n");
      }
   }
   return 0;
}