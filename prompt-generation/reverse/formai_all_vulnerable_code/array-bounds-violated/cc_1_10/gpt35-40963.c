//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define SENTENCE_LENGTH 100
#define NUM_SENTENCES 10

int main()
{
    char sentences[NUM_SENTENCES][SENTENCE_LENGTH] = {
        "The quick brown fox jumps over the lazy dog",
        "Jackdaws love my big sphinx of quartz",
        "Pack my box with five dozen liquor jugs",
        "How vexingly quick daft zebras jump",
        "My ex pub quiz crowd gave joyful thanks",
        "The five boxing wizards jump quickly",
        "Amazingly few discotheques provide jukeboxes",
        "My girl wove six dozen plaid jackets before she quit",
        "Few black taxis drive up major roads on quiet hazy nights",
        "Quick zephyrs blow vexing daft Jim"
    };
    
    srand(time(NULL));     // Initializing random number generator
    int sentence_index = rand() % NUM_SENTENCES;   // Generating random sentence index
    char typing_input[SENTENCE_LENGTH];
    int character_count = 0;    // Initializing typing character count
    time_t start_time, end_time;
    double elapsed_time;

    printf("Type the following sentence as quickly as possible:\n%s\n", sentences[sentence_index]);
    while (fgets(typing_input, SENTENCE_LENGTH, stdin))
    {
        // Stripping newline character from input
        if (typing_input[strlen(typing_input) - 1] == '\n')
            typing_input[strlen(typing_input) - 1] = '\0';

        // Counting correctly typed characters
        for (int i = 0; i < strlen(typing_input); i++)
        {
            if (typing_input[i] == sentences[sentence_index][i])
                character_count++;
        }

        // Checking if the entire sentence has been typed
        if (strcmp(typing_input, sentences[sentence_index]) == 0)
            break;

        printf("Incorrect! Please try again: ");
    }
    
    // Calculating typing speed and printing results
    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);
    printf("You typed %d characters in %.2f seconds.\n", character_count, elapsed_time);
    printf("Your typing speed is %.2f characters per second.\n", character_count/elapsed_time);

    return 0;
}