//Falcon-180B DATASET v1.0 Category: File handling ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50
#define MAX_ID_LEN 10
#define MAX_COURSE_LEN 30
#define MAX_GRADE_LEN 20

struct student{
    char name[MAX_NAME_LEN];
    char id[MAX_ID_LEN];
    char course[MAX_COURSE_LEN];
    char grade[MAX_GRADE_LEN];
    float score;
};

int main(){
    FILE *students_file;
    char filename[MAX_NAME_LEN];
    int num_students=0;
    struct student students[MAX_STUDENTS];

    //Get filename from user
    printf("Enter the name of the file containing student data: ");
    scanf("%s",filename);

    //Open file for reading
    students_file=fopen(filename,"r");
    if(students_file==NULL){
        printf("Error opening file.\n");
        exit(1);
    }

    //Read students from file
    while(fscanf(students_file,"%s %s %s %s %f\n",students[num_students].name,students[num_students].id,students[num_students].course,students[num_students].grade,&students[num_students].score)!=EOF){
        num_students++;
    }
    fclose(students_file);

    //Sort students by score
    for(int i=0;i<num_students-1;i++){
        for(int j=i+1;j<num_students;j++){
            if(students[i].score<students[j].score){
                struct student temp=students[i];
                students[i]=students[j];
                students[j]=temp;
            }
        }
    }

    //Print sorted list of students
    printf("\nSorted List of Students:\n");
    printf("%-20s %-10s %-20s %-10s %s\n","Name","ID","Course","Grade","Score");
    for(int i=0;i<num_students;i++){
        printf("%-20s %-10s %-20s %-10s %s\n",students[i].name,students[i].id,students[i].course,students[i].grade,students[i].score);
    }

    //Open file for writing
    students_file=fopen(filename,"w");
    if(students_file==NULL){
        printf("Error opening file.\n");
        exit(1);
    }

    //Write sorted list of students to file
    for(int i=0;i<num_students;i++){
        fprintf(students_file,"%s %s %s %s %.2f\n",students[i].name,students[i].id,students[i].course,students[i].grade,students[i].score);
    }
    fclose(students_file);

    return 0;
}