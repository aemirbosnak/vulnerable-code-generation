#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_MAX 100
#define FILE_NAME "temp.txt"

void display_file() {
    FILE *fp = fopen(FILE_NAME, "r");
    char line[LINE_MAX];
    int count = 0;
    while (fgets(line, LINE_MAX, fp)) {
        printf("%s", line);
        count++;
    }
    fclose(fp);
    printf("\nLines read: %d\n", count);
}

void write_line(int line_num, char *new_line) {
    FILE *fp = fopen(FILE_NAME, "r+");
    char lines[line_num][LINE_MAX];
    char buffer[LINE_MAX];
    int i = 0;

    while (fgets(buffer, LINE_MAX, fp) && i < line_num) {
        strcpy(lines[i], buffer);
        i++;
    }

    strcpy(lines[line_num - 1], new_line);

    rewind(fp);
    for (i = 0; i < line_num; i++) {
        fprintf(fp, lines[i]);
    }

    fclose(fp);
}

int main(int argC, char *argV[]) {
    if (argC < 3) {
        printf("Usage: editor [line_number] [new_line]\n");
        return 1;
    }

    int line_num = atoi(argV[1]);
    char *new_line = argV[2];

    if (line_num <= 0) {
        display_file();
    } else {
        write_line(line_num, new_line);
        display_file();
    }

    return 0;
}
