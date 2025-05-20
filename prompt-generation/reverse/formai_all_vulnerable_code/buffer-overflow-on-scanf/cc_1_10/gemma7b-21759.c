//Gemma-7B DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* filePtr;
    char fileName[20];
    int readCount = 0, writeCount = 0;
    char data[1024];

    printf("Enter file name: ");
    scanf("%s", fileName);

    filePtr = fopen(fileName, "r+w");

    if (filePtr == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter data to write (q to quit): ");
    scanf("%s", data);

    while (strcmp(data, "q") != 0)
    {
        writeCount++;
        fprintf(filePtr, "%s\n", data);

        printf("Enter data to write (q to quit): ");
        scanf("%s", data);
    }

    rewind(filePtr);

    readCount = fread(data, 1, 1024, filePtr);

    printf("Data read: ");
    for (int i = 0; i < readCount; i++)
    {
        printf("%c", data[i]);
    }

    fclose(filePtr);

    printf("\nNumber of reads: %d", readCount);
    printf("\nNumber of writes: %d", writeCount);

    return 0;
}