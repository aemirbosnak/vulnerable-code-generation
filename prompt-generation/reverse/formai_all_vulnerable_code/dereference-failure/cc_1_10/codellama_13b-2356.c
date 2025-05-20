//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
// Building a Cyberpunk-style CSV Reader in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 128

typedef struct {
    char name[MAX_FIELD_LENGTH];
    int age;
    float height;
} Person;

int main() {
    // Open the CSV file
    FILE *fp = fopen("people.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the CSV file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Remove the newline character from the end of the line
        line[strcspn(line, "\n")] = '\0';

        // Tokenize the line into individual fields
        char *field[MAX_FIELD_LENGTH];
        int num_fields = 0;
        for (char *token = strtok(line, ","); token != NULL; token = strtok(NULL, ",")) {
            field[num_fields++] = token;
        }

        // Extract the name, age, and height from the fields
        Person person;
        strcpy(person.name, field[0]);
        person.age = atoi(field[1]);
        person.height = atof(field[2]);

        // Print the person's information
        printf("Name: %s\n", person.name);
        printf("Age: %d\n", person.age);
        printf("Height: %.2f\n", person.height);
    }

    // Close the file
    fclose(fp);

    return 0;
}