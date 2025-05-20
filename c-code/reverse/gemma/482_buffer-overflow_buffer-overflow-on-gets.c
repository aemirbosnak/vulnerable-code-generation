#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char sentence[100];
  gets(sentence);

  int positive_words = 0;
  int negative_words = 0;

  char* positive_words_arr[] = {"happy", "joy", "good", "excellent", "great"};
  int positive_words_arr_size = 5;

  char* negative_words_arr[] = {"sad", "angry", "bad", "terrible", "awful"};
  int negative_words_arr_size = 5;

  for (int i = 0; i < positive_words_arr_size; i++) {
    if (strstr(sentence, positive_words_arr[i]) != NULL) {
      positive_words++;
    }
  }

  for (int i = 0; i < negative_words_arr_size; i++) {
    if (strstr(sentence, negative_words_arr[i]) != NULL) {
      negative_words++;
    }
  }

  int sentiment = (positive_words - negative_words) / 2;

  printf("Sentiment: %d\n", sentiment);

  return 0;
}
