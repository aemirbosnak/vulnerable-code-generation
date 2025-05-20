//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to split a string by delimiter
char **split(char *str, char delimiter) {
    int count = 0;
    char **result;
    char *token;

    result = (char **)malloc(sizeof(char *) * (strlen(str) + 1));
    if (result == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    token = strtok(str, delimiter);
    while (token!= NULL) {
        result[count] = token;
        count++;
        token = strtok(NULL, delimiter);
    }
    result[count] = NULL;

    return result;
}

// Function to read CSV file and print its contents
void read_csv_file(char *filename) {
    FILE *file;
    char line[1024];
    char delimiter = ',';
    char **fields;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        fields = split(line, delimiter);
        for (int i = 0; fields[i]!= NULL; i++) {
            printf("%s\t", fields[i]);
        }
        printf("\n");
        free(fields);
    }

    fclose(file);
}

int main() {
    char filename[1024];
    printf("Enter the name of the CSV file: ");
    scanf("%s", filename);

    read_csv_file(filename);

    return 0;
}