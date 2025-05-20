//FormAI DATASET v1.0 Category: Smart home automation ; Style: creative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char command[20];

void bedroomLights(int state) {
   if(state == 0)
      printf("Turning off bedroom lights\n");
   else if(state == 1)
      printf("Turning on bedroom lights\n");
   else
      printf("Invalid command\n");
}

void livingRoomLights(int state) {
   if(state == 0)
      printf("Turning off living room lights\n");
   else if(state == 1)
      printf("Turning on living room lights\n");
   else
      printf("Invalid command\n");
}

void bedroomFan(int state) {
   if(state == 0)
      printf("Turning off bedroom fan\n");
   else if(state == 1)
      printf("Turning on bedroom fan\n");
   else
      printf("Invalid command\n");
}

void livingRoomFan(int state) {
   if(state == 0)
      printf("Turning off living room fan\n");
   else if(state == 1)
      printf("Turning on living room fan\n");
   else
      printf("Invalid command\n");
}

void securitySystem(int state) {
   if(state == 0)
      printf("Disarming security system\n");
   else if(state == 1)
      printf("Arming security system\n");
   else
      printf("Invalid command\n");
}

int main() {
   printf("Welcome to Smart Home Automation\n");
   while(1) {
      printf("\nEnter your command: ");
      scanf("%s", command);
      if(strcmp(command, "bedroomLightsOn") == 0)
         bedroomLights(1);
      else if(strcmp(command, "bedroomLightsOff") == 0)
         bedroomLights(0);
      else if(strcmp(command, "livingRoomLightsOn") == 0)
         livingRoomLights(1);
      else if(strcmp(command, "livingRoomLightsOff") == 0)
         livingRoomLights(0);
      else if(strcmp(command, "bedroomFanOn") == 0)
         bedroomFan(1);
      else if(strcmp(command, "bedroomFanOff") == 0)
         bedroomFan(0);
      else if(strcmp(command, "livingRoomFanOn") == 0)
         livingRoomFan(1);
      else if(strcmp(command, "livingRoomFanOff") == 0)
         livingRoomFan(0);
      else if(strcmp(command, "securitySystemArm") == 0)
         securitySystem(1);
      else if(strcmp(command, "securitySystemDisarm") == 0)
         securitySystem(0);
      else if(strcmp(command, "exit") == 0)
         break;
      else
         printf("Invalid command\n");
   }
   return 0;
}