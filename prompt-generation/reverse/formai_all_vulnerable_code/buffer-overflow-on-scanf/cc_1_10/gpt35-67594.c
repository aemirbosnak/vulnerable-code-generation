//FormAI DATASET v1.0 Category: Database simulation ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RECORDS 100

struct Student{
    int id;
    char name[50];
    float attendance;
    int marks[3];
};

int num_students = 0;
struct Student students[MAX_RECORDS]; 

void add_student(){
    struct Student new_student;
    printf("Enter student id: ");
    scanf("%d",&new_student.id);
    printf("Enter student name: ");
    scanf("%s",new_student.name);
    printf("Enter student attendance percentage: ");
    scanf("%f",&new_student.attendance);
    printf("Enter student's marks in 3 subjects: ");
    for(int i=0;i<3;i++){
        scanf("%d",&new_student.marks[i]);
    }
    students[num_students] = new_student;
    num_students++;
    printf("Student record added successfully!\n");
    return;
}

void delete_student(){
    int id_to_delete;
    printf("Enter id of student to delete: ");
    scanf("%d",&id_to_delete);
    int i;
    for(i=0;i<num_students;i++){
        if(students[i].id==id_to_delete){
            num_students--;
            for(int j=i;j<num_students;j++){
                students[j] = students[j+1];
            }
            printf("Student record deleted successfully!\n");
            return;
        }
    }
    printf("Student record with id %d not found!\n",id_to_delete);
    return;
}

void update_student(){
    int id_to_update;
    printf("Enter id of student to update: ");
    scanf("%d",&id_to_update);
    int i;
    for(i=0;i<num_students;i++){
        if(students[i].id==id_to_update){
            printf("Enter updated student name: ");
            scanf("%s",students[i].name);
            printf("Enter updated student attendance percentage: ");
            scanf("%f",&students[i].attendance);
            printf("Enter updated student's marks in 3 subjects: ");
            for(int j=0;j<3;j++){
                scanf("%d",&students[i].marks[j]);
            }
            printf("Student record updated successfully!\n");
            return;
        }
    }
    printf("Student record with id %d not found!\n",id_to_update);
    return;
}

void display_student(){
    int id_to_display;
    printf("Enter id of student to display: ");
    scanf("%d",&id_to_display);
    int i;
    for(i=0;i<num_students;i++){
        if(students[i].id==id_to_display){
            printf("Id: %d\nName: %s\nAttendance: %f\nMarks: %d %d %d\n",students[i].id,students[i].name,students[i].attendance,students[i].marks[0],students[i].marks[1],students[i].marks[2]);
            return;
        }
    }
    printf("Student record with id %d not found!\n",id_to_display);
    return;
}

void display_all_students(){
    for(int i=0;i<num_students;i++){
        printf("Id: %d\nName: %s\nAttendance: %f\nMarks: %d %d %d\n",students[i].id,students[i].name,students[i].attendance,students[i].marks[0],students[i].marks[1],students[i].marks[2]);
        printf("\n");
    }
}

int main(){
    int choice;
    printf("Welcome to the student database management system!\n\n");

    while(1){
        printf("What would you like to do?\n");
        printf("1. Add student record\n");
        printf("2. Delete student record\n");
        printf("3. Update student record\n");
        printf("4. Display student record\n");
        printf("5. Display all student records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: add_student();
                    break;
            case 2: delete_student();
                    break;
            case 3: update_student();
                    break;
            case 4: display_student();
                    break;
            case 5: display_all_students();
                    break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
        printf("\n");
    }

    return 0;
}