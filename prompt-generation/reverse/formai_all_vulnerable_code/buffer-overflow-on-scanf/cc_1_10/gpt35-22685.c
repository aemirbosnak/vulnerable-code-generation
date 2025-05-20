//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

int main()
{
    // Initializing variables
    int total_space, used_space, free_space, i, j;

    // User Inputs
    printf("Enter the total size of disk in GB: ");
    scanf("%d", &total_space);

    printf("Enter the used space of disk in GB: ");
    scanf("%d", &used_space);

    // Calculation of free space
    free_space = total_space - used_space;

    // Calculation of percentage space used
    float percent_space_used = (float) used_space / total_space * 100;

    // Printing the Disk Space Analyzer
    printf("\n\n*** Disk Space Analyzer ***\n\n");
    printf("Total space: %d GB\n", total_space);
    printf("Used space: %d GB\n", used_space);
    printf("Free space: %d GB\n", free_space);

    // Drawing Free Space Bar Char and percentage
    printf("\n Free Space:");
    for(i = 0; i < free_space/4; i++)
    {
        printf("|");
    }
    printf(" %.2f%%", (float) free_space / total_space * 100);

    // Drawing Used Space Bar Char and percentage
    printf("\n Used Space:");
    for(j = 0; j < used_space/4; j++)
    {
        printf("|");
    }
    printf(" %.2f%%", percent_space_used);

   // Displaying the results
    printf("\n\nTotal %d GB disk space is divided into %d GB free space and %d GB used space.\n", total_space, free_space, used_space);

    if(percent_space_used >= 80)
    {
      printf("Disk is almost full. Please remove unnecessary files to free up some space.\n");
    }
    else if(percent_space_used >= 60 && percent_space_used < 80)
    {
      printf("Disk space is more than 60% used.\n");
    }
    else if(percent_space_used < 60)
    {
      printf("You have plenty of disk space.\n");
    }

    return 0;
}