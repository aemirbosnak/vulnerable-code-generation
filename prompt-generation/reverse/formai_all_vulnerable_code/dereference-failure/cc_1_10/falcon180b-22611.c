//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1 MB

typedef struct {
    char magic[4]; // should be "CRPT"
    int version;
    int num_files;
    int file_table_offset;
} CRPT_Header;

typedef struct {
    int id;
    char name[32];
    int size;
    int offset;
} CRPT_FileEntry;

int main(int argc, char *argv[]) {
    FILE *f;
    CRPT_Header header;
    CRPT_FileEntry *file_table;
    int i, j;
    char buffer[MAX_FILE_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <CRPT file>\n", argv[0]);
        return 1;
    }

    f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fread(&header, sizeof(CRPT_Header), 1, f);
    if (memcmp(header.magic, "CRPT", 4)!= 0 || header.version!= 1) {
        printf("Invalid CRPT file.\n");
        fclose(f);
        return 1;
    }

    file_table = malloc(header.num_files * sizeof(CRPT_FileEntry));
    if (file_table == NULL) {
        printf("Error allocating memory.\n");
        fclose(f);
        return 1;
    }

    fseek(f, header.file_table_offset, SEEK_SET);
    for (i = 0; i < header.num_files; i++) {
        fread(&file_table[i], sizeof(CRPT_FileEntry), 1, f);
    }

    printf("File Name\tSize\n");
    for (i = 0; i < header.num_files; i++) {
        printf("%s\t%d\n", file_table[i].name, file_table[i].size);
    }

    printf("Select a file to recover:\n");
    scanf("%d", &i);

    fseek(f, file_table[i].offset, SEEK_SET);

    while (fread(buffer, 1, MAX_FILE_SIZE, f) > 0) {
        for (j = 0; j < MAX_FILE_SIZE; j++) {
            printf("%c", buffer[j]);
        }
    }

    fclose(f);
    free(file_table);

    return 0;
}