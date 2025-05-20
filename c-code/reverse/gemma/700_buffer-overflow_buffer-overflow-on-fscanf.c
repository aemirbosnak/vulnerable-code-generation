#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *train_file = fopen("train.txt", "r");
  FILE *test_file = fopen("test.txt", "r");

  char label[10];
  fscanf(train_file, "%s", label);

  fclose(train_file);
  fclose(test_file);

  return 0;
}
