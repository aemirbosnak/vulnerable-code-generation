//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_FILENAME_LENGTH 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    FILE *file;
    long int checksum;
    int num_lines;
} file_info;

void print_help(void) {
    printf("Usage:./checksum_calculator <filename>\n");
    printf("Calculates the checksum of a file in a retro style!\n");
}

int is_valid_filename(char *filename) {
    int i = 0;
    while (filename[i]!= '\0') {
        if (!isalnum(filename[i]) && filename[i]!= '_') {
            return 0;
        }
        i++;
    }
    return 1;
}

int is_valid_line(char *line) {
    int i = 0;
    while (line[i]!= '\0') {
        if (!isprint(line[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

long int calculate_checksum(char *line) {
    long int checksum = 0;
    int i = 0;
    while (line[i]!= '\0') {
        checksum += tolower(line[i]);
        i++;
    }
    return checksum;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_help();
        return 1;
    }

    file_info info;
    strcpy(info.filename, argv[1]);

    if (!is_valid_filename(info.filename)) {
        printf("Invalid filename!\n");
        return 1;
    }

    info.file = fopen(info.filename, "r");
    if (info.file == NULL) {
        printf("Could not open file!\n");
        return 1;
    }

    info.checksum = 0;
    info.num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, info.file)!= NULL) {
        if (!is_valid_line(line)) {
            printf("Invalid line!\n");
            fclose(info.file);
            return 1;
        }
        info.checksum += calculate_checksum(line);
        info.num_lines++;
    }

    info.checksum = abs(info.checksum) % 1000000;

    printf("Checksum: %06ld\n", info.checksum);
    printf("Number of lines: %d\n", info.num_lines);

    fclose(info.file);
    return 0;
}