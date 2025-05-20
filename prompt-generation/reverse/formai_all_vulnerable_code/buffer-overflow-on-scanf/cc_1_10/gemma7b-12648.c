//Gemma-7B DATASET v1.0 Category: System administration ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void morph_admin(int argc, char *argv[])
{
  int choice, sys_admin_option;

  system("clear");

  printf("----------------------------------------\n");
  printf("Welcome to the Morph System Administration Menu\n");
  printf("----------------------------------------\n");

  printf("1. View System Statistics\n");
  printf("2. Modify System Configuration\n");
  printf("3. Create New User Account\n");
  printf("4. Delete User Account\n");
  printf("5. View System Logs\n");
  printf("Enter your choice: ");

  scanf("%d", &choice);

  switch (choice)
  {
    case 1:
      system("top");
      break;
    case 2:
      system("nano /etc/passwd");
      break;
    case 3:
      system("useradd");
      break;
    case 4:
      system("userdel");
      break;
    case 5:
      system("tail -f /var/log/messages");
      break;
    default:
      printf("Invalid choice.\n");
  }

  system("clear");

  printf("Thank you for using the Morph System Administration Menu.\n");

  return;
}

int main()
{
  morph_admin(0, NULL);

  return 0;
}