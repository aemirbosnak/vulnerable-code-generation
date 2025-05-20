#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 2

typedef struct CircuitComponent {
  char type;
  int value;
} CircuitComponent;

int main() {
  int numPlayers = 0;
  CircuitComponent components[MAX_PLAYERS][10];
  int i, j, k, totalResistance = 0, totalCapacitance = 0;

  printf("Enter the number of players (up to %d): ", MAX_PLAYERS);
  scanf("%d", &numPlayers);

  for (i = 0; i < numPlayers; i++) {
    components[i][0].type = 'r';
    components[i][0].value = 0;

    for (j = 1; j < 10; j++) {
      components[i][j].type = '\0';
      components[i][j].value = 0;
    }
  }

  for (i = 0; i < numPlayers; i++) {
    printf("Enter the components for player %d (separated by commas): ", i + 1);
    scanf("%s", components[i][0].value);

    char componentType;
    printf("Enter the type of component (r/c): ");
    scanf(" %c", &componentType);

    components[i][0].type = componentType;
  }

  for (i = 0; i < numPlayers; i++) {
    switch (components[i][0].type) {
      case 'r':
        totalResistance += components[i][0].value;
        break;
      case 'c':
        totalCapacitance += components[i][0].value;
        break;
    }
  }

  printf("Total resistance: %d ohms\n", totalResistance);
  printf("Total capacitance: %d farads\n", totalCapacitance);

  return 0;
}
