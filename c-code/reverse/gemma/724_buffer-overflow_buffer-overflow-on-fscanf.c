#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("data.txt", "r");
  char buffer[10];
  fscanf(fp, "%s", buffer);
  int layers = 3;
  for (int i = 0; i < layers; i++) {
    // Process data with neural network
  }
  return 0;
}
