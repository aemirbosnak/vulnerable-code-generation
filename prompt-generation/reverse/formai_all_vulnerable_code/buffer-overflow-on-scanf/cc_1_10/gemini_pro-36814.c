//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

// Bada-bing, a C File Synchronizer that'll make you jump for joy!

int compareFiles(char *file1, char *file2);
void syncFiles(char *src, char *dest);
void copyFile(char *src, char *dest);
void deleteFile(char *file);
void createDirectory(char *dir);

int main()
{
    // Let's get this party started!
    printf("** Welcome to the C File Synchronizer Spectacular! **\n");
    printf("Get ready to witness the ultimate file-syncing showdown!\n\n");

    // Cue the music, it's time for setup time!
    char srcDir[1024], destDir[1024];
    printf("Enter the source directory: ");
    scanf("%s", srcDir);
    printf("Enter the destination directory: ");
    scanf("%s", destDir);

    // Now, let's check if everything's in order...
    struct stat srcStat, destStat;
    if (stat(srcDir, &srcStat) == -1)
    {
        printf("Oops! Source directory not found. Check again!");
        exit(-1);
    }
    if (!S_ISDIR(srcStat.st_mode))
    {
        printf("Hold your horses! Source is not a directory!");
        exit(-1);
    }

    if (stat(destDir, &destStat) == -1)
    {
        // Don't worry, we'll create it for you!
        printf("Destination directory not found? No problem, we'll make it!");
        if (mkdir(destDir, 0777) == -1)
        {
            printf("Uh-oh! Couldn't create the destination directory.");
            exit(-1);
        }
    }
    else if (!S_ISDIR(destStat.st_mode))
    {
        printf("Hang on! Destination is not a directory!");
        exit(-1);
    }

    // Time to sync the files, baby!
    syncFiles(srcDir, destDir);

    // And now, for the grand finale!
    printf("\n** File sync complete! **\n");
    printf("Your files have been harmonized like a heavenly choir!\n\n");

    return 0;
}

// The heart of our sync engine: compareFiles!
int compareFiles(char *file1, char *file2)
{
    // Size check first, it's a quick way to spot differences.
    struct stat stat1, stat2;
    if (stat(file1, &stat1) == -1 || stat(file2, &stat2) == -1)
    {
        return 1;
    }
    if (stat1.st_size != stat2.st_size)
    {
        return 1;
    }

    // Time for a deeper dive: compare the contents byte by byte.
    FILE *fp1 = fopen(file1, "rb");
    FILE *fp2 = fopen(file2, "rb");
    int byte1, byte2;
    while ((byte1 = fgetc(fp1)) != EOF && (byte2 = fgetc(fp2)) != EOF)
    {
        if (byte1 != byte2)
        {
            fclose(fp1);
            fclose(fp2);
            return 1;
        }
    }
    fclose(fp1);
    fclose(fp2);

    // If we made it all the way through, they must be identical!
    return 0;
}

// The magic behind our file synchronization: syncFiles!
void syncFiles(char *src, char *dest)
{
    // Let's explore the source directory.
    DIR *srcDir = opendir(src);
    if (srcDir == NULL)
    {
        printf("Oops! Couldn't open the source directory.");
        exit(-1);
    }

    // Time to venture into the destination directory.
    DIR *destDir = opendir(dest);
    if (destDir == NULL)
    {
        printf("Oops! Couldn't open the destination directory.");
        exit(-1);
    }

    // Let's start by comparing files one by one.
    struct dirent *srcEntry, *destEntry;
    while ((srcEntry = readdir(srcDir)) != NULL)
    {
        // Skip the '.' and '..' entries.
        if (!strcmp(srcEntry->d_name, ".") || !strcmp(srcEntry->d_name, ".."))
        {
            continue;
        }

        // Construct the full file paths.
        char srcFile[1024], destFile[1024];
        sprintf(srcFile, "%s/%s", src, srcEntry->d_name);
        sprintf(destFile, "%s/%s", dest, srcEntry->d_name);

        // Check if the file exists in the destination directory.
        destEntry = NULL;
        while ((destEntry = readdir(destDir)) != NULL)
        {
            if (!strcmp(destEntry->d_name, srcEntry->d_name))
            {
                break;
            }
        }

        // If it doesn't exist, create it.
        if (destEntry == NULL)
        {
            printf("File %s not found in destination. Copying...\n", srcFile);
            copyFile(srcFile, destFile);
            continue;
        }

        // If it does exist, compare the files.
        if (compareFiles(srcFile, destFile))
        {
            printf("File %s has changed. Updating...\n", srcFile);
            copyFile(srcFile, destFile);
        }
    }

    // Time to clean up: close those directories.
    closedir(srcDir);
    closedir(destDir);
}

// The file-copying wizard: copyFile!
void copyFile(char *src, char *dest)
{
    // Let's read the source file.
    FILE *srcFile = fopen(src, "rb");
    if (srcFile == NULL)
    {
        printf("Oops! Couldn't open the source file.");
        exit(-1);
    }

    // Now, let's write to the destination file.
    FILE *destFile = fopen(dest, "wb");
    if (destFile == NULL)
    {
        printf("Oops! Couldn't open the destination file.");
        exit(-1);
    }

    // Time to transfer the bytes!
    int byte;
    while ((byte = fgetc(srcFile)) != EOF)
    {
        fputc(byte, destFile);
    }

    // All done, let's close the files.
    fclose(srcFile);
    fclose(destFile);
}

// The file-deleting dynamo: deleteFile!
void deleteFile(char *file)
{
    if (remove(file) == -1)
    {
        printf("Oops! Couldn't delete the file.");
        exit(-1);
    }
}

// The directory-creating wonder: createDirectory!
void createDirectory(char *dir)
{
    if (mkdir(dir, 0777) == -1)
    {
        printf("Oops! Couldn't create the directory.");
        exit(-1);
    }
}