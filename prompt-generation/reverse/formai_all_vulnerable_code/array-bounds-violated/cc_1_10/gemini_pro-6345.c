//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: light-weight
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SPAM_WORDS 50
#define MAX_MSG_SIZE 1024

char *spamWords[MAX_SPAM_WORDS];
int numSpamWords = 0;

int loadSpamWords(char *fileName) {
  FILE *file = fopen(fileName, "r");
  if (file == NULL) {
    return -1;
  }

  char line[256];
  while (fgets(line, sizeof(line), file)) {
    int len = strlen(line);
    if (line[len - 1] == '\n') {
      line[len - 1] = '\0';
    }
    spamWords[numSpamWords++] = strdup(line);
  }

  fclose(file);

  return 0;
}

int isSpam(char *msg) {
  int i, j;
  int score = 0;

  for (i = 0; i < numSpamWords; i++) {
    for (j = 0; msg[j] != '\0'; j++) {
      if (tolower(msg[j]) == tolower(spamWords[i][0])) {
        if (strncmp(&msg[j], spamWords[i], strlen(spamWords[i])) == 0) {
          score++;
        }
      }
    }
  }

  return score > 0;
}

int main() {
  if (loadSpamWords("spamWords.txt") != 0) {
    printf("Error loading spam words file.\n");
    return -1;
  }

  char msg[MAX_MSG_SIZE];

  while (1) {
    printf("Enter a message (or quit to exit): ");
    gets(msg);

    if (strcmp(msg, "quit") == 0) {
      break;
    }

    if (isSpam(msg)) {
      printf("This message is spam.\n");
    } else {
      printf("This message is not spam.\n");
    }
  }

  return 0;
}