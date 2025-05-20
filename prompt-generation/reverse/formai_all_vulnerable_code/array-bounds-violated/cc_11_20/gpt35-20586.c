//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#define MAX_INPUT 16
#define MAX_GATE_TYPES 4

enum gate_types {
  AND, OR, NOT, XOR
};

int eval(int input, char* cirt) {
  int c[MAX_INPUT], num_gates = 0;
  while (*cirt != '\0') {
    switch(*cirt++) {
    case '0': c[num_gates++] = 0; break;
    case '1': c[num_gates++] = 1; break;
    case 'A': c[num_gates - 2] = c[num_gates - 2] && c[num_gates - 1]; num_gates--; break;
    case 'O': c[num_gates - 2] = c[num_gates - 2] || c[num_gates - 1]; num_gates--; break;
    case 'N': c[num_gates - 1] = !c[num_gates - 1]; break;
    case 'X': c[num_gates - 2] = ((c[num_gates - 2] || c[num_gates - 1]) && !(c[num_gates - 2] && c[num_gates - 1])); num_gates--; break;
    case '(': c[num_gates] = eval(input, cirt); while (*cirt++ != ')'); num_gates++; break;
    default: break;
    }
  }
  return c[0];
}

int main() {
  char circuit[MAX_INPUT], input[MAX_INPUT];
  int i, t, num_cases, num_inputs, num_gates, output;
  scanf("%d", &num_cases);
  for (t = 0; t < num_cases; t++) {
    scanf("%s %d", circuit, &num_inputs);
    num_gates = 0;
    while (num_gates++ < MAX_GATE_TYPES) {
      scanf(" %c", &i);
      if (i == 'A') circuit[num_inputs + num_gates - 1] = 'A';
      else if (i == 'O') circuit[num_inputs + num_gates - 1] = 'O';
      else if (i == 'N') circuit[num_inputs + num_gates - 1] = 'N';
      else circuit[num_inputs + num_gates - 1] = 'X';
    }
    printf("Case %d:\n", t + 1);
    for (i = 0; i < (1 << num_inputs); i++) {
      for (int j = num_inputs - 1; j >= 0; j--)
        printf("%d", i >> j & 1);
      printf(" ");
      output = eval(i, circuit);
      printf("%d\n", output);
    }
  }
  return 0;
}