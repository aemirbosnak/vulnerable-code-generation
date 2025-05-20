//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void print_welcome_message();
int get_random_number(int min, int max);
int count_words(char *input_string);
int calculate_elapsed_time(time_t start_time, time_t end_time);
float calculate_typing_speed(int word_count, int elapsed_time);

int main()
{
    // Initialize variables
    char text_to_type[256] = "The quick brown fox jumps over the lazy dog.";
    char input_text[256];
    int word_count;
    time_t start_time, end_time;
    int elapsed_time;
    float typing_speed;

    // Print welcome message
    print_welcome_message();

    // Wait for user to start the test
    printf("Press any key to start typing...");
    getchar();

    // Get current time as the starting time for typing
    start_time = time(NULL);

    // Prompt user to type the text
    printf("\nType the following text: \n\n%s\n\n", text_to_type);
    printf("Begin typing: ");

    // Read the user input
    fgets(input_text, 256, stdin);

    // Get current time as the end time for typing
    end_time = time(NULL);

    // Calculate elapsed time
    elapsed_time = calculate_elapsed_time(start_time, end_time);

    // Convert input text to lowercase
    for (int i = 0; input_text[i]; i++)
    {
        input_text[i] = tolower(input_text[i]);
    }

    // Count number of words in input text
    word_count = count_words(input_text);

    // Calculate typing speed in words per minute (wpm)
    typing_speed = calculate_typing_speed(word_count, elapsed_time);

    // Print results
    printf("\nYou typed %d words in %d seconds.\n", word_count, elapsed_time);
    printf("Your typing speed is %.1f words per minute.\n", typing_speed);

    return 0;
}

void print_welcome_message()
{
    printf("Welcome to the Typing Speed Test.\n");
    printf("You will be given an English sentence to type.\n");
    printf("Your typing speed will be calculated based on the number of words you type per minute.\n");
    printf("Press any key to start the test...\n\n");
}

int get_random_number(int min, int max)
{
    // Generate a random number between min and max
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int count_words(char *input_string)
{
    // Count number of words in input string
    int word_count = 0;
    int i = 0;
    while (input_string[i] != '\0')
    {
        if (input_string[i] == ' ' || input_string[i] == '\n' || input_string[i] == '\t')
        {
            word_count++;
        }
        i++;
    }
    return word_count + 1;
}

int calculate_elapsed_time(time_t start_time, time_t end_time)
{
    // Calculate elapsed time in seconds
    return (int)difftime(end_time, start_time);
}

float calculate_typing_speed(int word_count, int elapsed_time)
{
    // Calculate typing speed in words per minute (wpm)
    return (word_count * 60.0) / elapsed_time;
}