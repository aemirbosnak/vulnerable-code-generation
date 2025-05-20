//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
  char phrase[100];
  int sentiment = 0;
  
  printf("Enter a phrase to analyze: ");
  scanf("%s", phrase);
  
  // loop through each letter in the phrase
  for (int i = 0; i < strlen(phrase); i++) {
    // check for positive words
    if (phrase[i] == 'h' && phrase[i+1] == 'a' && phrase[i+2] == 'p' && phrase[i+3] == 'p' && phrase[i+4] == 'y') {
      sentiment++;
    }
    else if (phrase[i] == 'g' && phrase[i+1] == 'o' && phrase[i+2] == 'o' && phrase[i+3] == 'd') {
      sentiment++;
    }
    else if (phrase[i] == 'a' && phrase[i+1] == 'w' && phrase[i+2] == 'e' && phrase[i+3] == 's' && phrase[i+4] == 'o' && phrase[i+5] == 'm' && phrase[i+6] == 'e') {
      sentiment++;
    }
    // check for negative words
    else if (phrase[i] == 's' && phrase[i+1] == 'a' && phrase[i+2] == 'd') {
      sentiment--;
    }
    else if (phrase[i] == 'a' && phrase[i+1] == 'n' && phrase[i+2] == 'g' && phrase[i+3] == 'r' && phrase[i+4] == 'y') {
      sentiment--;
    }
    else if (phrase[i] == 't' && phrase[i+1] == 'e' && phrase[i+2] == 'r' && phrase[i+3] == 'r' && phrase[i+4] == 'i' && phrase[i+5] == 'b' && phrase[i+6] == 'l' && phrase[i+7] == 'e') {
      sentiment--;
    }
  }
  
  // print out sentiment score
  printf("Sentiment score: %d\n", sentiment);
  
  // determine final sentiment
  if (sentiment > 0) {
    printf("Overall sentiment: positive!\n");
  }
  else if (sentiment < 0) {
    printf("Overall sentiment: negative.\n");
  }
  else {
    printf("Overall sentiment: neutral.\n");
  }
  
  return 0;
}