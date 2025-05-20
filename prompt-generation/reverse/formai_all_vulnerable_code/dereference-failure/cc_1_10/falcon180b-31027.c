//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1048576 // 1 MB
#define VIRUS_SIGNATURE "EICAR-STANDARD-ANTIVIRUS-TEST-FILE!"

int is_virus(char* file_content) {
    int i = 0, j = 0;
    while (file_content[i]) {
        if (tolower(file_content[i]) == tolower(VIRUS_SIGNATURE[j])) {
            j++;
            if (j == strlen(VIRUS_SIGNATURE)) {
                return 1;
            }
        } else {
            j = 0;
        }
        i++;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File is too large.\n");
        fclose(file);
        return 1;
    }

    rewind(file);
    char* file_content = malloc(file_size + 1);
    if (!file_content) {
        printf("Error: Could not allocate memory.\n");
        fclose(file);
        return 1;
    }

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