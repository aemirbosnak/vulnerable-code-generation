//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define MAX_WORDS 50

struct word {
    char word[20];
    int length;
};

void get_words(struct word words[], int num_words) {
    int i;
    FILE *file;
    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (i = 0; i < num_words; i++) {
        fscanf(file, "%s", words[i].word);
        words[i].length = strlen(words[i].word);
    }
    fclose(file);
}

int main() {
    int num_words, i, j, correct_count = 0, incorrect_count = 0, total_count = 0, score = 0;
    double accuracy;
    char input[20];
    struct word words[MAX_WORDS];
    srand(time(NULL));
    printf("Welcome to the Typing Speed Test!\n");
    printf("How many words would you like to type? (Max: %d)\n", MAX_WORDS);
    scanf("%d", &num_words);
    get_words(words, num_words);
    printf("Please type the following words:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\n", words[i].word);
    }
    for (i = 0; i < num_words; i++) {
        printf("Please type word %d: ", i + 1);
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character
        if (strcmp(input, words[i].word) == 0) {
            correct_count++;
        } else {
            incorrect_count++;
        }
        total_count++;
    }
    accuracy = (double)correct_count / total_count * 100;
    score = (int)(accuracy * 100);
    printf("\nYou scored %d out of %d words correctly (%.2f%% accuracy).\n", correct_count, num_words, accuracy);
    return 0;
}