//FormAI DATASET v1.0 Category: Database Indexing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct database{
    char name[20];
    int age;
    float salary;
} Record;

/*Searches for a record based on the given index*/
int search(Record *database, char *index, int size){
    int found = 0;
    for(int i=0;i<size;i++){
        if(strcmp(database[i].name,index)==0){
            printf("Record found:\nName: %s\nAge: %d\nSalary: %.2f\n",database[i].name,database[i].age,database[i].salary);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Record not found for index %s.\n",index);
    }
    return found;
}

/*Adds a new record to the database*/
void addRecord(Record *database, int *size){
    printf("Enter name: ");
    scanf("%s",database[*size].name);
    printf("Enter age: ");
    scanf("%d",&database[*size].age);
    printf("Enter salary: ");
    scanf("%f",&database[*size].salary);
    printf("Record added successfully.\n\n");
    (*size)++;
}

/*Deletes a record based on the given index*/
void deleteRecord(Record *database, char *index, int *size){
    int found = 0;
    for(int i=0;i<*size;i++){
        if(strcmp(database[i].name,index)==0){
            found = 1;
            for(int j=i;j<*size-1;j++){
                database[j] = database[j+1];
            }
            (*size)--;
            printf("Record deleted successfully.\n\n");
            break;
        }
    }
    if(!found){
        printf("Record not found for index %s.\n",index);
    }
}

/*Prints all records in the database*/
void printAll(Record *database, int size){
    printf("-----------------\n");
    printf("|   DATABASE    |\n");
    printf("-----------------\n");
    for(int i=0;i<size;i++){
        printf("Name: %s\nAge: %d\nSalary: %.2f\n\n",database[i].name,database[i].age,database[i].salary);
    }
}

int main(){
    printf("Welcome to the Database Indexing System.\n");
    int choice, size = 0; 
    Record *database = (Record*) malloc(sizeof(Record)*100);

    do{
        printf("Choose an option:\n");
        printf("1. Search for a record\n");
        printf("2. Add a new record\n");
        printf("3. Delete a record\n");
        printf("4. Print all records\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        printf("\n");

        switch(choice){
            case 1:{
                char index[20];
                printf("Enter index to search for: ");
                scanf("%s",index);
                search(database,index,size);
                break;
            }
            case 2:{
                addRecord(database,&size);
                break;
            }
            case 3:{
                char index[20];
                printf("Enter index to delete: ");
                scanf("%s",index);
                deleteRecord(database,index,&size);
                break;
            }
            case 4:{
                printAll(database,size);
                break;
            }
            case 5:{
                printf("Thank you for using the Database Indexing System.\n");
                break;
            }
            default:{
                printf("Invalid choice.\n");
            }
        }
    }while(choice!=5);

    free(database);
    return 0;
}