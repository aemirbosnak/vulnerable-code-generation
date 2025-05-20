//FormAI DATASET v1.0 Category: Database simulation ; Style: intelligent
#include<stdio.h> 

struct Student{
    int id;
    char name[20];
    float marks;
};

struct Student read(){
    struct Student s;
    printf("\nEnter student id : ");
    scanf("%d",&s.id);
    printf("Enter student name : ");
    scanf("%s",s.name);
    printf("Enter marks : ");
    scanf("%f",&s.marks);
    return s;
}

void print(struct Student s){
    printf("\nStudent id : %d",s.id);
    printf("\nStudent name : %s",s.name);
    printf("\nMarks : %.2f",s.marks);
}

void insert(struct Student s, struct Student list[], int *count){
    list[*count] = s;
    (*count)++;
    printf("\nRecord Inserted Successfully!");
}

void delete(int id, struct Student list[], int *count){
    int i,index=-1;
    for(i=0;i<*count;i++){
        if(list[i].id == id){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("\nRecord not found!");
        return;
    }
    for(i=index;i<*count-1;i++){
        list[i] = list[i+1];
    }
    (*count)--;
    printf("\nRecord Deleted Successfully!");
}

void search(int id, struct Student list[], int *count){
    int i,index=-1;
    for(i=0;i<*count;i++){
        if(list[i].id == id){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("\nRecord not found!");
        return;
    }
    print(list[index]);
}

void update(int id, struct Student list[], int *count){
    int i,index=-1;
    for(i=0;i<*count;i++){
        if(list[i].id == id){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("\nRecord not found!");
        return;
    }
    printf("\nEnter updated student name : ");
    scanf("%s",list[index].name);
    printf("Enter updated marks : ");
    scanf("%f",&list[index].marks);
    printf("\nRecord Updated Successfully!");
}

void display(struct Student list[], int *count){
    int i;
    if(*count == 0){
        printf("\nDatabase is empty!");
        return;
    }
    printf("\nDatabase : \n");
    for(i=0;i<*count;i++){
        print(list[i]);
    }
    printf("\n");
}

int main(){
    struct Student list[100];
    int choice,id,count=0;
    do{
        printf("\n\n***SIMULATION OF DATABASE OPERATIONS***\n");
        printf("\n1. Insert a record\n2. Delete a record\n3. Search a record\n4. Update a record\n5. Display all records\n6. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert(read(),list,&count);
                break;
            case 2:
                printf("\nEnter the student id to be deleted : ");
                scanf("%d",&id);
                delete(id,list,&count);
                break;
            case 3:
                printf("\nEnter the student id to be searched : ");
                scanf("%d",&id);
                search(id,list,&count);
                break;
            case 4:
                printf("\nEnter the student id to be updated : ");
                scanf("%d",&id);
                update(id,list,&count);
                break;
            case 5:
                display(list,&count);
                break;
            case 6:
                printf("\nThank you!\n");
                break;
            default:
                printf("\nInvalid choice! Please select a valid option.");
                break;
        }
    }while(choice!=6);
    return 0;
}