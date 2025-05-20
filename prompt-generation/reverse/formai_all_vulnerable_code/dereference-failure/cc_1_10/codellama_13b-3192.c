//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
/*
 * Building a CSV Reader in a Shocked Style
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *name;
    int age;
    float height;
} Person;

void read_csv(char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        Person person;
        char *token;

        token = strtok(line, ",");
        person.name = token;

        token = strtok(NULL, ",");
        person.age = atoi(token);

        token = strtok(NULL, ",");
        person.height = atof(token);

        printf("Name: %s, Age: %d, Height: %f\n", person.name, person.age, person.height);
    }

    fclose(fp);
    if (line) {
        free(line);
    }
}

int main() {
    read_csv("people.csv");
    return 0;
}