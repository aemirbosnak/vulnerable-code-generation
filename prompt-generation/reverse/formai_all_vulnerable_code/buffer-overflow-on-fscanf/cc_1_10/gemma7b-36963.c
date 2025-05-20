//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
  char str[1000];
  int i, sentiment = 0, word_count = 0;
  FILE *fp;

  // Open a file
  fp = fopen("poem.txt", "r");

  // Read the file
  fscanf(fp, "%[^\n]", str);

  // Close the file
  fclose(fp);

  // Tokenize the text
  char *token = strtok(str, " ");

  // Loop over the tokens
  while (token)
  {
    // Remove punctuation
    char *word = removePunctuation(token);

    // Check if the word is a stop word
    if (!isStopWord(word))
    {
      // Add the word to the sentiment analysis
      sentiment += calculateSentiment(word);

      // Increment the word count
      word_count++;
    }
    token = strtok(NULL, " ");
  }

  // Calculate the sentiment score
  float sentiment_score = (sentiment / word_count) * 100;

  // Print the sentiment score
  printf("The sentiment score is: %f%%", sentiment_score);

  return 0;
}

int removePunctuation(char *str)
{
  str = strchr(str, '.') ? strchr(str, '.') : strchr(str, ',');
  str = strchr(str, '?') ? strchr(str, '?') : strchr(str, '"');
  str = strchr(str, ')') ? strchr(str, ')') : strchr(str, '!');
  return str;
}

int isStopWord(char *word)
{
  char *stop_words[] = {"the", "a", "an", "of", "to", "in", "for", "at", "by", "with"};

  for (int i = 0; i < 10; i++)
  {
    if (strcmp(word, stop_words[i]) == 0)
    {
      return 1;
    }
  }

  return 0;
}

int calculateSentiment(char *word)
{
  char *sentiment_words[] = {"happy", "sad", "joy", "anger", "fear"};

  for (int i = 0; i < 5; i++)
  {
    if (strcmp(word, sentiment_words[i]) == 0)
    {
      return 2;
    }
  }

  return 0;
}