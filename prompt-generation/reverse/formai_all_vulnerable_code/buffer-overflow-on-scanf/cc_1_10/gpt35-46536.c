//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 1000
#define MAX_FILENAME_LENGTH 256
#define MAX_SCAN_LENGTH 100000

struct File {
    char filename[MAX_FILENAME_LENGTH];
    int size;
    char content[MAX_SCAN_LENGTH];
};

void scanFile(struct File *file) {
    int i;
    char virus[7] = {'v', 'i', 'r', 'u', 's', '\0'};
    for (i = 0; i < file->size; i++) {
        if (strncmp(file->content + i, virus, 5) == 0) {
            printf("Virus found in file %s\n", file->filename);
            break;
        }
    }
}

int main() {
    int i, j;
    char filename[MAX_FILENAME_LENGTH];
    struct File files[MAX_FILES];

    printf("Enter the number of files: ");
    int num_files;
    scanf("%d", &num_files);

    for (i = 0; i < num_files; i++) {
        printf("Enter filename %d: ", i+1);
        scanf("%s", filename);

        FILE* file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error opening file %s\n", filename);
            return 1;
        }

        // Load file content into memory
        fseek(file, 0L, SEEK_END);
        int size = ftell(file);
        rewind(file);
        char* file_content = malloc(size+1);
        fread(file_content, sizeof(char), size, file);
        file_content[size] = '\0';
        fclose(file);

        // Save file content in struct
        struct File new_file;
        strncpy(new_file.filename, filename, MAX_FILENAME_LENGTH-1);
        new_file.filename[MAX_FILENAME_LENGTH-1] = '\0';
        new_file.size = size;
        strncpy(new_file.content, file_content, MAX_SCAN_LENGTH-1);
        new_file.content[MAX_SCAN_LENGTH-1] = '\0';
        files[i] = new_file;

        free(file_content);
    }

    // Scan all files
    for (i = 0; i < num_files; i++) {
        scanFile(&files[i]);
    }

    return 0;
}