//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char **buffer = NULL;
    int buffer_size = 0;
    char line[MAX_BUFFER_SIZE];

    printf("Enter the path to the CSV file: ");
    scanf("%s", line);

    FILE *file = fopen(line, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Allocate memory for the buffer
    buffer = malloc(buffer_size * sizeof(char *));
    if (buffer == NULL)
    {
        perror("Error allocating memory");
        return 1;
    }

    // Read the CSV file line by line
    while (fgets(line, MAX_BUFFER_SIZE, file) != NULL)
    {
        // Parse the line and store it in the buffer
        buffer = realloc(buffer, (buffer_size + 1) * sizeof(char *));
        buffer[buffer_size++] = strdup(line);
    }

    // Close the file
    fclose(file);

    // Print the buffer
    for (int i = 0; i < buffer_size; i++)
    {
        printf("%s\n", buffer[i]);
    }

    // Free the buffer
    free(buffer);

    return 0;
}