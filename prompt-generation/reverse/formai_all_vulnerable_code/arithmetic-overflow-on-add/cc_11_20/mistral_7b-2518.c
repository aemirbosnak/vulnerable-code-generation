//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define MAX_WORD_LENGTH 50
#define WORD_DELIMITER " ,.!?\n"

int main(int argc, char **argv) {
    int file_fd, i, word_count = 0;
    char *file_buffer, word[MAX_WORD_LENGTH];

    // Check if file path is provided as an argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    // Open the file with given file path
    if ((file_fd = open(argv[1], O_RDONLY)) == -1) {
        perror("Error opening file");
        return 1;
    }

    // Calculate file size and allocate memory for the buffer
    off_t file_size = lseek(file_fd, 0, SEEK_END);
    file_buffer = malloc(file_size + 1);

    // Read the file content into the buffer
    if (read(file_fd, file_buffer, file_size) != file_size) {
        perror("Error reading file");
        free(file_buffer);
        close(file_fd);
        return 1;
    }

    // Set the last read character to null character
    file_buffer[file_size] = '\0';

    // Loop through the file content and count words
    for (i = 0; i <= file_size; i++) {
        // Find the start of a word
        while (i < file_size && strchr(WORD_DELIMITER, file_buffer[i]) != NULL) {
            i++;
        }

        // Find the end of a word
        int j = i;
        while (j < file_size && strchr(WORD_DELIMITER, file_buffer[j]) == NULL) {
            j++;
        }

        // Increment the word count if a valid word is found
        if (i < file_size && j < file_size) {
            strncpy(word, &file_buffer[i], j - i);
            word[j - i] = '\0';
            word_count++;
        }

        // Update the current position in the file buffer
        i = j;
    }

    // Print the word count in a post-apocalyptic style
    printf("In the ruins of civilization, we found %d words.\n", word_count);

    // Free the allocated memory and close the file
    free(file_buffer);
    close(file_fd);

    return 0;
}