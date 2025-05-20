//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int i, j, k, r, t, f = 0;
  char ch, p, n, m;

  // Haunted House Setup
  FILE *fp = fopen("haunted_house.txt", "w");
  fprintf(fp, "You are standing in the Haunted House.\n");
  fclose(fp);

  // Player's Entry
  printf("Enter your name: ");
  scanf("%s", &n);

  // Haunted House Exploration
  for (i = 0; i < 5; i++)
  {
    printf("Enter a direction (N/S/E/W): ");
    scanf("%c", &ch);

    switch (ch)
    {
      case 'N':
        printf("You moved north.\n");
        break;
      case 'S':
        printf("You moved south.\n");
        break;
      case 'E':
        printf("You moved east.\n");
        break;
      case 'W':
        printf("You moved west.\n");
        break;
      default:
        printf("Invalid direction.\n");
    }

    // Random Events
    r = rand() % 3;
    switch (r)
    {
      case 0:
        printf("Suddenly, a door slams shut.\n");
        break;
      case 1:
        printf("A cold wind blows through the halls.\n");
        break;
      case 2:
        printf("You hear footsteps approaching.\n");
        break;
    }

    // Ghost Encounter
    if (f == 0)
    {
      printf("You encounter a ghostly figure.\n");
      f = 1;
    }
  }

  // Conclusion
  printf("You have escaped the Haunted House!\n");

  return 0;
}