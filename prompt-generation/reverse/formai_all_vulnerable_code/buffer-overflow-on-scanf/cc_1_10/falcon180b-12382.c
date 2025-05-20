//Falcon-180B DATASET v1.0 Category: Memory management ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct{
    char name[20];
    int age;
    char address[50];
}student;

void main(){
    int i,n;
    FILE *fp;
    student s[MAX];
    char ch;

    printf("Enter the number of students: ");
    scanf("%d",&n);

    fp=fopen("student.dat","wb");

    if(fp==NULL){
        printf("Error in opening file");
        exit(0);
    }

    for(i=0;i<n;i++){
        printf("\nEnter the name of student %d: ",i+1);
        scanf("%s",s[i].name);

        printf("Enter the age of student %s: ",s[i].name);
        scanf("%d",&s[i].age);

        printf("Enter the address of student %s: ",s[i].name);
        scanf("%s",s[i].address);

        fwrite(&s[i],sizeof(student),1,fp);
    }

    fclose(fp);

    printf("\nThe data has been written to the file successfully");

    fp=fopen("student.dat","rb");

    if(fp==NULL){
        printf("Error in opening file");
        exit(0);
    }

    while((ch=fgetc(fp))!=EOF){
        if(ch=='\n'){
            printf("\n");
        }
        else{
            printf("%c",ch);
        }
    }

    fclose(fp);
}