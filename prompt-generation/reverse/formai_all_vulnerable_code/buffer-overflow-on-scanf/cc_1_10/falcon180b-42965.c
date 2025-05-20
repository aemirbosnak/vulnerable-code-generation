//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000
#define MAX_EXT 10
#define MAX_PATH 500

typedef struct{
    char name[MAX_SIZE];
    char ext[MAX_EXT];
}file;

typedef struct{
    char path[MAX_PATH];
    file file;
}backup;

void backup_system(backup *b){
    char *temp;
    FILE *fp;
    temp = strrchr(b->path,'\\');
    if(!temp){
        printf("Invalid Path\n");
        return;
    }
    strcpy(temp,".bak");
    fp = fopen(b->path,"rb");
    if(!fp){
        printf("File not Found\n");
        return;
    }
    rewind(fp);
    fp = fopen(b->path,"wb");
    if(!fp){
        printf("File not Found\n");
        return;
    }
    backup bk;
    while(fscanf(fp,"%s",temp)!=EOF){
        strcpy(bk.file.name,temp);
        strcpy(bk.file.ext,".bak");
        strcpy(bk.path,b->path);
        backup_system(&bk);
    }
    fclose(fp);
}

int main(){
    backup b;
    printf("Enter the File Path: ");
    scanf("%s",b.path);
    backup_system(&b);
    return 0;
}