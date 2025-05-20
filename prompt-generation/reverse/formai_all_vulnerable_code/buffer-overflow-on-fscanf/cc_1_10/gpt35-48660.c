//FormAI DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the amazing file handling program!\n");
    printf("We will read data from a file and perform some operations on it.\n");

    // Open file in read mode
    FILE *fp;
    fp = fopen("input.txt", "r");

    // Check for errors while opening a file
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read data from the file
    int num, sum = 0;
    while (fscanf(fp, "%d", &num) != EOF)
    {
        printf("%d ", num);
        sum += num;
    }

    printf("\n");

    // Close the file
    fclose(fp);

    // Open file in write mode
    fp = fopen("output.txt", "w");

    // Check for errors while opening a file
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Write sum to the output file
    fprintf(fp, "The sum of the numbers read from the input file is: %d", sum);

    printf("Data has been successfully read from the input file and written to the output file!\n");

    // Close the file
    fclose(fp);

    return 0;
}