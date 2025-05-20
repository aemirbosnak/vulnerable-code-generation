//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char json_data[] = "{'name':'John Doe','age':30,'interests':'music,reading,coding'}";
    int json_length = strlen(json_data) + 1;
    char *json_buffer = malloc(json_length);

    memcpy(json_buffer, json_data, json_length);

    // Parse JSON data
    int i = 0;
    char key[MAX_BUFFER_SIZE] = "";
    char value[MAX_BUFFER_SIZE] = "";
    int flag = 0;

    for (i = 0; i < json_length; i++)
    {
        // Key-value pair start
        if (json_buffer[i] == '{' || json_buffer[i] == '[')
        {
            flag = 1;
            key[0] = '\0';
            value[0] = '\0';
        }

        // Key-value pair end
        if (json_buffer[i] == '}' || json_buffer[i] == ']')
        {
            flag = 0;
            printf("Key: %s, Value: %s\n", key, value);
        }

        // Store key and value
        if (flag)
        {
            int j = 0;
            for (j = i; json_buffer[j] != ':' && j < json_length; j++)
            {
                key[j] = json_buffer[j];
            }

            key[j] = '\0';

            i = j + 1;
            for (j = 0; json_buffer[i] != ',' && json_buffer[i] != '}' && j < json_length; j++)
            {
                value[j] = json_buffer[i];
            }

            value[j] = '\0';
        }
    }

    free(json_buffer);

    return 0;
}