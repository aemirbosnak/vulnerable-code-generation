//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void main()
{
  int choice, x, y, map[5][5] = {{0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0}};

  system("clear");
  printf("You are in a labyrinth. Please choose a direction:\n");
  printf("1. North\n");
  printf("2. South\n");
  printf("3. East\n");
  printf("4. West\n");

  scanf("%d", &choice);

  switch (choice)
  {
    case 1:
      y = map[x][y - 1] == 1 ? 1 : 0;
      break;
    case 2:
      y = map[x][y + 1] == 1 ? 1 : 0;
      break;
    case 3:
      x = map[x + 1][y] == 1 ? 1 : 0;
      break;
    case 4:
      x = map[x - 1][y] == 1 ? 1 : 0;
      break;
    default:
      printf("Invalid choice.\n");
  }

  system("clear");
  printf("You have moved in the chosen direction. The map below shows your position:\n");

  for (x = 0; x < 5; x++)
  {
    for (y = 0; y < 5; y++)
    {
      printf("%d ", map[x][y]);
    }
    printf("\n");
  }

  printf("Please choose your next direction or press 'q' to quit.\n");

  scanf("%d", &choice);

  if (choice == 'q')
  {
    printf("Thank you for playing. Goodbye!\n");
  }
  else
  {
    main();
  }
}