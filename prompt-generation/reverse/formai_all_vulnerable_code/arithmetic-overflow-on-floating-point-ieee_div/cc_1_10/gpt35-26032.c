//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ERRORS 5
#define MAX_TIME 60 // time in seconds
#define SENTENCE_LENGTH 100

char *generate_sentence() {
    char *sentences[] = {"The quick brown fox jumps over the lazy dog.", 
                         "The five boxing wizards jump quickly.", 
                         "Pack my box with five dozen liquor jugs.",
                         "Sphinx of black quartz, judge my vow.",
                         "The quick onyx goblin jumps over the lazy dwarf.",
                         "How vexingly quick daft zebras jump!",
                         "Two driven jocks help fax my big quiz.",
                         "Jackdaws love my big sphinx of quartz.",
                         "The jay, pig, fox, zebra and my wolves quack!",
                         "The five boxing wizards jump quickly."};
    int random = rand() % 10;
    return sentences[random];
}

int main() {
    srand(time(NULL)); // seed for random number generation
    int errors = 0;
    int correct_chars = 0;
    int incorrect_chars = 0;
    float time_elapsed = 0.0;
    char input[SENTENCE_LENGTH];

    printf("Type the following sentence as quickly and accurately as possible:\n");
    char *sentence = generate_sentence();
    printf("%s\n", sentence);

    time_t start_time = time(NULL); // get start time
    while (time_elapsed < MAX_TIME) {
        fgets(input, SENTENCE_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character from input
        if (strcmp(input, sentence) == 0) {
            printf("Congratulations! You typed the sentence correctly.\n");
            break;
        } else {
            // loop through each character and compare it to the sentence
            for (int i = 0; i < strlen(sentence); i++) {
                if (i >= strlen(input) || input[i] != sentence[i]) {
                    incorrect_chars++;
                    if (errors < MAX_ERRORS) {
                        printf("Incorrect character '%c'. Try again.\n", input[i]);
                        errors++;
                    }
                } else {
                    correct_chars++;
                }
            }
        }
        // calculate time elapsed
        time_elapsed = difftime(time(NULL), start_time);
    }

    // calculate and print WPM and accuracy
    float wpm = (float)correct_chars / 5 / time_elapsed * 60;
    float accuracy = (float)correct_chars / (correct_chars + incorrect_chars) * 100;
    printf("Your typing speed is %.2f WPM with an accuracy of %.2f%%.\n", wpm, accuracy);

    return 0;
}