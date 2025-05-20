//FormAI DATASET v1.0 Category: Database simulation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
    int roll_no;
    char name[50];
    int marks;
};

int main() {
    FILE *file_pointer;
    int num_of_students = 0, search_rollno = 0;
    char search_name[50];
    int choice = 0;
    struct Student st;

    file_pointer = fopen("database.txt", "rb+");

    // Check if file exists and can be read
    if(file_pointer == NULL) {
        printf("Error in opening database file..!!");
        exit(1);
    }

    // Counting number of students
    while(fread(&st, sizeof(st), 1, file_pointer) == 1) {
        num_of_students++;
    }

    do {
        printf("\nChoose an option:\n");
        printf("1. Add a student\n");
        printf("2. Display all students\n");
        printf("3. Search for a student\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter Student's Roll No: ");
                scanf("%d", &st.roll_no);
                printf("Enter Student's Name: ");
                scanf("%s", &st.name);
                printf("Enter Student's Marks: ");
                scanf("%d", &st.marks);

                fseek(file_pointer, 0, SEEK_END);
                fwrite(&st, sizeof(st), 1, file_pointer);
                printf("\nStudent added successfully..!!");
                break;

            case 2:
                printf("\nList of all Students:\n");
                rewind(file_pointer);
                while(fread(&st, sizeof(st), 1, file_pointer) == 1) {
                    printf("\nRoll No: %d\nName: %s\nMarks: %d\n", st.roll_no, st.name, st.marks);
                }
                break;

            case 3:
                printf("\nSearch for student:\n");
                printf("Enter Roll No. to search: ");
                scanf("%d", &search_rollno);
                printf("Enter Name to search: ");
                scanf("%s", search_name);

                rewind(file_pointer);
                while(fread(&st, sizeof(st), 1, file_pointer) == 1) {
                    if((st.roll_no == search_rollno) && (strcmp(st.name, search_name) == 0)) {
                        printf("\nRoll No: %d\nName: %s\nMarks: %d\n", st.roll_no, st.name, st.marks);
                        break;
                    }
                }
                break;

            case 4:
                exit(0);
        }

    } while(choice != 4);

    fclose(file_pointer);
    return 0;
}