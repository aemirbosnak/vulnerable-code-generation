//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define max 100

struct{
    int id;
    char name[10];
    int age;
    char gender;
    int phone;
    char email[15];
}s;

int main(){
    int i,j,n,ch;
    char str[50];
    FILE *fp;

    fp=fopen("romeo.txt","r");
    if(fp==NULL){
        printf("File does not exist\n");
        exit(0);
    }

    printf("\nID\tName\tAge\tGender\tPhone\tEmail\n");

    while(!feof(fp)){
        fscanf(fp,"%d %s %d %c %d %s\n",&s.id,s.name,&s.age,&s.gender,&s.phone,s.email);
        printf("%d\t%s\t%d\t%c\t%d\t%s\n",s.id,s.name,s.age,s.gender,s.phone,s.email);
    }

    fclose(fp);

    printf("\nEnter the ID of the person you want to search: ");
    scanf("%d",&n);

    fp=fopen("romeo.txt","r");
    rewind(fp);

    while(!feof(fp)){
        fscanf(fp,"%d %s %d %c %d %s\n",&s.id,s.name,&s.age,&s.gender,&s.phone,s.email);
        if(s.id==n){
            printf("\nID\tName\tAge\tGender\tPhone\tEmail\n");
            printf("%d\t%s\t%d\t%c\t%d\t%s\n",s.id,s.name,s.age,s.gender,s.phone,s.email);
        }
    }

    fclose(fp);

    return 0;
}