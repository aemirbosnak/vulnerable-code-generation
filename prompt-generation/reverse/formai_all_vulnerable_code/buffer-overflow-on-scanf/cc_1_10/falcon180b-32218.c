//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct{
    char name[10];
    int rollno;
}student;

student arr[MAX];
int n;

void read_data(){
    printf("Enter the number of students: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the name and rollno of student %d: ",i+1);
        scanf("%s %d",arr[i].name,&arr[i].rollno);
    }
}

void display_data(){
    printf("\nName\tRoll No\n");
    for(int i=0;i<n;i++){
        printf("%s\t%d\n",arr[i].name,arr[i].rollno);
    }
}

void search_data(){
    printf("\nEnter the name to search: ");
    char name[20];
    scanf("%s",name);
    int found=0;
    for(int i=0;i<n;i++){
        if(strcmp(name,arr[i].name)==0){
            printf("\nName: %s\nRoll No: %d",arr[i].name,arr[i].rollno);
            found=1;
            break;
        }
    }
    if(found==0){
        printf("\nName not found!");
    }
}

int main(){
    read_data();
    display_data();
    printf("\nEnter 1 to search data\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        search_data();
    }
    return 0;
}