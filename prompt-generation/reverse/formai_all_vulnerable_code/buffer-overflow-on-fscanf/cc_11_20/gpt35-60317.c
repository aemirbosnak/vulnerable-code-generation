//FormAI DATASET v1.0 Category: File handling ; Style: bold
#include <stdio.h>
#include <string.h>

struct Student{
    char name[20];
    char id[10];
    int age;
    float gpa;
};

int main(){
    int option, num_of_students=0, i;
    struct Student students[50];
    FILE *fp;

    printf("Welcome to the Student Database Program!\n\n");

    do{
        printf("\n\nWhat would you like to do?\n");
        printf("1. Add a student\n");
        printf("2. View all students\n");
        printf("3. Save students to file\n");
        printf("4. Load students from file\n");
        printf("5. Quit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\nEnter name: ");
                scanf("%s", students[num_of_students].name);
                printf("Enter ID: ");
                scanf("%s", students[num_of_students].id);
                printf("Enter age: ");
                scanf("%d", &students[num_of_students].age);
                printf("Enter GPA: ");
                scanf("%f", &students[num_of_students].gpa);
                num_of_students++;
                break;
                
            case 2:
                printf("\nStudent List:\n");
                for(i=0; i<num_of_students; i++){
                    printf("Name: %s\nID: %s\nAge: %d\nGPA: %.2f\n\n", students[i].name, students[i].id, students[i].age, students[i].gpa);
                }
                break;

            case 3:
                fp = fopen("students.txt", "w");
                if(fp == NULL){
                    printf("Error saving to file!");
                    break;
                }
                for(i=0; i<num_of_students; i++){
                    fprintf(fp, "%s %s %d %.2f\n", students[i].name, students[i].id, students[i].age, students[i].gpa);
                }
                fclose(fp);
                printf("Successfully saved to file!");
                break;

            case 4:
                fp = fopen("students.txt", "r");
                if(fp == NULL){
                    printf("Error loading from file!");
                    break;
                }
                num_of_students = 0;
                while(!feof(fp)){
                    fscanf(fp, "%s %s %d %f", students[num_of_students].name, students[num_of_students].id, &students[num_of_students].age, &students[num_of_students].gpa);
                    num_of_students++;
                }
                fclose(fp);
                num_of_students--;
                printf("Successfully loaded from file!");
                break;

            case 5:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid option! Please try again.\n");
        }
    } while(option != 5);

    return 0;
}