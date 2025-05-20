#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void log_message(char *message) {
    char log_file[BUFFER_SIZE];
    snprintf(log_file, BUFFER_SIZE, "/temp/log_%d.txt", getpid());
    FILE *log_file_ptr = fopen(log_file, "a+");
    fprintf(log_file_ptr, "%s\n", message);
    fclose(log_file_ptr);
}

void process_input(char *input) {
    char buffer[256];
    char *token = strtok(input, " ");
    int counter = 0;
    while (token != NULL) {
        counter += sscanf(token, "%255s", buffer);
        token = strtok(NULL, " ");
    }
    log_message(buffer);
}

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage: %s <input_message>\n", argv[0]);
        return 1;
    }

    strcpy(buffer, argv[1]);

    for (int i = 0; i < 1000000; ++i) {
        printf("Inputting data...\n");
        process_input(buffer);
    }

    return 0;
}
