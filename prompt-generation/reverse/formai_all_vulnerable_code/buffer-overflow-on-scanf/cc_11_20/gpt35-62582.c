//FormAI DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int roll_no;
    char name[30];
    char dept[20];
};

int main(){
    int choice;
    FILE *fp;
    struct student s;
    char file_name[20];
    printf("Enter the database file name: ");
    scanf("%s", file_name);
    while(1){ // Loop to display the menu
        printf("\nDATABASE OPERATIONS\n");
        printf("1.Add a record\n2.Display all records\n3.Search for a record\n4.Update a record\n5.Delete a record\n6.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                fp = fopen(file_name, "ab");
                printf("Enter details of student:\n");
                printf("Roll No.: ");
                scanf("%d", &s.roll_no);
                printf("Name: ");
                scanf("%s", s.name);
                printf("Department: ");
                scanf("%s", s.dept);
                fwrite(&s, sizeof(s), 1, fp);
                printf("\nRecord added successfully!\n");
                fclose(fp);
                break;
            }
            case 2:{
                fp = fopen(file_name, "rb");
                printf("Student Records:\n");
                printf("Roll No.\tName\t\tDepartment\n");
                while (fread(&s, sizeof(s), 1, fp)){
                    printf("%d\t\t%s\t\t%s\n", s.roll_no, s.name, s.dept);
                }
                fclose(fp);
                break;
            }
            case 3:{
                int roll;
                int is_found = 0;
                printf("Enter roll no. to search: ");
                scanf("%d", &roll);
                fp = fopen(file_name, "rb");
                while (fread(&s, sizeof(s), 1, fp)){
                    if(s.roll_no == roll){
                        printf("\nRecord found!\n");
                        printf("Roll No.: %d\n", s.roll_no);
                        printf("Name: %s\n", s.name);
                        printf("Department: %s\n", s.dept);
                        is_found = 1;
                        break;
                    }
                }
                if(!is_found){
                    printf("\nRecord not found!\n");
                }
                fclose(fp);
                break;
            }
            case 4:{
                int roll;
                int is_found = 0;
                printf("Enter roll no. to update: ");
                scanf("%d", &roll);
                fp = fopen(file_name, "r+b");
                while (fread(&s, sizeof(s), 1, fp)){
                    if(s.roll_no == roll){
                        printf("\nRecord found!\n");
                        printf("Roll No.: %d\n", s.roll_no);
                        printf("Name: %s\n", s.name);
                        printf("Department: %s\n", s.dept);
                        printf("\nEnter new details:\n");
                        printf("Roll No.: ");
                        scanf("%d", &s.roll_no);
                        printf("Name: ");
                        scanf("%s", s.name);
                        printf("Department: ");
                        scanf("%s", s.dept);
                        fseek(fp, -sizeof(s), SEEK_CUR);
                        fwrite(&s, sizeof(s), 1, fp);
                        is_found = 1;
                        printf("\nRecord updated successfully!\n");
                        break;
                    }
                }
                if(!is_found){
                    printf("\nRecord not found!\n");
                }
                fclose(fp);
                break;
            }
            case 5:{
                int roll;
                int is_found = 0;
                printf("Enter roll no. to delete: ");
                scanf("%d", &roll);
                fp = fopen(file_name, "rb");
                FILE *temp = fopen("temp.bin", "wb");
                while (fread(&s, sizeof(s), 1, fp)){
                    if(s.roll_no == roll){
                        printf("\nRecord found and deleted!\n");
                        is_found = 1;
                    }else{
                        fwrite(&s, sizeof(s), 1, temp);
                    }
                }
                if(!is_found){
                    printf("\nRecord not found!\n");
                }
                fclose(fp);
                fclose(temp);
                remove(file_name);
                rename("temp.bin", file_name);
                break;
            }
            case 6:{
                printf("\nExiting...\n");
                exit(0);
            }
            default:{
                printf("\nInvalid choice! Please try again.\n");
                break;
            }
        }
    }
    return 0;
}