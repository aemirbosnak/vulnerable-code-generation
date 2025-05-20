//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: Alan Turing
// Turing's Dance of the C Periodic Table Quiz

#include <stdio.h>
#include <stdlib.h>

void dance(int group, int element)
{
  switch (group)
  {
    case 1:
      printf("The alkali metals, group %d, are characterized by their low ionization energy and high chemical activity.\n", group);
      break;
    case 2:
      printf("The alkaline earth metals, group %d, are characterized by their low ionization energy and moderate chemical activity.\n", group);
      break;
    case 3:
      printf("The transition metals, group %d, are characterized by their variable ionization energy and electrical conductivity.\n", group);
      break;
    case 4:
      printf("The inner transition metals, group %d, are characterized by their high ionization energy and low electrical conductivity.\n", group);
      break;
    default:
      printf("Invalid group number.\n");
  }

  switch (element)
  {
    case 1:
      printf("Hydrogen, element %d, is the most abundant element in the universe.\n", element);
      break;
    case 2:
      printf("Helium, element %d, is the second most abundant element in the universe.\n", element);
      break;
    case 3:
      printf("Lithium, element %d, is the lightest alkali metal.\n", element);
      break;
    case 4:
      printf("Sodium, element %d, is a soft metal that is highly reactive.\n", element);
      break;
    case 5:
      printf("Potassium, element %d, is a reactive alkali metal.\n", element);
      break;
    default:
      printf("Invalid element number.\n");
  }
}

int main()
{
  int group, element;

  printf("Enter the group number (1-4): ");
  scanf("%d", &group);

  printf("Enter the element number (1-5): ");
  scanf("%d", &element);

  dance(group, element);

  return 0;
}