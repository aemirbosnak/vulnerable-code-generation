//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int index = 0;
    char current_key[MAX_BUFFER_SIZE];
    char current_value[MAX_BUFFER_SIZE];
    int nested_level = 0;
    FILE *fp;

    fp = fopen("sample.json", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Read the JSON file
    while (fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL)
    {
        // Process the JSON data
        for (index = 0; buffer[index] != '\0'; index++)
        {
            // Key-value pair
            if (buffer[index] == '"')
            {
                // Extract the key
                current_key[0] = '\0';
                index++;
                while (buffer[index] != '"' && buffer[index] != '\0')
                {
                    current_key[index - 1] = buffer[index];
                    index++;
                }

                // Extract the value
                current_value[0] = '\0';
                index++;
                while (buffer[index] != '}' && buffer[index] != ']' && buffer[index] != '\0')
                {
                    current_value[index - 1] = buffer[index];
                    index++;
                }

                // Process the key-value pair
                printf("Key: %s, Value: %s\n", current_key, current_value);
            }

            // Nested object
            else if (buffer[index] == '{')
            {
                nested_level++;
            }

            // Nested array
            else if (buffer[index] == '[')
            {
                nested_level++;
            }

            // End of object or array
            else if (buffer[index] == '}')
            {
                nested_level--;
            }

            // End of array
            else if (buffer[index] == ']')
            {
                nested_level--;
            }
        }

        fclose(fp);
    }

    return 0;
}