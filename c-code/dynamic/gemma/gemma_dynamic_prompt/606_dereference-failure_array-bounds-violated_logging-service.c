#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char **arr = NULL;
  arr = (char**)malloc(10 * sizeof(char*));
  arr[0] = "Test";
  arr[1] = "Log";
  arr[2] = "Entry";
  arr[3] = "With";
  arr[4] = "Overflow";
  arr[5] = "Bounds";
  arr[6] = "Violation";
  arr[7] = "But";
  arr[8] = "It";
  arr[9] = "Compiles";

  printf("%s\n", arr[10]);

  free(arr);
  return 0;
}
