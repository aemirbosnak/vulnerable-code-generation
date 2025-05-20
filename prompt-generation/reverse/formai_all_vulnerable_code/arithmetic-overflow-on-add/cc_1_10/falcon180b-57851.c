//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"
#define VIRUS_SIGNATURE_LENGTH 68

int is_infected(char* file_content, int content_length)
{
    char* signature = VIRUS_SIGNATURE;
    int signature_length = strlen(signature);

    for (int i = 0; i < content_length - signature_length; i++) {
        if (memcmp(file_content + i, signature, signature_length) == 0) {
            return 1;
        }
    }

    return 0;
}

void scan_file(char* file_path)
{
    FILE* file = fopen(file_path, "rb");

    if (file == NULL) {
        printf("Error opening file: %s\n", file_path);
        return;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    char* file_content = malloc(file_size + 1);
    fread(file_content, file_size, 1, file);
    file_content[file_size] = '\0';

    int is_infected_result = is_infected(file_content, file_size);

    if (is_infected_result) {
        printf("Virus found in file: %s\n", file_path);
    } else {
        printf("File is clean: %s\n", file_path);
    }

    free(file_content);
    fclose(file);
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char* file_path = argv[1];
    scan_file(file_path);

    return 0;
}