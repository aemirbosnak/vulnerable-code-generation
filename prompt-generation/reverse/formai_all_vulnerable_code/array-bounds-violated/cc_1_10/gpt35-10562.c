//FormAI DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *srcfile, *destfile;
    char srcfilename[50], destfilename[50], ch;
    int choice;
    
    printf("1. Backup an existing file\n2. Restore a backup file\nEnter your choice: ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1: // Backup a file
            printf("Enter filename to backup: ");
            scanf("%s", srcfilename);
            srcfile = fopen(srcfilename, "r");
            if(srcfile == NULL)
            {
                printf("File not found!\n");
                exit(1);
            }
            strcpy(destfilename, srcfilename); // Create a backup filename by appending ".bak"
            strcat(destfilename, ".bak");
            destfile = fopen(destfilename, "w");
            if(destfile == NULL)
            {
                printf("Error creating backup file!\n");
                exit(1);
            }
            while((ch = fgetc(srcfile)) != EOF) // Copy the content from source file to backup file
            {
                fputc(ch, destfile);
            }
            fclose(srcfile);
            fclose(destfile);
            printf("\nBackup created successfully with filename %s.\n", destfilename);
            break;
            
        case 2: // Restore a backup file
            printf("Enter backup filename to restore: ");
            scanf("%s", srcfilename);
            srcfile = fopen(srcfilename, "r");
            if(srcfile == NULL)
            {
                printf("File not found!\n");
                exit(1);
            }
            strcpy(destfilename, srcfilename);
            destfilename[strlen(destfilename) - 4] = '\0'; // Remove ".bak" extension from backup filename
            destfile = fopen(destfilename, "w");
            if(destfile == NULL)
            {
                printf("Error restoring backup file!\n");
                exit(1);
            }
            while((ch = fgetc(srcfile)) != EOF) // Copy the content from backup file to original file
            {
                fputc(ch, destfile);
            }
            fclose(srcfile);
            fclose(destfile);
            printf("\nBackup restored successfully to file %s.\n", destfilename);
            break;
            
        default:
            printf("Invalid choice!\n");
            exit(1);
    }
    
    return 0;
}