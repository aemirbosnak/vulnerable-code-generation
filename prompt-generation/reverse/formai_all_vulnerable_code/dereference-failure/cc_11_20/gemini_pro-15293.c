//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

#define CACHE_LINE_SIZE 64
#define PAGE_SIZE 4096

typedef struct {
    int64_t timestamp;
    uint32_t value;
} cache_line_t;

int main(int argc, char *argv[]) {
    // Parse command-line arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open input and output files.
    int input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    int output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Allocate memory for input and output buffers.
    size_t input_buffer_size = PAGE_SIZE;
    char *input_buffer = malloc(input_buffer_size);
    if (input_buffer == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    size_t output_buffer_size = PAGE_SIZE;
    char *output_buffer = malloc(output_buffer_size);
    if (output_buffer == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Read input file into input buffer.
    ssize_t input_bytes_read = read(input_fd, input_buffer, input_buffer_size);
    if (input_bytes_read == -1) {
        perror("read");
        return EXIT_FAILURE;
    }


    // Process input buffer.
    int64_t previous_timestamp = 0;
    uint32_t previous_value = 0;
    int64_t current_timestamp = 0;
    uint32_t current_value = 0;
    int64_t delta_timestamp = 0;
    uint32_t delta_value = 0;

    int latency = 0;
    int period = 0;

    for (int i = 0; i < input_bytes_read; i += CACHE_LINE_SIZE) {
        // Get the timestamp and value from the cache line.
        memcpy(&current_timestamp, input_buffer + i, sizeof(int64_t));
        memcpy(&current_value, input_buffer + i + sizeof(int64_t), sizeof(uint32_t));

        // Calculate the delta timestamp and delta value.
        delta_timestamp = current_timestamp - previous_timestamp;
        delta_value = current_value - previous_value;

	// Calculate the latency
	if (delta_timestamp == 0) {

	} else {
		latency += (delta_timestamp / 2);
	} 

	// Calculate the period
	period += delta_timestamp;

        // Update the previous timestamp and value.
        previous_timestamp = current_timestamp;
        previous_value = current_value;

	if (delta_timestamp != 0) {
	    period = period / delta_timestamp;
	}
    }

    // Write output buffer to output file.
    ssize_t output_bytes_written = write(output_fd, output_buffer, output_buffer_size);
    if (output_bytes_written == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Print results
    printf("Latency: %d\n", latency);
    printf("Period: %d\n", period);

    // Close input and output files.
    close(input_fd);
    close(output_fd);

    // Free memory.
    free(input_buffer);
    free(output_buffer);

    return EXIT_SUCCESS;
}