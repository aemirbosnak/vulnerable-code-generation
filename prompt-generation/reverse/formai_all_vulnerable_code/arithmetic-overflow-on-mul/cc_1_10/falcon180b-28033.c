//Falcon-180B DATASET v1.0 Category: File handling ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_FILE_SIZE 1000000 // 1 MB

typedef struct{
    char name[50];
    int age;
    float salary;
}Employee;

int main(){

    FILE *fp;
    Employee emp;
    char ch;
    int count = 0;
    fp = fopen("employee.txt","r"); // open file in read mode
    if(fp == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    while((ch = fgetc(fp))!= EOF){
        if(count == MAX_FILE_SIZE){
            printf("File size exceeded 1 MB\n");
            break;
        }
        if(ch == '\n'){
            printf("\n");
            count = 0;
            emp.age = 0;
            emp.salary = 0;
            strcpy(emp.name,"");
        }
        else if(isdigit(ch)){
            emp.age = emp.age * 10 + ch - '0';
        }
        else if(ch == ','){
            emp.salary = atof(emp.name);
            emp.name[strcspn(emp.name,",")] = '\0'; // remove comma from name
        }
        else{
            strcat(emp.name,&ch);
        }
        count++;
    }

    fclose(fp);

    fp = fopen("employee.txt","w");
    if(fp == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    while(fscanf(fp,"%s %d %f",emp.name,&emp.age,&emp.salary)!= EOF){
        printf("%s %d %.2f\n",emp.name,emp.age,emp.salary);
        fprintf(fp,"%s %d %.2f\n",emp.name,emp.age,emp.salary);
    }

    fclose(fp);

    return 0;
}