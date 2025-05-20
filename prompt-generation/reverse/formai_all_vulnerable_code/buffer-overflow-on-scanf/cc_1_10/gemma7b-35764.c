//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DETECTIVES 10

typedef struct detective {
  char name[20];
  int experience;
  int is_active;
  int cases_solved;
} detective;

int main() {

  // Create an array of detectives
  detective detectives[MAX_DETECTIVES] = {
    {"Detective Bob", 5, 1, 10},
    {"Detective Sue", 3, 0, 5},
    {"Detective Harry", 2, 1, 2},
    {"Detective Jane", 4, 0, 7},
    {"Detective Lisa", 1, 0, 1},
    {"Detective Mark", 3, 1, 4},
    {"Detective Mary", 2, 0, 3},
    {"Detective Tom", 4, 0, 6},
    {"Detective Alice", 1, 0, 0},
    {"Detective Phil", 3, 0, 2}
  };

  // Simulate an intrusion
  printf("Enter the name of the intruder:");
  char intruder_name[20];
  scanf("%s", intruder_name);

  // Check if the intruder's name is on the blacklist
  int is_intruder_detected = 0;
  for (int i = 0; i < MAX_DETECTIVES; i++) {
    if (strcmp(intruder_name, detectives[i].name) == 0) {
      is_intruder_detected = 1;
      break;
    }
  }

  // If the intruder is detected, activate the detectives
  if (is_intruder_detected) {
    for (int i = 0; i < MAX_DETECTIVES; i++) {
      if (detectives[i].is_active) {
        printf("Detective %s has been activated!\n", detectives[i].name);
      }
    }
  }

  // Print a message to the user
  if (is_intruder_detected) {
    printf("The intruder has been detected and is being chased away!\n");
  } else {
    printf("The intruder's name is not on the blacklist.\n");
  }

  return 0;
}