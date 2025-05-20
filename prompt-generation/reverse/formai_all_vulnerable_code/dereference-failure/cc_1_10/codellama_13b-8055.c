//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CSVRecord {
    char *name;
    int age;
    char *gender;
    char *email;
};

int main() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        char *token;
        char *saveptr;

        token = strtok_r(line, ",", &saveptr);
        struct CSVRecord record;
        record.name = token;

        token = strtok_r(NULL, ",", &saveptr);
        record.age = atoi(token);

        token = strtok_r(NULL, ",", &saveptr);
        record.gender = token;

        token = strtok_r(NULL, ",", &saveptr);
        record.email = token;

        // Print the record
        printf("Name: %s\n", record.name);
        printf("Age: %d\n", record.age);
        printf("Gender: %s\n", record.gender);
        printf("Email: %s\n", record.email);
    }

    fclose(fp);
    return 0;
}