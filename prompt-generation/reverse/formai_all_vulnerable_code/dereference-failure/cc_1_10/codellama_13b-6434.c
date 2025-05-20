//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: cheerful
/*
 * File Backup System Example Program
 *
 * This program allows the user to backup a file to a different location.
 * The program prompts the user for the file name and location of the backup,
 * and then copies the file to the specified location.
 *
 * Usage:
 *   1. Compile the program with a C compiler.
 *   2. Run the program and enter the file name and location of the backup.
 *   3. The program will copy the file to the specified location.
 *
 * Author:
 *   1. Your Name
 *   2. Your Email
 *   3. Date
 *
 * Compiler:
 *   1. gcc (GCC) 11.2.0
 *
 * Compilation Command:
 *   gcc -Wall -o backup backup.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    char file_name[100];
    char backup_name[100];
    char *file_path;
    char *backup_path;
    FILE *fp;
    FILE *bfp;

    // Prompt user for file name
    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Prompt user for backup location
    printf("Enter the backup location: ");
    scanf("%s", backup_name);

    // Construct file paths
    file_path = malloc(strlen(file_name) + 1);
    strcpy(file_path, file_name);
    backup_path = malloc(strlen(backup_name) + 1);
    strcpy(backup_path, backup_name);

    // Open file for reading
    fp = fopen(file_path, "r");
    if (fp == NULL)
    {
        printf("Error: Could not open file for reading.\n");
        return 1;
    }

    // Open backup file for writing
    bfp = fopen(backup_path, "w");
    if (bfp == NULL)
    {
        printf("Error: Could not open backup file for writing.\n");
        return 1;
    }

    // Copy file to backup location
    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        fputc(c, bfp);
    }

    // Close files
    fclose(fp);
    fclose(bfp);

    // Print confirmation message
    printf("File backup complete.\n");

    return 0;
}