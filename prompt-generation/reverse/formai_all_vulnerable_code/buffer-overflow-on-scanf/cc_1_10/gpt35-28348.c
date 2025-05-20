//FormAI DATASET v1.0 Category: Database simulation ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXRECORDS 50

//structure to hold student information
struct Student{
    int rollNumber;
    char name[30];
    float marks;
};

//function to create and display database
void displayDatabase(struct Student* database, int count){
    printf("Roll No.\tName\t\tMarks\n");
    for(int i=0; i<count; i++){
        printf("%d\t\t%s\t\t%.2f\n", database[i].rollNumber, database[i].name, database[i].marks);
    }
}

//function to insert new record in database
void insertRecord(struct Student* database, int *count){
    if(*count == MAXRECORDS){
        printf("Database is full! Cannot add new record.\n");
        return;
    }

    struct Student newRecord;
    printf("Enter Roll Number: ");
    scanf("%d", &newRecord.rollNumber);

    //check if roll number already exists
    for(int i=0; i<*count; i++){
        if(database[i].rollNumber == newRecord.rollNumber){
            printf("Roll Number %d already exists!\n", newRecord.rollNumber);
            return;
        }
    }

    printf("Enter Name: ");
    scanf("%s", newRecord.name);
    printf("Enter Marks: ");
    scanf("%f", &newRecord.marks);

    database[*count] = newRecord;
    (*count)++;

    printf("Record added successfully!\n\n");
}

//function to search record based on roll number
void searchRecord(struct Student* database, int count){
    int rollNumber;
    printf("Enter Roll Number to search: ");
    scanf("%d", &rollNumber);

    for(int i=0; i<count; i++){
        if(database[i].rollNumber == rollNumber){
            printf("Roll Number: %d\nName: %s\nMarks: %.2f\n\n", database[i].rollNumber, database[i].name, database[i].marks);
            return;
        }
    }

    printf("Record not found!\n\n");
}

//function to update record based on roll number
void updateRecord(struct Student* database, int count){
    int rollNumber;
    printf("Enter Roll Number to update: ");
    scanf("%d", &rollNumber);

    for(int i=0; i<count; i++){
        if(database[i].rollNumber == rollNumber){
            printf("Enter new Name: ");
            scanf("%s", database[i].name);
            printf("Enter new Marks: ");
            scanf("%f", &database[i].marks);
            printf("Record updated successfully!\n\n");
            return;
        }
    }

    printf("Record not found!\n\n");
}

//function to delete record based on roll number
void deleteRecord(struct Student* database, int *count){
    int rollNumber;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &rollNumber);

    for(int i=0; i<*count; i++){
        if(database[i].rollNumber == rollNumber){
            //shift all records after this one by one place left to fill the gap
            for(int j=i; j<*count-1; j++){
                database[j] = database[j+1];
            }
            (*count)--;
            printf("Record deleted successfully!\n\n");
            return;
        }
    }

    printf("Record not found!\n\n");
}

//main function
int main(){
    struct Student database[MAXRECORDS];
    int count = 0;
    int choice;

    do{
        printf("Menu\n");
        printf("1. Display Database\n");
        printf("2. Insert Record\n");
        printf("3. Search Record\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                displayDatabase(database, count);
                break;

            case 2:
                insertRecord(database, &count);
                break;

            case 3:
                searchRecord(database, count);
                break;

            case 4:
                updateRecord(database, count);
                break;

            case 5:
                deleteRecord(database, &count);
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n\n");
        }
    }while(choice != 6);

    return 0;
}