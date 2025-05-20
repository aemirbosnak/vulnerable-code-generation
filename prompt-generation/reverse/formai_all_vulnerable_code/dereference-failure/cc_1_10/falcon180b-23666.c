//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_SIZE 1024
#define MAX_LINE_SIZE 8192

// Function prototypes
int split_line(char *line, char delimiter, char **fields);
int read_csv_file(FILE *fp, char delimiter, void (*process_row)(char **));

typedef struct {
    int id;
    char name[MAX_FIELD_SIZE];
    char email[MAX_FIELD_SIZE];
} Person;

void process_person(char **fields) {
    Person person = {0};
    sscanf(fields[0], "%d", &person.id);
    strcpy(person.name, fields[1]);
    strcpy(person.email, fields[2]);
    printf("ID: %d\nName: %s\nEmail: %s\n\n", person.id, person.name, person.email);
}

int split_line(char *line, char delimiter, char **fields) {
    char *token = strtok(line, delimiter);
    int count = 0;
    while (token!= NULL) {
        fields[count] = token;
        count++;
        token = strtok(NULL, delimiter);
    }
    fields[count] = NULL;
    return count;
}

int read_csv_file(FILE *fp, char delimiter, void (*process_row)(char **)) {
    char line[MAX_LINE_SIZE];
    char **fields = NULL;
    int num_fields = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        num_fields = split_line(line, delimiter, fields);
        if (num_fields > 0) {
            process_row(fields);
        }
        free(fields);
        fields = NULL;
    }

    return 0;
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    char delimiter = ',';
    void (*process_row)(char **) = &process_person;

    read_csv_file(fp, delimiter, process_row);

    fclose(fp);
    return 0;
}