#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char choice[20];

  printf("Menu:\n");
  printf("1. Turn on lights\n");
  printf("2. Turn off lights\n");
  printf("3. Change color\n");

  printf("Enter your choice: ");
  scanf("%s", choice);

  if (strcmp(choice, "1") == 0) {
    printf("Lights are on.\n");
  } else if (strcmp(choice, "2") == 0) {
    printf("Lights are off.\n");
  } else if (strcmp(choice, "3") == 0) {
    printf("Enter new color: ");
    scanf("%s", choice);
    printf("Lights are changed to %s.\n", choice);
  } else {
    printf("Invalid choice.\n");
  }

  return 0;
}
