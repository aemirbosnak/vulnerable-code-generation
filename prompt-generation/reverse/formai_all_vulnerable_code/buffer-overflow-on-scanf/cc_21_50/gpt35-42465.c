//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct student {
    char name[50];
    int roll_no;
    float marks;
};

typedef struct student Student;

int main() {
    
    Student db[MAX];
    int choice, count=0;
    
    do {
        printf("\nC DATABASE SIMULATION\n");
        printf("==========================");
        printf("\n1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Add Record\n");
        printf("4. Delete Record\n");
        printf("5. Search Record\n");
        printf("6. Modify Record\n");
        printf("7. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            
            case 1:
                if (count == MAX) {
                    printf("Sorry, database is full.\n");
                } else {
                    printf("Enter details of student %d:\n", count+1);
                    printf("Name: ");
                    scanf("%s", db[count].name);
                    printf("Roll No.: ");
                    scanf("%d", &db[count].roll_no);
                    printf("Marks: ");
                    scanf("%f", &db[count].marks);
                    count++;
                    printf("Record added successfully.\n");
                }
                break;
                
            case 2:
                if (count == 0) {
                    printf("Sorry, database is empty.\n");
                } else {
                    printf("\nStudent Database:\n");
                    printf("==================\n");
                    printf("Roll No.\tName\tMarks\n");
                    for (int i=0; i<count; i++) {
                        printf("%d\t\t%s\t%.2f\n", db[i].roll_no, db[i].name, db[i].marks);
                    }
                }
                break;
                
            case 3:
                if (count == MAX) {
                    printf("Sorry, database is full.\n");
                } else {
                    printf("Enter details of new student:\n");
                    printf("Name: ");
                    scanf("%s", db[count].name);
                    printf("Roll No.: ");
                    scanf("%d", &db[count].roll_no);
                    printf("Marks: ");
                    scanf("%f", &db[count].marks);
                    count++;
                    printf("Record added successfully.\n");
                }
                break;
                
            case 4:
                if (count == 0) {
                    printf("Sorry, database is empty.\n");
                } else {
                    int roll_no, flag=0;
                    printf("Enter the roll no. of the student to be deleted: ");
                    scanf("%d", &roll_no);
                    for (int i=0; i<count; i++) {
                        if (db[i].roll_no == roll_no) {
                            for (int j=i; j<count-1; j++) {
                                db[j] = db[j+1];
                            }
                            count--;
                            printf("Record deleted successfully.\n");
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag) {
                        printf("Sorry, the student record was not found.\n");
                    }
                }
                break;
                
            case 5:
                if (count == 0) {
                    printf("Sorry, database is empty.\n");
                } else {
                    int roll_no, flag=0;
                    printf("Enter the roll no. of the student to search for: ");
                    scanf("%d", &roll_no);
                    for (int i=0; i<count; i++) {
                        if (db[i].roll_no == roll_no) {
                            printf("Roll No.\tName\tMarks\n");
                            printf("%d\t\t%s\t%.2f\n", db[i].roll_no, db[i].name, db[i].marks);
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag) {
                        printf("Sorry, student record not found.\n");
                    }
                }
                break;
                
            case 6:
                if (count == 0) {
                    printf("Sorry, database is empty.\n");
                } else {
                    int roll_no, flag=0;
                    printf("Enter the roll no. of the student to modify: ");
                    scanf("%d", &roll_no);
                    for (int i=0; i<count; i++) {
                        if (db[i].roll_no == roll_no) {
                            printf("Enter new details of the student:\n");
                            printf("Name: ");
                            scanf("%s", db[i].name);
                            printf("Roll No.: ");
                            scanf("%d", &db[i].roll_no);
                            printf("Marks: ");
                            scanf("%f", &db[i].marks);
                            printf("Record modified successfully.\n");
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag) {
                        printf("Sorry, student record not found.\n");
                    }
                }
                break;
                
            case 7:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
    } while (choice != 7);
    
    return 0;
}