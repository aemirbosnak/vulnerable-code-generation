//Code Llama-13B DATASET v1.0 Category: Robot movement control ; Style: Sherlock Holmes
#include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>

    int main() {
      // Initialize variables
      int x = 0, y = 0;
      char direction = 'N';

      // Main loop
      while (1) {
        // Read user input
        char input[100];
        scanf("%s", input);

        // Parse user input
        if (strcmp(input, "left") == 0) {
          direction = 'W';
        } else if (strcmp(input, "right") == 0) {
          direction = 'E';
        } else if (strcmp(input, "up") == 0) {
          y++;
        } else if (strcmp(input, "down") == 0) {
          y--;
        } else if (strcmp(input, "forward") == 0) {
          if (direction == 'N') {
            y++;
          } else if (direction == 'S') {
            y--;
          } else if (direction == 'E') {
            x++;
          } else if (direction == 'W') {
            x--;
          }
        } else if (strcmp(input, "backward") == 0) {
          if (direction == 'N') {
            y--;
          } else if (direction == 'S') {
            y++;
          } else if (direction == 'E') {
            x--;
          } else if (direction == 'W') {
            x++;
          }
        } else if (strcmp(input, "report") == 0) {
          printf("Robot is at (%d, %d) and facing %c\n", x, y, direction);
        } else if (strcmp(input, "quit") == 0) {
          break;
        }
      }

      // Exit program
      return 0;
    }