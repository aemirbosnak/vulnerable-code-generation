//Code Llama-13B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_PASSENGERS 100

typedef struct {
  char name[50];
  int age;
  char destination[50];
} passenger_t;

typedef struct {
  int id;
  char type;
  int weight;
  char owner[50];
} baggage_t;

void simulate_baggage_handling(passenger_t passengers[], baggage_t baggage[], int num_passengers, int num_baggage) {
  int i, j;
  srand(time(NULL));
  for (i = 0; i < num_passengers; i++) {
    printf("Passenger %d: %s (%d years old)\n", i, passengers[i].name, passengers[i].age);
    for (j = 0; j < num_baggage; j++) {
      if (strcmp(passengers[i].name, baggage[j].owner) == 0) {
        printf("  Baggage %d: %c (%d pounds)\n", j, baggage[j].type, baggage[j].weight);
      }
    }
  }
}

int main() {
  passenger_t passengers[MAX_PASSENGERS];
  baggage_t baggage[MAX_BAGGAGE];
  int num_passengers, num_baggage;
  printf("Enter the number of passengers: ");
  scanf("%d", &num_passengers);
  printf("Enter the number of baggage: ");
  scanf("%d", &num_baggage);
  for (int i = 0; i < num_passengers; i++) {
    printf("Enter passenger %d's name: ", i);
    scanf("%s", passengers[i].name);
    printf("Enter passenger %d's age: ", i);
    scanf("%d", &passengers[i].age);
    printf("Enter passenger %d's destination: ", i);
    scanf("%s", passengers[i].destination);
  }
  for (int i = 0; i < num_baggage; i++) {
    printf("Enter baggage %d's id: ", i);
    scanf("%d", &baggage[i].id);
    printf("Enter baggage %d's type (L or S): ", i);
    scanf(" %c", &baggage[i].type);
    printf("Enter baggage %d's weight: ", i);
    scanf("%d", &baggage[i].weight);
    printf("Enter baggage %d's owner: ", i);
    scanf("%s", baggage[i].owner);
  }
  simulate_baggage_handling(passengers, baggage, num_passengers, num_baggage);
  return 0;
}