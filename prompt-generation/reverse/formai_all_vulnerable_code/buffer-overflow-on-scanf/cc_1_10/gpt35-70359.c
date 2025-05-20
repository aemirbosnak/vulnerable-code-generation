//FormAI DATASET v1.0 Category: Firewall ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the C Firewall app! Let's start by blocking some pesky IP addresses.\n");

  char blockedList[5][20] = {"127.0.0.1", "192.168.1.1", "10.0.0.1", "172.16.0.1", "1337.1337.1337.1337"};
  int numBlocked = 5;

  printf("The following IP addresses are currently blocked: \n");

  for(int i = 0; i < numBlocked; i++) {
    printf("%s \n", blockedList[i]);
  }

  printf("Enter a new IP address to block: ");
  char newIP[20];
  scanf("%s", newIP);

  int alreadyBlocked = 0;

  for(int j = 0; j < numBlocked; j++) {
    if(strcmp(blockedList[j], newIP) == 0) {
      alreadyBlocked = 1;
      printf("Oops! That IP address is already blocked. \n");
      break;
    }
  }

  if(!alreadyBlocked) {
    printf("%s has been blocked. \n", newIP);
    strcpy(blockedList[numBlocked], newIP);
    numBlocked++;
  }

  printf("Would you like to remove an IP from the blocked list?\n");
  printf("Enter 'Y' for yes or 'N' for no: ");
  char choice;
  scanf(" %c", &choice);

  if(choice == 'Y') {
    printf("Enter an IP address to unblock: ");
    char removeIP[20];
    scanf("%s", removeIP);

    int indexToRemove = -1;

    for(int k = 0; k < numBlocked; k++) {
      if(strcmp(blockedList[k], removeIP) == 0) {
        indexToRemove = k;
        break;
      }
    }

    if(indexToRemove != -1) {
      printf("%s has been unblocked. \n", removeIP);
      for(int l = indexToRemove; l < numBlocked - 1; l++) {
        strcpy(blockedList[l], blockedList[l + 1]);
      }
      numBlocked--;
    } else {
      printf("That IP address is not currently blocked. \n");
    }
  } else {
    printf("No problem, we'll keep the current blocked list. \n");
  }

  printf("Thanks for using the C Firewall app! Exiting now. \n");
  return 0;
}