#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char statement[1000];
  printf("Enter a statement: ");
  fgets(statement, 1000, stdin);

  int happy_count = 0;
  int sad_count = 0;
  int neutral_count = 0;

  char* emoticons[] = {":)", ":("};

  for (int i = 0; i < strlen(statement); i++) {
    for (int j = 0; j < 2; j++) {
      if (strcmp(statement + i, emoticons[j]) == 0) {
        if (emoticons[j][0] == ')') {
          happy_count++;
        } else if (emoticons[j][0] == '(') {
          sad_count++;
        }
      }
    }
  }

  neutral_count = strlen(statement) - happy_count - sad_count;

  printf("Overall sentiment: ");

  if (happy_count > sad_count) {
    printf("Happy\n");
  } else if (sad_count > happy_count) {
    printf("Sad\n");
  } else {
    printf("Neutral\n");
  }

  printf("Number of happy emojis: %d\n", happy_count);
  printf("Number of sad emojis: %d\n", sad_count);
  printf("Number of neutral emojis: %d\n", neutral_count);

  return 0;
}
