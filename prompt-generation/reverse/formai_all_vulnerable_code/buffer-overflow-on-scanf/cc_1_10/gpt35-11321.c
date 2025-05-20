//FormAI DATASET v1.0 Category: System administration ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("WARNING: THIS PROGRAM WILL MAKE CHANGES TO YOUR SYSTEM.\n"
         "ARE YOU SURE YOU WANT TO PROCEED? (Y/N)\n");

  char userInput;
  scanf("%c", &userInput);
  if (userInput != 'Y' && userInput != 'y')
    return 0;

  printf("We're going to start making some changes to your system now. Please sit back and enjoy the ride.\n");

  // Set system date and time to a random value
  srand(time(0));
  int randomYear = rand() % 100 + 2020;
  int randomMonth = rand() % 12 + 1;
  int randomDay = rand() % 28 + 1;
  int randomHour = rand() % 24;
  int randomMinute = rand() % 60;
  int randomSecond = rand() % 60;
  char setDateCommand[100];
  sprintf(setDateCommand, "sudo date %02d%02d%02d%02d%04d.%02d", randomMonth, randomDay, randomHour, randomMinute, randomYear, randomSecond);
  system(setDateCommand);
  printf("New system date and time set to: %02d/%02d/%04d %02d:%02d:%02d\n", randomMonth, randomDay, randomYear, randomHour, randomMinute, randomSecond);

  // Set the system hostname to a random value
  char randomHostname[7] = "";
  for (int i = 0; i < 6; i++) {
    randomHostname[i] = rand() % 26 + 97;
  }
  char setHostnameCommand[100];
  sprintf(setHostnameCommand, "sudo hostname %s", randomHostname);
  system(setHostnameCommand);
  printf("New system hostname set to: %s\n", randomHostname);

  // Create a new user and grant them sudo privileges
  char newUsername[7] = "";
  for (int i = 0; i < 6; i++) {
    newUsername[i] = rand() % 26 + 97;
  }
  char createUserCommand[100];
  sprintf(createUserCommand, "sudo useradd -m -p $(openssl passwd -1 'password') -s /bin/bash %s && sudo usermod -aG sudo %s", newUsername, newUsername);
  system(createUserCommand);
  printf("New user created with username: %s and password: password\n", newUsername);

  // Add an entry to /etc/hosts directing all traffic to 127.0.0.1
  char addHostCommand[100];
  sprintf(addHostCommand, "sudo sh -c 'echo \"127.0.0.1\t\talltrafficredirect.com\" >> /etc/hosts'");
  system(addHostCommand);
  printf("Added entry to /etc/hosts to redirect all traffic to 127.0.0.1 for domain: alltrafficredirect.com\n");

  printf("\nCongratulations, you've successfully made some shocking changes to your system!\n");

  return 0;
}