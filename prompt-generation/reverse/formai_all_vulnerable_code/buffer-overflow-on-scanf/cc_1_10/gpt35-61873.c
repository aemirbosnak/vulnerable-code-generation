//FormAI DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>

int main()
{
    // Create a file pointer and open file in append mode
    FILE *filePointer = fopen("example.txt", "a");

    // If file is not found
    if (filePointer == NULL)
    {
        printf("File not found.\n");
        return 0;
    }

    printf("Enter your name: ");
    char name[20];
    scanf("%s", name);

    // Write name to file
    fprintf(filePointer, "Name: %s\n", name);

    printf("Enter your age: ");
    int age;
    scanf("%d", &age);

    // Write age to file
    fprintf(filePointer, "Age: %d\n", age);

    printf("Enter your email: ");
    char email[30];
    scanf("%s", email);

    // Write email to file
    fprintf(filePointer, "Email: %s\n", email);

    // Close file
    fclose(filePointer);

    // Open the file in read mode
    filePointer = fopen("example.txt", "r");

    // If file is not found
    if (filePointer == NULL)
    {
        printf("File not found.\n");
        return 0;
    }

    printf("\n----------\n\n");

    // Read file line by line and print to screen
    char line[100];
    printf("File contents:\n");
    while (fgets(line, 100, filePointer) != NULL)
    {
        printf("%s", line);
    }

    // Close file
    fclose(filePointer);

    return 0;
}