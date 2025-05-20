//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <time.h>

int main()
{
  time_t start, end;
  float time_taken;
  int words_per_minute, characters_per_minute;
  char message[100] = "The wasteland stretches endlessly, but hope remains. A lone traveler journeys through the barren landscape, seeking redemption.";

  start = time(NULL);
  printf("%s", message);
  end = time(NULL);

  time_taken = (float)(end - start) / 60;
  words_per_minute = (int)(words_per_minute_calc(message) / time_taken) * 60;
  characters_per_minute = (int)(characters_per_minute_calc(message) / time_taken) * 60;

  printf("\nWords per minute: %d", words_per_minute);
  printf("\nCharacters per minute: %d", characters_per_minute);

  return 0;
}

int words_per_minute_calc(char *message)
{
  int words = 0;
  char *word_start = message;

  while (word_start)
  {
    word_start = strstr(word_start, " ") || strstr(word_start, ".") ? word_start + 1 : NULL;
    words++;
  }

  return words;
}

int characters_per_minute_calc(char *message)
{
  int characters = 0;
  char *character_start = message;

  while (character_start)
  {
    character_start = strstr(character_start, " ") || strstr(character_start, ".") ? character_start + 1 : NULL;
    characters++;
  }

  return characters;
}