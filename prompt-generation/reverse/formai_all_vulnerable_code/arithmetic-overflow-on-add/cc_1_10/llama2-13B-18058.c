//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 1024
#define MAX_LINES 1024

// Structure to hold the search state
typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t current_line;
    size_t start_position;
    size_t end_position;
} search_state_t;

// Function to search for the word in a file
search_state_t *search_file(const char *filename, const char *word) {
    // Open the file in read-only mode
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }

    // Get the file size
    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("Error getting file size");
        close(fd);
        return NULL;
    }

    // Calculate the number of buffers needed
    size_t num_buffers = (file_stat.st_size + BUFFER_SIZE - 1) / BUFFER_SIZE;

    // Allocate the search state
    search_state_t *state = calloc(1, sizeof(search_state_t));
    state->buffer = calloc(num_buffers, BUFFER_SIZE);
    state->buffer_size = num_buffers * BUFFER_SIZE;
    state->current_line = 0;
    state->start_position = 0;
    state->end_position = 0;

    // Read the file into the buffers
    off_t file_position = 0;
    for (size_t i = 0; i < num_buffers; i++) {
        size_t bytes_read = read(fd, state->buffer + i * BUFFER_SIZE, BUFFER_SIZE);
        if (bytes_read == -1) {
            perror("Error reading from file");
            close(fd);
            free(state->buffer);
            free(state);
            return NULL;
        }
        file_position += bytes_read;
    }

    // Search for the word in each buffer
    for (size_t i = 0; i < num_buffers; i++) {
        size_t start = state->start_position;
        size_t end = state->end_position;
        if (strstr(state->buffer + start, word) != NULL) {
            state->current_line = i;
            state->start_position = start;
            state->end_position = end;
        }
    }

    // Close the file
    close(fd);

    return state;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file> <word>\n", argv[0]);
        return 1;
    }

    // Search for the word in the file
    search_state_t *state = search_file(argv[1], argv[2]);
    if (state == NULL) {
        perror("Error searching for word");
        return 2;
    }

    // Print the line number and contents where the word was found
    printf("Found word at line %zu, starting at position %zu\n", state->current_line + 1, state->start_position + 1);
    printf("Contents of line: %s\n", state->buffer + state->start_position + 1);

    // Clean up
    free(state->buffer);
    free(state);

    return 0;
}