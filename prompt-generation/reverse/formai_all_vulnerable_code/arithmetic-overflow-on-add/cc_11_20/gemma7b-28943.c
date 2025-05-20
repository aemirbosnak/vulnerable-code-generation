//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main()
{
  int i, n, choice, found = 0;
  char name[20], phone[20];
  struct phoneBook
  {
    char name[20];
    char phone[20];
  } phoneBook[100];

  printf("Welcome to the Enchanted Phone Book!\n");
  printf("Please select an option:\n");
  printf("1. Add a new entry.\n");
  printf("2. Search for a name.\n");
  printf("3. Update an entry.\n");
  printf("4. Delete an entry.\n");
  scanf("%d", &choice);

  switch (choice)
  {
    case 1:
      printf("Enter the name:");
      scanf("%s", phoneBook[n].name);
      printf("Enter the phone number:");
      scanf("%s", phoneBook[n].phone);
      n++;
      break;

    case 2:
      printf("Enter the name:");
      scanf("%s", name);
      for (i = 0; i < n; i++)
      {
        if (strcmp(name, phoneBook[i].name) == 0)
        {
          printf("Phone number: %s\n", phoneBook[i].phone);
          found = 1;
        }
      }
      if (!found)
      {
        printf("Name not found.\n");
      }
      break;

    case 3:
      printf("Enter the name:");
      scanf("%s", name);
      for (i = 0; i < n; i++)
      {
        if (strcmp(name, phoneBook[i].name) == 0)
        {
          printf("Enter the new phone number:");
          scanf("%s", phoneBook[i].phone);
          found = 1;
        }
      }
      if (!found)
      {
        printf("Name not found.\n");
      }
      break;

    case 4:
      printf("Enter the name:");
      scanf("%s", name);
      for (i = 0; i < n; i++)
      {
        if (strcmp(name, phoneBook[i].name) == 0)
        {
          found = 1;
          printf("Entry deleted.\n");
          phoneBook[i].name[0] = '\0';
          phoneBook[i].phone[0] = '\0';
        }
      }
      if (!found)
      {
        printf("Name not found.\n");
      }
      break;

    default:
      printf("Invalid choice.\n");
  }

  return 0;
}