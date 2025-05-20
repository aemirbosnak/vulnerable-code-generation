#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char board[64] = "-------------------------------------------------------------------";
  char move[10] = "";

  printf("%s", board);

  printf("\nEnter your move (e.g. a2b3): ");
  scanf("%s", move);

  if (strlen(move) > 9) {
    printf("Error: Move too long.\n");
  } else {
    // Vulnerable code: Buffer overflow exploit
    move[9] = 'A';
    memcpy(board, move, 64);

    printf("%s", board);
  }

  return 0;
}
