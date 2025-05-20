#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <unistd.h>

int main() {
  char buffer[1024];
  FILE* pipe = popen("/proc/stat/cpu", "r");
  fscanf(pipe, "%s", buffer);
  pclose(pipe);
  return 0;
}
