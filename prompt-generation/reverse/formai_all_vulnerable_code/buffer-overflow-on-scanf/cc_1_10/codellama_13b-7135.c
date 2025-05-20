//Code Llama-13B DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
  #include <string.h>
  #include <ctype.h>
  #include <math.h>

  #define MAX_WORD_LENGTH 100
  #define MAX_SENTENCE_LENGTH 1000
  #define MAX_SPAM_SCORE 100

  struct spam_word {
    char word[MAX_WORD_LENGTH];
    int weight;
  };

  struct spam_sentence {
    char sentence[MAX_SENTENCE_LENGTH];
    int score;
  };

  int is_spam_word(char* word) {
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
      if (word[i] == '\0') {
        return 0;
      }
      if (!isalpha(word[i])) {
        return 1;
      }
    }
    return 0;
  }

  int spam_score(char* sentence) {
    int score = 0;
    for (int i = 0; i < MAX_SENTENCE_LENGTH; i++) {
      if (sentence[i] == '\0') {
        return score;
      }
      if (is_spam_word(sentence[i])) {
        score++;
      }
    }
    return score;
  }

  int main() {
    struct spam_word spam_words[100];
    struct spam_sentence spam_sentences[100];
    int spam_count = 0;
    int non_spam_count = 0;

    for (int i = 0; i < 100; i++) {
      scanf("%s", spam_words[i].word);
      spam_words[i].weight = 1;
    }

    for (int i = 0; i < 100; i++) {
      scanf("%s", spam_sentences[i].sentence);
      spam_sentences[i].score = spam_score(spam_sentences[i].sentence);
      if (spam_sentences[i].score > MAX_SPAM_SCORE) {
        spam_count++;
      } else {
        non_spam_count++;
      }
    }

    printf("Spam count: %d\n", spam_count);
    printf("Non-spam count: %d\n", non_spam_count);

    return 0;
  }