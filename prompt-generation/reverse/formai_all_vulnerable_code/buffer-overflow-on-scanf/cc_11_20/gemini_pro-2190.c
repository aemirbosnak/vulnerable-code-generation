//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
  // Feeling happy today! 😄
  char sentence[100];
  int score = 0;

  // Let's analyze your sentence!
  printf("Type in your sentence: ");
  scanf("%s", sentence);

  // Check for positive words: words with 'good' in them
  if (strstr(sentence, "good") != NULL) {
    score += 1;
  }
  if (strstr(sentence, "great") != NULL) {
    score += 2;
  }
  if (strstr(sentence, "awesome") != NULL) {
    score += 3;
  }
  if (strstr(sentence, "fantastic") != NULL) {
    score += 4;
  }

  // Check for negative words: words with 'bad' in them
  if (strstr(sentence, "bad") != NULL) {
    score -= 1;
  }
  if (strstr(sentence, "terrible") != NULL) {
    score -= 2;
  }
  if (strstr(sentence, "horrible") != NULL) {
    score -= 3;
  }
  if (strstr(sentence, "awful") != NULL) {
    score -= 4;
  }

  // Print the sentiment score
  printf("Your sentence has a sentiment score of %d.\n", score);

  // Spread the cheer!
  if (score > 0) {
    printf("Yay! It's a positive sentence! 😁");
  } else if (score < 0) {
    printf("Uh-oh, a bit negative. Chin up! 😊");
  } else {
    printf("Hmm, a neutral sentence. 🤔");
  }

  return 0;
}