//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: ultraprecise
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50

char* words[MAX_WORDS] = {
    "deduction", "irate", "delineate", "gossamer", "furtive", 
    "expunge", "pangolin", "raconteur", "abstemious", "alacrity", 
    "avarice", "inexorable", "bibliophile", "callipygian", "diaphanous", 
    "ebullient", "effulgent", "fastidious", "gregarious", "histrionic", 
    "imperturbable", "jocund", "lugubrious", "mellifluous", "nefarious",
    "obtuse", "pellucid", "quiescent", "rambunctious", "scintillating", 
    "temerity", "ubiquitous", "vacillate", "wheedle", "xenophobe", 
    "yoke", "zealot", "aberration", "benevolent", "capitulate", 
    "cumbersome", "discordant", "erroneous", "fabricate", "guileless", 
    "hackneyed", "inane", "jejune", "kindle", "languor"
};

int nwords = sizeof(words) / sizeof(char*);

int random_word() {
    srand(time(NULL));
    return rand() % nwords;
}

int main() {
    printf("Welcome to the Typing Speed Test program\n");
    printf("Type the following words as quickly and as accurately as possible\n\n");

    int i, correct = 0, incorrect = 0;
    double elapsed_time;

    clock_t start_time, end_time;
    start_time = clock();

    for (i = 0; i < 10; i++) {
        int word_index = random_word();
        char* word = words[word_index];

        printf("Word %d: %s\n", i + 1, word);

        char input[100];
        scanf("%s", input);

        if (strcmp(word, input) == 0) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect!\n");
            incorrect++;
        }

        printf("\n");
    }

    end_time = clock();
    elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Test Result:\n");
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Elapsed Time: %.2f seconds\n", elapsed_time);
    printf("Typing Speed: %.2f words per minute\n", (correct * 60.0 / elapsed_time));

    return 0;
}