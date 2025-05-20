//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define WORD_LENGTH 50
#define NUM_WORDS 10
#define BUFFER_SIZE 2048
#define FILE_NAME "words.txt"

void read_words(char *buffer) {
    int fd;
    struct stat st;

    fd = open(FILE_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (fstat(fd, &st) == -1) {
        perror("Error getting file size");
        exit(EXIT_FAILURE);
    }

    read(fd, buffer, st.st_size);
    close(fd);
}

void print_word(char *word) {
    printf("%s ", word);
}

void test(char *buffer) {
    char *words[NUM_WORDS];
    char *token;
    int i = 0;
    char input[WORD_LENGTH];

    token = strtok(buffer, " \n");
    while (token != NULL && i < NUM_WORDS) {
        words[i] = token;
        i++;
        token = strtok(NULL, " \n");
    }

    printf("\nTyping Speed Test:\n");
    for (int j = 0; j < NUM_WORDS; j++) {
        printf("\nType the following word: %s\n", words[j]);
        scanf("%s", input);
        while (strcmp(input, words[j]) != 0) {
            printf("Incorrect! Try again: ");
            scanf("%s", input);
        }
        printf("Correct! Next word:\n");
    }

    printf("\nCongratulations! You passed the typing speed test.\n");
}

int main() {
    char buffer[BUFFER_SIZE];
    char *words[NUM_WORDS];

    read_words(buffer);
    test(buffer);

    return 0;
}

// words.txt contains 10 unique words, one per line.