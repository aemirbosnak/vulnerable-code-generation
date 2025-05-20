//Falcon-180B DATASET v1.0 Category: File handling ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct student{
    char name[MAX];
    int age;
    float grade;
};

void swap(struct student *a,struct student *b){
    struct student temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void sort(struct student arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(strcmp(arr[j].name,arr[j+1].name)>0){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

int main(){
    FILE *fp;
    char ch;
    int count=0;
    struct student arr[MAX];
    fp=fopen("data.txt","r");
    if(fp==NULL){
        printf("File does not exist");
        exit(1);
    }
    while((ch=fgetc(fp))!=EOF){
        if(ch=='\n'){
            count++;
        }
    }
    rewind(fp);
    for(int i=0;i<count;i++){
        fscanf(fp,"%s %d %f",arr[i].name,&arr[i].age,&arr[i].grade);
    }
    sort(arr,count);
    printf("\nSorted Data:\n");
    for(int i=0;i<count;i++){
        printf("Name: %s\nAge: %d\nGrade: %.2f\n",arr[i].name,arr[i].age,arr[i].grade);
    }
    fclose(fp);
    return 0;
}