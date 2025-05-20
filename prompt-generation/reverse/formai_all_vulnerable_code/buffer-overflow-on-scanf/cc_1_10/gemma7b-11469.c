//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void morph(int);

int main()
{
  int choice;
  int shape_num = 0;
  char character_name[20] = "";

  printf("Enter your character name: ");
  scanf("%s", character_name);

  printf("Welcome, %s. You are a polymorphic being with the ability to shift shapes.\n", character_name);

  while (1)
  {
    printf("What shape do you want to transform into? (1-5): ");
    scanf("%d", &choice);

    switch (choice)
    {
      case 1:
        shape_num = 1;
        morph(shape_num);
        break;
      case 2:
        shape_num = 2;
        morph(shape_num);
        break;
      case 3:
        shape_num = 3;
        morph(shape_num);
        break;
      case 4:
        shape_num = 4;
        morph(shape_num);
        break;
      case 5:
        shape_num = 5;
        morph(shape_num);
        break;
      default:
        printf("Invalid input. Please try again.\n");
    }

    printf("You have transformed into a %s.\n", shape_num);
  }

  return 0;
}

void morph(int shape_num)
{
  switch (shape_num)
  {
    case 1:
      printf("You are now a majestic lion.\n");
      break;
    case 2:
      printf("You are now a cunning fox.\n");
      break;
    case 3:
      printf("You are now a swift hawk.\n");
      break;
    case 4:
      printf("You are now a powerful tiger.\n");
      break;
    case 5:
      printf("You are now a wise owl.\n");
      break;
    default:
      printf("Invalid shape. Please try again.\n");
  }
}