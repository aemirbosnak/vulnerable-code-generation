//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int choice, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
  char ch;
  float f, g, h, i1, i2, i3, i4;
  double d;

  srand(time(0));
  printf("Enter your choice:\n");
  printf("1. Car\n2. Bike\n3. Truck\n4. Bus\n");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("You have chosen Car.\n");
      printf("Enter the number of wheels:\n");
      scanf("%d", &n);
      printf("Enter the shape of the car:\n");
      scanf(" %c", &ch);
      printf("You have chosen %c shaped car with %d wheels.\n", ch, n);
      break;

    case 2:
      printf("You have chosen Bike.\n");
      printf("Enter the number of wheels:\n");
      scanf("%d", &n);
      printf("Enter the shape of the bike:\n");
      scanf(" %c", &ch);
      printf("You have chosen %c shaped bike with %d wheels.\n", ch, n);
      break;

    case 3:
      printf("You have chosen Truck.\n");
      printf("Enter the number of wheels:\n");
      scanf("%d", &n);
      printf("Enter the shape of the truck:\n");
      scanf(" %c", &ch);
      printf("You have chosen %c shaped truck with %d wheels.\n", ch, n);
      break;

    case 4:
      printf("You have chosen Bus.\n");
      printf("Enter the number of wheels:\n");
      scanf("%d", &n);
      printf("Enter the shape of the bus:\n");
      scanf(" %c", &ch);
      printf("You have chosen %c shaped bus with %d wheels.\n", ch, n);
      break;

    default:
      printf("Invalid choice.\n");
  }

  return 0;
}