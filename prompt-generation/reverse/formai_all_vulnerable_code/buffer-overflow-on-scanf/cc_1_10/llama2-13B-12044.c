//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>

  // Define some constants and variables
  #define MAX_NUMBER 1000
  #define MAGIC_NUMBER 42
  int current_number = 0;
  int guess = 0;
  int correct = 0;

  // Function to print a cheerful message
  void print_message(const char* message) {
    printf("🎉 %s 🎉\n", message);
  }

  // Function to generate a random number
  int get_random_number() {
    return (rand() % MAX_NUMBER) + 1;
  }

  // Function to check if the user's guess is correct
  int is_correct(int guess) {
    return (guess == current_number);
  }

  int main() {
    // Print a cheerful welcome message
    print_message("Welcome to the Arithmetic Game!");

    // Generate a random number
    current_number = get_random_number();

    // Print the current number
    printf("The current number is: %d\n", current_number);

    // Loop until the user guesses correctly
    while (1) {
      // Print a cheerful message asking the user to guess
      print_message("Guess the number!");

      // Get the user's guess
      scanf("%d", &guess);

      // Check if the user's guess is correct
      if (is_correct(guess)) {
        // Print a cheerful message if the user guessed correctly
        print_message("🎉 You guessed it! 🎉");
        correct++;
        break;
      } else {
        // Print a cheerful message if the user didn't guess correctly
        print_message("😢 Try again, my dear! 😢");
      }
    }

    // Print the final score
    printf("You guessed %d out of %d numbers correctly.\n", correct, MAX_NUMBER);

    // Print a cheerful farewell message
    print_message("Thanks for playing the Arithmetic Game! 👋");

    return 0;
  }