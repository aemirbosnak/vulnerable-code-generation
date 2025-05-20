//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    // Input the file names
    char *f1, *f2, *f3;
    printf("Enter the name of the first file: ");
    scanf("%s", &f1);
    printf("Enter the name of the second file: ");
    scanf("%s", &f2);
    printf("Enter the name of the reference file: ");
    scanf("%s", &f3);

    // Check if files exist
    FILE *fp1, *fp2, *fp3;
    if ((fp1 = fopen(f1, "r")) == NULL || (fp2 = fopen(f2, "r")) == NULL || (fp3 = fopen(f3, "r")) == NULL)
    {
        printf("One or more of the files does not exist.\n");
        return;
    }

    // Read the reference file
    char buf[100];
    while (fgets(buf, sizeof(buf), fp3)!= NULL)
    {
        // Check if line is in the first file
        if (fgets(buf, sizeof(buf), fp1)!= NULL)
        {
            // Check if line is in the second file
            if (fgets(buf, sizeof(buf), fp2)!= NULL)
            {
                // Both lines are in both files, so the files are synchronized
                printf("%s is in both files.\n", buf);
            }
            else
            {
                // Line is in the first file but not in the second file
                printf("%s is in the first file but not in the second file.\n", buf);
            }
        }
        else
        {
            // Line is in the reference file but not in the first file
            printf("%s is in the reference file but not in the first file.\n", buf);
        }
    }

    // Close the files
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}