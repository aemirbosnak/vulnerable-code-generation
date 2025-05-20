//FormAI DATASET v1.0 Category: File Synchronizer ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>

//function to copy a file from source directory to destination directory
void copy_file(char source[], char destination[]){
    FILE *fptr1, *fptr2;
    char c;
    //opening both files in respective directories
    fptr1 = fopen(source, "r");
    fptr2 = fopen(destination, "w");
    //if either directory is not accessible, display error message
    if(fptr1 == NULL || fptr2 == NULL){
        printf("\nError opening file!");
        return;
    }
    //copying contents of source file to destination file
    c = fgetc(fptr1);
    while (c != EOF){
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
    printf("\nFile copied successfully!");
    fclose(fptr1);
    fclose(fptr2);
}

//function to compare two files and copy the new or modified files to destination directory
void synchronize_files(char source[], char destination[]){
    DIR *dir1, *dir2;
    struct dirent *dirent1, *dirent2;
    struct stat file1, file2;
    int flag;
    //opening both directories and checking for accessibility
    dir1 = opendir(source);
    dir2 = opendir(destination);
    if(dir1 == NULL || dir2 == NULL){
        printf("\nError opening directory!");
        return;
    }
    //reading files in source directory
    while((dirent1 = readdir(dir1)) != NULL){
        char file_path1[100], file_path2[100];
        strcpy(file_path1, source);
        strcat(file_path1, "/");
        strcat(file_path1, dirent1->d_name);
        //if file is not a directory in source directory
        if(!(dirent1->d_type & DT_DIR)){
            flag = 0;
            //reading files in destination directory
            while((dirent2 = readdir(dir2)) != NULL){
                strcpy(file_path2, destination);
                strcat(file_path2, "/");
                strcat(file_path2, dirent2->d_name);
                //if file is not a directory in destination directory
                if(!(dirent2->d_type & DT_DIR)){
                    //comparing mtime of both files
                    stat(file_path1, &file1);
                    stat(file_path2, &file2);
                    if(file1.st_mtime > file2.st_mtime){
                        flag = 1;
                        copy_file(file_path1, file_path2);
                    }
                    break;
                }
            }
            //if file not found in destination directory, copy the file to destination directory
            if(flag == 0){
                strcpy(file_path2, destination);
                strcat(file_path2, "/");
                strcat(file_path2, dirent1->d_name);
                copy_file(file_path1, file_path2);
            }
        }
    }
    closedir(dir1);
    closedir(dir2);
}

int main(){
    char source[100], destination[100];
    printf("\nEnter the path of the Source Directory: ");
    scanf("%s", source);
    printf("\nEnter the path of the Destination Directory: ");
    scanf("%s", destination);
    //synchronizing files in both directories
    synchronize_files(source, destination);
    return 0;
}