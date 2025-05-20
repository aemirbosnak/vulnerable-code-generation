#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define DIARY_FILE "diary.txt"
#define ENTRY_SIZE 100
#define BUFFER_SIZE 20

void read_entries(char *filename);
void write_entry(char *entry);
void validate_entry(char *entry);

int main(int argc, char *argv[]) {
    char entry[ENTRY_SIZE];

    if (argc != 2) {
        printf("Usage: diary <entry>\n");
        return 1;
    }

    strcpy(entry, argv[1]);
    validate_entry(entry);
    write_entry(entry);
    read_entries(DIARY_FILE);

    return 0;
}

void read_entries(char *filename) {
    FILE *file = fopen(filename, "r");
    char entry[ENTRY_SIZE];
    int lines = 0;

    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(entry, ENTRY_SIZE, file)) {
        printf("%s", entry);
        lines++;
    }

    fclose(file);
    printf("\nTotal entries: %d\n", lines);
}

void write_entry(char *entry) {
    FILE *file = fopen(DIARY_FILE, "a");
    if (!file) {
        printf("Error writing to file.\n");
        return;
    }

    fprintf(file, "%s", entry);
    fclose(file);
}

void validate_entry(char *entry) {
    int i = 0;
    while (entry[i] && i < BUFFER_SIZE - 1) {
        if (isalpha(entry[i]) || entry[i] == ' ' || entry[i] == '\n') {
            i++;
        } else {
            entry[i] = '\0';
        }
    }
}
