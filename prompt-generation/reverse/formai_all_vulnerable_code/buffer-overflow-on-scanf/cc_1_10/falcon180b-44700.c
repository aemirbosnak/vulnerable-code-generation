//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20
#define MAX_LINE_LENGTH 80

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int num_words;

void generate_random_words(int num_words) {
    FILE *fp = fopen("words.txt", "r");
    char line[MAX_LINE_LENGTH];
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *word = strtok(line, " ");

        while (word!= NULL) {
            if (strlen(word) > 0 && strlen(word) <= MAX_WORD_LENGTH) {
                strcpy(words[i].word, word);
                words[i].length = strlen(word);
                i++;

                if (i >= num_words) {
                    break;
                }
            }

            word = strtok(NULL, " ");
        }
    }

    fclose(fp);
}

int main() {
    srand(time(NULL));

    printf("Enter the number of words to type: ");
    scanf("%d", &num_words);

    generate_random_words(num_words);

    int score = 0;
    int correct_words = 0;
    int incorrect_words = 0;

    for (int i = 0; i < num_words; i++) {
        printf("Type the word '%s': ", words[i].word);

        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i].word) == 0) {
            correct_words++;
            score += words[i].length;
        } else {
            incorrect_words++;
        }
    }

    printf("Your final score is %d out of %d\n", score, num_words * words[0].length);
    printf("You got %d words correct and %d words incorrect\n", correct_words, incorrect_words);

    return 0;
}