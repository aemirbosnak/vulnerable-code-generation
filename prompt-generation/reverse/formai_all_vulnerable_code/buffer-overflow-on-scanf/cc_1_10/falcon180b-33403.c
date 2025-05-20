//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<limits.h>

#define SIZE 100

typedef struct{
    char filename[50];
    int size;
    char data[SIZE];
}file;

file *createfile(char *filename){
    file *f = (file *)malloc(sizeof(file));
    strcpy(f->filename,filename);
    return f;
}

int readfile(file *f){
    FILE *fp = fopen(f->filename,"rb");
    if(fp==NULL){
        printf("Cannot open file\n");
        exit(1);
    }
    fseek(fp,0,SEEK_END);
    f->size = ftell(fp);
    rewind(fp);
    if(f->size>SIZE){
        printf("File is too large\n");
        exit(1);
    }
    fread(f->data,1,f->size,fp);
    fclose(fp);
}

int writefile(file *f){
    FILE *fp = fopen(f->filename,"wb");
    if(fp==NULL){
        printf("Cannot open file\n");
        exit(1);
    }
    fwrite(f->data,1,f->size,fp);
    fclose(fp);
}

int recoverfile(file *f){
    FILE *fp = fopen(f->filename,"wb");
    if(fp==NULL){
        printf("Cannot open file\n");
        exit(1);
    }
    char ch;
    int count = 0;
    while((ch=fgetc(stdin))!=EOF){
        if(isprint(ch)){
            fputc(ch,fp);
            count++;
        }
    }
    fclose(fp);
    printf("Recovered %d characters\n",count);
}

int main(){
    char filename[50];
    printf("Enter filename: ");
    scanf("%s",filename);
    file *f = createfile(filename);
    readfile(f);
    recoverfile(f);
    writefile(f);
    return 0;
}