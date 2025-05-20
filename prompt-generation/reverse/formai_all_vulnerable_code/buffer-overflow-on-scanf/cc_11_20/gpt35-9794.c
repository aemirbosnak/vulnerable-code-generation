//FormAI DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    int roll_no;
    char name[50];
    float marks;
};

int main(){
    FILE *fp;
    char filename[50];
    int choice;
    int num_records = 0;
    int i;

    printf("Enter the filename to create/open: ");
    scanf("%s", filename);

    fp = fopen(filename, "r+");

    if(fp == NULL){
        printf("Error opening file\n");
        exit(1);
    }    

    while(!feof(fp)){
        struct Student student;
        fread(&student, sizeof(struct Student), 1, fp);

        if(feof(fp)){
            break;
        }

        printf("Record %d:\n", num_records + 1);
        printf("Roll No: %d\n", student.roll_no);
        printf("Name: %s\n", student.name);
        printf("Marks: %f\n", student.marks);

        num_records++;
    }

    do{
        printf("\n\nMENU\n");
        printf("1. Add a new record\n");
        printf("2. Edit an existing record\n");
        printf("3. Delete a record\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                struct Student student;

                printf("\nEnter the roll no: ");
                scanf("%d", &student.roll_no);

                printf("Enter the name: ");
                scanf("%s", student.name);

                printf("Enter the marks: ");
                scanf("%f", &student.marks);

                fseek(fp, 0L, SEEK_END);
                fwrite(&student, sizeof(struct Student), 1, fp);

                printf("Record added successfully\n");

                num_records++;
                break;
            }
            case 2:{
                int roll_no;
                int found = 0;

                printf("\nEnter the roll no of the record to be edited: ");
                scanf("%d", &roll_no);

                rewind(fp);

                for(i = 0; i < num_records; i++){
                    struct Student student;
                    fread(&student, sizeof(struct Student), 1, fp);

                    if(student.roll_no == roll_no){
                        found = 1;

                        printf("Record %d:\n", i + 1);
                        printf("Roll No: %d\n", student.roll_no);
                        printf("Name: %s\n", student.name);
                        printf("Marks: %f\n", student.marks);

                        printf("\nEnter the new details:\n");
                        printf("Enter the roll no: ");
                        scanf("%d", &student.roll_no);

                        printf("Enter the name: ");
                        scanf("%s", student.name);

                        printf("Enter the marks: ");
                        scanf("%f", &student.marks);

                        fseek(fp, -(int)sizeof(struct Student), SEEK_CUR);
                        fwrite(&student, sizeof(struct Student), 1, fp);

                        printf("Record updated successfully\n");
                        break;
                    }
                }

                if(!found){
                    printf("Record not found\n");
                }

                break;
            }
            case 3:{
                int roll_no;
                int found = 0;

                printf("\nEnter the roll no of the record to be deleted: ");
                scanf("%d", &roll_no);

                rewind(fp);

                for(i = 0; i < num_records; i++){
                    struct Student student;
                    fread(&student, sizeof(struct Student), 1, fp);

                    if(student.roll_no == roll_no){
                        found = 1;

                        printf("Record %d:\n", i + 1);
                        printf("Roll No: %d\n", student.roll_no);
                        printf("Name: %s\n", student.name);
                        printf("Marks: %f\n", student.marks);

                        fseek(fp, -(int)sizeof(struct Student), SEEK_CUR);
                        fwrite(&student, sizeof(struct Student), 1, fp);

                        printf("Record deleted successfully\n");
                        num_records--;
                        break;
                    }
                }

                if(!found){
                    printf("Record not found\n");
                }

                break;
            }
            case 4:{
                printf("Exiting program...");
                break;
            }
            default:{
                printf("Invalid choice\n");
                break;
            }
        }
    }while(choice != 4);

    fclose(fp);

    return 0;
}