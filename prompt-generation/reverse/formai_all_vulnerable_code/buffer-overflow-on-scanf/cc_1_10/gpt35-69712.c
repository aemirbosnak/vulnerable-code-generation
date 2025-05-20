//FormAI DATASET v1.0 Category: Database simulation ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

struct student{   //student structure
    int id;
    char name[20];
    int marks;
};

void insert(struct student*, int);  
void display(struct student*, int);  
void search(struct student*, int, int);

int main(){
    int n,choice,id;
    struct student *s;
    printf("Enter number of students: ");
    scanf("%d",&n);
    s=(struct student*)malloc(sizeof(struct student)*n);

    while(1){
        printf("\n------- MENU -------\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("--------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                insert(s,n);
                break;
            case 2:
                display(s,n);
                break;
            case 3:
                printf("Enter id: ");
                scanf("%d",&id);
                search(s,n,id);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void insert(struct student *s, int n){
    int i;
    for(i=0;i<n;i++){
        printf("\nEnter details of student %d: \n",i+1);
        printf("ID: ");
        scanf("%d",&s[i].id);
        printf("Name: ");
        scanf("%s",s[i].name);
        printf("Marks: ");
        scanf("%d",&s[i].marks);
    }
}

void display(struct student *s, int n){
    int i;
    printf("\n------------------------------\n");
    printf("ID\tName\tMarks\n");
    printf("------------------------------\n");
    for(i=0;i<n;i++)
        printf("%d\t%s\t%d\n",s[i].id,s[i].name,s[i].marks);
    printf("------------------------------\n");
}

void search(struct student *s, int n, int id){
    int i;
    for(i=0;i<n;i++){
        if(s[i].id==id){
            printf("\n------------------------------\n");
            printf("ID\tName\tMarks\n");
            printf("------------------------------\n");
            printf("%d\t%s\t%d\n",s[i].id,s[i].name,s[i].marks);
            printf("------------------------------\n");
            return;
        }
    }
    printf("Student with ID %d not found\n",id);
}