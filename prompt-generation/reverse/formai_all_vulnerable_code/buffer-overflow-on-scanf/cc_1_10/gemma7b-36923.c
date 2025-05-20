//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw_phone_book(void);

int main(void)
{
  draw_phone_book();

  return 0;
}

void draw_phone_book(void)
{
  system("clear");

  // Draw a big phone book cover
  printf("           /\n"
         "          ||||_\n"
         "          \__)_\n"
         "--------------------\n");

  // Print the phone book entries
  printf("Mr. A. Abernathy: 555-123-4567\n"
         "Ms. B. Baker: 555-234-5678\n"
         "Mr. C. Carter: 555-345-6789\n"
         "Ms. D. Davis: 555-456-7890\n");

  // Draw a border around the phone book
  printf("--------------------\n"
         "           /\n"
         "          ||||_\n"
         "--------------------\n");

  // Prompt the user to enter a name
  printf("Enter a name: ");

  // Get the user's input
  char name[20];
  scanf("%s", name);

  // Search for the user's name in the phone book
  int found = 0;
  for (int i = 0; i < 4; i++)
  {
    if (strcmp(name, "Mr. A. Abernathy") == 0 ||
        strcmp(name, "Ms. B. Baker") == 0 ||
        strcmp(name, "Mr. C. Carter") == 0 ||
        strcmp(name, "Ms. D. Davis") == 0)
    {
      found = 1;
      printf("Phone number: %d-%d-%d\n",
             555 + i, 123 + i, 456 + i);
    }
  }

  // If the user's name was not found, print an error message
  if (!found)
  {
    printf("Name not found.\n");
  }
}