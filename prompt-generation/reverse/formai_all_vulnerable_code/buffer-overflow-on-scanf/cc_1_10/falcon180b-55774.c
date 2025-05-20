//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *data;
    size_t size;
} String;

String read_line(FILE *file) {
    String line = {0};
    char buffer[MAX_LINE_SIZE];
    size_t length = 0;

    while (fgets(buffer, MAX_LINE_SIZE, file)!= NULL) {
        length = strlen(buffer);
        line.data = realloc(line.data, line.size + length + 1);
        strcat(line.data, buffer);
        line.size += length;
    }

    return line;
}

void free_string(String *string) {
    free(string->data);
    string->data = NULL;
    string->size = 0;
}

int main() {
    FILE *file;
    String line;
    char delimiter;
    int num_fields;

    printf("Enter the name of the CSV file: ");
    scanf("%s", &line.data);
    file = fopen(line.data, "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    printf("Enter the delimiter character: ");
    scanf(" %c", &delimiter);
    num_fields = 0;

    while ((line = read_line(file)).data!= NULL) {
        char *token = strtok(line.data, delimiter);
        while (token!= NULL) {
            num_fields++;
            token = strtok(NULL, delimiter);
        }
        printf("Number of fields: %d\n", num_fields);
        num_fields = 0;
        free_string(&line);
    }

    fclose(file);
    free(line.data);
    return 0;
}