//FormAI DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    int choice, num;
    char name[20];
    float GPA;

    while(1){
        printf("\nEnter a choice:\n");
        printf("1. Create a new file\n");
        printf("2. Add a record to an existing file\n");
        printf("3. Display a record from a file\n");
        printf("4. Display all records from a file\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter file name: ");
                scanf("%s", name);

                fp = fopen(name, "w");

                if(fp == NULL){
                    printf("Unable to create file.\n");
                    exit(0);
                }

                printf("\nFile created successfully.\n");

                fclose(fp);

                break;

            case 2:
                printf("\nEnter file name: ");
                scanf("%s", name);

                fp = fopen(name, "a");

                if(fp == NULL){
                    printf("Unable to open file.\n");
                    exit(0);
                }

                printf("Enter number: ");
                scanf("%d", &num);

                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter GPA: ");
                scanf("%f", &GPA);

                fprintf(fp, "%d %s %f\n", num, name, GPA);

                printf("\nRecord added successfully.\n");

                fclose(fp);

                break;

            case 3:
                printf("\nEnter file name: ");
                scanf("%s", name);

                fp = fopen(name, "r");

                if(fp == NULL){
                    printf("Unable to open file.\n");
                    exit(0);
                }

                printf("Enter number to search: ");
                scanf("%d", &num);

                while(fscanf(fp, "%d %s %f", &num, name, &GPA) == 3){
                    if(num == num){
                        printf("Number\tName\tGPA\n");
                        printf("%d\t%s\t%f\n", num, name, GPA);
                        break;
                    }
                }

                if(num != num){
                    printf("Record not found.\n");
                }

                fclose(fp);

                break;

            case 4:
                printf("\nEnter file name: ");
                scanf("%s", name);

                fp = fopen(name, "r");

                if(fp == NULL){
                    printf("Unable to open file.\n");
                    exit(0);
                }

                printf("\nNumber\tName\tGPA\n");

                while(fscanf(fp, "%d %s %f", &num, name, &GPA) == 3){
                    printf("%d\t%s\t%f\n", num, name, GPA);
                }

                fclose(fp);

                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice.\n");
        }

    }

    return 0;
}