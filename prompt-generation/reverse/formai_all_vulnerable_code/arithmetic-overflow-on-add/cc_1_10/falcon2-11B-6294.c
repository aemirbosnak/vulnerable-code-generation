//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char* file_name = NULL;
    int file_size;
    char* line = NULL;
    char* token = NULL;
    int token_count = 0;
    char* keyword = NULL;

    printf("Enter the file name: ");
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    line = (char*) malloc(file_size + 1);
    if (line == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }

    while (fgets(line, file_size, file)!= NULL) {
        token = strtok(line, " \t\n");

        while (token!= NULL) {
            token_count++;
            token = strtok(NULL, " \t\n");
        }

        free(line);
        line = NULL;
    }

    free(line);
    line = NULL;

    printf("Total number of tokens in the file: %d\n", token_count);

    printf("Enter the keyword: ");
    scanf("%s", keyword);

    line = (char*) malloc(file_size + 1);
    if (line == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }

    while (fgets(line, file_size, file)!= NULL) {
        token = strstr(line, keyword);

        if (token!= NULL) {
            printf("%s\n", line);
        }

        free(line);
        line = NULL;
    }

    free(line);
    line = NULL;

    fclose(file);

    return 0;
}