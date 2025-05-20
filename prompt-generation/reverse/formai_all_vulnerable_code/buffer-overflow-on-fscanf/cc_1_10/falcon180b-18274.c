//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

struct line {
    char text[MAX_LINE_LENGTH];
    int length;
    int count;
};

void read_file(FILE* file, struct line* lines, int num_lines) {
    char ch;
    int i = 0;
    while (fscanf(file, "%c", &ch)!= EOF) {
        if (i >= num_lines) {
            printf("Error: Maximum number of lines exceeded.\n");
            exit(1);
        }
        lines[i].length = strlen(lines[i].text);
        lines[i].count = 0;
        strcat(lines[i].text, ch);
        i++;
    }
}

void count_words(struct line* lines, int num_lines) {
    int i;
    for (i = 0; i < num_lines; i++) {
        char* word = strtok(lines[i].text, " ");
        while (word!= NULL) {
            lines[i].count++;
            word = strtok(NULL, " ");
        }
    }
}

void print_line(struct line line) {
    printf("Line %d: %s (%d words)\n", line.count, line.text, line.count);
}

void print_lines(struct line* lines, int num_lines) {
    int i;
    for (i = 0; i < num_lines; i++) {
        print_line(lines[i]);
    }
}

int main() {
    FILE* file;
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    int num_lines;
    printf("Enter number of lines to read: ");
    scanf("%d", &num_lines);
    struct line lines[MAX_NUM_LINES];
    read_file(file, lines, num_lines);
    count_words(lines, num_lines);
    print_lines(lines, num_lines);
    fclose(file);
    return 0;
}