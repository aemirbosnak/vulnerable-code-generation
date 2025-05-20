//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define VIRUS_SIGNATURE "EVIL_VIRUS"

int is_infected(char* file_content) {
    int i, j;
    for (i = 0; i < strlen(VIRUS_SIGNATURE) - 1; i++) {
        for (j = 0; j < strlen(file_content) - strlen(VIRUS_SIGNATURE) + 1; j++) {
            if (file_content[j] == VIRUS_SIGNATURE[i]) {
                if (strncmp(&file_content[j], VIRUS_SIGNATURE, strlen(VIRUS_SIGNATURE)) == 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    char file_name[100];
    printf("Enter the name of the file to scan: ");
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "rb");

    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("File is too large to scan.\n");
        fclose(file);
        return 1;
    }

    char* file_content = (char*) malloc(file_size + 1);

    fseek(file, 0, SEEK_SET);
    fread(file_content, file_size, 1, file);
    file_content[file_size] = '\0';

    int is_infected_result = is_infected(file_content);

    if (is_infected_result == 1) {
        printf("File is infected with the EVIL_VIRUS.\n");
    } else {
        printf("File is clean.\n");
    }

    free(file_content);
    fclose(file);

    return 0;
}