//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 5
#define MAX_LENGTH 10

int main() {
    char words[MAX_WORDS][MAX_LENGTH] = {"hello", "world", "programming", "language", "typing"};
    char input[MAX_WORDS][MAX_LENGTH];

    printf("\nWelcome to Typing Speed Test!\n");
    printf("\nYou will be given five words to type as quickly and accurately as possible.\n");
    printf("\nPress ENTER to start.");

    getchar();

    srand(time(0));
    int i, j, count=0, correct_words=0, incorrect_words=0;
    double time_taken;
    clock_t start, end;

    start = clock();

    for(i=0; i<MAX_WORDS; i++) {
        printf("\n%s : ", words[i]);
        scanf("%s", input[i]);

        if(strcmp(words[i], input[i]) == 0) {
            count += strlen(words[i]);
            correct_words += 1;
        } else {
            count -= strlen(words[i]);
            incorrect_words += 1;
        }
    }

    end = clock();
    time_taken = (double) (end - start) / CLOCKS_PER_SEC;

    printf("\n\nYour typing speed test is complete!\n");

    printf("\nYou typed a total of %d characters.", count);

    if(correct_words == MAX_WORDS) {
        printf("\nCongratulations! You typed all the words correctly.");
    } else {
        printf("\nYou typed %d words correctly and %d words incorrectly.", correct_words, incorrect_words);
    }

    printf("\n\nYour test lasted for %.2f seconds.", time_taken);
    printf("\nYour adjusted typing speed is %.2f characters per minute.\n", (count / time_taken) * 60);

    return 0;
}