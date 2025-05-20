//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stdint.h>

#define MAX_WORD_LEN 50
#define BUF_SIZE 1024

typedef uint32_t word_count_t;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file> <word>\n", argv[0]);
        return 1;
    }

    const char *file_name = argv[1];
    const char *search_word = argv[2];
    char encoding[10] = {0}; // assuming UTF-8 by default

    FILE *fp = NULL;
    size_t file_size = 0;
    char *file_buffer = NULL;

    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    file_buffer = (char *)calloc(file_size + 1, sizeof(char));
    if (file_buffer == NULL) {
        perror("Memory allocation failed");
        fclose(fp);
        return 1;
    }

    size_t read_size = fread(file_buffer, 1, file_size, fp);
    if (read_size != file_size) {
        perror("Error reading file");
        free(file_buffer);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    setlocale(LC_ALL, ""); // enable locale support for wcswidth()

    word_count_t word_count = 0;
    int pos = 0;
    while ((pos = strcspn(file_buffer, "\n")) < file_size) {
        size_t word_len = wcswidth(NULL, &file_buffer[pos]) + pos;
        if (word_len > MAX_WORD_LEN) {
            break;
        }

        char word[MAX_WORD_LEN + 1] = {0};
        strncpy(word, &file_buffer[pos], MAX_WORD_LEN);
        for (size_t i = 0; i < strlen(search_word); i++) {
            if (strncmp(&word[pos + i], search_word, strlen(search_word)) == 0) {
                word_count++;
                break;
            }
        }

        pos += word_len;
    }

    printf("Word '%s' appears %lu times in the file.\n", search_word, word_count);

    free(file_buffer);
    return 0;
}