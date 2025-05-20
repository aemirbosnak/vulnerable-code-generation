//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include<stdio.h> 
#include<stdlib.h> 
#include<dirent.h> 
#include<string.h> 
#include<sys/stat.h> 

//structure to store file details 
struct File 
{ 
    char name[200]; 
    double size; 
}; 

//function to get file details 
void getFileDetails(char* path, struct File* file) 
{ 
    struct stat st; 
    if(stat(path,&st)==0) 
    { 
        strcpy(file->name,path);
        file->size=st.st_size; 
    } 
} 

//function to check if path is a directory 
int isDir(char* path) 
{ 
    struct stat st; 
    if(stat(path,&st)==0) 
    { 
        if(S_ISDIR(st.st_mode)) 
            return 1; 
    } 
    return 0; 
} 

//function to get disk space used by a directory 
double getDirSize(char* path) 
{ 
    double size=0; 
    DIR* dir; 
    struct dirent* entry; 
    struct File* file; 
    char fullPath[200]; 
    dir=opendir(path); 
    if(dir!=NULL) 
    { 
        while(entry=readdir(dir)) 
        { 
            //skip . and .. directories 
            if(strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0) 
                continue; 
            //create full path 
            strcpy(fullPath,path); 
            strcat(fullPath,"/"); 
            strcat(fullPath,entry->d_name); 
            //get file details 
            file=(struct File*)malloc(sizeof(struct File)); 
            getFileDetails(fullPath,file); 
            //if path is a directory, call recursively 
            if(isDir(fullPath)) 
                size+=getDirSize(fullPath); 
            //add file size 
            size+=file->size; 
            free(file); 
        } 
    } 
    closedir(dir); 
    return size; 
} 

int main() 
{ 
    printf("Disk Space Analyzer\n\n"); 
    printf("Enter directory path: "); 
    char path[200]; 
    scanf("%s",path); 
    printf("\nDisk space used by %s: %.2f KB",path,getDirSize(path)/1024); 
    return 0; 
}