//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50 // maximum number of words in the sentence
#define MAX_LENGTH 15 // maximum length of each word

int main() {
    char sentence[MAX_WORDS][MAX_LENGTH]; // array to store the words
    int i, j, typed = 0, correct = 0;
    float accuracy, speed;
    time_t start_time, end_time;

    // array of sample sentences for typing test
    char sample_sentences[5][80] = {
        "The quick brown fox jumps over the lazy dog.",
        "Jackdaws love my big sphinx of quartz.",
        "Pack my box with five dozen liquor jugs.",
        "How vexingly quick daft zebras jump!",
        "Waltz, bad nymph, for quick jigs vex."
    };

    // generate a random sentence from the sample sentences
    srand(time(NULL));
    int index = rand() % 5;
    char *sentence_ptr = sample_sentences[index];
    printf("Type the following sentence:\n%s\n", sentence_ptr);

    // split the sentence into words and store in the array
    i = 0;
    while (*sentence_ptr != '\0') {
        if (*sentence_ptr == ' ') {
            sentence[i][j] = '\0';
            i++;
            j = 0;
        }
        else {
            sentence[i][j] = *sentence_ptr;
            j++;
        }
        sentence_ptr++;
    }
    sentence[i][j] = '\0';

    start_time = time(NULL); // get start time

    // prompt user to type the words
    for (int k = 0; k <= i; k++) {
        printf("%s ", sentence[k]);
        char typed_word[MAX_LENGTH];
        scanf("%s", typed_word);
        typed++;
        if (strcmp(typed_word, sentence[k]) == 0) {
            correct++;
        }
    }

    end_time = time(NULL); // get end time

    accuracy = (float) correct / typed * 100;
    speed = (float) typed / difftime(end_time, start_time) * 60;

    printf("\n\nResults:\n");
    printf("Words typed: %d\n", typed);
    printf("Words correct: %d\n", correct);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Typing speed: %.2f words per minute\n", speed);

    return 0;
}