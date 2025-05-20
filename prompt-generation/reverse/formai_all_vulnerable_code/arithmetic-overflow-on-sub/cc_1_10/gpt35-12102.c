//FormAI DATASET v1.0 Category: Smart home automation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_ROOMS 5
#define NUM_DEVICES 3

// Device Structure
typedef struct device {
   bool state;
   int brightness;
   int temperature;
} device_t;

// Room Structure
typedef struct room {
   int id;
   bool hasMotion;
   device_t devices[NUM_DEVICES];   
} room_t;

// Smart Home Automation System
typedef struct smart_home {
   room_t rooms[NUM_ROOMS];
} smart_home_t;

// Initialize Smart Home
void initSmartHome(smart_home_t *home) {
   home->rooms[0] = (room_t){1, false, {{false, 0, 22}, {false, 0, 20}, {false, 0, 21}}}; // Room 1
   home->rooms[1] = (room_t){2, false, {{false, 0, 25}, {false, 0, 23}, {false, 0, 20}}}; // Room 2
   home->rooms[2] = (room_t){3, true, {{false, 0, 21}, {false, 0, 22}, {false, 0, 23}}};  // Room 3
   home->rooms[3] = (room_t){4, false, {{false, 0, 25}, {false, 0, 24}, {false, 0, 20}}}; // Room 4
   home->rooms[4] = (room_t){5, true, {{false, 0, 21}, {false, 0, 22}, {false, 0, 23}}};  // Room 5
}

// Toggle Device
void toggleDevice(smart_home_t *home, int roomId, int deviceId) {
   home->rooms[roomId-1].devices[deviceId-1].state ^= true;
}

// Set Brightness
void setBrightness(smart_home_t *home, int roomId, int deviceId, int brightness) {
   home->rooms[roomId-1].devices[deviceId-1].brightness = brightness;
}

// Set Temperature
void setTemperature(smart_home_t *home, int roomId, int deviceId, int temperature) {
   home->rooms[roomId-1].devices[deviceId-1].temperature = temperature;
}

// Main Function
int main() {
   smart_home_t home;
   int choice, roomId, deviceId, brightness, temperature;
   
   initSmartHome(&home); // Initialize Smart Home
   
   while(1) {
      // Main Menu
      printf("\n");
      printf("1. Toggle Device\n");
      printf("2. Set Brightness\n");
      printf("3. Set Temperature\n");
      printf("4. Exit\n");
      printf("\nEnter Choice : ");
      scanf("%d", &choice);
      
      switch(choice) {
         case 1:
            printf("\nEnter Room Id : ");
            scanf("%d", &roomId);
            printf("Enter Device Id : ");
            scanf("%d", &deviceId);
            toggleDevice(&home, roomId, deviceId);
            break;
         
         case 2:
            printf("\nEnter Room Id : ");
            scanf("%d", &roomId);
            printf("Enter Device Id : ");
            scanf("%d", &deviceId);
            printf("Enter Brightness : ");
            scanf("%d", &brightness);
            setBrightness(&home, roomId, deviceId, brightness);
            break;
         
         case 3:
            printf("\nEnter Room Id : ");
            scanf("%d", &roomId);
            printf("Enter Device Id : ");
            scanf("%d", &deviceId);
            printf("Enter Temperature : ");
            scanf("%d", &temperature);
            setTemperature(&home, roomId, deviceId, temperature);
            break;
            
         case 4:
            return 0;
            break;
         
         default:
            printf("\nInvalid Choice!\n");
      }
      
      // Display Current State
      printf("\nCurrent State : \n");
      for(int i=0; i<NUM_ROOMS; i++) {
         printf("\nRoom %d\n", home.rooms[i].id);
         for(int j=0; j<NUM_DEVICES; j++) {
            printf("    Device %d -> State : %s, Brightness : %d, Temperature : %d\n", 
               j+1, home.rooms[i].devices[j].state ? "ON" : "OFF", home.rooms[i].devices[j].brightness, home.rooms[i].devices[j].temperature);
         }
         
         if(home.rooms[i].hasMotion) {
            printf("    Motion Sensor : ON\n");
         }
      }
   }
   
   return 0;
}