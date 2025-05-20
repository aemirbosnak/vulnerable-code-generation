//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: dynamic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

int main()
{
   srand(time(0)); // This line ensures that every run of the program generates a different set of random words
          
   // A list of random words:
   char words[][MAX_LEN] = {"apple", "banana", "cherry", "dragonfruit", "elderberry", "fig", "grape", "honeydew", "indian gooseberry", "jackfruit", "kiwi", "lemon", "mango", "nectarine"};

   int num_words = sizeof(words) / MAX_LEN; // calculate the number of words
   int random_index;
   char user_string[MAX_LEN];  
   int start_time, end_time;
   int seconds_elapsed;
   int count_chars = 0;
   int total_characters = 0;
   int correct_characters = 0;
   float typing_speed;
   
   printf("Welcome to the Typing Speed Test!\n\n");
   printf("Type the following words as fast as you can:\n");

   // Loop to display the words for the user to type
   for (int i = 0; i < 10; i++) {
      random_index = rand() % num_words; // choose a random word from the list
      printf("%d. %s\n", i+1, words[random_index]);
   }

   printf("\nType the words again:\n");  
   start_time = time(NULL);
   
   // Loop to prompt the user to type the words and calculate their typing speed
   for (int i = 0; i < 10; i++) {
      random_index = rand() % num_words; // choose a random word from the list
      printf("%d. ", i+1);
      scanf("%s", user_string);
      count_chars = strlen(user_string);
      total_characters += count_chars;
      if (strcmp(user_string, words[random_index]) == 0) {
         correct_characters += count_chars;
         printf("Correct!\n");
      }
      else {
         printf("Incorrect.\n");
      }
   }
   
   end_time = time(NULL);
   seconds_elapsed = end_time - start_time;  
   typing_speed = (float)correct_characters/seconds_elapsed;
   
   printf("\nYou typed a total of %d characters in %d seconds.\n", total_characters, seconds_elapsed);
   printf("Your typing speed is %.2f characters per second.\n", typing_speed);   
   
   return 0;
}