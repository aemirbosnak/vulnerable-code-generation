//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;

void generate_words() {
    FILE *file;
    char word[MAX_WORD_LENGTH];

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Could not open words.txt\n");
        exit(1);
    }

    num_words = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[num_words], word);
        num_words++;
    }

    fclose(file);
}

void display_word(int index) {
    printf("%s", words[index]);
}

int main() {
    srand(time(NULL));

    generate_words();
    int word_index = rand() % num_words;

    printf("You have 30 seconds to type the following word:\n");
    display_word(word_index);

    int start_time = time(NULL);
    char input[MAX_WORD_LENGTH];
    int input_length = 0;

    while (input_length < strlen(words[word_index]) && time(NULL) - start_time < 30) {
        if (read(0, &input[input_length], 1)!= 1) {
            printf("Error reading input\n");
            exit(1);
        }

        if (input[input_length] == '\n') {
            input_length = strlen(input) - 1;
        } else {
            input_length++;
        }
    }

    if (input_length == strlen(words[word_index]) && input_length > 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect.\n");
    }

    return 0;
}