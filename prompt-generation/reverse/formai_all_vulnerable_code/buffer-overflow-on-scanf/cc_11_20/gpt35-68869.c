//FormAI DATASET v1.0 Category: Database Indexing System ; Style: all-encompassing
#include<stdio.h>
#include<string.h>

struct student {
    char name[50];
    int id;
    float gpa;
};

int main(){
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct student students[numStudents];
    // collecting data
    for(int i=0; i<numStudents; i++){
        printf("Enter the name of the student %d: ", i+1);
        scanf("%s", students[i].name);
        printf("Enter the id of the student %d: ", i+1);
        scanf("%d", &students[i].id);
        printf("Enter the GPA of the student %d: ", i+1);
        scanf("%f", &students[i].gpa);
    }

    // indexing based on id
    int ids[numStudents];
    for(int i=0; i<numStudents; i++){
        ids[i] = students[i].id;
    }

    // sorting the id array 
    for(int i=0; i<numStudents; i++){
        for(int j=i+1; j<numStudents; j++){
            if(ids[i] > ids[j]){
                int temp = ids[i];
                ids[i] = ids[j];
                ids[j] = temp;
            }
        }
    }

    // printing database based on id
    printf("\nDatabase based on id:\n");
    printf("Name\tId\tGPA\n");
    for(int i=0; i<numStudents; i++){
        for(int j=0; j<numStudents; j++){
            if(students[j].id == ids[i]){
                printf("%s\t%d\t%.2f\n", students[j].name, students[j].id, students[j].gpa);
            }
        }
    }

    // indexing based on name
    char names[numStudents][50];
    for(int i=0; i<numStudents; i++){
        strcpy(names[i], students[i].name);
    }

    // sorting the name array
    for(int i=0; i<numStudents; i++){
        for(int j=i+1; j<numStudents; j++){
            if(strcmp(names[i], names[j]) > 0){
                char temp[50];
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    // printing database based on name
    printf("\nDatabase based on name:\n");
    printf("Name\tId\tGPA\n");
    for(int i=0; i<numStudents; i++){
        for(int j=0; j<numStudents; j++){
            if(strcmp(students[j].name, names[i]) == 0){
                printf("%s\t%d\t%.2f\n", students[j].name, students[j].id, students[j].gpa);
            }
        }
    }

    return 0;
}