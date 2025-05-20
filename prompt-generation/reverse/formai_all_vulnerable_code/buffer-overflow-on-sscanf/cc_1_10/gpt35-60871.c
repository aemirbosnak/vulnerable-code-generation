//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 1024

void printTitle() {
  printf("\n\n");
  printf("                  _______    ___      ___    _______                \n");
  printf("       /\\        |   ____|  | \\ \\    / / |  |   ____|       /\\      \n");
  printf("      /  \\       |  |__     |  \\ \\  / /  |  |  |__         /  \\     \n");
  printf("     / /\\ \\      |   __|    |   \\ \\/ /   |  |   __|       / /\\ \\    \n");
  printf("    / /  \\ \\     |  |____   |    \\  /    |  |  |____     / /  \\ \\   \n");
  printf("   /_/    \\_\\    |_______|  |____\\/_\\    |__|_______|   /_/    \\_\\  \n");
  printf("                     ___     _____   ____    _____                     \n");
  printf("                    /   \\   / ____| |___ \\  | ____|                    \n");
  printf("                   / \\ /\\| |          __) | | |__                      \n");
  printf("                  / /_\\ \\ |         |__ <  |  __|                     \n");
  printf("                 / _____ \\|          ___) | | |____                    \n");
  printf("                /_/     \\_\\         |____/  |______|                   \n\n\n");
}

void printUsage(char* processName, int memSize, int percent) {
  printf("\033[H\033[J");
  printTitle();
  printf("                 **** C RAM Usage Monitor ****                 \n");
  printf("________________________________________________________________\n");
  printf("\n");
  printf(" Process Name : %s\n", processName);
  printf(" Memory Used  : %d KB\n", memSize);
  printf(" Memory Load  : %d%%\n", percent);
}

int main() {
  char command[MAX_SIZE];
  char processName[MAX_SIZE];
  char memSize[MAX_SIZE];
  char c;
  int percent;

  printTitle();

  while (1) {
    printf(" Enter the process name to monitor (q to quit): ");
    fgets(command, MAX_SIZE, stdin);

    if (strcmp(command, "q\n") == 0 || strcmp(command, "Q\n") == 0) {
      printf("\n      Goodbye!\n");
      break;
    }

    // Remove trailing newline character
    int len = strlen(command);
    if (len > 0 && command[len-1] == '\n') {
      command[len-1] = '\0';
    }

    printf("\n\n   Monitoring process \"%s\" every 5 seconds...\n\n", command);

    while (1) {
      // Clear screen
      printf("\033[H\033[J");

      // Get RAM usage
      FILE* fp;
      char buffer[MAX_SIZE];
      int pid = -1;
      int memSizeKb = -1;
      int n = -1;
      float memUsedPercent = -1.0f;

      snprintf(command, MAX_SIZE, "pmap $(pgrep %s) | tail -1", processName);

      /* Open the command for reading. */
      fp = popen(command, "r");
      if (fp == NULL) {
        printf(" Failed to run command\n" );
        exit(1);
      }

      /* Read the output a line at a time - output it. */
      while (fgets(buffer, MAX_SIZE, fp) != NULL) {
        // Scan for memory size
        n = sscanf(buffer, "%d %s %s", &pid, memSize, memSize+16);
        if (n >= 2) {
          // Convert memory size to kilobytes
          if (strcmp(memSize+strlen(memSize)-2, "KB") == 0) {
            memSizeKb = atoi(memSize);
          } else if (strcmp(memSize+strlen(memSize)-2, "MB") == 0) {
            memSizeKb = atoi(memSize)*1024;
          } else if (strcmp(memSize+strlen(memSize)-2, "GB") == 0) {
            memSizeKb = atoi(memSize)*1024*1024;
          }
        }
        // Scan for memory used percentage
        if (n >= 3) {
          if (sscanf(memSize+16, "%f%c", &memUsedPercent, &c) == 1) {
            memUsedPercent *= 100.0f;
          }
        }
      }

      /* close */
      pclose(fp);

      percent = (int)memUsedPercent;

      printUsage(processName, memSizeKb, percent);

      usleep(5000000);
    }
  }

  return 0;
}