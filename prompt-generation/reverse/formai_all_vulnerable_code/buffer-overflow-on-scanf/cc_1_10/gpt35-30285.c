//FormAI DATASET v1.0 Category: Recursive ; Style: futuristic
#include <stdio.h>

void teleport(int x, int y);

int main() {
  printf("Welcome to the teleport hub!\n");
  printf("Enter the X coordinate of your destination: ");
  int x_dest;
  scanf("%d", &x_dest);

  printf("Enter the Y coordinate of your destination: ");
  int y_dest;
  scanf("%d", &y_dest);

  printf("You will now be teleported to (%d, %d)\n", x_dest, y_dest);

  teleport(x_dest, y_dest);

  printf("You have arrived at your destination. Thank you for using the teleport hub!\n");

  return 0;
}

void teleport(int x, int y) {
  if (x == 0 && y == 0) {
    printf("You are already at the teleport hub.\n");
    return;
  }

  printf("Teleporting to (%d, %d)...\n", x, y);

  if (x < 0 || y < 0) {
    printf("Invalid destination, teleportation failed.\n");
    return;
  }

  if (x > 100 || y > 100) {
    printf("Teleportation destination out of range, teleportation failed.\n");
    return;
  }

  teleport(x-1, y-1);
}

/*
Sample Output:
Welcome to the teleport hub!
Enter the X coordinate of your destination: 5
Enter the Y coordinate of your destination: 7
You will now be teleported to (5, 7)
Teleporting to (4, 6)...
Teleporting to (3, 5)...
Teleporting to (2, 4)...
Teleporting to (1, 3)...
Teleporting to (0, 2)...
Teleporting to (0, 1)...
Teleporting to (0, 0)...
You are already at the teleport hub.
You have arrived at your destination. Thank you for using the teleport hub!
*/