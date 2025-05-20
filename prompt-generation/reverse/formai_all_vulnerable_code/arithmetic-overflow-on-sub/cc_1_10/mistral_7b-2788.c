//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define TEXT_FILE "shannon.txt"
#define BUFFER_SIZE 4096
#define MAX_CHARS 256
#define RANDOM_DELAY 10

void generate_random_string(char *str, int length) {
    int i;
    for (i = 0; i < length; i++) {
        str[i] = 'A' + rand() % 26;
    }
    str[length] = '\0';
}

void save_text_file(char *content) {
    int fd = open(TEXT_FILE, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    if (write(fd, content, strlen(content)) < 0) {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }

    close(fd);
}

void print_random_string(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
        usleep(RANDOM_DELAY * 1000);
    }
    printf("\n");
}

int main() {
    char text[MAX_CHARS];
    char random_text[MAX_CHARS];
    int text_length, random_text_length;
    struct stat file_stats;
    clock_t start, end;
    double elapsed_time;

    if (stat(TEXT_FILE, &file_stats) < 0) {
        perror("Error getting file stats");
        exit(EXIT_FAILURE);
    }

    text_length = file_stats.st_size;
    random_text_length = text_length > MAX_CHARS ? MAX_CHARS : text_length;

    if (text_length > 0) {
        int fd = open(TEXT_FILE, O_RDONLY);
        if (fd < 0) {
            perror("Error opening file for reading");
            exit(EXIT_FAILURE);
        }

        if (read(fd, text, text_length) < 0) {
            perror("Error reading from file");
            exit(EXIT_FAILURE);
        }

        close(fd);
    } else {
        generate_random_string(text, text_length = random_text_length);
        save_text_file(text);
    }

    generate_random_string(random_text, random_text_length);

    start = clock();
    print_random_string(text);
    print_random_string(random_text);
    end = clock();

    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Typing speed: %f characters per second\n", elapsed_time * 256);

    return 0;
}