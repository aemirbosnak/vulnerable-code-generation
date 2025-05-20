//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a random string to type as quickly and accurately as possible.\n");
    printf("Are you ready to start? Press any key to begin.\n");
    getchar();

    // list of possible words to use in the test
    char *words[] = {"programming", "keyboard", "hacker", "javascript", "algorithm", "computer", 
                     "python", "developer", "coding", "debugging", "syntax", "software", "mysql", 
                     "linux", "github", "terminal", "agile", "java", "binary", "frontend"};

    int number_of_words = sizeof(words) / sizeof(words[0]);

    // seed the random number generator with current time
    srand(time(0));

    // select a random word from the list
    int random_index = rand() % number_of_words;
    char *random_word = words[random_index];

    // print the randomly selected word
    printf("\nYour word to type is: %s\n", random_word);

    // start the timer for the typing test
    clock_t start_time = clock();

    // prompt the user to type the word
    char input_word[50];
    printf("Type the word and press enter:\n");
    scanf("%s", input_word);

    // end the timer for the typing test
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // calculate the accuracy of the user's typing
    int incorrect_letters = 0;
    for (int i = 0; i < strlen(random_word); i++) {
        if (input_word[i] != random_word[i]) {
            incorrect_letters++;
        }
    }
    int total_letters = strlen(random_word);
    int accuracy = (1 - (double)incorrect_letters / total_letters) * 100;

    // calculate the typing speed in words per minute (WPM)
    int total_time_in_seconds = (int)time_taken;
    int total_words_typed = strlen(input_word) / 5; // assume 5 letters per word
    int typing_speed = total_words_typed * 60 / total_time_in_seconds;

    // print the results of the typing test
    printf("\nTime taken: %.2f seconds\n", time_taken);
    printf("Accuracy: %d%%\n", accuracy);
    printf("Typing speed: %d WPM\n", typing_speed);

    return 0;
}