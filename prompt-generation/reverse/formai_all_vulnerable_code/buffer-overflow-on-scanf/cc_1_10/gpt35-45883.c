//FormAI DATASET v1.0 Category: Firewall ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char ip[20];
  int block = 0;
  printf("Welcome to the Firewall!\n\n");

  while (1) {
    printf("Enter an IP address to block (or type 'exit' to quit): ");
    scanf("%s", ip);
    if (strcmp(ip, "exit") == 0) break;

    printf("Blocking %s...\n", ip);
    block++;

    // write blocked IP address to file
    FILE *fp;
    fp = fopen("blocked_ips.txt", "a");
    fprintf(fp, "%s\n", ip);
    fclose(fp);

    // check if user wants to unblock an IP
    printf("Would you like to unblock an IP? (y/n) ");
    char answer[2];
    scanf("%s", answer);
    if (strcmp(answer, "y") == 0) {
      printf("Enter the IP address to unblock: ");
      char unblock_ip[20];
      scanf("%s", unblock_ip);

      // read blocked IPs from file
      FILE *blocked_ips;
      blocked_ips = fopen("blocked_ips.txt", "r");
      char line[20];
      int unblocked = 0;
      FILE *new_blocked;

      // write all blocked IPs except for the one to be unblocked to a new file
      new_blocked = fopen("new_blocked_ips.txt", "w");
      while (fgets(line, sizeof(line), blocked_ips) != NULL) {
        line[strcspn(line, "\r\n")] = 0;
        if (strcmp(line, unblock_ip) != 0) {
          fprintf(new_blocked, "%s\n", line);
        } else {
          unblocked = 1;
        }
      }
      fclose(blocked_ips);
      fclose(new_blocked);

      // replace old blocked_ips.txt with new_blocked_ips.txt if an IP was unblocked
      if (unblocked == 1) {
        remove("blocked_ips.txt");
        rename("new_blocked_ips.txt", "blocked_ips.txt");
        printf("%s has been unblocked.\n", unblock_ip);
      } else {
        printf("Could not find %s in blocked IPs.\n", unblock_ip);
      }
    }
  }

  // print out number of blocked IPs
  printf("\n%d IPs are currently blocked.\n", block);
  return 0;
}