//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size to scan
#define VIRUS_SIGNATURE "virus" // Signature to detect virus

int is_virus(char* file_content) {
    int file_size = strlen(file_content);
    char* virus_signature = VIRUS_SIGNATURE;
    int virus_size = strlen(virus_signature);

    for (int i = 0; i <= file_size - virus_size; i++) {
        if (strncmp(file_content + i, virus_signature, virus_size) == 0) {
            return 1; // Virus found
        }
    }

    return 0; // No virus found
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File too large.\n");
        fclose(file);
        exit(1);
    }

    char* file_content = (char*)malloc(file_size + 1);
    fseek(file, 0, SEEK_SET);
    fread(file_content, file_size, 1, file);
    file_content[file_size] = '\0';

    int is_infected = is_virus(file_content);

    if (is_infected) {
        printf("Virus found!\n");
    } else {
        printf("No virus found.\n");
    }

    free(file_content);
    fclose(file);

    return 0;
}