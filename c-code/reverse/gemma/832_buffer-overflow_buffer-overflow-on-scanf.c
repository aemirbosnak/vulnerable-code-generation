#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_COMPONENTS 10

typedef struct Component {
  char name[20];
  int value;
} Component;

Component components[MAX_COMPONENTS];

int main() {
  int numComponents = 0;
  int playerTurn = 0;

  while (1) {
    // Display menu options
    printf("1. Add Component\n");
    printf("2. View Components\n");
    printf("3. Exit\n");

    // Get user input
    int choice = 0;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // Add component
        components[numComponents].name[0] = '\0';
        printf("Enter component name: ");
        scanf("%s", components[numComponents].name);

        printf("Enter component value: ");
        scanf("%d", &components[numComponents].value);
        numComponents++;
        break;
      case 2:
        // View components
        for (int i = 0; i < numComponents; i++) {
          printf("Name: %s\n", components[i].name);
          printf("Value: %d\n", components[i].value);
        }
        break;
      case 3:
        // Exit
        printf("Thank you for playing!\n");
        return 0;
    }

    // Switch to next player turn
    playerTurn = (playerTurn + 1) % 2;
  }
}
