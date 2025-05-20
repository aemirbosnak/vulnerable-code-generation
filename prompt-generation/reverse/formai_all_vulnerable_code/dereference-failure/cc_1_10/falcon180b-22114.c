//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char name[MAX_WORD_LENGTH];
    char value[MAX_WORD_LENGTH];
} KeyValuePair;

char* readLine(FILE* file) {
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file);
    return strdup(line);
}

void parseKeyValuePair(char* line, KeyValuePair* kvp) {
    char* token = strtok(line, ": ");
    if (token == NULL) {
        printf("Invalid line: %s\n", line);
        exit(1);
    }
    strcpy(kvp->name, token);
    token = strtok(NULL, ": ");
    if (token == NULL) {
        printf("Invalid line: %s\n", line);
        exit(1);
    }
    strcpy(kvp->value, token);
}

int main() {
    FILE* file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        exit(1);
    }

    char* line = readLine(file);
    while (line!= NULL) {
        KeyValuePair kvp;
        parseKeyValuePair(line, &kvp);
        printf("Name: %s, Value: %s\n", kvp.name, kvp.value);
        free(line);
        line = readLine(file);
    }

    fclose(file);
    return 0;
}