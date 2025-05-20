//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void goto_next_room(int room_num) {
  switch (room_num) {
    case 1:
      printf("You have entered Room 1. It's a cozy room with a fireplace and a comfortable bed.\n");
      break;
    case 2:
      printf("You have entered Room 2. It's a spacious room with a lot of natural light. There's a table and chairs in the center.\n");
      break;
    case 3:
      printf("You have entered Room 3. It's a dark and mysterious room. There's a single bed in the center.\n");
      break;
  }
  system("pause");
  return;
}

int main() {
  int current_room = 1;

  printf("Welcome to the Mysterious Mansion.\n");

  while (current_room != 3) {
    printf("You are in Room %d. What do you want to do? (go north, go south, go east, go west, examine)\n", current_room);
    char input[20];
    scanf("%s", input);

    if (strcmp(input, "go north") == 0) {
      current_room = 2;
      goto_next_room(current_room);
    } else if (strcmp(input, "go south") == 0) {
      current_room = 1;
      goto_next_room(current_room);
    } else if (strcmp(input, "go east") == 0) {
      current_room = 3;
      goto_next_room(current_room);
    } else if (strcmp(input, "go west") == 0) {
      current_room = 1;
      goto_next_room(current_room);
    } else if (strcmp(input, "examine") == 0) {
      printf("You examine your surroundings and find nothing of interest.\n");
    } else {
      printf("Invalid input. Please try again.\n");
    }
  }

  printf("You have reached the end of the mansion. Congratulations!\n");

  return 0;
}