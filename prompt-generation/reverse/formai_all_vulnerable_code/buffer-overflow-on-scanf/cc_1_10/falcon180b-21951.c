//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_SIZE 1024*1024*10   // 10MB
#define VIRUS_SIGNATURE "Virus123"

int count_lines(FILE *file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    return count;
}

int check_virus(FILE *file, int file_size) {
    char buffer[MAX_FILE_SIZE];
    int i;
    for (i = 0; i < file_size; i++) {
        fseek(file, i, SEEK_SET);
        fgets(buffer, MAX_FILE_SIZE, file);
        if (strstr(buffer, VIRUS_SIGNATURE)!= NULL) {
            return 1;
        }
    }
    return 0;
}

void scan_file(char *filename) {
    FILE *file;
    int file_size;
    char ch;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return;
    }

    file_size = 0;
    while ((ch = fgetc(file))!= EOF) {
        file_size++;
    }

    if (check_virus(file, file_size)) {
        printf("Virus detected in file %s.\n", filename);
    } else {
        printf("File %s is clean.\n", filename);
    }

    fclose(file);
}

int main() {
    int i, num_files;
    char filename[100];

    printf("Enter the number of files to scan:\n");
    scanf("%d", &num_files);

    for (i = 0; i < num_files; i++) {
        printf("Enter file name %d:\n", i+1);
        scanf("%s", filename);
        scan_file(filename);
    }

    return 0;
}