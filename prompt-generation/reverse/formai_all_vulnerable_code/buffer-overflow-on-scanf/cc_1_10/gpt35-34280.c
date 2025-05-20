//FormAI DATASET v1.0 Category: Data recovery tool ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function Prototype
void recoverData(FILE *file, char *filename, unsigned int offset, unsigned int size);

int main()
{
    FILE *fp;
    char filename[50];
    unsigned int offset, size;

    printf("Welcome to the Curious Data Recovery Tool!\n\n");
    printf("Enter the name of the file you want to recover data from: ");
    scanf("%s", filename);

    // Open file in read mode
    fp = fopen(filename, "rb");

    if(fp == NULL) // Check if file is open
    {
        printf("Error Opening File\n");
        exit(1);
    }

    // Get offset and size of data to be recovered
    printf("\nEnter the offset and size of the data you want to recover (in bytes): ");
    scanf("%u %u", &offset, &size);

    // Call recoverData() function to recover data
    recoverData(fp, filename, offset, size);

    // Close the file
    fclose(fp);

    printf("\nData recovery done! Check the recovered data file.\n");

    return 0;
}

// Function to recover data from a file
void recoverData(FILE *file, char *filename, unsigned int offset, unsigned int size)
{
    // Create filename for recovered data
    char newFilename[50];
    snprintf(newFilename, sizeof(newFilename), "Recovered_%s", filename);

    // Open new file in write mode
    FILE *newFile = fopen(newFilename, "wb");

    if(newFile == NULL) // Check if new file is open
    {
        printf("Error Opening New File\n");
        exit(1);
    }

    // Set file position to the offset
    fseek(file, offset, SEEK_SET);

    // Allocate memory to store recovered data
    char *recoveredData = (char*)malloc(size);

    if(recoveredData == NULL) // Check if memory is allocated
    {
        printf("Memory Allocation Error\n");
        exit(1);
    }

    // Read data from file and store it in memory variable
    fread(recoveredData, size, 1, file);

    // Write recovered data to new file
    fwrite(recoveredData, size, 1, newFile);

    // Free allocated memory
    free(recoveredData);

    // Close new file
    fclose(newFile);
}