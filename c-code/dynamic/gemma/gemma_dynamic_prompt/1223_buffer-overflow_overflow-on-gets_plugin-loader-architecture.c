#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char shell[1024];

void main() {
  gets(shell);
  puts(shell);
}
