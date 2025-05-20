//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int signal_strength = 0; // variable to store the signal strength
  int signal_type = 0; // variable to store the type of Wi-Fi signal
  int frequency = 0; // variable to store the frequency of the Wi-Fi signal

  printf("Enter the signal strength: ");
  scanf("%d", &signal_strength);

  // Determine the type of Wi-Fi signal based on signal strength
  if (signal_strength < -70) {
    signal_type = 1; // weak signal
  } else if (signal_strength > -50) {
    signal_type = 3; // strong signal
  } else {
    signal_type = 2; // moderate signal
  }

  printf("Enter the frequency of the Wi-Fi signal: ");
  scanf("%d", &frequency);

  // Determine the type of Wi-Fi signal based on frequency
  if (frequency < 2.4) {
    signal_type = signal_type + 4; // 2.4 GHz signal
  } else {
    signal_type = signal_type + 8; // 5.0 GHz signal
  }

  // Print the type of Wi-Fi signal
  if (signal_type == 1) {
    printf("Weak 2.4 GHz signal\n");
  } else if (signal_type == 2) {
    printf("Moderate 2.4 GHz signal\n");
  } else if (signal_type == 3) {
    printf("Strong 2.4 GHz signal\n");
  } else if (signal_type == 5) {
    printf("Weak 5.0 GHz signal\n");
  } else if (signal_type == 6) {
    printf("Moderate 5.0 GHz signal\n");
  } else if (signal_type == 7) {
    printf("Strong 5.0 GHz signal\n");
  } else {
    printf("Invalid signal type!\n");
  }

  return 0;
}