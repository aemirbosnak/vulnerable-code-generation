//FormAI DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RECORDS 100

struct Student{
    int id;
    char name[20];
    int age;
    char gender[10];
    float cgpa;
};

struct Database{
    struct Student records[MAX_RECORDS];
    int count;
};

void initialize(struct Database* db){
    db->count = 0;
}

void add_record(struct Database* db){
    struct Student new_record;
    printf("\nEnter Student's ID: ");
    scanf("%d", &new_record.id);
    printf("\nEnter Student's Name: ");
    scanf("%s", new_record.name);
    printf("\nEnter Student's Age: ");
    scanf("%d", &new_record.age);
    printf("\nEnter Student's Gender: ");
    scanf("%s", new_record.gender);
    printf("\nEnter Student's CGPA: ");
    scanf("%f", &new_record.cgpa);

    db->records[db->count++] = new_record;
}

void display_records(struct Database* db){
    printf("\nList of all Students:\n\n");
    printf("ID\tName\tAge\tGender\tCGPA\n");
    printf("--\t----\t---\t------\t----\n");
    for(int i=0; i<db->count; i++){
        printf("%d\t%s\t%d\t%s\t%.2f\n", db->records[i].id, db->records[i].name, db->records[i].age, db->records[i].gender, db->records[i].cgpa);
    }
}

void search_record(struct Database* db, int id){
    for(int i=0; i<db->count; i++){
        if(db->records[i].id == id){
            printf("\nRecord Found:\n\n");
            printf("ID\tName\tAge\tGender\tCGPA\n");
            printf("--\t----\t---\t------\t----\n");
            printf("%d\t%s\t%d\t%s\t%.2f\n", db->records[i].id, db->records[i].name, db->records[i].age, db->records[i].gender, db->records[i].cgpa);
            return;
        }
    }
    printf("\nRecord not Found!\n");
}

int main(){
    struct Database db;
    initialize(&db);
    int choice, id;

    while(1){
        printf("\nMenu:\n\n");
        printf("1. Add Record\n");
        printf("2. Display all Records\n");
        printf("3. Search Record\n");
        printf("4. Exit\n");

        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_record(&db);
                break;
            case 2:
                display_records(&db);
                break;
            case 3:
                printf("\nEnter ID of Student to search: ");
                scanf("%d", &id);
                search_record(&db, id);
                break;
            case 4:
                printf("\nExiting Program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select correct option.\n");
        }
    }

    return 0;
}