//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 256
#define MAX_VIRUS_NAME_SIZE 32
#define MAX_BUFFER_SIZE 1024

typedef struct {
    char name[MAX_VIRUS_NAME_SIZE];
    char signature[MAX_BUFFER_SIZE];
} virus_signature_t;

void scan_file(char* file_path, virus_signature_t* virus_signatures, int signature_count) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Failed to open file %s\n", file_path);
        return;
    }

    int viruses_found = 0;
    char line[MAX_BUFFER_SIZE];
    while (fgets(line, MAX_BUFFER_SIZE, file)) {
        for (int i = 0; i < signature_count; i++) {
            if (strstr(line, virus_signatures[i].signature) != NULL) {
                printf("Found virus: %s\n", virus_signatures[i].name);
                viruses_found++;
            }
        }
    }

    if (viruses_found == 0) {
        printf("No viruses found in file %s\n", file_path);
    }

    fclose(file);
}

int main() {
    char file_name[MAX_FILE_NAME_SIZE];
    printf("Enter file to scan: ");
    scanf("%s", file_name);

    virus_signature_t virus_signatures[] = {
        {"Virus 1", "68 65 6c 6c 6f 20 77 6f 72 6c 64"},
        {"Virus 2", "69 6e 66 65 63 74 65 64 20 62 79 20 76 69 72 75 73"},
        {"Virus 3", "64 61 6d 61 67 65 20 76 69 72 75 73"}
    };

    int signature_count = sizeof(virus_signatures) / sizeof(virus_signature_t);

    scan_file(file_name, virus_signatures, signature_count);

    return 0;
}