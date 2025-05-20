//FormAI DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to hold details of a student
struct Student {
    char name[30];
    int roll;
    float marks;
};

int main() {
    int choice, num;
    FILE *fp;
    struct Student s;
    
    // Opening file in write mode
    fp = fopen("students.dat", "w");
    
    // Getting number of students
    printf("Enter the number of students: ");
    scanf("%d", &num);
    
    // Writing details of each student to file
    for(int i=0; i<num; i++) {
        printf("Enter details of student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", s.name);
        printf("Roll: ");
        scanf("%d", &s.roll);
        printf("Marks: ");
        scanf("%f", &s.marks);
        fwrite(&s, sizeof(struct Student), 1, fp);
    }
    
    // Closing file
    fclose(fp);
    
    // Menu for user to choose different file operations
    printf("\nWhat operation do you want to perform?\n");
    printf("1. Read details of all students from file\n");
    printf("2. Read details of a specific student from file\n");
    printf("3. Modify details of a specific student\n");
    printf("4. Delete details of a specific student\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: 
            // Opening file in read mode
            fp = fopen("students.dat", "r");
            
            printf("\nDetails of all students:\n");
            
            // Reading details of all students from file
            while(fread(&s, sizeof(struct Student), 1, fp)) {
                printf("Name: %s\n", s.name);
                printf("Roll: %d\n", s.roll);
                printf("Marks: %.2f\n", s.marks);
            }
            
            // Closing file
            fclose(fp);
            break;
            
        case 2:
            // Opening file in read mode
            fp = fopen("students.dat", "r");
            
            printf("\nEnter roll number of student whose details you want to read: ");
            int roll_num;
            scanf("%d", &roll_num);
            
            // Searching for details of specific student
            while(fread(&s, sizeof(struct Student), 1, fp)) {
                if(s.roll == roll_num) {
                    printf("\nDetails of student with roll number %d:\n", roll_num);
                    printf("Name: %s\n", s.name);
                    printf("Roll: %d\n", s.roll);
                    printf("Marks: %.2f\n", s.marks);
                    break;
                }
            }
            
            // Closing file
            fclose(fp);
            break;
            
        case 3:
            // Opening file in read and write mode
            fp = fopen("students.dat", "r+");
            
            printf("\nEnter roll number of student whose details you want to modify: ");
            int mod_roll_num;
            scanf("%d", &mod_roll_num);
            
            // Searching for details of specific student
            while(fread(&s, sizeof(struct Student), 1, fp)) {
                if(s.roll == mod_roll_num) {
                    printf("\nEnter new details of student:\n");
                    printf("Name: ");
                    scanf("%s", s.name);
                    printf("Roll: ");
                    scanf("%d", &s.roll);
                    printf("Marks: ");
                    scanf("%f", &s.marks);
                    fseek(fp, -sizeof(struct Student), SEEK_CUR);
                    fwrite(&s, sizeof(struct Student), 1, fp);
                    printf("\nDetails of student with roll number %d modified successfully!\n", mod_roll_num);
                    break;
                }
            }
            
            // Closing file
            fclose(fp);
            break;
            
        case 4:
            // Opening file in read and write mode
            fp = fopen("students.dat", "r+");
            
            printf("\nEnter roll number of student whose details you want to delete: ");
            int del_roll_num;
            scanf("%d", &del_roll_num);
            
            // Searching for details of specific student
            while(fread(&s, sizeof(struct Student), 1, fp)) {
                if(s.roll == del_roll_num) {
                    fseek(fp, -sizeof(struct Student), SEEK_CUR);
                    s.roll = -1;
                    fwrite(&s, sizeof(struct Student), 1, fp);
                    printf("\nDetails of student with roll number %d deleted successfully!\n", del_roll_num);
                    break;
                }
            }
            
            // Closing file
            fclose(fp);
            break;
            
        default:
            printf("\nInvalid choice!\n");
            break;
    }
    
    return 0;
}