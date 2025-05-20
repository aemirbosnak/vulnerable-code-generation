#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Circuit {
  char playerName[20];
  int score;
} Circuit;

int main() {
  Circuit circuit;
  scanf("%s", circuit.playerName);
  circuit.score = 0;
  printf("Hello, %s!", circuit.playerName);
  return 0;
}
