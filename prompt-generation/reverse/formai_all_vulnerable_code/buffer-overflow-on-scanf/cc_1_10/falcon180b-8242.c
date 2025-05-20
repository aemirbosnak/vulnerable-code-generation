//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<locale.h>
#define SIZE 100

typedef struct{
    char name[30];
    int age;
    float height;
}person;

void add_person(person* list, int count, char name[30], int age, float height){
    strcpy(list[count].name,name);
    list[count].age=age;
    list[count].height=height;
}

void print_person(person* list, int count){
    printf("\nName: %s",list[count].name);
    printf("\nAge: %d",list[count].age);
    printf("\nHeight: %.2f",list[count].height);
}

int main(){
    setlocale(LC_ALL,"");
    person list[SIZE];
    int count=0;
    char name[30];
    int age;
    float height;
    while(true){
        printf("\nEnter name: ");
        scanf("%s",name);
        if(name[0]=='q') break;
        printf("\nEnter age: ");
        scanf("%d",&age);
        printf("\nEnter height: ");
        scanf("%f",&height);
        add_person(list,count,name,age,height);
        count++;
    }
    printf("\nList of people:\n");
    for(int i=0;i<count;i++){
        print_person(list,i);
    }
    return 0;
}