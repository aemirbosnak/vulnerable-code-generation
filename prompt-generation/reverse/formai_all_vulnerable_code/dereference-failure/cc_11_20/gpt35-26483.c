//FormAI DATASET v1.0 Category: Data recovery tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Shape Shifting Data Recovery Tool!\n");
    printf("Please enter the name of the file you wish to recover: ");
    char filename[50];
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        printf("File not found.");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char *data = (char *)malloc(sizeof(char) * size);

    if (data == NULL)
    {
        printf("Unable to allocate memory");
        exit(1);
    }

    int bytes_read = fread(data, sizeof(char), size, fp);
    fclose(fp);

    if (bytes_read != size)
    {
        printf("Error reading file.");
        exit(1);
    }

    printf("File read successfully!\n");
    printf("Data:\n%s\n", data);

    // Now let's do some shape shifting!
    int option;
    printf("Choose an option:\n1. Convert all lowercase letters to uppercase.\n2. Convert all uppercase letters to lowercase.\n3. Convert all spaces to underscores.\n4. Convert all underscores to spaces.\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        for (int i = 0; i < size; i++)
        {
            if (data[i] >= 97 && data[i] <= 122)
            {
                data[i] = data[i] - 32;
            }
        }
        printf("Data successfully converted to uppercase!");
        break;

    case 2:
        for (int i = 0; i < size; i++)
        {
            if (data[i] >= 65 && data[i] <= 90)
            {
                data[i] = data[i] + 32;
            }
        }
        printf("Data successfully converted to lowercase!");
        break;

    case 3:
        for (int i = 0; i < size; i++)
        {
            if (data[i] == ' ')
            {
                data[i] = '_';
            }
        }
        printf("Spaces successfully converted to underscores!");
        break;

    case 4:
        for (int i = 0; i < size; i++)
        {
            if (data[i] == '_')
            {
                data[i] = ' ';
            }
        }
        printf("Underscores successfully converted to spaces!");
        break;

    default:
        printf("Invalid option selected.");
        break;
    }

    // Finally, let's save the changed data to a new file.
    char new_filename[50] = "changed_";
    strcat(new_filename, filename);
    fp = fopen(new_filename, "wb");

    if (fp == NULL)
    {
        printf("Unable to create new file.");
        exit(1);
    }

    fwrite(data, sizeof(char), size, fp);
    fclose(fp);

    printf("Data saved to %s.\n", new_filename);
    free(data);
    return 0;
}