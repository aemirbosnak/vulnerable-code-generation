//FormAI DATASET v1.0 Category: Database simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUM_RECORDS 1000

struct Student{
    int roll_no;
    char name[MAX_NAME_LENGTH];
    float cgpa;
};

struct Student students[MAX_NUM_RECORDS];

int total_num_students = 0;

void add_student(){
    if(total_num_students >= MAX_NUM_RECORDS){
        printf("Maximum number of students reached!\n");
        return;
    }
    printf("Enter Roll No: ");
    scanf("%d", &students[total_num_students].roll_no);
    printf("Enter Name: ");
    scanf("%s", students[total_num_students].name);
    printf("Enter CGPA: ");
    scanf("%f", &students[total_num_students].cgpa);
    total_num_students++;
    printf("Student added successfully.\n");
}

void print_student(struct Student s){
    printf("Roll No: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("CGPA: %.2f\n", s.cgpa);
}

void print_all_students(){
    if(total_num_students == 0){
        printf("No students added yet!\n");
        return;
    }
    printf("List of all students:\n");
    for(int i=0; i<total_num_students; i++){
        printf("------------------------\n");
        print_student(students[i]);
    }
}

void search_student(){
    if(total_num_students == 0){
        printf("No students added yet!\n");
        return;
    }
    int search_roll_no;
    printf("Enter Roll No to search: ");
    scanf("%d", &search_roll_no);
    int found = 0;
    for(int i=0; i<total_num_students; i++){
        if(students[i].roll_no == search_roll_no){
            printf("Student found!\n");
            printf("------------------------\n");
            print_student(students[i]);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Student with Roll No %d not found.\n", search_roll_no);
    }
}

void delete_student(){
    if(total_num_students == 0){
        printf("No students added yet!\n");
        return;
    }
    int delete_roll_no;
    printf("Enter Roll No to delete: ");
    scanf("%d", &delete_roll_no);
    int found = 0;
    for(int i=0; i<total_num_students; i++){
        if(students[i].roll_no == delete_roll_no){
            found = 1;
            for(int j=i+1; j<total_num_students; j++){
                students[j-1] = students[j];
            }
            total_num_students--;
            printf("Student with Roll No %d deleted successfully.\n", delete_roll_no);
            break;
        }
    }
    if(!found){
        printf("Student with Roll No %d not found.\n", delete_roll_no);
    }
}

int main(){
    int choice;
    while(1){
        printf("\n");
        printf("1. Add Student\n");
        printf("2. Print All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_student();
                break;
            case 2:
                print_all_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                delete_student();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}