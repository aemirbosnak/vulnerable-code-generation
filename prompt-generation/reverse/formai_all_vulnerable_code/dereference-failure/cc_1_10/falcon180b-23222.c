//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define VIRUS_SIGNATURE "VIRUS"

int is_virus(char *file_data) {
    int i = 0, j = 0;
    while (file_data[i]) {
        if (file_data[i] == VIRUS_SIGNATURE[j]) {
            j++;
            if (VIRUS_SIGNATURE[j] == '\0') {
                return 1;
            }
        } else {
            j = 0;
        }
        i++;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0L, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *file_data = (char*) malloc(file_size + 1);
    if (file_data == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return 1;
    }

    fread(file_data, file_size, 1, file);
    file_data[file_size] = '\0';

    if (is_virus(file_data)) {
        printf("File contains virus.\n");
    } else {
        printf("File is clean.\n");
    }

    free(file_data);
    fclose(file);
    return 0;
}