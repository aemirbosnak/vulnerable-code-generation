//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_NUM_FIELDS 10

// Struct to hold a single field
typedef struct {
    char *field;
    int field_len;
} Field;

// Struct to hold a resume
typedef struct {
    int num_fields;
    Field *fields;
} Resume;

// Function to split a line into fields
void split_line(char *line, Field *fields) {
    int num_fields = 0;
    char *word = strtok(line, ",");
    while (word!= NULL && num_fields < MAX_NUM_FIELDS) {
        fields[num_fields].field_len = strlen(word);
        fields[num_fields].field = malloc(fields[num_fields].field_len + 1);
        strcpy(fields[num_fields].field, word);
        num_fields++;
        word = strtok(NULL, ",");
    }
}

// Function to parse a resume
Resume *parse_resume(FILE *fp) {
    Resume *resume = malloc(sizeof(Resume));
    char line[MAX_LINE_LENGTH];
    int line_num = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (line_num >= MAX_NUM_FIELDS) {
            printf("Error: Too many fields in line %d\n", line_num + 1);
            exit(1);
        }
        Field *fields = resume->fields + line_num;
        split_line(line, fields);
        line_num++;
    }
    resume->num_fields = line_num;
    return resume;
}

// Function to print a resume
void print_resume(Resume *resume) {
    for (int i = 0; i < resume->num_fields; i++) {
        printf("%s\n", resume->fields[i].field);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        exit(1);
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        exit(1);
    }
    Resume *resume = parse_resume(fp);
    print_resume(resume);
    return 0;
}