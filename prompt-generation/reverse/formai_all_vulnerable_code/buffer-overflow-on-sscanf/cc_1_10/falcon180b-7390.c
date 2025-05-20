//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct entry {
    char date[11];
    char mood[21];
    char text[1001];
};

void read_entries(FILE *file, struct entry entries[], int *size) {
    char line[1025];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (*size >= 1000) {
            fprintf(stderr, "Error: Too many entries.\n");
            exit(1);
        }
        int i = 0;
        while (isspace(line[i])) {
            i++;
        }
        if (line[i]!= '#') {
            fprintf(stderr, "Error: Invalid format.\n");
            exit(1);
        }
        i++;
        if (sscanf(&line[i], "%s %s %[^\n]", entries[*size].date, entries[*size].mood, entries[*size].text)!= 3) {
            fprintf(stderr, "Error: Invalid format.\n");
            exit(1);
        }
        (*size)++;
    }
}

void write_entries(FILE *file, struct entry entries[], int size) {
    for (int i = 0; i < size; i++) {
        fprintf(file, "# %s %s\n%s\n\n", entries[i].date, entries[i].mood, entries[i].text);
    }
}

void sort_entries(struct entry entries[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(entries[j].date, entries[i].date) < 0) {
                struct entry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
}

int main() {
    FILE *file;
    file = fopen("diary.txt", "r+");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file.\n");
        exit(1);
    }
    struct entry entries[1000];
    int size = 0;
    read_entries(file, entries, &size);
    sort_entries(entries, size);
    write_entries(file, entries, size);
    fclose(file);
    return 0;
}