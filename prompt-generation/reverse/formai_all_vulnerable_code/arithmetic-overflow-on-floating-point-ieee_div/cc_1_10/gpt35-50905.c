//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: funny
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Typing Speed Test game!\n");
  printf("Type the following words as fast as you can:\n");

  char words[15][20] = {
      "elephant",
      "banana",
      "supercalifragilisticexpialidocious",
      "chocolate",
      "penguin",
      "pajamas",
      "programming",
      "jazz",
      "xylophone",
      "yacht",
      "pizza",
      "bacon",
      "taco",
      "avocado",
      "burrito"
  };
  
  int num_of_words = 15;
  int random_num;
  int i;
  
  srand(time(NULL)); // random seed
  
  clock_t start, end;
  double time_elapsed;
  
  start = clock();
  for(i = 0; i < num_of_words; i++) {
    random_num = rand() % num_of_words;
    printf("%s ", words[random_num]);
  }
  printf("\n");
  
  char user_input[20];
  int correct_input = 0;
  for(i = 0; i < num_of_words; i++) {
    scanf("%s", user_input);
    if(strcmp(user_input, words[i]) == 0) {
      correct_input++;
    }
  }
  end = clock();
  time_elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
  
  if(correct_input == num_of_words) {
    printf("Congratulations! You typed all the words correctly!\n");
  } else {
    printf("Oops! You made some errors while typing.\n");
  }
  
  printf("Your typing speed is %.2f words per minute.\n", ((double)num_of_words / time_elapsed) * 60);
  
  return 0;
}