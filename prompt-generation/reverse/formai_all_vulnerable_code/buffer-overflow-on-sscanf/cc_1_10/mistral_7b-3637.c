//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define WORD_LENGTH 50
#define MAGIC_WORDS_COUNT 100

typedef struct {
    char word[WORD_LENGTH];
    int is_magic;
} word_t;

word_t magic_words[MAGIC_WORDS_COUNT];

void load_magic_words(char *filename) {
    int fd, i;
    char line[100];

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < MAGIC_WORDS_COUNT; i++) {
        if (fgets(line, sizeof(line), fd) == NULL) {
            break;
        }
        sscanf(line, "%s%n", magic_words[i].word, &line[strlen(magic_words[i].word)]);
        magic_words[i].is_magic = 1;
    }

    close(fd);
}

int is_magic_word(char *word) {
    int i;
    for (i = 0; i < MAGIC_WORDS_COUNT; i++) {
        if (strcmp(magic_words[i].word, word) == 0) {
            return magic_words[i].is_magic;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_magic_words("magic_words.txt");

    int fd, i, j;
    char line[1024];
    char *token;

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (read(fd, line, sizeof(line)) > 0) {
        token = strtok(line, " ");
        while (token != NULL) {
            if (strlen(token) > WORD_LENGTH) {
                printf("Warning: word too long: %s\n", token);
                token = strtok(NULL, " ");
                continue;
            }

            if (is_magic_word(token)) {
                printf("Magic word found: %s\n", token);
            } else {
                for (i = 0; i < strlen(token); i++) {
                    for (j = 0; j < strlen(token); j++) {
                        if (token[i] == token[j] && i != j) {
                            printf("Warning: repeated character: %s\n", token);
                            break;
                        }
                    }
                    if (token[i] < 'a' || token[i] > 'z') {
                        printf("Warning: non-alphabetic character: %s\n", token);
                        break;
                    }
                }
            }

            token = strtok(NULL, " ");
        }
    }

    close(fd);
    return EXIT_SUCCESS;
}