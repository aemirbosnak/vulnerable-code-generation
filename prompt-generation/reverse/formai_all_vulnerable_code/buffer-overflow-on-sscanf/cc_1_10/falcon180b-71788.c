//Falcon-180B DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

struct Person {
    char name[100];
    int age;
    float height;
};

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    char line[MAX_LINE_SIZE];
    struct Person person;
    int num_people = 0;

    // Prompt user for input filename
    printf("Enter input filename: ");
    scanf("%s", input_filename);

    // Open input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Open output file for writing
    printf("Enter output filename: ");
    scanf("%s", output_filename);
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read input file and write to output file
    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        if (sscanf(line, "%s %d %f", person.name, &person.age, &person.height) == 3) {
            fprintf(output_file, "%s %d %f\n", person.name, person.age, person.height);
            num_people++;
        } else {
            printf("Invalid line format: %s\n", line);
        }
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    // Print summary
    printf("Number of people in input file: %d\n", num_people);
    printf("Output written to file: %s\n", output_filename);

    return 0;
}