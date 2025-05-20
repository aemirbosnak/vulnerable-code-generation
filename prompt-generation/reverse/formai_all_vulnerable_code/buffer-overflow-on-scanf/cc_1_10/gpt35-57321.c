//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 20

struct wifi_network {
  char ssid[MAX_SSID_LENGTH];
  int signal_strength;
};

int main() {
  struct wifi_network networks[MAX_NETWORKS];
  int network_count = 0;

  while (true) {
    char prompt[] = "Enter SSID (or 'exit' to stop): ";
    printf("%s", prompt);

    char input[MAX_SSID_LENGTH];
    scanf("%s", input);

    if (strcmp(input, "exit") == 0) {
      break;
    }

    char signal_prompt[] = "Enter signal strength (between 0 and 100): ";
    printf("%s", signal_prompt);

    int signal_strength;
    scanf("%d", &signal_strength);

    if (network_count >= MAX_NETWORKS) {
      printf("Cannot add more networks, maximum number reached.\n");
      continue;
    }

    struct wifi_network network;
    strcpy(network.ssid, input);
    network.signal_strength = signal_strength;

    networks[network_count] = network;
    network_count++;
  }

  printf("\n");

  printf("NETWORKS:\n");
  for (int i = 0; i < network_count; i++) {
    struct wifi_network network = networks[i];
    printf("[%d] %s: %d\n", i + 1, network.ssid, network.signal_strength);
  }

  return 0;
}