#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char room = 'a';
  char input[1024];

  switch (room) {
    case 'a':
      printf("You are in the first room. There is a door to the north and south.\n");
      printf("Enter a command: ");
      fgets(input, 1024, stdin);
      sscanf(input, "go %s", &room);
      if (room == 'n') {
        room = 'b';
      } else if (room == 's') {
        room = 'c';
      } else {
        printf("Invalid command.\n");
      }
      break;
    case 'b':
      printf("You are in the second room. There is a door to the east and west.\n");
      printf("Enter a command: ");
      fgets(input, 1024, stdin);
      sscanf(input, "go %s", &room);
      if (room == 'e') {
        room = 'c';
      } else if (room == 'w') {
        room = 'a';
      } else {
        printf("Invalid command.\n");
      }
      break;
    case 'c':
      printf("You are in the third room. You have won!\n");
      break;
  }

  return 0;
}
