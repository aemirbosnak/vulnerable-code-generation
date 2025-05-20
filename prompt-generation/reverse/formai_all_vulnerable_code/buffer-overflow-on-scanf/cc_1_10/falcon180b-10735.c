//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>

#define MAX 100

//function to check if file is infected
bool isInfected(char *filename){
    FILE *file;
    char ch;
    int count=0;
    file=fopen(filename,"r");
    if(file==NULL){
        printf("\n File not found ");
        return false;
    }
    while((ch=fgetc(file))!=EOF){
        if(ch=='.' && count==0){
            count++;
        }
        else if(ch=='.' && count==1){
            count++;
        }
        else{
            count=0;
        }
    }
    fclose(file);
    if(count==2){
        return true;
    }
    else{
        return false;
    }
}

//function to scan directory and subdirectory
void scan(char *dir){
    DIR *d;
    struct dirent *dirp;
    d=opendir(dir);
    if(d==NULL){
        printf("\n Directory not found ");
        return;
    }
    while((dirp=readdir(d))!=NULL){
        if(strcmp(dirp->d_name,".")!=0 && strcmp(dirp->d_name,"..")!=0){
            char path[MAX];
            strcat(path,dir);
            strcat(path,"/");
            strcat(path,dirp->d_name);
            if(isInfected(path)){
                printf("\n File infected : %s",dirp->d_name);
            }
        }
    }
    closedir(d);
}

int main(){
    char dir[MAX];
    printf("\n Enter directory path : ");
    scanf("%s",dir);
    scan(dir);
    return 0;
}