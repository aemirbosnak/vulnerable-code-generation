//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int word_count;

void load_words() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int i = 0;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[i], word);
        i++;
    }

    word_count = i;
    fclose(file);
}

void shuffle_words() {
    for (int i = 0; i < word_count; i++) {
        int j = rand() % word_count;
        char temp[MAX_WORD_LENGTH];

        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }
}

int main() {
    load_words();
    shuffle_words();

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will be typing the following words:\n");

    for (int i = 0; i < word_count; i++) {
        printf("%s ", words[i]);
    }

    printf("\n\nPress enter to start the test.\n");
    getchar();

    clock_t start_time = clock();

    for (int i = 0; i < word_count; i++) {
        printf("%s ", words[i]);
        fflush(stdout);

        char input[MAX_WORD_LENGTH];
        scanf("%s", input);

        if (strcmp(input, words[i])!= 0) {
            printf("\nIncorrect input!\n");
            return 1;
        }
    }

    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n\nTest complete! Your typing speed is %.2f WPM.\n", word_count / elapsed_time);

    return 0;
}