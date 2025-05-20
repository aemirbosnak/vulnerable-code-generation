//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1 MB
#define MAX_VIRUS_SIZE 512
#define VIRUS_SIGNATURE "VIRUS"

typedef struct {
    char* name;
    unsigned char* data;
    size_t size;
} File;

typedef struct {
    char* name;
    unsigned char* data;
    size_t size;
} Virus;

bool is_virus(const Virus* virus) {
    if (virus->size > MAX_VIRUS_SIZE) {
        return false;
    }

    for (int i = 0; i < virus->size; i++) {
        if (tolower(virus->data[i])!= VIRUS_SIGNATURE[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char file_path[512];
    printf("Enter the file path: ");
    scanf("%s", file_path);

    FILE* fp = fopen(file_path, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    if (file_size > MAX_FILE_SIZE) {
        printf("File is too large.\n");
        fclose(fp);
        return 1;
    }

    rewind(fp);

    File file = {
       .name = file_path,
       .data = malloc(file_size),
       .size = file_size
    };

    if (file.data == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fp);
        return 1;
    }

    size_t bytes_read = fread(file.data, 1, file_size, fp);
    if (bytes_read!= file_size) {
        printf("Error reading file.\n");
        free(file.data);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    Virus virus = {
       .name = "Virus",
       .data = malloc(MAX_VIRUS_SIZE),
       .size = 0
    };

    if (virus.data == NULL) {
        printf("Memory allocation failed.\n");
        free(file.data);
        return 1;
    }

    if (is_virus(&virus)) {
        printf("File contains a virus!\n");
    } else {
        printf("File is clean.\n");
    }

    free(file.data);
    free(virus.data);

    return 0;
}