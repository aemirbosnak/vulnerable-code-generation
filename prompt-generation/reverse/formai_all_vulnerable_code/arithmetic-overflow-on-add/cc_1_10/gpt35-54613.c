//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define TEST_LENGTH 5
#define MAX_TYPING_ATTEMPTS 3

char* generate_sentence()
{
    char* sentences[] = {"The quick brown fox jumps over the lazy dog",
                         "Pack my box with five dozen liquor jugs",
                         "Sphinx of black quartz, judge my vow",
                         "How vexingly quick daft zebras jump",
                         "Jackdaws love my big sphinx of quartz",
                         "The five boxing wizards jump quickly",
                         "Quick zephyrs blow, vexing daft Jim",
                         "A wizard’s job is to vex chumps quickly in fog",
                         "Watch Jeopardy!, Alex Trebek’s fun TV quiz game",
                         "Jaded zombies acted quaintly but kept driving their oxen"
                        };

    int random_index = rand() % 10;

    return sentences[random_index];
}

int main()
{
    srand(time(0));

    printf("Welcome to the Typing Speed Test Program\n\n");

    char* sentence = generate_sentence();
    printf("Your sentence to type is: %s\n\n", sentence);

    int correct_count = 0;
    int incorrect_count = 0;
    int typing_attempts = 0;
    int total_typing_time = 0;

    while (typing_attempts < MAX_TYPING_ATTEMPTS)
    {
        printf("Attempt %d:\n", (typing_attempts + 1));

        time_t start_time = time(NULL);

        for (int i = 0; i < TEST_LENGTH; i++)
        {
            char input_char = getchar();
            char expected_char = sentence[i];

            if (input_char == expected_char)
            {
                correct_count++;
            }
            else
            {
                incorrect_count++;
            }

            if (!isspace(input_char) && !isalnum(input_char) && !ispunct(input_char))
            {
                printf("Invalid character entered. Try again.\n");
                i--;
            }
        }

        time_t end_time = time(NULL);
        int typing_time = (int) (end_time - start_time);
        total_typing_time += typing_time;

        printf("\nResults:\n");
        printf("Time Taken: %d seconds\n", typing_time);
        printf("Correct Characters: %d\n", correct_count);
        printf("Incorrect Characters: %d\n\n", incorrect_count);

        typing_attempts++;
        correct_count = 0;
        incorrect_count = 0;
    }

    int average_typing_time = total_typing_time / MAX_TYPING_ATTEMPTS;
    printf("Your average typing time over %d attempts is %d seconds.\n\n", MAX_TYPING_ATTEMPTS, average_typing_time);

    printf("Thank you for using the Typing Speed Test Program!\n");

    return 0;
}