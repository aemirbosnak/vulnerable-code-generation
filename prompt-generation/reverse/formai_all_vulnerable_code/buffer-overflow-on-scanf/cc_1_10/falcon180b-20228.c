//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 100

struct person{
    char name[20];
    int age;
    float weight,height;
    char gender[10];
};

void add_person(struct person *ptr, int size){
    printf("\nEnter name: ");
    scanf("%s",ptr->name);
    printf("Enter age: ");
    scanf("%d",&ptr->age);
    printf("Enter weight: ");
    scanf("%f",&ptr->weight);
    printf("Enter height: ");
    scanf("%f",&ptr->height);
    printf("Enter gender: ");
    scanf("%s",ptr->gender);
    size++;
}

void display_person(struct person *ptr, int size){
    printf("\nName\tAge\tWeight\tHeight\tGender\n");
    for(int i=0;i<size;i++){
        printf("%s\t%d\t%.2f\t%.2f\t%s\n",ptr[i].name,ptr[i].age,ptr[i].weight,ptr[i].height,ptr[i].gender);
    }
}

void search_person(struct person *ptr, int size){
    char name[20];
    printf("\nEnter name to search: ");
    scanf("%s",name);
    int flag=0;
    for(int i=0;i<size;i++){
        if(strcmp(ptr[i].name,name)==0){
            printf("\nName found!\n");
            printf("Age: %d\n",ptr[i].age);
            printf("Weight: %.2f\n",ptr[i].weight);
            printf("Height: %.2f\n",ptr[i].height);
            printf("Gender: %s\n",ptr[i].gender);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("\nName not found!");
    }
}

int main(){
    struct person *ptr=(struct person*)malloc(MAX*sizeof(struct person));
    int size=0;
    int choice;
    do{
        printf("\n1.Add person\n2.Display persons\n3.Search person\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter number of persons to add: ");
                scanf("%d",&size);
                for(int i=0;i<size;i++){
                    add_person(ptr,size);
                }
                break;
            case 2:
                display_person(ptr,size);
                break;
            case 3:
                search_person(ptr,size);
                break;
            case 4:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice!");
        }
    }while(choice!=4);
    free(ptr);
    return 0;
}