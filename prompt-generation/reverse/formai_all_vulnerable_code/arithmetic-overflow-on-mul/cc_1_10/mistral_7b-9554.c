//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  char letter;
  int random_number;
} invasive_typing_challenge;

void generate_random_character_and_number(invasive_typing_challenge* challenge) {
  challenge->letter = 33 + (rand() % 95); // generate random ASCII character
  challenge->random_number = rand() % 10000; // generate random number
}

long int get_current_time_in_milliseconds() {
  clock_t current_time = clock();
  return (current_time * 1000) / CLOCKS_PER_SEC;
}

void display_result(const char* message, long int start_time, long int end_time, int words_per_minute) {
  printf("\n%s\n", message);
  printf("Test Completed! Your typing speed is: %d words per minute.\n", words_per_minute);
  printf("Time Taken: %ld milliseconds\n", (end_time - start_time));
}

int main() {
  int number_of_characters_to_type = 100;
  int words_in_one_minute = 5;
  int characters_typed = 0;
  int total_words = 0;
  invasive_typing_challenge typing_challenge;
  long int start_time, end_time;

  printf("*****************************************************************************\n");
  printf("*                                                                           *\n");
  printf("*                  INVASIVE TYPING SPEED TEST                               *\n");
  printf("*                                                                           *\n");
  printf("*****************************************************************************\n");
  printf("\nStart Typing Speed Test!\n");

  srand(time(NULL));

  start_time = get_current_time_in_milliseconds();

  for (int i = 0; i < number_of_characters_to_type; ++i) {
    generate_random_character_and_number(&typing_challenge);
    putchar(typing_challenge.letter);
    fflush(stdout);

    int key_pressed = getchar();
    fflush(stdin);

    if (key_pressed == typing_challenge.letter) {
      ++characters_typed;
    }

    if (characters_typed >= words_in_one_minute) {
      ++total_words;
      characters_typed = 0;
    }
  }

  end_time = get_current_time_in_milliseconds();
  int words_per_minute = total_words * words_in_one_minute;

  display_result("Test Completed!", start_time, end_time, words_per_minute);

  return 0;
}