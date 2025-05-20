#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char text[1024];
  printf("Enter text: ");
  fgets(text, 1024, stdin);

  int happy_count = 0;
  int sad_count = 0;
  int neutral_count = 0;

  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      if (text[i] == 'h' || text[i] == 'H' || text[i] == 'a' || text[i] == 'A') {
        happy_count++;
      } else if (text[i] == 's' || text[i] == 'S' || text[i] == 'n' || text[i] == 'N') {
        sad_count++;
      } else if (text[i] == 'o' || text[i] == 'O') {
        neutral_count++;
      }
    }
  }

  printf("Happy count: %d\n", happy_count);
  printf("Sad count: %d\n", sad_count);
  printf("Neutral count: %d\n", neutral_count);

  return 0;
}
