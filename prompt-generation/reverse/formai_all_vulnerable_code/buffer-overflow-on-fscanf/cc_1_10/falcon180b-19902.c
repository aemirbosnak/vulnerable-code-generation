//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char text[MAX_WORD_LENGTH];
    int length;
};

void generate_words(struct word words[]) {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s", words[count].text)!= EOF) {
        words[count].length = strlen(words[count].text);
        count++;
    }

    fclose(fp);
}

int main() {
    struct word words[MAX_WORDS];
    generate_words(words);

    int num_words = rand() % MAX_WORDS;
    int total_length = 0;

    for (int i = 0; i < num_words; i++) {
        int word_index = rand() % MAX_WORDS;
        total_length += words[word_index].length;
    }

    printf("You will be typing %d words with a total length of %d characters.\n", num_words, total_length);

    srand(time(NULL));
    int correct_count = 0;
    int incorrect_count = 0;

    for (int i = 0; i < num_words; i++) {
        int word_index = rand() % MAX_WORDS;
        char *word = words[word_index].text;
        int length = words[word_index].length;

        char input[MAX_WORD_LENGTH];
        printf("Type the word '%s': ", word);
        fgets(input, MAX_WORD_LENGTH, stdin);

        int j;
        for (j = 0; j < length; j++) {
            if (input[j]!= word[j]) {
                break;
            }
        }

        if (j == length) {
            correct_count++;
        } else {
            incorrect_count++;
        }
    }

    int accuracy = (100 * correct_count) / (correct_count + incorrect_count);

    printf("You typed %d words correctly and %d words incorrectly.\n", correct_count, incorrect_count);
    printf("Your accuracy is %.2f%%\n", accuracy);

    return 0;
}