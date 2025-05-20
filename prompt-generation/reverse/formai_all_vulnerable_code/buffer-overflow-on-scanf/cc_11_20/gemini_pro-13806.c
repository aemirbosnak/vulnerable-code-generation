//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Linus Torvalds
// Linus Torvalds style C Remote Control Vehicle Simulation

#define RIGHT 'r'
#define LEFT 'l'
#define FORWARD 'f'
#define BACK 'b'
#define QUIT 'q'

// Initialize the vehicle's position and orientation
int x = 0, y = 0, direction = 0;

// Main function
int main() {
  char command;

  // Main loop
  while (1) {
    // Get a command from the user
    printf("Enter a command (r/l/f/b/q): ");
    scanf(" %c", &command);

    // Execute the command
    switch (command) {
      case RIGHT:
        direction = (direction + 1) % 4;
        break;
      case LEFT:
        direction = (direction - 1) % 4;
        break;
      case FORWARD:
        switch (direction) {
          case 0:
            y++;
            break;
          case 1:
            x++;
            break;
          case 2:
            y--;
            break;
          case 3:
            x--;
            break;
        }
        break;
      case BACK:
        switch (direction) {
          case 0:
            y--;
            break;
          case 1:
            x--;
            break;
          case 2:
            y++;
            break;
          case 3:
            x++;
            break;
        }
        break;
      case QUIT:
        return 0;
    }

    // Print the vehicle's position and orientation
    printf("Vehicle position: (%d, %d)\n", x, y);
    switch (direction) {
      case 0:
        printf("Vehicle direction: North\n");
        break;
      case 1:
        printf("Vehicle direction: East\n");
        break;
      case 2:
        printf("Vehicle direction: South\n");
        break;
      case 3:
        printf("Vehicle direction: West\n");
        break;
    }
  }

  return 0;
}