//FormAI DATASET v1.0 Category: Data recovery tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char old_file[50], new_file[50], c[1000];
    FILE *fp1, *fp2;
    int i, len;

    printf("Enter name of file to recover: ");
    scanf("%s", old_file);

    // Open the file in read mode
    fp1 = fopen(old_file, "r");
    if (fp1 == NULL)
    {
        printf("Error: Cannot open file");
        exit(0);
    }

    // Get the length of the file
    fseek(fp1, 0, SEEK_END);
    len = ftell(fp1);
    fseek(fp1, 0, SEEK_SET);

    // Create a new file to write the recovered data
    strncpy(new_file, old_file, strlen(old_file) - 4);
    new_file[strlen(old_file) - 4] = '\0';
    strcat(new_file, "_recovered.txt");

    fp2 = fopen(new_file, "w");
    if (fp2 == NULL)
    {
        printf("Error: Cannot create new file");
        exit(0);
    }

    // Read the data from the old file and write it to the new file
    for (i = 0; i < len; i++)
    {
        c[i] = fgetc(fp1);
        if (c[i] == '\r')
        {
            i--;
            continue;
        }
        fputc(c[i], fp2);
    }

    printf("Data recovered successfully\n");
    printf("Recovered data stored in file: %s", new_file);

    fclose(fp1);
    fclose(fp2);
    return 0;
}