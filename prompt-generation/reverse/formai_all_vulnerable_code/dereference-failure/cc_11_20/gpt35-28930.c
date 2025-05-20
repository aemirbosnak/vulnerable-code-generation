//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    printf("My love, like two files on different computers,\n");
    printf("We must synchronize our paths to stay together.\n");
    printf("Let us build a file synchronizer!\n");
    sleep(2);
    printf("\n");

    if(argc != 3)
    {
        printf("Usage: %s <directory1> <directory2>\n", argv[0]);
        printf("Please specify two directories to synchronize.\n");
        exit(EXIT_FAILURE);
    }

    printf("My darling, hand me your files,\n");
    printf("We will compare them and determine their styles.\n");
    sleep(2);
    printf("\n");

    DIR *dir1 = opendir(argv[1]);
    DIR *dir2 = opendir(argv[2]);
    if(dir1 == NULL || dir2 == NULL)
    {
        printf("Could not open directories. Please check your path and try again.\n");
        exit(EXIT_FAILURE);
    }

    printf("Dearest, let us see if our files match,\n");
    printf("We will compare each file to see if they are a catch.\n");
    sleep(2);
    printf("\n");

    struct dirent *file1 = readdir(dir1);
    struct dirent *file2 = readdir(dir2);
    struct stat stats1, stats2;
    char path1[1000], path2[1000];

    while(file1 != NULL && file2 != NULL)
    {
        sprintf(path1, "%s/%s", argv[1], file1->d_name);
        sprintf(path2, "%s/%s", argv[2], file2->d_name);

        if(stat(path1, &stats1) == -1 || stat(path2, &stats2) == -1)
        {
            printf("Error in getting file stats!\n");
            exit(EXIT_FAILURE);
        }

        if(S_ISREG(stats1.st_mode) && S_ISREG(stats2.st_mode))
        {
            if(strcmp(file1->d_name, file2->d_name) == 0)
            {
                if(stats1.st_mtime > stats2.st_mtime)
                {
                    printf("My love, file %s on %s needs to be updated!\n", file1->d_name, argv[2]);
                    printf("We will copy it from %s to %s.\n", argv[1], argv[2]);
                    FILE *fp1 = fopen(path1, "rb");
                    FILE *fp2 = fopen(path2, "wb");
                    char buffer[1000];
                    int count;
                    while((count = fread(buffer, 1, sizeof(buffer), fp1)) > 0)
                    {
                        fwrite(buffer, 1, count, fp2);
                    }
                    fclose(fp1);
                    fclose(fp2);
                    printf("\n");
                }
                else if(stats1.st_mtime < stats2.st_mtime)
                {
                    printf("My love, file %s on %s needs to be updated!\n", file1->d_name, argv[1]);
                    printf("We will copy it from %s to %s.\n", argv[2], argv[1]);
                    FILE *fp1 = fopen(path2, "rb");
                    FILE *fp2 = fopen(path1, "wb");
                    char buffer[1000];
                    int count;
                    while((count = fread(buffer, 1, sizeof(buffer), fp1)) > 0)
                    {
                        fwrite(buffer, 1, count, fp2);
                    }
                    fclose(fp1);
                    fclose(fp2);
                    printf("\n");
                }
                else
                {
                    printf("My soulmate, file %s on both computers are synced!\n", file1->d_name);
                    printf("\n");
                }
                file1 = readdir(dir1);
                file2 = readdir(dir2);
            }
            else if(strcmp(file1->d_name, file2->d_name) < 0)
            {
                printf("My love, file %s on %s is missing!\n", file1->d_name, argv[2]);
                printf("We will copy it from %s to %s.\n", argv[1], argv[2]);
                sprintf(path1, "%s/%s", argv[1], file1->d_name);
                sprintf(path2, "%s/%s", argv[2], file1->d_name);
                FILE *fp1 = fopen(path1, "rb");
                FILE *fp2 = fopen(path2, "wb");
                char buffer[1000];
                int count;
                while((count = fread(buffer, 1, sizeof(buffer), fp1)) > 0)
                {
                    fwrite(buffer, 1, count, fp2);
                }
                fclose(fp1);
                fclose(fp2);
                printf("\n");
                file1 = readdir(dir1);
            }
            else
            {
                printf("My love, file %s on %s is missing!\n", file2->d_name, argv[1]);
                printf("We will copy it from %s to %s.\n", argv[2], argv[1]);
                sprintf(path1, "%s/%s", argv[2], file2->d_name);
                sprintf(path2, "%s/%s", argv[1], file2->d_name);
                FILE *fp1 = fopen(path1, "rb");
                FILE *fp2 = fopen(path2, "wb");
                char buffer[1000];
                int count;
                while((count = fread(buffer, 1, sizeof(buffer), fp1)) > 0)
                {
                    fwrite(buffer, 1, count, fp2);
                }
                fclose(fp1);
                fclose(fp2);
                printf("\n");
                file2 = readdir(dir2);
            }
        }
        else
        {
            file1 = readdir(dir1);
            file2 = readdir(dir2);
        }
    }

    printf("My darling, all files have been synchronized!\n");
    printf("We can now share and use them together.\n");
    sleep(2);
    printf("\n");

    closedir(dir1);
    closedir(dir2);
    return 0;
}