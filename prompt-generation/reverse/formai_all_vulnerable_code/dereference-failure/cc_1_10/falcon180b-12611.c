//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // 1MB
#define VIRUS_SIGNATURE "VIRUS"

int is_infected(char* file_content) {
    int i = 0;
    while (file_content[i]!= '\0') {
        if (strstr(&file_content[i], VIRUS_SIGNATURE)!= NULL) {
            return 1;
        }
        i++;
    }
    return 0;
}

int main() {
    char file_name[100];
    printf("Enter the name of the file to scan: ");
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File is too large.\n");
        fclose(file);
        return 1;
    }

    char* file_content = (char*) malloc(file_size + 1);
    if (file_content == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    fseek(file, 0, SEEK_SET);
    fread(file_content, file_size, 1, file);
    file_content[file_size] = '\0';

    int is_infected_result = is_infected(file_content);

    if (is_infected_result == 1) {
        printf("File is infected with a virus.\n");
    } else {
        printf("File is clean.\n");
    }

    free(file_content);
    fclose(file);

    return 0;
}