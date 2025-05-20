//FormAI DATASET v1.0 Category: Compression algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main()
{
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    char temp[MAX_SIZE];
    int count = 0;
    int input_length, i, j;
    printf("Enter a string to compress:\n");
    scanf("%s", input);
    input_length = strlen(input);

    for(i = 0; i < input_length; i++)
    {
        if(i == input_length - 1)
        {
            temp[count++] = input[i];
            temp[count++] = count + '0';
            break;
        }

        if(input[i] != input[i+1])
        {
            int temp_count = count;
            temp[count++] = input[i];
            temp[count++] = count + '0';

            if(count >= MAX_SIZE)
            {
                printf("Compressed string is too long. Exiting.\n");
                return 1;
            }

            count = 0;
        }
        else
        {
            temp[count++] = input[i];
        }
    }

    strcpy(output, temp);

    printf("Compressed string: %s\n", output);
    return 0;
}