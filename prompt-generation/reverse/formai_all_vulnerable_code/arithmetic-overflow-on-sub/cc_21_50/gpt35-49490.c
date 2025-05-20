//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

#define GB 1073741824    // 1 GB = 1024^3 bytes
#define MB 1048576      // 1 MB = 1024^2 bytes
#define KB 1024         // 1 KB = 1024 bytes

int main(int argc,char *argv[])
{
    DIR *dir;
    struct dirent *entry;
    struct stat filestat;
    char path[1024], fullname[1024];
    int total_size=0,exec_size=0,dir_size=0,lib_size=0,other_size=0,cal_size=0;
    char *ext;

    strcpy(path,".");    // root directory
    if(argc==2)
        strcpy(path,argv[1]);

    dir=opendir(path);
    while((entry=readdir(dir)))
    {
        strcpy(fullname,path);
        strcat(fullname,"/");
        strcat(fullname,entry->d_name);
        if(stat(fullname,&filestat))
            continue;

        // add size of directory and its contents recursively
        if(S_ISDIR(filestat.st_mode))
        {
            if((strcmp(".",entry->d_name)==0) || (strcmp("..",entry->d_name)==0))
                continue;
            total_size+=filestat.st_size;
            continue;
        }

        // add size of executable files
        ext=strrchr(entry->d_name,'.');
        if(ext!=NULL && (strcmp(".exe",ext)==0 || strcmp(".dll",ext)==0 || strcmp(".so",ext)==0))
            exec_size+=filestat.st_size;

        // add size of directories that may contain libraries
        ext=strrchr(fullname,'/');
        if(ext!=NULL && (strcmp("/lib",ext)==0 || strcmp("/lib32",ext)==0 || strcmp("/lib64",ext)==0 || strcmp("/usr/lib",ext)==0 || strcmp("/usr/lib32",ext)==0 || strcmp("/usr/lib64",ext)==0))
            lib_size+=filestat.st_size;

        // add size of other files
        other_size+=filestat.st_size;
    }
    closedir(dir);

    // calculate directory size and print results
    dir_size=total_size-(exec_size+lib_size+other_size);
    printf("\nTotal size of directory: ");
    if(total_size>GB)
        printf("%d GB ",total_size/GB);
    else if(total_size>MB)
        printf("%d MB ",total_size/MB);
    else if(total_size>KB)
        printf("%d KB ",total_size/KB);
    else
        printf("%d bytes ",total_size);
    printf("(%d bytes)\n",total_size);

    printf("Size of executable files: ");
    if(exec_size>GB)
        printf("%d GB ",exec_size/GB);
    else if(exec_size>MB)
        printf("%d MB ",exec_size/MB);
    else if(exec_size>KB)
        printf("%d KB ",exec_size/KB);
    else
        printf("%d bytes ",exec_size);
    printf("(%d bytes)\n",exec_size);

    printf("Size of library directories: ");
    if(lib_size>GB)
        printf("%d GB ",lib_size/GB);
    else if(lib_size>MB)
        printf("%d MB ",lib_size/MB);
    else if(lib_size>KB)
        printf("%d KB ",lib_size/KB);
    else
        printf("%d bytes ",lib_size);
    printf("(%d bytes)\n",lib_size);

    printf("Size of regular files and directories: ");
    if(dir_size>GB)
        printf("%d GB ",dir_size/GB);
    else if(dir_size>MB)
        printf("%d MB ",dir_size/MB);
    else if(dir_size>KB)
        printf("%d KB ",dir_size/KB);
    else
        printf("%d bytes ",dir_size);
    printf("(%d bytes)\n",dir_size);

    printf("Size of other files: ");
    if(other_size>GB)
        printf("%d GB ",other_size/GB);
    else if(other_size>MB)
        printf("%d MB ",other_size/MB);
    else if(other_size>KB)
        printf("%d KB ",other_size/KB);
    else
        printf("%d bytes ",other_size);
    printf("(%d bytes)\n",other_size);

    return 0;
}