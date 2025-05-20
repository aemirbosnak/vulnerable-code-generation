//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

int scan_file(char *filename);
int scan_dir(char *dirname);

int main()
{
    char path[100];
    printf("Enter the filepath to scan:\t");
    scanf("%s", path);
    if(scan_file(path))
        printf("Virus detected in file %s\n", path);
    else
        printf("File %s is clean\n", path);
    return 0;
}

int scan_file(char *filename)
{
    FILE *fp;
    char buffer[100];
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Cannot open file %s", filename);
        return -1;
    }
    // scan the contents of the file here
    while(fgets(buffer, 100, fp))
    {
        if(strstr(buffer, "virus"))
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int scan_dir(char *dirname)
{
    struct dirent *dp;
    DIR *dir;
    dir = opendir(dirname);
    if(dir == NULL)
    {
        printf("Cannot open directory %s", dirname);
        return -1;
    }
    while((dp = readdir(dir)) != NULL)
    {
        char path[100];
        sprintf(path, "%s/%s", dirname, dp->d_name);
        if(dp->d_type == DT_REG)
        {
            if(scan_file(path))
            {
                printf("Virus detected in file %s\n", path);
            }
        }
        else if(dp->d_type == DT_DIR)
        {
            if((strcmp(dp->d_name, ".") != 0) && (strcmp(dp->d_name, "..") != 0))
            {
                scan_dir(path);
            }
        }
    }
    closedir(dir);
    return 0;
}