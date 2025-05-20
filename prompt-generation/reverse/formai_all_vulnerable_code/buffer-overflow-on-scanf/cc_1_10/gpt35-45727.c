//FormAI DATASET v1.0 Category: Online Examination System ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    char name[30];
    int roll_no;
    int marks;
}s;

int main() {
    int choice;
    FILE *fp;
    char filename[30];
    printf("Enter the filename: ");
    scanf("%s", filename);  // user input for filename
    fp=fopen(filename,"wb");   // create binary file
    
    while(1) {
        printf("\n1. Add a student's record\n2. Display the record of all students\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice); // user input for choice
        
        switch(choice) {
            case 1:
                printf("\nEnter the name of the student: ");
                scanf("%s", s.name); // user input for name
                printf("Enter the roll number of the student: ");
                scanf("%d", &s.roll_no); // user input for roll number
                printf("Enter the marks of the student: ");
                scanf("%d", &s.marks); // user input for marks
                fwrite(&s, sizeof(s), 1, fp); // writing into the binary file
                break;
                
            case 2:
                rewind(fp); // setting file pointer to beginning of the file
                printf("\n%-15s %-15s %-15s\n", "Name", "Roll No.", "Marks");
                while(fread(&s, sizeof(s), 1, fp) == 1) { // reading from the binary file
                    printf("%-15s %-15d %-15d\n", s.name, s.roll_no, s.marks);
                }
                break;
                
            case 3:
                fclose(fp); // closing the file pointer
                exit(0); // exiting the program
                
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}