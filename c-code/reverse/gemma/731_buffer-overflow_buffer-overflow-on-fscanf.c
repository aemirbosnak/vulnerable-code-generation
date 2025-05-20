#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_HISTORY 10

int main() {
  int i, j, history[MAX_HISTORY];
  FILE *fp;
  char line[1024];
  int usage, total_usage = 0;

  for (i = 0; i < MAX_HISTORY; i++) {
    history[i] = 0;
  }

  fp = popen("top -b", "r");
  if (fp == NULL) {
    perror("popen");
    return 1;
  }

  while (1) {
    fgets(line, 1024, fp);
    if (feof(fp)) {
      break;
    }

    usage = atoi(line);
    total_usage += usage;
    history[i] = usage;

    for (j = 0; j < MAX_HISTORY - 1; j++) {
      history[j] = history[j + 1];
    }

    printf("CPU usage: %.2f%% (total: %.2f%%)\n", (float)history[0], (float)total_usage);

    sleep(1);
  }

  pclose(fp);

  return 0;
}
