#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_COMPONENTS 10

typedef struct Component {
  char type;
  int value;
} Component;

int main() {
  int numPlayers = 2;
  Component components[MAX_COMPONENTS];
  int currentPlayer = 0;

  // Initialize components for each player
  for (int i = 0; i < numPlayers; i++) {
    components[i].type = '\0';
    components[i].value = 0;
  }

  // Game loop
  while (components[currentPlayer].type) {
    // Get user input for component type and value
    printf("Enter component type (R/C/V): ");
    scanf("%c", &components[currentPlayer].type);

    printf("Enter component value: ");
    scanf("%d", &components[currentPlayer].value);

    // Display circuit
    for (int i = 0; i < numPlayers; i++) {
      if (components[i].type) {
        printf("%c %d ", components[i].type, components[i].value);
      }
    }

    // Calculate total resistance and capacitance
    int totalResistance = 0;
    int totalCapacitance = 0;
    for (int i = 0; i < numPlayers; i++) {
      if (components[i].type == 'R') {
        totalResistance += components[i].value;
      } else if (components[i].type == 'C') {
        totalCapacitance += components[i].value;
      }
    }

    // Display results
    printf("\nTotal resistance: %d ohms", totalResistance);
    printf("\nTotal capacitance: %d farads", totalCapacitance);

    // Switch to next player
    currentPlayer = (currentPlayer + 1) % numPlayers;
  }

  return 0;
}
