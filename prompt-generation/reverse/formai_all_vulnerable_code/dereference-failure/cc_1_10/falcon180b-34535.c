//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 10000000 // Maximum file size

typedef struct {
    char *filename;
    unsigned int filesize;
    unsigned int checksum;
} FileInfo;

unsigned int calculate_checksum(char *filename, unsigned int filesize) {
    unsigned int checksum = 0;
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    char buffer[1024];
    while (fread(buffer, 1, 1024, fp) > 0) {
        for (int i = 0; i < 1024; i++) {
            checksum += buffer[i];
        }
    }
    fclose(fp);
    return checksum;
}

void print_file_info(FileInfo *file_info, int num_files) {
    printf("Filename\tSize\t\tChecksum\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t%d\t\t%d\n", file_info[i].filename, file_info[i].filesize, file_info[i].checksum);
    }
}

int main() {
    srand(time(NULL));
    int num_files = rand() % 5 + 1; // Randomly generate number of files between 1 and 5
    FileInfo *file_info = malloc(num_files * sizeof(FileInfo));
    for (int i = 0; i < num_files; i++) {
        char filename[20];
        sprintf(filename, "file_%d.txt", i + 1);
        file_info[i].filename = filename;
        file_info[i].filesize = rand() % MAX_SIZE + 1; // Randomly generate file size between 1 and 10MB
        file_info[i].checksum = calculate_checksum(file_info[i].filename, file_info[i].filesize);
    }
    print_file_info(file_info, num_files);
    free(file_info);
    return 0;
}