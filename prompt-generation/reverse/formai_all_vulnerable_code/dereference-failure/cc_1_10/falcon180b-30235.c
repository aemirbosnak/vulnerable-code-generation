//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to split a string into an array of strings based on a delimiter
char **split(char *str, char delimiter) {
    int count = 0;
    char *token;
    char **result = NULL;

    // Count the number of tokens in the string
    while (*str) {
        if (*str == delimiter) {
            count++;
        }
        str++;
    }

    // Allocate memory for the result array and each token
    result = (char **) malloc(sizeof(char *) * (count + 1));
    if (result == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    str = strtok(str, delimiter);
    while (str!= NULL) {
        token = strdup(str);
        result[count] = token;
        str = strtok(NULL, delimiter);
        count++;
    }
    result[count] = NULL;

    return result;
}

int main() {
    FILE *csv_file;
    char *line = NULL;
    size_t len = 0;
    char **data;

    // Open the CSV file
    csv_file = fopen("data.csv", "r");
    if (csv_file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Read the first line of the file (header)
    getline(&line, &len, csv_file);
    data = split(line, ',');

    // Print the header
    printf("Header:\n");
    for (int i = 0; data[i]!= NULL; i++) {
        printf("%s\n", data[i]);
    }

    // Read the rest of the file and print the data
    while (getline(&line, &len, csv_file)!= -1) {
        data = split(line, ',');
        printf("Data:\n");
        for (int i = 0; data[i]!= NULL; i++) {
            printf("%s\n", data[i]);
        }
    }

    // Free the memory allocated for the data array
    for (int i = 0; data[i]!= NULL; i++) {
        free(data[i]);
    }
    free(data);

    // Close the file
    fclose(csv_file);

    return 0;
}