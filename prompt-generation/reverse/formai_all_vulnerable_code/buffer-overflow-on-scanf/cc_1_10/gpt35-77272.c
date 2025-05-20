//FormAI DATASET v1.0 Category: File handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct student{ // define structure for student
    char name[50];
    int id;
    float marks;
};

int main()
{
    FILE *fptr;
    
    struct student s[5]; // array of structures
    
    // read student data from the user
    printf("Enter 5 student details (name, id, marks):\n");
    for(int i=0; i<5; i++){
        printf("Enter details of student %d:\n", i+1);
        scanf("%s %d %f", &s[i].name, &s[i].id, &s[i].marks); // storing data in student structure array
    }
    
    // write data to file
    fptr = fopen("student.txt", "w");
    if(fptr == NULL){
        printf("Unable to open file.\n");
        exit(1);
    }
    
    fwrite(s, sizeof(struct student), 5, fptr);
    printf("Data written to file successfully.\n");
    fclose(fptr);
    
    // read data from file
    struct student st[5];
    fptr = fopen("student.txt", "r");
    if(fptr == NULL){
        printf("Unable to open file.\n");
        exit(1);
    }
    
    fread(st, sizeof(struct student), 5, fptr);
    printf("\nData read from file:\n");
    for(int i=0; i<5; i++){
        printf("Name: %s | ID: %d | Marks: %.2f\n", st[i].name, st[i].id, st[i].marks);
    }
    
    fclose(fptr);
    
    return 0;
}