#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char input[1024];
  int room = 1;

  switch (room) {
    case 1:
      printf("You are in a dark room. There is a door to the north and a chest to the east.\n");
      break;
    case 2:
      printf("You are in a bright room. There is a door to the south and a table with a sword on it.\n");
      break;
  }

  printf("Enter your command: ");
  scanf("%s", input);

  if (strcmp(input, "north") == 0) {
    room = 2;
  } else if (strcmp(input, "east") == 0) {
    // Implement chest interaction
  }

  switch (room) {
    case 1:
      printf("You are in a dark room. There is a door to the north and a chest to the east.\n");
      break;
    case 2:
      printf("You are in a bright room. There is a door to the south and a table with a sword on it.\n");
      break;
  }

  return 0;
}
