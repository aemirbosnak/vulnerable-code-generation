//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the CSV Reader program!\n");
    printf("Please enter the path of the CSV file you want to read: ");

    char path[256];
    scanf("%s", path);

    printf("Opening file...\n");

    FILE *file = fopen(path, "r");

    if(file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char file_contents[1024];
    int i = 0;
    char c;

    printf("Reading file contents...\n");

    while((c = fgetc(file)) != EOF) {
        file_contents[i] = c;
        i++;
    }

    fclose(file);

    printf("Parsing CSV data...\n");

    char *token;
    char *line;
    int line_num = 1;

    line = strtok(file_contents, "\n");

    while(line != NULL) {
        printf("Line %d:\n", line_num);
        token = strtok(line, ",");

        while(token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }

        line_num++;
        line = strtok(NULL, "\n");
    }

    printf("Done!\n");

    return 0;
}