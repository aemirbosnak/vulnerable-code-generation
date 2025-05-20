#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int choice, i, data[10];

  printf("Menu:\n");
  printf("1. Add item\n");
  printf("2. Remove item\n");
  printf("3. List items\n");

  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter item name: ");
      char item[20];
      scanf("%s", item);
      data[i] = item;
      break;
    case 2:
      printf("Enter item name: ");
      scanf("%s", item);
      for (i = 0; item[i] != '\0'; i++) {
        if (strcmp(item, data[i]) == 0) {
          data[i] = NULL;
          break;
        }
      }
      break;
    case 3:
      for (i = 0; data[i] != NULL; i++) {
        printf("%s\n", data[i]);
      }
      break;
  }

  return 0;
}
