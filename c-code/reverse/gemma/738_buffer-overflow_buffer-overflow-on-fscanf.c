#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <unistd.h>

int main() {
  char buff[1024];
  int i = 0;
  float cpu_usage[1024];

  while (1) {
    system("top -b -n 1 | grep \"user\" | awk 'NR==2' | tr -d \"%\")");
    fscanf(stdin, "%f", &cpu_usage[i]);
    i++;

    // Display CPU usage
    for (int j = 0; j < i; j++) {
      printf("%f%% ", cpu_usage[j]);
    }
    printf("\n");

    sleep(1);
  }
}
