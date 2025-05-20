//FormAI DATASET v1.0 Category: Database simulation ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure of a student record
typedef struct student {
    int roll_no;
    char name[50];
    int marks;
} STUDENT;

// Function to display menu and get user input
int menu() {
    int choice;
    printf("\n\n============================================");
    printf("\n 1. Add a Student Record");
    printf("\n 2. Display all Student Records");
    printf("\n 3. Search a Student Record");
    printf("\n 4. Update a Student Record");
    printf("\n 5. Delete a Student Record");
    printf("\n 6. Exit");
    printf("\n\n Enter your choice (1-6) : ");
    scanf("%d", &choice);
    return choice;
}

// Function to add a student record to the database
void add_student(STUDENT *db, int *num_students) {
    printf("\n Enter the Roll No : ");
    scanf("%d", &db[*num_students].roll_no);
    printf("\n Enter the Name : ");
    scanf("%s", db[*num_students].name);
    printf("\n Enter the Marks : ");
    scanf("%d", &db[*num_students].marks);
    (*num_students)++;
    printf("\n Student Record Added Successfully!\n");
}

// Function to display all student records in the database
void display_students(STUDENT *db, int num_students) {
    printf("\n\nAll Student Records\n");
    printf("===============================");
    printf("\nRoll No\tName\tMarks");
    printf("\n------------------------------");
    for(int i=0; i<num_students; i++) {
        printf("\n%d\t%s\t%d", db[i].roll_no, db[i].name, db[i].marks);
    }
    printf("\n");
}

// Function to search a student record in the database
void search_student(STUDENT *db, int num_students) {
    int roll_no, found=0;
    printf("\n Enter the Roll No : ");
    scanf("%d", &roll_no);
    for(int i=0; i<num_students; i++) {
        if(db[i].roll_no == roll_no) {
            printf("\n Student Record Found!");
            printf("\nRoll No\tName\tMarks");
            printf("\n------------------------------");
            printf("\n%d\t%s\t%d", db[i].roll_no, db[i].name, db[i].marks);
            found = 1;
            break;
        }
    }
    if(!found)
        printf("\n No record found with roll no %d\n", roll_no);
}

// Function to update a student record in the database
void update_student(STUDENT *db, int num_students) {
    int roll_no, found=0;
    printf("\n Enter the Roll No : ");
    scanf("%d", &roll_no);
    for(int i=0; i<num_students; i++) {
        if(db[i].roll_no == roll_no) {
            printf("\n Enter the new Name : ");
            scanf("%s", db[i].name);
            printf("\n Enter the new Marks : ");
            scanf("%d", &db[i].marks);
            printf("\n Student Record Updated Successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found)
        printf("\n No record found with roll no %d\n", roll_no);
}

// Function to delete a student record from the database
void delete_student(STUDENT *db, int *num_students) {
    int roll_no, found=0;
    printf("\n Enter the Roll No : ");
    scanf("%d", &roll_no);
    for(int i=0; i<*num_students; i++) {
        if(db[i].roll_no == roll_no) {
            for(int j=i; j<*num_students-1; j++) {
                db[j] = db[j+1];
            }
            (*num_students)--;
            printf("\n Student Record Deleted Successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found)
        printf("\n No record found with roll no %d\n", roll_no);
}

int main() {
    int choice, num_students=0;
    STUDENT db[100];

    do {
        choice = menu();

        switch(choice) {
            case 1:
                add_student(db, &num_students);
                break;

            case 2:
                display_students(db, num_students);
                break;

            case 3:
                search_student(db, num_students);
                break;

            case 4:
                update_student(db, num_students);
                break;

            case 5:
                delete_student(db, &num_students);
                break;

            case 6:
                printf("\n\nExiting the Program...\n");
                break;

            default:
                printf("\n\nInvalid Choice! Please Try Again.\n");
                break;
        }

    } while(choice != 6);

    return 0;
}