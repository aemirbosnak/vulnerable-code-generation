//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdint.h>

#define MAX_QUESTIONS 10
#define FILENAME_LEN 100
#define FILE_MODE 0644

typedef struct {
    char question[MAX_QUESTIONS][128];
    char answer[MAX_QUESTIONS][128];
} fortune_data_t;

void load_fortune_file(char *filename, fortune_data_t *data) {
    FILE *fp;
    int i = 0;
    char line[256];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp) != NULL && i < MAX_QUESTIONS) {
        sscanf(line, "%[^:]: %s", data->question[i], data->answer[i]);
        i++;
    }

    fclose(fp);
}

void print_fortune(fortune_data_t data, int seed) {
    int i = 0;
    int rand_num;
    char *question;
    char *answer;

    srand(seed);
    rand_num = rand() % MAX_QUESTIONS;

    question = data.question[rand_num];
    answer = data.answer[rand_num];

    printf("Question: %s", question);
    printf("\nAnswer: %s\n", answer);
}

int main(int argc, char *argv[]) {
    fortune_data_t data;
    int seed;

    if (argc != 2) {
        printf("Usage: %s <seed>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    seed = atoi(argv[1]);

    if (access("fortunes.txt", F_OK) != 0) {
        perror("File not found");
        exit(EXIT_FAILURE);
    }

    load_fortune_file("fortunes.txt", &data);

    print_fortune(data, seed);

    return EXIT_SUCCESS;
}