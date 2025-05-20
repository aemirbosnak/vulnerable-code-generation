//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "virus"

int is_infected(char *file_contents) {
    char *needle = VIRUS_SIGNATURE;
    char *haystack = file_contents;

    while (*haystack) {
        if (strstr(haystack, needle)!= NULL) {
            return 1;
        }
        haystack++;
    }

    return 0;
}

int main() {
    char file_path[100];
    printf("Enter the file path: ");
    scanf("%s", file_path);

    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *file_contents = (char *) malloc(file_size + 1);
    if (file_contents == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    fread(file_contents, file_size, 1, file);
    file_contents[file_size] = '\0';

    int is_infected_result = is_infected(file_contents);

    if (is_infected_result == 1) {
        printf("File is infected with a virus.\n");
    } else {
        printf("File is clean.\n");
    }

    free(file_contents);
    fclose(file);

    return 0;
}