//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100

int main() {
    // The following array contains randomly generated sentences for typing speed test
    char words[10][MAX] = {"The quick brown fox jumps over the lazy dog",
                           "I am the walrus, coo coo ca choo",
                           "The rain in Spain stays mainly in the plain",
                           "Elementary, my dear Watson",
                           "It was the best of times, it was the worst of times",
                           "Bond, James Bond",
                           "To be or not to be, that is the question",
                           "Houston, we have a problem",
                           "Four score and seven years ago",
                           "I have a dream"};

    int choice, correct = 0, wrong = 0;
    char input[MAX];

    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given random sentences to type. Try to type as fast and accurately as possible.\n\n");

    do {
        choice = rand() % 10; // Choose a random sentence from the array
        printf("%s\n", words[choice]); // Print the chosen sentence
        printf("Type the sentence correctly: ");

        fgets(input, MAX, stdin); // Get user input

        // Remove the newline character from the end of the input
        if(input[strlen(input) - 1] == '\n') 
            input[strlen(input) - 1] = '\0';

        // Compare the input with the chosen sentence
        if(strcmp(input, words[choice]) == 0) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect!\n");
            wrong++;
        }

        // Ask user if they want to continue
        printf("Do you want to continue? (1 for Yes / 0 for No) ");
        scanf("%d", &choice);
        getchar(); // Remove the newline character left behind by scanf

    } while(choice != 0);

    printf("\n\nYour typing speed test is over. Here are your results:\n");
    printf("Total Correct: %d\n", correct);
    printf("Total Incorrect: %d\n", wrong);
    printf("Accuracy: %.2f%%\n", (float)correct / (correct + wrong) * 100);

    return 0;
}