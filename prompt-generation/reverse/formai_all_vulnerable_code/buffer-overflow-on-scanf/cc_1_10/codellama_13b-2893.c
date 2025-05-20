//Code Llama-13B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: brave
/*
 * Airport Baggage Handling Simulation
 *
 * This program simulates the baggage handling process at an airport.
 * It accepts user input for the number of passengers and their baggage,
 * and outputs the time it takes for each passenger to complete the process.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 100
#define MAX_BAGGAGE 5
#define TOTAL_HANDLING_TIME 60
#define BAGGAGE_HANDLING_TIME 10
#define PASSENGER_HANDLING_TIME 20

// Function prototypes
void welcome();
void get_input();
void handle_baggage(int, int);
void handle_passenger(int);
void output_results();

// Global variables
int num_passengers;
int baggage[MAX_PASSENGERS][MAX_BAGGAGE];
int handling_time[MAX_PASSENGERS];

int main() {
  // Welcome message
  welcome();

  // Get input from user
  get_input();

  // Handle baggage for each passenger
  for (int i = 0; i < num_passengers; i++) {
    handle_baggage(i, baggage[i][0]);
  }

  // Handle passengers
  for (int i = 0; i < num_passengers; i++) {
    handle_passenger(i);
  }

  // Output results
  output_results();

  return 0;
}

void welcome() {
  printf("Welcome to the airport baggage handling simulation!\n");
}

void get_input() {
  // Get number of passengers
  printf("Enter the number of passengers: ");
  scanf("%d", &num_passengers);

  // Get baggage information for each passenger
  for (int i = 0; i < num_passengers; i++) {
    printf("Enter the number of baggage items for passenger %d: ", i + 1);
    scanf("%d", &baggage[i][0]);

    // Get baggage information for each item
    for (int j = 1; j <= baggage[i][0]; j++) {
      printf("Enter the weight of baggage item %d for passenger %d: ", j, i + 1);
      scanf("%d", &baggage[i][j]);
    }
  }
}

void handle_baggage(int passenger, int num_baggage) {
  int total_baggage_time = 0;

  // Calculate total time for baggage handling
  for (int i = 0; i < num_baggage; i++) {
    total_baggage_time += BAGGAGE_HANDLING_TIME * baggage[passenger][i];
  }

  // Add baggage time to passenger's total handling time
  handling_time[passenger] += total_baggage_time;
}

void handle_passenger(int passenger) {
  handling_time[passenger] += PASSENGER_HANDLING_TIME;
}

void output_results() {
  printf("Passenger Handling Time:\n");

  for (int i = 0; i < num_passengers; i++) {
    printf("Passenger %d: %d seconds\n", i + 1, handling_time[i]);
  }
}