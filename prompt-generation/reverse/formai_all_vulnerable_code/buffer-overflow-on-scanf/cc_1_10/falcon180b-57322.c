//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 1000

struct node{
    char name[30];
    int age;
    int bmi;
    int fitness_level;
};

struct node database[MAX];
int count=0;

void add_data(){
    printf("\nEnter name: ");
    scanf("%s",&database[count].name);

    printf("\nEnter age: ");
    scanf("%d",&database[count].age);

    printf("\nEnter BMI: ");
    scanf("%d",&database[count].bmi);

    printf("\nEnter fitness level (1-10): ");
    scanf("%d",&database[count].fitness_level);

    count++;
}

void display_data(){
    int i;
    for(i=0;i<count;i++){
        printf("\nName: %s",database[i].name);
        printf("\nAge: %d",database[i].age);
        printf("\nBMI: %d",database[i].bmi);
        printf("\nFitness level: %d",database[i].fitness_level);
        printf("\n\n");
    }
}

void search_data(){
    char name[30];
    int i;

    printf("\nEnter name to search: ");
    scanf("%s",name);

    for(i=0;i<count;i++){
        if(strcmp(name,database[i].name)==0){
            printf("\nName: %s",database[i].name);
            printf("\nAge: %d",database[i].age);
            printf("\nBMI: %d",database[i].bmi);
            printf("\nFitness level: %d",database[i].fitness_level);
        }
    }
}

void main(){
    int choice;

    do{
        printf("\n\nFitness Tracker\n");
        printf("\n1. Add data");
        printf("\n2. Display data");
        printf("\n3. Search data");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                add_data();
                break;

            case 2:
                display_data();
                break;

            case 3:
                search_data();
                break;

            case 4:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid choice!");
        }
    }while(choice!=4);
}