//Code Llama-13B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_BAGGAGE 100
#define MAX_PASSENGERS 100

typedef struct {
  char* name;
  char* id;
  int checked_baggage;
  int carry_on_baggage;
} passenger;

typedef struct {
  passenger* passengers;
  int num_passengers;
  int checked_baggage;
  int carry_on_baggage;
} flight;

flight* generate_flight(int num_passengers, int checked_baggage, int carry_on_baggage) {
  flight* new_flight = malloc(sizeof(flight));
  new_flight->passengers = malloc(num_passengers * sizeof(passenger));
  new_flight->num_passengers = num_passengers;
  new_flight->checked_baggage = checked_baggage;
  new_flight->carry_on_baggage = carry_on_baggage;
  return new_flight;
}

void add_passenger(flight* flight, char* name, char* id, int checked_baggage, int carry_on_baggage) {
  passenger* new_passenger = malloc(sizeof(passenger));
  new_passenger->name = strdup(name);
  new_passenger->id = strdup(id);
  new_passenger->checked_baggage = checked_baggage;
  new_passenger->carry_on_baggage = carry_on_baggage;
  flight->passengers[flight->num_passengers++] = *new_passenger;
}

void handle_baggage(flight* flight, int baggage_type) {
  for (int i = 0; i < flight->num_passengers; i++) {
    passenger* passenger = &flight->passengers[i];
    if (baggage_type == 1) {
      passenger->checked_baggage++;
    } else {
      passenger->carry_on_baggage++;
    }
  }
}

void simulate_baggage_handling(flight* flight, int baggage_type) {
  handle_baggage(flight, baggage_type);
}

int main() {
  srand(time(NULL));
  flight* flight = generate_flight(MAX_PASSENGERS, MAX_BAGGAGE, MAX_BAGGAGE);
  add_passenger(flight, "John Doe", "ABC123", 2, 1);
  add_passenger(flight, "Jane Doe", "DEF456", 1, 2);
  simulate_baggage_handling(flight, 1);
  simulate_baggage_handling(flight, 0);
  for (int i = 0; i < flight->num_passengers; i++) {
    passenger* passenger = &flight->passengers[i];
    printf("Passenger %s (%s): checked baggage %d, carry-on baggage %d\n",
      passenger->name, passenger->id, passenger->checked_baggage, passenger->carry_on_baggage);
  }
  free(flight->passengers);
  free(flight);
  return 0;
}