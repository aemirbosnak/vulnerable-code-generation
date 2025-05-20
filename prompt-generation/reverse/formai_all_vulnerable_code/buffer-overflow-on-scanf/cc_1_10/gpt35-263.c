//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LENGTH 32
#define MIN_SIGNAL_STRENGTH -100
#define MAX_SIGNAL_STRENGTH 0

typedef struct {
  char ssid[MAX_SSID_LENGTH];
  int signal_strength;
} AccessPoint;

int main() {
  int num_ap = 0;
  AccessPoint *ap_list = NULL;
  
  printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
  printf("How many access points do you want to analyze? ");
  scanf("%d", &num_ap);
  
  ap_list = malloc(sizeof(AccessPoint) * num_ap);
  
  for (int i = 0; i < num_ap; i++) {
    printf("Enter the SSID and signal strength (in dBm) for access point #%d: ", i + 1);
    scanf("%s %d", ap_list[i].ssid, &ap_list[i].signal_strength);
  }

  printf("***** SUMMARY REPORT *****\n");

  int strongest = MIN_SIGNAL_STRENGTH;
  int weakest = MAX_SIGNAL_STRENGTH;
  float signal_sum = 0.0;

  for (int i = 0; i < num_ap; i++) {
    if (ap_list[i].signal_strength > strongest) {
      strongest = ap_list[i].signal_strength;
    }

    if (ap_list[i].signal_strength < weakest) {
      weakest = ap_list[i].signal_strength;
    }

    signal_sum += ap_list[i].signal_strength;
  }

  printf("The average signal strength is %.2f dBm.\n", signal_sum / num_ap);
  printf("The strongest signal is %d dBm from SSID: %s\n", strongest, ap_list[num_ap - 1].ssid);
  printf("The weakest signal is %d dBm from SSID: %s\n", weakest, ap_list[0].ssid);

  printf("***** SIGNAL STRENGTH GRAPH *****\n");

  int signal_range = strongest - weakest + 1;
  const int bar_length = 20;

  for (int i = strongest; i >= weakest; i--) {
    printf("%3d |", i);

    for (int j = 0; j < num_ap; j++) {
      if (ap_list[j].signal_strength >= i) {
        printf("X");
      } else {
        printf(" ");
      }
    }

    printf("\n");
  }

  printf("    ");
  
  for (int i = 0; i < num_ap; i++) {
    printf("-");
  }

  printf("\n    ");

  for (int i = 0; i < num_ap; i++) {
    printf("%s", ap_list[i].ssid);
  }

  printf("\n");
  
  free(ap_list);
  
  return 0;
}