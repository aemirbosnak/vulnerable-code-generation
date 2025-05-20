//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10)
#define MAX_VIRUS_NAME_LEN 50
#define MAX_VIRUS_SIGNATURE_LEN 100

typedef struct {
    char name[MAX_VIRUS_NAME_LEN];
    char signature[MAX_VIRUS_SIGNATURE_LEN];
} Virus;

typedef struct {
    FILE *file;
    char *buffer;
    size_t size;
} FileData;

int scan_file(const char *filename, Virus *viruses, int num_viruses) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    FileData data = {
       .file = file,
       .buffer = malloc(MAX_FILE_SIZE),
       .size = 0
    };

    while (fread(data.buffer + data.size, 1, 1, file) == 1) {
        data.size++;
        if (data.size >= MAX_FILE_SIZE) {
            printf("Error: File '%s' is too large\n", filename);
            fclose(file);
            free(data.buffer);
            return 1;
        }
    }

    fclose(file);

    for (int i = 0; i < num_viruses; i++) {
        Virus virus = viruses[i];
        int signature_size = strlen(virus.signature);
        int buffer_size = data.size - signature_size + 1;

        for (int j = 0; j <= buffer_size - signature_size; j++) {
            int k = 0;
            while (j + k < buffer_size && virus.signature[k] == data.buffer[j + k]) {
                k++;
            }

            if (k == signature_size) {
                printf("Virus '%s' found in file '%s'\n", virus.name, filename);
                return 1;
            }
        }
    }

    free(data.buffer);
    return 0;
}

int main() {
    Virus viruses[] = {
        { "WannaCry", "fc6f0d2e8bbc9c4e4c8c0a0a1c0b9d9a8d8b9d9c7c7b6c6c5b4c4c3c2c1c0" },
        { "Petya", "fc6f0d2e8bbc9c4e4c8c0a0a1c0b9d9a8d8b9d9c7c7b6c6c5b4c4c3c2c1c0" }
    };

    int num_viruses = sizeof(viruses) / sizeof(Virus);

    char filename[256];
    printf("Enter file name: ");
    scanf("%s", filename);

    int result = scan_file(filename, viruses, num_viruses);

    if (result == 0) {
        printf("No viruses found\n");
    }

    return 0;
}