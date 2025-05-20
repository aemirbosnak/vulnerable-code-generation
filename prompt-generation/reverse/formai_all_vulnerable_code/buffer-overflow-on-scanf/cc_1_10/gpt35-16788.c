//FormAI DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[20];
    float gpa;
};

typedef struct student Student;

int main() {

    // create a new file for writing
    FILE *fp;
    fp = fopen("student_db.dat", "wb");
    if(fp==NULL){
        printf("Error creating file.");
        exit(1);
    }

    // declare variables
    char choice;
    int num_records = 0;
    int i;
    Student s;

    // loop for adding records
    do {
        
        // get input from user
        printf("Enter student ID: ");
        scanf("%d", &s.id);
        printf("Enter name: ");
        scanf("%s", s.name);
        printf("Enter GPA: ");
        scanf("%f", &s.gpa);

        // write to file
        fwrite(&s, sizeof(Student), 1, fp);
        num_records++;

        // ask user to continue
        printf("\nDo you want to add another record? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    // close the file
    fclose(fp);

    // open the file for reading
    fp = fopen("student_db.dat", "rb");
    if(fp==NULL){
        printf("Error opening file.");
        exit(1);
    }

    // loop for reading records
    printf("\nID\tNAME\tGPA\n");
    for (i = 0; i < num_records; i++) {
        
        // read from file
        fread(&s, sizeof(Student), 1, fp);

        // output to console
        printf("%d\t%s\t%.2f\n", s.id, s.name, s.gpa);
    }

    // close the file
    fclose(fp);

    return 0;
}