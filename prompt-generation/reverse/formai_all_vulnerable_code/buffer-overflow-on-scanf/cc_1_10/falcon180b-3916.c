//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100

struct word {
    char text[MAX_WORD_LENGTH];
    int length;
};

struct word words[MAX_WORDS];
int num_words;

void load_words(char* filename) {
    FILE* file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH];
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        line[strcspn(line, "\n")] = '\0';
        strcpy(words[i].text, line);
        words[i].length = strlen(line);
        i++;
    }

    fclose(file);
    num_words = i;
}

void shuffle_words() {
    for (int i = 0; i < num_words; i++) {
        int j = rand() % num_words;
        struct word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

void print_word(struct word word) {
    for (int i = 0; i < word.length; i++) {
        printf("%c", word.text[i]);
    }
}

void print_stats(int correct, int incorrect, int total) {
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Total: %d\n", total);
}

int main() {
    srand(time(NULL));

    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    load_words(filename);
    shuffle_words();

    int correct = 0;
    int incorrect = 0;
    int total = 0;

    printf("Press enter to start...\n");
    getchar();

    struct word word;
    char input[MAX_WORD_LENGTH];

    while (1) {
        print_word(word);
        printf(" ");

        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, word.text) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        total++;

        if (total == num_words) {
            break;
        }

        word = words[total % num_words];
    }

    print_stats(correct, incorrect, total);

    return 0;
}