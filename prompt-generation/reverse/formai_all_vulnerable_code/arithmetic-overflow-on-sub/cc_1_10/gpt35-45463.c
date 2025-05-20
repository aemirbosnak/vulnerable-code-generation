//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printSentence()
{
    printf("The quick brown fox jumps over the lazy dog.\n");
    printf("The five boxing wizards jump quickly.\n");
    printf("How vexingly quick daft zebras jump!\n");
    printf("Jived fox nymph grabs quick waltz.\n");
    printf("Bright vixens jump; dozy fowl quack.\n");
    printf("Quick wafting zephyrs vex bold Jim.\n");
    printf("Sphinx of black quartz, judge my vow.\n");
    printf("Jackdaws love my big sphinx of quartz.\n");
    printf("The vixen jump over the fence, quickly followed by the lazy dog.\n");
    printf("Boxers need to be quick on their feet to win the fight.\n");
}

int main()
{
    int count = 0, num_words = 0;
    char c;

    // print the instructions
    printf("Welcome to the typing speed test!\n");
    printf("Type the sentences shown below as quickly as possible.\n");
    printf("Press ENTER after each sentence to move on to the next one.\n");
    printf("\n");

    // print the sentences
    printSentence();

    printf("\nPress any key to start the test...\n");
    getchar();

    // start the timer
    time_t start = time(NULL);

    // loop through each sentence
    for (int i = 0; i < 10; i++)
    {
        printf("Sentence %d:\n", i+1);
        printf("Type the sentence below:\n");

        // print the sentence
        printSentence();

        // count the number of words
        num_words = 0;

        // read input from user
        while ((c = getchar()) != '\n')
        {
            // count the number of words
            if (c == ' ')
            {
                num_words++;
            }
        }

        // count the final word
        num_words++;

        printf("You typed %d words in the sentence.\n", num_words);

        // increment the counter
        count += num_words;
    }

    // stop the timer
    time_t end = time(NULL);
    int time_taken = end - start;

    printf("\nCongratulations, you completed the typing speed test!\n");
    printf("You typed %d words in total in %d seconds.\n", count, time_taken);

    return 0;
}