#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define LOG_FILE "logs.log"

void log_message(char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Error opening logs.log");
        return;
    }

    fputs(message, file);
    fputc('\n', file);
    fclose(file);
}

void process_logs(char *input_line) {
    char token[BUFFER_SIZE];
    char* tokenizer = strtok(input_line, " ");
    int i = 0;

    while (tokenizer != NULL) {
        strcpy(token, tokenizer);
        printf("Processing token %s\n", token);

        // Forgotten memory dereference
        int num = atoi(token);
        int* ptr = (int*)malloc(sizeof(int));
        *ptr = num * num;

        tokenizer = strtok(NULL, " ");
        i++;
    }
}

int main(int argc, char *argv[]) {
    char input_line[BUFFER_SIZE];

    while (1) {
        printf("Enter a log message: ");
        fgets(input_line, BUFFER_SIZE, stdin);
        process_logs(input_line);
    }

    return 0;
}
