//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: peaceful
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>

  #define MAX_WORD_LENGTH 100
  #define MAX_TEXT_LENGTH 1000

  struct word {
    char text[MAX_WORD_LENGTH];
    int count;
    float sentiment;
  };

  int main() {
    char text[MAX_TEXT_LENGTH];
    struct word words[MAX_WORD_LENGTH];
    int num_words = 0;
    float sentiment = 0.0;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; i < strlen(text); i++) {
      if (isalpha(text[i])) {
        if (num_words == MAX_WORD_LENGTH) {
          printf("Error: too many words\n");
          return 1;
        }
        words[num_words].text[i] = tolower(text[i]);
        words[num_words].count++;
        if (words[num_words].text[i] == 'h' || words[num_words].text[i] == 's') {
          words[num_words].sentiment = 0.5;
        } else if (words[num_words].text[i] == 'l' || words[num_words].text[i] == 'd') {
          words[num_words].sentiment = -0.5;
        } else {
          words[num_words].sentiment = 0.0;
        }
        num_words++;
      }
    }

    for (int i = 0; i < num_words; i++) {
      sentiment += words[i].sentiment;
    }

    printf("Sentiment: %f\n", sentiment / num_words);

    return 0;
  }