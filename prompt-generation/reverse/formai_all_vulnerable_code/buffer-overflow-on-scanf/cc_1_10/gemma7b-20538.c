//Gemma-7B DATASET v1.0 Category: System administration ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void paint_system_landscape()
{
  system("clear");
  printf("           /\n"
         "          ||||/\n"
         "           \__)\n"
         "                  /\n"
         "                 ||/\n"
         "                 \__)\n");
}

void draw_menu()
{
  paint_system_landscape();
  printf("#################################\n"
         "## System Admin Menu\n"
         "#################################\n"
         "1. Users\n"
         "2. Files\n"
         "3. Processes\n"
         "4. Network\n"
         "5. Exit\n"
         "Please select an option:");
}

int main()
{
  draw_menu();
  int option;
  scanf("%d", &option);

  switch (option)
  {
    case 1:
      printf("You selected Users.\n");
      break;
    case 2:
      printf("You selected Files.\n");
      break;
    case 3:
      printf("You selected Processes.\n");
      break;
    case 4:
      printf("You selected Network.\n");
      break;
    case 5:
      printf("You selected Exit.\n");
      exit(0);
    default:
      printf("Invalid option.\n");
  }

  draw_menu();
  printf("Please select an option:");

  return 0;
}