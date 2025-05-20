//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

void synchronize(const char *dir1, const char *dir2)
{
    DIR *d1, *d2;
    struct dirent *dir1_entry, *dir2_entry;
    struct stat st;
    const char *file1, *file2;
    int found1, found2;

    if ((d1 = opendir(dir1)) == NULL)
    {
        perror("opendir error");
        return;
    }
    if ((d2 = opendir(dir2)) == NULL)
    {
        perror("opendir error");
        return;
    }

    while ((dir1_entry = readdir(d1))!= NULL)
    {
        if (strcmp(dir1_entry->d_name, ".") == 0 || strcmp(dir1_entry->d_name, "..") == 0)
            continue;

        found1 = stat(dir1_entry->d_name, &st);
        if (found1 == 0 && S_ISDIR(st.st_mode))
        {
            synchronize(dir1_entry->d_name, dir2);
        }
        else if (found1 == 0 && S_ISREG(st.st_mode))
        {
            file1 = dir1_entry->d_name;
        }
    }
    closedir(d1);

    while ((dir2_entry = readdir(d2))!= NULL)
    {
        if (strcmp(dir2_entry->d_name, ".") == 0 || strcmp(dir2_entry->d_name, "..") == 0)
            continue;

        found2 = stat(dir2_entry->d_name, &st);
        if (found2 == 0 && S_ISDIR(st.st_mode))
        {
            synchronize(dir2_entry->d_name, dir1);
        }
        else if (found2 == 0 && S_ISREG(st.st_mode))
        {
            file2 = dir2_entry->d_name;
        }
    }
    closedir(d2);

    if (found1 == 0 && found2 == 0)
    {
        printf("Directory synchronisation complete.\n");
        return;
    }

    if (found1 == 0 && found2 == 1)
    {
        printf("File '%s' was found in '%s' but not in '%s'.\n", file2, dir2, dir1);
        FILE *fp = fopen(dir1, "w");
        if (fp == NULL)
        {
            perror("fopen error");
            return;
        }
        fprintf(fp, "File '%s' was found in '%s' but not in '%s'.\n", file2, dir2, dir1);
        fclose(fp);
    }
    else if (found1 == 1 && found2 == 0)
    {
        printf("File '%s' was found in '%s' but not in '%s'.\n", file1, dir1, dir2);
        FILE *fp = fopen(dir2, "w");
        if (fp == NULL)
        {
            perror("fopen error");
            return;
        }
        fprintf(fp, "File '%s' was found in '%s' but not in '%s'.\n", file1, dir1, dir2);
        fclose(fp);
    }
}

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        printf("Usage: %s source destination\n", argv[0]);
        return 1;
    }

    synchronize(argv[1], argv[2]);

    return 0;
}