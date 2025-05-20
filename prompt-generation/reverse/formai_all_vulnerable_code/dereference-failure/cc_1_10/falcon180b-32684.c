//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10

// Struct to hold field information
typedef struct {
    char fieldName[32];
    char fieldValue[1024];
} Field;

// Function to split a line into fields
int splitLine(char *line, Field *fields) {
    char *token = strtok(line, ",");
    int numFields = 0;

    while (token!= NULL && numFields < MAX_NUM_FIELDS) {
        strcpy(fields[numFields].fieldName, token);
        strcpy(fields[numFields].fieldValue, strchr(line, ',') + 1);
        numFields++;
        token = strtok(NULL, ",");
    }

    return numFields;
}

// Function to parse a resume
void parseResume(FILE *resumeFile) {
    char line[MAX_LINE_LENGTH];
    Field fields[MAX_NUM_FIELDS];
    int numFields;

    while (fgets(line, MAX_LINE_LENGTH, resumeFile)!= NULL) {
        numFields = splitLine(line, fields);

        for (int i = 0; i < numFields; i++) {
            printf("%s: %s\n", fields[i].fieldName, fields[i].fieldValue);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    FILE *resumeFile = fopen(argv[1], "r");

    if (resumeFile == NULL) {
        printf("Error opening file '%s'.\n", argv[1]);
        return 1;
    }

    parseResume(resumeFile);

    fclose(resumeFile);
    return 0;
}