#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_COMPONENT_LENGTH 20

int main() {
  char player_name[MAX_NAME_LENGTH];
  char component_type[MAX_COMPONENT_LENGTH];

  printf("Enter your player name: ");
  scanf("%s", player_name);

  printf("Enter the component type: ");
  scanf("%s", component_type);

  // Handle potential buffer overflows
  if (strlen(player_name) > MAX_NAME_LENGTH - 1) {
    printf("Error: Player name too long.\n");
  } else if (strlen(component_type) > MAX_COMPONENT_LENGTH - 1) {
    printf("Error: Component type too long.\n");
  } else {
    printf("Hello, %s! You have chosen the component type: %s.\n", player_name, component_type);
  }

  return 0;
}
