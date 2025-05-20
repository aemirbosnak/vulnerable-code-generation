//FormAI DATASET v1.0 Category: System boot optimizer ; Style: automated
#include <stdio.h>

int main()
{
    printf("Welcome to C System boot optimizer!\n");
    printf("This program will optimize your system's booting process.\n");

    // Step 1: Disable unnecessary startup programs
    printf("Do you want to disable unnecessary startup programs (y/n)? ");
    char choose_disable_startup;
    scanf("%c", &choose_disable_startup);

    if (choose_disable_startup == 'y' || choose_disable_startup == 'Y')
    {
        printf("Disabling unnecessary startup programs...\n");
        // Code to disable unnecessary startup programs goes here
    }
    else
    {
        printf("Skipping disabling unnecessary startup programs...\n");
    }

    // Step 2: Clean up temporary files
    printf("Do you want to clean up temporary files (y/n)? ");
    char choose_cleanup_temp_files;
    scanf("%c", &choose_cleanup_temp_files);

    if (choose_cleanup_temp_files == 'y' || choose_cleanup_temp_files =='Y')
    {
        printf("Cleaning up temporary files...\n");
        // Code to clean up temporary files goes here
    }
    else
    {
        printf("Skipping cleaning up temporary files...\n");
    }

    // Step 3: Defragment hard disk
    printf("Do you want to defragment your hard disk (y/n)? ");
    char choose_defragment;
    scanf("%c", &choose_defragment);

    if (choose_defragment == 'y' || choose_defragment == 'Y')
    {
        printf("Defragmenting hard disk...\n");
        // Code to defragment hard disk goes here
    }
    else
    {
        printf("Skipping defragmenting hard disk...\n");
    }

    // Step 4: Update drivers
    printf("Do you want to update drivers (y/n)? ");
    char choose_update_drivers;
    scanf("%c", &choose_update_drivers);

    if (choose_update_drivers == 'y' || choose_update_drivers == 'Y')
    {
        printf("Updating drivers...\n");
        // Code to update drivers goes here
    }
    else
    {
        printf("Skipping updating drivers...\n");
    }

    printf("System boot optimization completed!\n");

    return 0;
}