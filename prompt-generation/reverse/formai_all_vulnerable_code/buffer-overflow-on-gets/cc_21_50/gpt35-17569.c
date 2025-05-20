//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: mathematical
#include <stdio.h>

int main() {
  int positive_count = 0, negative_count = 0, neutral_count = 0, total_count = 0;
  float positive_percentage, negative_percentage, neutral_percentage;
  char sentence[100], ch;

  printf("Enter a sentence: ");
  gets(sentence);  //Note: gets function is not recommended for use in real code

  for(int i=0; sentence[i]!='\0'; i++) {
    ch = sentence[i];
    if(ch == ' ') {
      continue;
    } else if(ch == '.') {
      total_count++;
      continue;
    } else if(ch == '!' || ch == '?') {
      total_count++;
      if(negative_count > positive_count) {
        negative_percentage = ((float)negative_count/total_count)*100;
        printf("\nSentiment analysis: Negative with %.2f%%\n", negative_percentage);
      } else if(positive_count > negative_count) {
        positive_percentage = ((float)positive_count/total_count)*100;
        printf("\nSentiment analysis: Positive with %.2f%%\n", positive_percentage);
      } else {
        neutral_percentage = ((float)neutral_count/total_count)*100;
        printf("\nSentiment analysis: Neutral with %.2f%%\n", neutral_percentage);
      }
      break;
    }

    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
      positive_count++;
    } else if(ch == '!' || ch == '?' || ch == '.' || ch == ',' || ch == ':') {
      total_count++;
    } else {
      negative_count++;
    }
  }

  if(ch != '!' && ch != '?') {
    total_count++;
    if(negative_count > positive_count) {
      negative_percentage = ((float)negative_count/total_count)*100;
      printf("\nSentiment analysis: Negative with %.2f%%\n", negative_percentage);
    } else if(positive_count > negative_count) {
      positive_percentage = ((float)positive_count/total_count)*100;
      printf("\nSentiment analysis: Positive with %.2f%%\n", positive_percentage);
    } else {
      neutral_percentage = ((float)neutral_count/total_count)*100;
      printf("\nSentiment analysis: Neutral with %.2f%%\n", neutral_percentage);
    }
  }
  
  return 0;
}