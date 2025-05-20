//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB
#define VIRUS_SIGNATURE "EICAR-STANDARD-ANTIVIRUS-TEST-FILE!"

int is_virus(char *file_content, int file_size) {
    char *virus_signature = VIRUS_SIGNATURE;
    int virus_signature_size = strlen(virus_signature);

    if (file_size < virus_signature_size) {
        return 0;
    }

    char *content_ptr = file_content;
    while (content_ptr < file_content + file_size - virus_signature_size) {
        if (!strncmp(content_ptr, virus_signature, virus_signature_size)) {
            return 1;
        }
        content_ptr++;
    }

    return 0;
}

int main() {
    char file_path[256];
    printf("Enter the file path: ");
    scanf("%s", file_path);

    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File is too large.\n");
        fclose(file);
        return 1;
    }

    char *file_content = malloc(file_size);
    if (file_content == NULL) {
        printf("Error: Could not allocate memory.\n");
        fclose(file);
        return 1;
    }

    fseek(file, 0, SEEK_SET);
    fread(file_content, file_size, 1, file);
    fclose(file);

    int is_infected = is_virus(file_content, file_size);

    if (is_infected) {
        printf("Virus detected!\n");
    } else {
        printf("No virus found.\n");
    }

    free(file_content);
    return 0;
}