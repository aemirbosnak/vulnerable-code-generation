//Gemma-7B DATASET v1.0 Category: File handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[255];
    char data[1024];
    int read_size = 0;
    int write_size = 0;

    // Get the file name from the user
    printf("Enter file name: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r");

    // If the file is open, read data from it
    if (fp)
    {
        // Read data from the file
        read_size = fread(data, 1, 1024, fp);

        // Close the file
        fclose(fp);
    }

    // If data was read, write it to the console
    if (read_size)
    {
        // Print the data
        printf("Data read from file: \n");
        printf("%s", data);

        // Get the data to write
        printf("Enter data to write: ");
        scanf("%s", data);

        // Open the file again in write mode
        fp = fopen(filename, "w");

        // If the file is open, write data to it
        if (fp)
        {
            // Write data to the file
            write_size = fwrite(data, 1, read_size, fp);

            // Close the file
            fclose(fp);
        }

        // If data was written, print a success message
        if (write_size)
        {
            printf("Data written to file: \n");
            printf("%s", data);
        }
    }

    return 0;
}