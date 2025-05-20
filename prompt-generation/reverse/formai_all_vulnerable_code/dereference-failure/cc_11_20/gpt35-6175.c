//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

typedef struct {
  char* network_name;
  int signal_strength;
} wifi_signal;

int main() {
  int num_networks;
  
  printf("Welcome to the Brave Wi-Fi Signal Strength Analyzer\n");
  printf("Please enter the number of Wi-Fi networks you would like to analyze: ");
  scanf("%d", &num_networks);
  
  wifi_signal* signal_array = malloc(num_networks * sizeof(wifi_signal));
  
  for(int i=0; i<num_networks; i++) {
    signal_array[i].network_name = malloc(sizeof(char) * 50);
    printf("Please enter the name of network %d: ", i+1);
    scanf("%s", signal_array[i].network_name);
    printf("Please enter the signal strength of network %d (0 - 100): ", i+1);
    scanf("%d", &signal_array[i].signal_strength);
  }
  
  printf("\n========================================\n");
  printf("Wi-Fi Signal Strength Report\n");
  printf("========================================\n");
  
  for(int i=0; i<num_networks; i++) {
    printf("Network Name: %s\nSignal Strength: %d\n", signal_array[i].network_name, signal_array[i].signal_strength);
    printf("----------------------------------------\n");

    // brave conditionals
    if(signal_array[i].signal_strength == MAX_SIGNAL_STRENGTH) {
      printf("Brave Analysis: This network has perfect signal strength! You'll never have to worry about buffering again!\n\n");
    } else if(signal_array[i].signal_strength >= 70 && signal_array[i].signal_strength < MAX_SIGNAL_STRENGTH) {
      printf("Brave Analysis: This network has strong signal strength. You'll have a smooth streaming experience most of the time!\n\n");
    } else if(signal_array[i].signal_strength >= 40 && signal_array[i].signal_strength < 70) {
      printf("Brave Analysis: This network has average signal strength. You'll experience occasional buffering and lagging while streaming.\n\n");
    } else if(signal_array[i].signal_strength >= MIN_SIGNAL_STRENGTH && signal_array[i].signal_strength < 40) {
      printf("Brave Analysis: This network has weak signal strength. Streaming will likely be a frustrating experience.\n\n");
    } else {
      printf("Brave Analysis: The signal strength you entered for this network is incorrect.\n\n");
    }
  }

  for(int i=0; i<num_networks; i++) {
    free(signal_array[i].network_name);
  }
  free(signal_array); 
  
  return 0;
}