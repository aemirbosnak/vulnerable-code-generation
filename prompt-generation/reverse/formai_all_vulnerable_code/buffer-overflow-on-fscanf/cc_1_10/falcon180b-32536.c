//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define WORD_LENGTH_MIN 5
#define WORD_LENGTH_MAX 15

typedef struct {
    char word[MAX_WORDS][WORD_LENGTH_MAX];
    int length;
} word_list;

word_list generate_words() {
    word_list words;
    words.length = 0;
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }
    char buffer[WORD_LENGTH_MAX];
    while (fscanf(file, "%s", buffer)!= EOF) {
        if (strlen(buffer) >= WORD_LENGTH_MIN && strlen(buffer) <= WORD_LENGTH_MAX) {
            strcpy(words.word[words.length], buffer);
            words.length++;
        }
    }
    fclose(file);
    return words;
}

int main() {
    srand(time(NULL));
    word_list words = generate_words();
    int num_words = rand() % words.length + 1;
    int score = 0;
    char word_to_type[WORD_LENGTH_MAX];
    for (int i = 0; i < num_words; i++) {
        int index = rand() % words.length;
        strcpy(word_to_type, words.word[index]);
        printf("Type the following word: ");
        for (int j = 0; j < strlen(word_to_type); j++) {
            if (isalpha(word_to_type[j])) {
                printf("_");
            } else {
                printf("%c", word_to_type[j]);
            }
        }
        printf("\n");
        char input[WORD_LENGTH_MAX];
        fgets(input, WORD_LENGTH_MAX, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, word_to_type) == 0) {
            score++;
        }
    }
    printf("Your final score is: %d out of %d\n", score, num_words);
    return 0;
}