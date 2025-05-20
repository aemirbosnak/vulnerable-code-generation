//FormAI DATASET v1.0 Category: File handling ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

struct student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    int choice, newRoll, flag = 0, i, num;
    struct student s;

    FILE *fptr, *newfptr;

    fptr = fopen("students.dat", "rb");
    if(fptr == NULL) {
        printf("File does not exist.\n");
        exit(1);
    }

    // Counting number of student records in the file
    fseek(fptr, 0, SEEK_END);
    num = ftell(fptr) / sizeof(s);
    rewind(fptr);

    printf("Number of student records in the file: %d\n", num);

    printf("Enter choice:\n1 - Add new student record\n2 - Display all student records\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // Adding new student record
            newfptr = fopen("students.dat", "ab");

            printf("Enter roll: ");
            scanf("%d", &s.roll);

            // Checking if the entered roll already exists
            for(i = 0; i < num; i++) {
                fread(&s, sizeof(s), 1, fptr);
                if(s.roll == newRoll) {
                    printf("Record with roll %d already exists.\n", newRoll);
                    flag = 1;
                    break;
                }
            }
            // If roll number does not exist, add new record
            if(!flag) {
                printf("Enter name: ");
                scanf("%s", s.name);
                printf("Enter marks: ");
                scanf("%f", &s.marks);

                fwrite(&s, sizeof(s), 1, newfptr);
                printf("Record added successfully.\n");
            }
            
            fclose(newfptr);
            break;

        case 2:
            // Displaying all student records
            printf("Roll\tName\t\t\tMarks\n");
            for(i = 0; i < num; i++) {
                fread(&s, sizeof(s), 1, fptr);
                printf("%d\t%s\t\t%.2f\n", s.roll, s.name, s.marks);
            }
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    fclose(fptr);

    return 0;
}