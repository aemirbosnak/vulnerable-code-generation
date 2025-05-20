//FormAI DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define filename and file pointer
    char filename[30];
    FILE *fp;

    // Get filename from user input
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open file in read mode
    fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    // Define variables to store data
    int num1, num2, sum = 0;

    // Read two integers from file and calculate sum
    fscanf(fp, "%d %d", &num1, &num2);
    sum = num1 + num2;

    // Close the file
    fclose(fp);

    // Open the file in write mode
    fp = fopen(filename, "w");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    // Write the sum to the file
    fprintf(fp, "%d", sum);

    // Close the file
    fclose(fp);

    // Print success message to user
    printf("Sum of %d and %d written to file %s successfully!\n", num1, num2, filename);

    return 0;
}