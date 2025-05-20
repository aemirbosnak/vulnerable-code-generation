//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_CHARS 10000
#define FILENAME "typing_speed_test.txt"
#define BUFFER_SIZE 4096

typedef struct {
    char filename[100];
    int chars_typed;
    int start_time;
    int end_time;
    int accuracy;
} TypingTestResult;

void generate_random_string(char *str, int len) {
    int i;
    for (i = 0; i < len; i++) {
        str[i] = (char)(rand() % 128);
    }
    str[len] = '\0';
}

void write_file(char *filename, char *content) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(fd, content, strlen(content));
    close(fd);
}

void print_result(TypingTestResult result) {
    printf("\n----------------------------------------\n");
    printf("Filename: %s\n", result.filename);
    printf("Chars typed: %d\n", result.chars_typed);
    printf("Accuracy: %.2f%%\n", (float)result.chars_typed / (float)MAX_CHARS * 100);
    printf("Time taken: %d ms\n", result.end_time - result.start_time);
    printf("----------------------------------------\n");
}

int main() {
    srand(time(NULL));

    TypingTestResult result;
    strcpy(result.filename, FILENAME);
    result.start_time = time(NULL) * 1000;

    write_file(FILENAME, "");
    generate_random_string(result.filename + strlen(FILENAME), MAX_CHARS);

    int fd = open(FILENAME, O_RDONLY);
    char buffer[BUFFER_SIZE];
    int chars_typed = 0;

    printf("Filename: %s\n", FILENAME);
    printf("Press Enter to begin the test...\n");
    getchar();

    int start_time = time(NULL) * 1000;
    while (read(fd, buffer, BUFFER_SIZE)) {
        for (int i = 0; i < strlen(buffer); i++) {
            char input;
            scanf(" %c", &input);

            if (input == buffer[i]) {
                chars_typed++;
            }
        }
    }

    result.end_time = time(NULL) * 1000;
    result.chars_typed = chars_typed;

    close(fd);
    print_result(result);

    return 0;
}