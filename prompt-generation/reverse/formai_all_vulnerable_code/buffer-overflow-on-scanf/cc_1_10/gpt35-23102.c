//FormAI DATASET v1.0 Category: Database querying ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee{
    int empid;
    char empname[20];
    int salary;
};

void insert_record(struct employee *emp, int n){
    for(int i=0;i<n;i++){
        printf("Enter employee id: ");
        scanf("%d",&emp[i].empid);
        printf("Enter employee name: ");
        scanf("%s",&emp[i].empname);
        printf("Enter employee salary: ");
        scanf("%d",&emp[i].salary);
    }
    printf("Records inserted successfully!\n\n");
}

void display_record(struct employee *emp, int n){
    printf("Employee Records:\n");
    printf("------------------\n");
    printf("ID\tName\tSalary\n");
    printf("------------------\n");
    for(int i=0;i<n;i++){
        printf("%d\t%s\t%d\n",emp[i].empid,emp[i].empname,emp[i].salary);
    }
    printf("\n");
}

void search_record(struct employee *emp, int n){
    int id;
    printf("Enter employee id to search: ");
    scanf("%d",&id);
    for(int i=0;i<n;i++){
        if(emp[i].empid == id){
            printf("Record found!\n\n");
            printf("ID\tName\tSalary\n");
            printf("------------------\n");
            printf("%d\t%s\t%d\n",emp[i].empid,emp[i].empname,emp[i].salary);
            return;
        }
    }
    printf("Record not found!\n\n");
}

void update_record(struct employee *emp, int n){
    int id;
    printf("Enter employee id to update: ");
    scanf("%d",&id);
    for(int i=0;i<n;i++){
        if(emp[i].empid == id){
            printf("Record found!\n");
            printf("Enter new salary: ");
            scanf("%d",&emp[i].salary);
            printf("Record updated successfully!\n\n");
            return;
        }
    }
    printf("Record not found!\n\n");
}

void delete_record(struct employee *emp, int *n){
    int id;
    printf("Enter employee id to delete: ");
    scanf("%d",&id);
    for(int i=0;i<*n;i++){
        if(emp[i].empid == id){
            for(int j=i;j<*n-1;j++){
                emp[j] = emp[j+1];
            }
            (*n)--;
            printf("Record deleted successfully!\n\n");
            return;
        }
    }
    printf("Record not found!\n\n");
}

int main(){
    int choice, n=0;
    struct employee *emp = (struct employee *)malloc(sizeof(struct employee));
    while(1){
        printf("Employee Records Management System\n");
        printf("---------------------------------\n");
        printf("1. Insert record\n");
        printf("2. Display all records\n");
        printf("3. Search record\n");
        printf("4. Update record\n");
        printf("5. Delete record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                n++;
                emp = (struct employee *)realloc(emp,sizeof(struct employee)*n);
                insert_record(emp,n);
                break;
            case 2:
                display_record(emp,n);
                break;
            case 3:
                search_record(emp,n);
                break;
            case 4:
                update_record(emp,n);
                break;
            case 5:
                delete_record(emp,&n);
                emp = (struct employee *)realloc(emp,sizeof(struct employee)*n);
                break;
            case 6:
                printf("Thank you for using Employee Records Management System!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    free(emp);
    return 0;
}