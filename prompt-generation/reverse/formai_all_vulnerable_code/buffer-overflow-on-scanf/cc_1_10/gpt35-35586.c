//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("Welcome to Grateful System Administration!\n");
  printf("This program will allow you to manage your computer and perform system tasks.\n\n");
  printf("Please select an option below:\n");
  printf("1. Check system information\n");
  printf("2. Change system settings\n");
  printf("3. Perform system maintenance\n");
  printf("4. Exit the program\n");

  int option;
  scanf("%d", &option);

  switch(option) {
    case 1:
      printf("\nHere are your system details:\n");
      system("uname -a");
      break;
    case 2:
      printf("\nWhich setting would you like to change?\n");
      printf("1. Change the hostname\n");
      printf("2. Change the IP address\n");
      printf("3. Change the timezone\n");

      int change;
      scanf("%d", &change);

      switch(change) {
        case 1:
          printf("\nEnter the new hostname: ");
          char hostname[20];
          scanf("%s", &hostname);
          char command[50] = "hostnamectl set-hostname ";
          strcat(command, hostname);
          system(command);
          printf("\nHostname set to %s\n", hostname);
          break;
        case 2:
          printf("\nEnter the new IP address: ");
          char ip[20];
          scanf("%s", &ip);
          char command2[50] = "ifconfig eth0 ";
          strcat(command2, ip);
          system(command2);
          printf("\nIP address set to %s\n", ip);
          break;
        case 3:
          printf("\nEnter the new timezone (e.g. America/New_York): ");
          char timezone[40];
          scanf("%s", &timezone);
          char command3[80] = "timedatectl set-timezone ";
          strcat(command3, timezone);
          system(command3);
          printf("\nTimezone set to %s\n", timezone);
          break;
        default:
          printf("\nInvalid option selected\n");
      }

      break;
    case 3:
      printf("\nPerforming system maintenance...\n");
      printf("Cleaning up disk space...\n");
      system("sudo apt-get clean");
      printf("Removing unused packages...\n");
      system("sudo apt-get autoremove -y");
      printf("\nMaintenance tasks completed\n");
      break;
    case 4:
      printf("\nExiting the program...\n");
      exit(0);
      break;
    default:
      printf("\nInvalid option selected\n");
  }

  printf("\nWould you like to perform another task? (Y/N)\n");
  char answer;
  scanf(" %c", &answer);

  if (answer == 'Y' || answer == 'y') {
    main();
  } else {
    printf("\nThank you for using Grateful System Administration!\n");
  }

  return 0;
}