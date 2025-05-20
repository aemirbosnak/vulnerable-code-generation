//FormAI DATASET v1.0 Category: Data mining ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int total_scores = 0;
    float average_score = 0.0;
    int count = 0;
    int max_score = 0;
    char max_name[MAX_LINE_LENGTH];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        exit(1);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char name[MAX_LINE_LENGTH];
        int score;
        sscanf(line, "%s %d\n", name, &score);
        total_scores += score;
        count++;

        if (score > max_score) {
            max_score = score;
            strcpy(max_name, name);
        }
    }

    fclose(fp);

    if (count > 0) {
        average_score = (float) total_scores / count;
    }

    printf("Total number of students in class: %d\n", count);
    printf("Average score of class: %.2f\n", average_score);
    printf("Maximum score in class: %d\n", max_score);
    printf("Name of student with maximum score: %s\n", max_name);

    return 0;
}