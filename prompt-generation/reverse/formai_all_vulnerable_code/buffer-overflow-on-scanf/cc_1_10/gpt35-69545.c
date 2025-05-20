//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>

void hanoi(int n, char source, char destination, char auxiliary) {

  if (n == 0) {
    return;
  }
  
  hanoi(n-1, source, auxiliary, destination);
  printf("Move disk %d from %c to %c\n", n, source, destination);
  hanoi(n-1, auxiliary, destination, source);
}

int main() {
  int n = 4;
  char source = 'A';
  char destination = 'C';
  char auxiliary = 'B';
  
  printf("Welcome to the Shapeshifter's Tower of Hanoi!\n");
  printf("In this universe, the number of disks can change!\n");
  printf("How many disks (1-10) would you like to start with?\n");
  
  scanf("%d", &n);
  
  printf("Great choice! Here's the solution:\n");
  
  // Let the shapeshifting begin!
  if (n <= 0) {
    printf("Invalid number of disks\n");
    return 0;
  }
  else if (n == 1) {
    printf("Move disk 1 from %c to %c\n", source, destination);
    return 0;
  }
  else if (n == 2) {
    printf("Move disk 1 from %c to %c\n", source, auxiliary);
    printf("Move disk 2 from %c to %c\n", source, destination);
    printf("Move disk 1 from %c to %c\n", auxiliary, destination);
    return 0;
  }
  else {
    hanoi(n, source, destination, auxiliary);
  }
  
  printf("Hope you enjoyed this shapeshifting experience!\n");
  
  return 0;
}