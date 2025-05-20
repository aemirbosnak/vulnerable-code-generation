//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024*1024*10) // 10 MB
#define VIRUS_SIGNATURE "hello world"

int is_infected(char *file_content, int content_size) {
    char *virus_signature = VIRUS_SIGNATURE;
    int virus_signature_size = strlen(virus_signature);

    if (content_size < virus_signature_size) {
        return 0;
    }

    char *content_ptr = file_content;
    while (content_ptr < (file_content + content_size - virus_signature_size)) {
        if (memcmp(content_ptr, virus_signature, virus_signature_size) == 0) {
            return 1;
        }
        content_ptr++;
    }

    return 0;
}

int main() {
    FILE *file;
    char buffer[MAX_FILE_SIZE];
    int content_size = 0;

    printf("Enter the file path: ");
    scanf("%s", buffer);

    file = fopen(buffer, "rb");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(buffer, MAX_FILE_SIZE, file)!= NULL) {
        content_size += strlen(buffer);
        if (content_size > MAX_FILE_SIZE) {
            printf("Error: File is too large.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    if (is_infected(buffer, content_size)) {
        printf("Virus detected!\n");
    } else {
        printf("No virus detected.\n");
    }

    return 0;
}