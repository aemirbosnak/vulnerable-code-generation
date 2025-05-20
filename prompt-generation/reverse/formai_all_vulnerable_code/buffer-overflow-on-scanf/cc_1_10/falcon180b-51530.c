//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_of_words, num_of_correct_words, num_of_incorrect_words, total_words;
    char word[10];
    char user_input[20];
    int i, j;
    float wpm, accuracy;
    time_t start_time, end_time;
    srand(time(NULL));

    printf("Welcome to the C Typing Speed Test!\n");
    printf("This program will test your typing speed and accuracy.\n");
    printf("You will be given a series of words to type.\n");
    printf("Type each word as accurately and quickly as possible.\n");
    printf("Press enter after each word.\n");
    printf("Good luck!\n\n");

    // Get number of words from user
    printf("How many words do you want to type? ");
    scanf("%d", &num_of_words);

    // Initialize variables
    num_of_correct_words = 0;
    num_of_incorrect_words = 0;
    total_words = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random words
    for (i = 0; i < num_of_words; i++)
    {
        word[0] = rand() % 26 + 'a';
        for (j = 1; j < 5; j++)
        {
            word[j] = rand() % 26 + 'a';
        }
        word[5] = '\0';
        printf("%s ", word);
    }

    // Get user input
    printf("\n\nEnter your typed words: ");
    fgets(user_input, sizeof(user_input), stdin);

    // Compare user input with correct words
    for (i = 0; i < strlen(user_input); i++)
    {
        if (user_input[i] == '\n')
        {
            total_words++;
            if (strncmp(word, user_input, strlen(word)) == 0)
            {
                num_of_correct_words++;
            }
            else
            {
                num_of_incorrect_words++;
            }
            word[0] = rand() % 26 + 'a';
            for (j = 1; j < 5; j++)
            {
                word[j] = rand() % 26 + 'a';
            }
            word[5] = '\0';
        }
    }

    // Calculate words per minute and accuracy
    wpm = (float)total_words / ((float)5 * num_of_words);
    accuracy = ((float)num_of_correct_words / (float)total_words) * 100;

    // Print results
    printf("\n\nResults:\n");
    printf("Words per minute: %.2f\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}