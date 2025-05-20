//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    FILE *file;
    char filename[MAX_SIZE];
    char line[MAX_SIZE];

    printf("Enter the name of the CSV file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read and print header row
    if (fgets(line, MAX_SIZE, file) != NULL) {
        printf("Header: %s", line);
    }

    // Read and print data rows
    while (fgets(line, MAX_SIZE, file) != NULL) {
        char *token;
        char *name;
        char *age;
        char *city;

        // Parse CSV row
        token = strtok(line, ",");
        name = token;
        token = strtok(NULL, ",");
        age = token;
        token = strtok(NULL, ",");
        city = token;

        // Print parsed data
        printf("Name: %s\n", name);
        printf("Age: %s\n", age);
        printf("City: %s\n", city);
    }

    fclose(file);

    return 0;
}