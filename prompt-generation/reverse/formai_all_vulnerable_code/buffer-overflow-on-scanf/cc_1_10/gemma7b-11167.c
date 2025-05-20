//Gemma-7B DATASET v1.0 Category: System administration ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SYS_NAME "The Matrix"

void sys_admin(void)
{
  system("clear");
  printf("\n**Welcome to %s System Administration Interface!\n", SYS_NAME);
  printf("------------------------------------------------\n");
  printf("Please select an option:\n");
  printf("1. View System Status\n");
  printf("2. Modify System Settings\n");
  printf("3. Create New User Account\n");
  printf("4. Delete User Account\n");
  printf("5. View User Accounts\n");
  printf("Enter your selection: ");

  int selection = 0;
  scanf("%d", &selection);

  switch (selection)
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
      system("cat /etc/passwd");
      break;
    default:
      printf("Invalid selection.\n");
  }

  printf("\nThank you for using the %s System Administration Interface.\n", SYS_NAME);
  printf("------------------------------------------------\n");
  system("sleep 2");
  sys_admin();
}

int main()
{
  sys_admin();

  return 0;
}