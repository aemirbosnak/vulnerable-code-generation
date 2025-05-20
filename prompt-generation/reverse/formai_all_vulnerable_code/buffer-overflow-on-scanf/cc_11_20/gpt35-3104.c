//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Romeo and Juliet
/* Intrusion Detection System - Romeo and Juliet style */

#include <stdio.h>
#include <stdbool.h>

/* Define the possible intruders */
typedef enum {
  MONTAGUES = 0,
  CAPULETS
} intruders_t;

/* Define the possible states of the intrusion detection system */
typedef enum {
  IDLE = 0,
  TRIGGERED 
} ids_state_t;

int main() {

  /* Initialize the variables */
  intruders_t current_intruder = MONTAGUES;
  ids_state_t current_state = IDLE;
  bool is_alarm_sounding = false;

  /* Main program loop */
  while (true) {
    switch (current_state) {
      case IDLE:
        /* Check for intruders */
        if (current_intruder == MONTAGUES) {
          current_state = TRIGGERED;
          printf("Montagues detected! Raising alarm...\n");
          is_alarm_sounding = true;
        } else if (current_intruder == CAPULETS) {
          current_state = TRIGGERED;
          printf("Capulets detected! Raising alarm...\n");
          is_alarm_sounding = true;
        }
        break;
      case TRIGGERED:
        /* Check if the alarm has been reset */
        if (current_intruder == MONTAGUES || current_intruder == CAPULETS) {
          /* Do nothing - we are still detecting */
        } else {
          /* Reset the alarm */
          current_state = IDLE;
          printf("Alarm has been reset.\n");
          is_alarm_sounding = false;
        }
        break;
    }

    /* Prompt for user input */
    printf("Which house are you from? (Montagues or Capulets): ");
    char house[10];
    scanf("%s", house);

    /* Update the variable based on user input */
    if (strcmp(house, "Montagues") == 0) {
      current_intruder = MONTAGUES;
    } else if (strcmp(house, "Capulets") == 0) {
      current_intruder = CAPULETS;
    } else {
      printf("Invalid input. Try again.\n");
    }

    /* Check if the alarm is sounding */
    if (is_alarm_sounding) {
      printf("ALARM!\n");
    }
  }

  return 0;
}