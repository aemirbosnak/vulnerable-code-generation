//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
// The Typing Speed Test
// A Sherlock Holmes style program
// written by a chatbot named Watson

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to The Typing Speed Test!\n");
    printf("Please type the following sentence as fast and accurately as possible:\n\n");

    // Generate a random sentence to type
    srand(time(NULL));
    const char* sentences[] = {"It is a capital mistake to theorize before one has data.", 
                               "My name is Sherlock Holmes. It is my business to know what other people don't know.",
                               "There is nothing more deceptive than an obvious fact.",
                               "Mediocrity knows nothing higher than itself; but genius recognizes itself at once.",
                               "What one man can invent, another can discover."};
    int num_sentences = sizeof(sentences) / sizeof(sentences[0]);
    int random_index = rand() % num_sentences;
    const char* sentence = sentences[random_index];

    printf("%s\n\n", sentence);

    // Measure the time it takes to type the sentence
    time_t start_time = time(NULL);
    char typed_sentence[100];
    fgets(typed_sentence, 100, stdin);
    time_t end_time = time(NULL);

    // Calculate the typing speed and accuracy
    double elapsed_time = difftime(end_time, start_time);
    int typed_chars = strlen(typed_sentence) - 1; // -1 to exclude the newline character
    int correct_chars = 0;
    for (int i = 0; i < typed_chars && i < strlen(sentence); i++)
    {
        if (typed_sentence[i] == sentence[i])
        {
            correct_chars++;
        }
    }
    int accuracy = (int)(((double)correct_chars / typed_chars) * 100);
    int speed = (int)(((double)typed_chars / elapsed_time) * 60);

    printf("\nYou typed %d characters in %.2lf seconds.\n", typed_chars, elapsed_time);
    printf("Your typing speed is %d characters per minute.\n", speed);
    printf("Your typing accuracy is %d%%.\n", accuracy);

    if (accuracy < 70)
    {
        printf("Your accuracy is a bit low. Try again!\n");
    }
    else if (speed < 60)
    {
        printf("Your typing speed is a bit slow. Try again!\n");
    }
    else
    {
        printf("Well done! You are a good typist.\n");
    }

    return 0;
}