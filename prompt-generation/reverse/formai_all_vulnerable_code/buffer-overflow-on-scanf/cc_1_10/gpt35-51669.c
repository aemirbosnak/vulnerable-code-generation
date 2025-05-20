//FormAI DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[50], name[20], email[30];
    int choice;

    printf("Enter the name of the file you want to create: ");
    scanf("%s", filename);

    fp = fopen(filename, "w"); // Opening file in write mode

    if (fp == NULL)
    {
        printf("Error creating the file!"); // Error handling
        exit(1);
    }

    printf("\nEnter the user details in the following format: Name Email\n");

    do
    {
        fprintf(fp, "\n"); // Adding a new line to the file

        // Taking input from user
        printf("User details: ");
        scanf("%s %s", name, email);

        fprintf(fp, "%s %s", name, email);

        printf("Do you want to add another user? (0/1): ");
        scanf("%d", &choice);

    } while (choice != 0);

    fclose(fp); // Closing file

    printf("\nFile created successfully!");

    printf("\nThe content of the file is: \n");

    fp = fopen(filename, "r"); // Opening file in read mode

    if (fp == NULL)
    {
        printf("Error reading the file!"); // Error handling
        exit(1);
    }

    char buffer[50];

    // Reading the file
    while (fgets(buffer, 50, fp))
    {
        printf("%s", buffer);
    }

    fclose(fp); // Closing file

    return 0;
}