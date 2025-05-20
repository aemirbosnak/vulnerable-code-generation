#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_POINTS 60

int main() {
  char **lines = NULL;
  int lines_read = 0;
  char cpu_usage[MAX_POINTS] = {};
  int i = 0;

  while (1) {
    // Read the top output
    FILE *fp = popen("top -b", "r");
    lines = realloc(lines, lines_read + 1);
    lines_read++;
    fgets(lines[lines_read - 1], 256, fp);
    pclose(fp);

    // Extract CPU usage from the output
    char *cpu_usage_str = strchr(lines[lines_read - 1], "%");
    cpu_usage_str++;
    cpu_usage[i] = atoi(cpu_usage_str);
    i++;

    // Update the graph
    if (i == MAX_POINTS) {
      i = 0;
    }

    sleep(1);
  }

  return 0;
}
