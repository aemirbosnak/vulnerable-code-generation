#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char sentence[100];
  gets(sentence);

  int positive = 0;
  int negative = 0;
  char* words[] = {"good", "happy", "joy", "positive", "excellent", "great", "wonderful", "bad", "sad", "terrible", "awful"};

  for (int i = 0; i < 11; i++) {
    if (strstr(sentence, words[i]) != NULL) {
      positive++;
    } else if (strstr(sentence, words[i]) != NULL) {
      negative++;
    }
  }

  if (positive > negative) {
    printf("The sentiment of the sentence is positive.\n");
  } else if (negative > positive) {
    printf("The sentiment of the sentence is negative.\n");
  } else {
    printf("The sentiment of the sentence is neutral.\n");
  }

  return 0;
}
