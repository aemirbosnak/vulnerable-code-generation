#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

void log_message(const char *message) {
    char log_file[200] = "log.txt";
    FILE *fp = fopen(log_file, "a");

    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open log file.\n");
        return;
    }

    fprintf(fp, "%s\n", message);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);
    printf("You entered: %s\n", input);

    // The vulnerability is in the following loop that writes the input buffer back to the input buffer
    int i;
    for (i = 0; i < strlen(input); i++) {
        input[i] = input[i] + 1;
    }

    log_message(input);
    printf("Logged message: %s\n", input);

    return 0;
}
