//FormAI DATASET v1.0 Category: Data recovery tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define BLOCK_SIZE 512

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    FILE* file;
    char buffer[BLOCK_SIZE];
    int block_number = 0;
    int bytes_read, i;

    printf("Enter the name of the file to recover: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    // check if file exists and can be opened
    if (file == NULL)
    {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    // iterate through all blocks of the file and print their content
    while (1)
    {
        bytes_read = fread(buffer, sizeof(char), BLOCK_SIZE, file);

        // break loop if end of file is reached
        if (bytes_read == 0)
            break;

        // check if block is empty and skip it
        if (bytes_read < BLOCK_SIZE && block_number != 0)
        {
            printf("Block %d is empty\n", block_number);
        }
        else
        {
            printf("Block %d:\n", block_number);
            for (i = 0; i < BLOCK_SIZE; i++)
                printf("%c", buffer[i]);
            printf("\n");
        }

        block_number++;
    }

    fclose(file);
    return 0;
}