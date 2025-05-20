//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char *text;
    int length;
    int difficulty;
} Text;

Text *generate_text(int length, int difficulty) {
    Text *text = malloc(sizeof(Text));
    char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    int word_count = 0;
    int word_length = 0;
    char *text_buffer = malloc(length + 1);
    text_buffer[0] = '\0';

    srand(time(NULL));

    while (word_count < length) {
        int word_index = rand() % 9;
        strcat(text_buffer, words[word_index]);
        word_count++;
        word_length += strlen(words[word_index]) + 1;
    }

    text->text = text_buffer;
    text->length = length;
    text->difficulty = difficulty;

    return text;
}

void print_text(Text *text) {
    printf("%s\n", text->text);
}

int main() {
    int length, difficulty;
    Text *text;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("Please enter the length of the text you would like to type:\n");
    scanf("%d", &length);

    printf("Please enter the difficulty level (1-5):\n");
    scanf("%d", &difficulty);

    text = generate_text(length, difficulty);
    print_text(text);

    int start_time = clock();
    char input_buffer[length + 1];
    fgets(input_buffer, length + 1, stdin);
    int end_time = clock();

    int elapsed_time = (end_time - start_time) / CLOCKS_PER_SEC;

    printf("You typed %d characters in %d seconds.\n", strlen(input_buffer), elapsed_time);

    return 0;
}