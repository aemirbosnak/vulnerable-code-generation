//FormAI DATASET v1.0 Category: Compression algorithms ; Style: romantic
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100

int main()
{
    char input_str[MAX_BUFFER_SIZE];
    char output_str[MAX_BUFFER_SIZE];
    int freq[MAX_BUFFER_SIZE] = {0};
    int i, j;
    int count = 0;

    printf("Enter a string to compress:\n");
    fgets(input_str, MAX_BUFFER_SIZE, stdin);
    
    for(i = 0; i < strlen(input_str); i++)
    {
        freq[input_str[i] - 'a']++;
    }

    for(i = 0; i < strlen(input_str); i++)
    {
        count = 0;
        for(j = i; j < strlen(input_str); j++)
        {
            if(input_str[i] == input_str[j])
            {
                count++;
            }
            else
            {
                break;
            }
        }

        if(count > 1)
        {
            sprintf(output_str + strlen(output_str), "%d%c", count, input_str[i]);
            i += count - 1;
        }
        else
        {
            sprintf(output_str + strlen(output_str), "%c", input_str[i]);
        }
    }

    printf("Compressed string: %s\n", output_str);

    return 0;
}