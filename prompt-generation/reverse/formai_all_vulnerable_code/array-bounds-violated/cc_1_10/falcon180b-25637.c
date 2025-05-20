//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_NUM_LINES 1000

typedef struct {
    char *filename;
    char *contents;
    int length;
} file_t;

file_t files[MAX_NUM_LINES];
int num_files = 0;

void read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int length = strlen(line);
        if (length == 0 || line[length - 1] == '\n') {
            line[--length] = '\0';
        }

        file_t *file = malloc(sizeof(file_t));
        file->filename = strdup(filename);
        file->contents = strdup(line);
        file->length = length;

        files[num_files++] = *file;
    }

    fclose(fp);
}

unsigned short calculate_checksum(const char *data, int length) {
    unsigned short sum = 0;
    for (int i = 0; i < length; i++) {
        sum += data[i];
    }
    return sum;
}

void print_checksums() {
    printf("Filename\tChecksum\n");
    for (int i = 0; i < num_files; i++) {
        unsigned short checksum = calculate_checksum(files[i].contents, files[i].length);
        printf("%s\t0x%04X\n", files[i].filename, checksum);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename1> [<filename2>...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        read_file(argv[i]);
    }

    print_checksums();

    return 0;
}