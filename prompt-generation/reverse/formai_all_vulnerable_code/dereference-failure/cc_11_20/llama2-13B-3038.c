//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_LOG_SIZE 100000

struct word {
    char *word;
    int count;
};

struct stats {
    int num_words;
    int total_occurrences;
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    // Open the log file
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening log file");
        return 2;
    }

    // Get the file size
    struct stat stat_info;
    fstat(fd, &stat_info);
    int log_size = stat_info.st_size;

    // Mmap the log file into memory
    char *log_buffer = mmap(NULL, log_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (log_buffer == MAP_FAILED) {
        perror("Error mapping log file into memory");
        return 3;
    }

    // Parse the log file and count the number of occurrences of each word
    struct word *words = calloc(1, sizeof(struct word));
    int word_index = 0;
    for (int i = 0; i < log_size; i++) {
        char c = log_buffer[i];
        if (c == ' ' || c == '\t' || c == '\n') {
            // Ignore whitespace and newlines
            continue;
        }

        // Find the end of the current word
        int word_end = i;
        while (word_end > 0 && log_buffer[word_end - 1] != ' ' && log_buffer[word_end - 1] != '\t') {
            word_end--;
        }

        // Add the word to the list of words
        struct word *new_word = calloc(1, sizeof(struct word));
        new_word->word = log_buffer + word_end + 1;
        new_word->count = 1;
        words[word_index++] = *new_word;
    }

    // Generate the report
    struct stats stats;
    stats.num_words = word_index;
    stats.total_occurrences = 0;
    for (int i = 0; i < word_index; i++) {
        struct word *word = words + i;
        stats.total_occurrences += word->count;
    }

    // Print the report
    printf("Log Analysis Report\n");
    printf("-----------------\n");
    printf("Number of words: %d\n", stats.num_words);
    printf("Total occurrences: %d\n", stats.total_occurrences);

    // Print the list of words and their occurrences
    for (int i = 0; i < word_index; i++) {
        struct word *word = words + i;
        printf("%s (%d occurrences)\n", word->word, word->count);
    }

    // Clean up
    munmap(log_buffer, log_size);
    free(words);

    return 0;
}