#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <unistd.h>

int main() {
  long double data[1024];
  FILE *pipe = popen("/proc/stat/cpu", "r");
  int i = 0;
  while (fscanf(pipe, "%lf ", data[i++]) != EOF) {}
  pclose(pipe);

  while (1) {
    for (i = 0; data[i] != -1; i++) {
      printf("%lf ", data[i]);
    }
    printf("\n");
    sleep(1);
  }
}
