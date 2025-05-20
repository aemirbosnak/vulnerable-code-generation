//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_SENTENCE_LENGTH 20

char* nouns[] = {
  "government",
  "aliens",
  "illuminati",
  "Big Brother",
  "secret society",
  "corporations",
  "elites",
  "shadow government",
  "New World Order",
  "deep state"
};

char* verbs[] = {
  "controls",
  "manipulates",
  "conspires with",
  "suppresses",
  "hides",
  "deceives",
  "monitors",
  "tracks",
  "spies on",
  "brainwashes"
};

char* adjectives[] = {
  "sinister",
  "evil",
  "corrupt",
  "manipulative",
  "secretive",
  "deceptive",
  "powerful",
  "influential",
  "dominant",
  "threatening"
};

char* generateRandomSentence(int length) {
  char* sentence = malloc(length + 1);
  memset(sentence, '\0', length + 1);

  int i = 0;
  while (i < length) {
    int wordType = rand() % 3;

    if (wordType == 0) {
      strncat(sentence, adjectives[rand() % sizeof(adjectives) / sizeof(char*)], length - i - 1);
      i++;
    } else if (wordType == 1) {
      strncat(sentence, nouns[rand() % sizeof(nouns) / sizeof(char*)], length - i - 1);
      i++;
    } else {
      strncat(sentence, verbs[rand() % sizeof(verbs) / sizeof(char*)], length - i - 1);
      i++;
    }
  }

  return sentence;
}

int main() {
  srand(time(NULL));

  int numSentences = rand() % 10 + 1;
  for (int i = 0; i < numSentences; i++) {
    int sentenceLength = rand() % MAX_SENTENCE_LENGTH + 1;
    char* sentence = generateRandomSentence(sentenceLength);

    printf("Conspiracy Theory #%d: %s\n", i + 1, sentence);
  }

  return 0;
}