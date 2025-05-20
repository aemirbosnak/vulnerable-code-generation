//FormAI DATASET v1.0 Category: Error handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define error codes
#define ERROR_NONE 0
#define ERROR_INVALID_INPUT 1
#define ERROR_MEMORY_ALLOCATION 2
#define ERROR_FILE_READ 3
#define ERROR_FILE_WRITE 4

// Define a custom error structure that contains error code and error description
typedef struct 
{
    int error_code;
    char error_desc[100];
} CustomError;

// Function to generate a random error code
int generateErrorCode()
{
    srand(time(NULL));
    int error_code = rand() % 5 + 1;
    return error_code;
}

// Function to handle errors and return custom error structure
CustomError handleError(int error_code)
{
    CustomError custom_error;
    switch (error_code)
    {
        case ERROR_NONE:
            strcpy(custom_error.error_desc, "No error found.");
            break;
        case ERROR_INVALID_INPUT:
            strcpy(custom_error.error_desc, "Invalid input.");
            break;
        case ERROR_MEMORY_ALLOCATION:
            strcpy(custom_error.error_desc, "Memory allocation failed.");
            break;
        case ERROR_FILE_READ:
            strcpy(custom_error.error_desc, "Failed to read file.");
            break;
        case ERROR_FILE_WRITE:
            strcpy(custom_error.error_desc, "Failed to write to file.");
            break;
        default:
            strcpy(custom_error.error_desc, "Unknown error occurred.");
            break;
    }
    custom_error.error_code = error_code;
    return custom_error;
}

int main()
{
    // Example program that reads from a file and writes to another file
    FILE *fp_read, *fp_write;
    char filename_read[50], filename_write[50], ch;
    int error_code = generateErrorCode();

    // Handle error if file cannot be opened for read
    if (error_code == ERROR_FILE_READ)
    {
        strcpy(filename_read, "non_existent_file.txt");
        fp_read = fopen(filename_read, "r");
        if (fp_read == NULL)
        {
            CustomError custom_error = handleError(ERROR_FILE_READ);
            printf("%s\n", custom_error.error_desc);
            return custom_error.error_code;
        }
    }
    else
    {
        printf("Enter filename to read from: ");
        scanf("%s", filename_read);
        fp_read = fopen(filename_read, "r");
        if (fp_read == NULL)
        {
            CustomError custom_error = handleError(ERROR_FILE_READ);
            printf("%s\n", custom_error.error_desc);
            return custom_error.error_code;
        }
    }

    // Handle error if file cannot be opened for write
    if (error_code == ERROR_FILE_WRITE)
    {
        strcpy(filename_write, "invalid_directory/new_file.txt");
        fp_write = fopen(filename_write, "w");
        if (fp_write == NULL)
        {
            CustomError custom_error = handleError(ERROR_FILE_WRITE);
            printf("%s\n", custom_error.error_desc);
            fclose(fp_read);
            return custom_error.error_code;
        }
    }
    else
    {
        printf("Enter filename to write to: ");
        scanf("%s", filename_write);
        fp_write = fopen(filename_write, "w");
        if (fp_write == NULL)
        {
            CustomError custom_error = handleError(ERROR_FILE_WRITE);
            printf("%s\n", custom_error.error_desc);
            fclose(fp_read);
            return custom_error.error_code;
        }
    }

    // Example program to read from file and write to another file
    while ((ch = fgetc(fp_read)) != EOF)
        fputc(ch, fp_write);

    printf("File copied successfully.\n");

    // Close file pointers
    fclose(fp_read);
    fclose(fp_write);

    return 0;
}