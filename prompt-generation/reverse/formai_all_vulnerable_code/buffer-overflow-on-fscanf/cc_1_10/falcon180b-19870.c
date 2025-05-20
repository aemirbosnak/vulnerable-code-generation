//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50
#define WORD_LENGTH_MIN 3
#define WORD_LENGTH_MAX 10

char words[MAX_WORDS][20];
int word_count = 0;
int word_length = 0;

void generate_word() {
    char word[WORD_LENGTH_MAX];
    int i;
    for (i = 0; i < word_length; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[word_length] = '\0';
    strcpy(words[word_count], word);
    word_count++;
}

void load_words() {
    char word[20];
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open words.txt\n");
        exit(1);
    }
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[word_count], word);
        word_count++;
    }
    fclose(file);
    if (word_count == 0) {
        printf("Error: words.txt is empty\n");
        exit(1);
    }
}

int main() {
    srand(time(NULL));
    load_words();
    int i;
    for (i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
    }
    int correct = 0;
    int incorrect = 0;
    char input[20];
    int start_time = clock();
    while (1) {
        printf("Enter your guess: ");
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, words[i]) == 0) {
            correct++;
        } else {
            incorrect++;
        }
        i++;
        if (i >= word_count) {
            break;
        }
    }
    int end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("You got %d correct and %d incorrect\n", correct, incorrect);
    printf("Your typing speed is %.2f words per minute\n",
        word_count / (elapsed_time / 60.0));
    return 0;
}