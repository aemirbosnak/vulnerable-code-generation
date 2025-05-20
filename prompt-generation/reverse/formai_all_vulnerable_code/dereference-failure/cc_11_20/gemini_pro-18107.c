//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: irregular
/*
 * BrainFuck! A programming language with only 8 commands.
 * By Urban Müller, 2016
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 30000

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <program>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int cells[MAX_CELLS] = {0};
  int cell = 0;
  int loop_stack[MAX_CELLS] = {0};
  int loop_depth = 0;

  char *program = argv[1];
  while (*program) {
    switch (*program) {
      case '+':
        cells[cell]++;
        break;
      case '-':
        cells[cell]--;
        break;
      case '>':
        cell++;
        break;
      case '<':
        cell--;
        break;
      case '.':
        putchar(cells[cell]);
        break;
      case ',':
        cells[cell] = getchar();
        break;
      case '[':
        if (cells[cell] == 0) {
          int level = 1;
          while (level > 0) {
            program++;
            switch (*program) {
              case '[':
                level++;
                break;
              case ']':
                level--;
                break;
            }
          }
        } else {
          loop_stack[loop_depth++] = program - argv[1];
        }
        break;
      case ']':
        if (cells[cell] != 0) {
          program = argv[1] + loop_stack[--loop_depth];
        }
        break;
    }
    program++;
  }

  return EXIT_SUCCESS;
}