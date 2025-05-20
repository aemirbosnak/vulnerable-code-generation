//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store data from CSV file
struct data {
    char name[20];
    int age;
    float weight;
};

// Function to read data from CSV file
void read_data(const char *file_name, struct data *data, int *n) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", file_name);
        return;
    }

    // Skip the first line (header)
    char line[1024];
    fgets(line, sizeof(line), fp);

    // Read data from each line
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *p = strtok(line, ",");
        strcpy(data[*n].name, p);
        p = strtok(NULL, ",");
        data[*n].age = atoi(p);
        p = strtok(NULL, ",");
        data[*n].weight = atof(p);
        *n += 1;
    }

    fclose(fp);
}

// Function to print data from CSV file
void print_data(struct data *data, int n) {
    printf("Name,Age,Weight\n");
    for (int i = 0; i < n; i++) {
        printf("%s,%d,%f\n", data[i].name, data[i].age, data[i].weight);
    }
}

int main() {
    // Read data from CSV file
    char file_name[1024];
    printf("Enter file name: ");
    scanf("%s", file_name);
    struct data *data = malloc(100 * sizeof(struct data));
    int n = 0;
    read_data(file_name, data, &n);

    // Print data
    print_data(data, n);

    // Free memory
    free(data);

    return 0;
}