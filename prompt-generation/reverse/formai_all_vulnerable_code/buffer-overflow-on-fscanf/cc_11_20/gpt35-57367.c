//FormAI DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

struct student {
    char name[50];
    int roll;
    float marks;
}data;

int main() {
    FILE *fptr, *fptr2;
    int choice, roll_no, new_roll;
    printf("1. Add Student records\n");
    printf("2. View Student records\n");
    printf("3. Modify Student records\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);    
    switch(choice){
        case 1:
            fptr = fopen("students.txt", "a"); 
            printf("\nEnter the details of the student\n\n");
            printf("Name : ");
            scanf("%s", &data.name);
            printf("Roll No : ");
            scanf("%d", &data.roll);
            printf("Marks : ");
            scanf("%f", &data.marks);
            fprintf(fptr,"%s %d %.2f \n",data.name,data.roll,data.marks); 
            printf("\nStudent added successfully\n");
            fclose(fptr);
            break;
        case 2:
            fptr = fopen("students.txt", "r");
            if(fptr == NULL) {
                printf("\nNo students records found\n");
            } 
            else { 
                printf("\nStudent Details\n\n");             
                printf("Name\tRoll No\tMarks\n");
                printf("_______________________________\n");
                while(fscanf(fptr,"%s %d %f",data.name,&data.roll,&data.marks)!=EOF) {
                    printf("%s\t%d\t%.2f\n",data.name,data.roll,data.marks);
                }
                fclose(fptr);
            }
            break;
        case 3:
            fptr = fopen("students.txt", "r");
            if(fptr == NULL) {
                printf("\nNo students records found\n");
            } 
            else { 
                printf("\nEnter the Roll No of the student to modify: ");
                scanf("%d",&roll_no);                 
                int found = 0;
                while(fscanf(fptr,"%s %d %f",data.name,&data.roll,&data.marks)!=EOF) {
                    if(roll_no == data.roll) {
                        printf("\nFound Record:\n");                
                        printf("Name : %s\n",data.name);
                        printf("Roll No : %d\n",data.roll);
                        printf("Marks : %.2f\n",data.marks);
                        printf("\nEnter the modified details \n\n");                
                        printf("New Name : ");
                        scanf("%s",data.name);
                        printf("New Roll No : ");
                        scanf("%d",&new_roll);
                        printf("New Marks : ");
                        scanf("%f",&data.marks);
                        fptr2 = fopen("temp.txt", "a");
                        fprintf(fptr2,"%s %d %.2f \n",data.name,new_roll,data.marks);
                        fclose(fptr2);
                        printf("\nStudent record modified successfully\n");
                        found = 1;
                        break;
                    }                
                }
                if(found == 0) {
                    printf("\nRecord not found\n");
                }
                fclose(fptr);

                fptr = fopen("students.txt", "w");
                fptr2 = fopen("temp.txt", "r");
                while(fscanf(fptr2,"%s %d %f",data.name,&data.roll,&data.marks)!=EOF) {
                    fprintf(fptr,"%s %d %.2f \n",data.name,data.roll,data.marks); 
                }
                fclose(fptr);
                fclose(fptr2);
            }
            break;
        default:
            printf("\nInvalid Choice!\n");
            break;
    }
    return 0;
}