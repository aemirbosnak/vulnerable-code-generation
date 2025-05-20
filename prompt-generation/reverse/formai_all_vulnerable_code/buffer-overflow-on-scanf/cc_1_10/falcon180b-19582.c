//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define MAX_FILE_NAME 256
#define MAX_NUM_FILES 100

typedef struct {
    char *filename;
    char *checksum;
} file_t;

void calculate_checksum(char *filename, char *checksum) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File '%s' not found.\n", filename);
        exit(1);
    }

    unsigned char buffer[MAX_LINE_LENGTH];
    size_t bytes_read;
    unsigned int checksum_value = 0;

    while ((bytes_read = fread(buffer, 1, MAX_LINE_LENGTH, file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            checksum_value += (unsigned int) buffer[i];
        }
    }

    fclose(file);

    sprintf(checksum, "%08X", checksum_value);
}

int main() {
    char filename[MAX_FILE_NAME];
    char checksum[9];
    file_t files[MAX_NUM_FILES];
    int num_files = 0;

    printf("Enter the name of the file to calculate its checksum: ");
    scanf("%s", filename);

    calculate_checksum(filename, checksum);

    printf("Checksum for file '%s': %s\n", filename, checksum);

    return 0;
}