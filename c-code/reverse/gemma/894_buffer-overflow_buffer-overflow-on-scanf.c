#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char name[20];
  scanf("%s", name);

  if (strlen(name) > 19) {
    printf("Error: name too long.\n");
  } else {
    printf("Hello, %s. You are in a haunted house.\n", name);

    // Branching narrative
    if (name[0] == 'a' || name[0] == 'A') {
      printf("You hear a scream from the upstairs. You cautiously explore the hallway...\n");
    } else if (name[0] == 'e' || name[0] == 'E') {
      printf("You smell burning incense. You find a hidden secret room...\n");
    } else {
      printf("You hear footsteps behind you. You turn around, but see nothing...\n");
    }
  }

  return 0;
}
