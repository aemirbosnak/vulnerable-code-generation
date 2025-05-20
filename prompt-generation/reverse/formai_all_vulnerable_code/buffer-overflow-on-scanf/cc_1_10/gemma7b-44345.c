//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void main()
{
  char name[20];
  char number[20];
  int i = 0;

  printf("Enter the name of the person: ");
  scanf("%s", name);

  printf("Enter the phone number: ");
  scanf("%s", number);

  printf("Here is the phone number for %s: ", name);
  printf("%s\n", number);

  printf("Would you like to add another person to the phone book? (Y/N) ");
  char answer;
  scanf(" %c", &answer);

  if (answer == 'Y')
  {
    i = 0;
    while (name[i] != '\0')
    {
      i++;
    }
    name[i] = '\0';

    i = 0;
    while (number[i] != '\0')
    {
      i++;
    }
    number[i] = '\0';

    printf("Enter the name of the person: ");
    scanf("%s", name);

    printf("Enter the phone number: ");
    scanf("%s", number);

    printf("Here is the phone number for %s: ", name);
    printf("%s\n", number);
  }

  printf("Thank you for using the phone book.\n");
}