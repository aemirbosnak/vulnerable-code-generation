//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELD_LENGTH 50
#define DELIMITER ','

int main()
{
    char filename[50];
    printf("Enter the name of the CSV file to read: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File not found!\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int field_count = 0;
    int line_count = 0;
    char* field;

    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        line_count++;

        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0'; // Remove the newline character

        field_count = 0;

        // Parse the line into fields
        field = strtok(line, ",");

        while (field != NULL)
        {
            field_count++;
            if (field_count == 1)
            {
                printf("Line %d: ", line_count);
            }
            printf("%s ", field);

            field = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(file);

    return 0;
}