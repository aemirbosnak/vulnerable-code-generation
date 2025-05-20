//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 255
#define MAX_SSID_LENGTH 32

typedef struct {
  char ssid[MAX_SSID_LENGTH];
  char bssid[18];
  int channel;
  int signal_strength;
} Device;

int main() {
  Device devices[MAX_DEVICES];
  int num_devices = 0;
  
  // Simulate scanning for devices
  printf("Scanning for devices...\n");
  for(int i = 1; i <= 10; i++) {
    Device d;
    sprintf(d.ssid, "SSID%d", i);
    sprintf(d.bssid, "BSSID:%02x:%02x:%02x:%02x:%02x:%02x",
            rand() % 256, rand() % 256, rand() % 256,
            rand() % 256, rand() % 256, rand() % 256);
    d.channel = rand() % 11 + 1;
    d.signal_strength = rand() % 101;
    
    devices[num_devices++] = d;
  }
  
  // Output the list of devices
  printf("List of Devices:\n");
  printf("----------------------------\n");
  for(int i = 0; i < num_devices; i++) {
    printf("SSID: %s\n", devices[i].ssid);
    printf("BSSID: %s\n", devices[i].bssid);
    printf("Channel: %d\n", devices[i].channel);
    printf("Signal Strength: %d\n", devices[i].signal_strength);
    printf("----------------------------\n");
  }
  
  // Prompt user for channel and output devices on that channel
  int channel;
  printf("Enter channel to scan for: ");
  scanf("%d", &channel);
  printf("Devices on channel %d:\n", channel);
  printf("----------------------------\n");
  for(int i = 0; i < num_devices; i++) {
    if(devices[i].channel == channel) {
      printf("SSID: %s\n", devices[i].ssid);
      printf("BSSID: %s\n", devices[i].bssid);
      printf("Signal Strength: %d\n", devices[i].signal_strength);
      printf("----------------------------\n");
    }
  }
  
  return 0;
}