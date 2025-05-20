//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10)
#define VIRUS_SIGNATURE "EICAR-STANDARD-ANTIVIRUS-TEST-FILE!"

int is_infected(char *file_content, int file_size);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char *file_path = argv[1];
    FILE *file = fopen(file_path, "rb");

    if (!file) {
        printf("Error: Could not open file '%s'.\n", file_path);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File is too large.\n");
        fclose(file);
        return 1;
    }

    char *file_content = malloc(file_size + 1);

    if (!file_content) {
        printf("Error: Could not allocate memory.\n");
        fclose(file);
        return 1;
    }

    fseek(file, 0, SEEK_SET);
    fread(file_content, file_size, 1, file);
    fclose(file);

    if (is_infected(file_content, file_size)) {
        printf("Infected with EICAR test virus.\n");
    } else {
        printf("No virus found.\n");
    }

    free(file_content);
    return 0;
}

int is_infected(char *file_content, int file_size) {
    char *virus_signature = VIRUS_SIGNATURE;
    int virus_size = strlen(virus_signature);

    for (int i = 0; i < file_size - virus_size; i++) {
        if (memcmp(file_content + i, virus_signature, virus_size) == 0) {
            return 1;
        }
    }

    return 0;
}