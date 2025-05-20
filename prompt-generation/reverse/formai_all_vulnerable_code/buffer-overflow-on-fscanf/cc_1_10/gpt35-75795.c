//FormAI DATASET v1.0 Category: File handling ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp; //pointer to file type
    int rollnum, age;
    char name[25];

    fp = fopen("StudentsRecord.txt", "w"); //open file in write mode

    if(fp == NULL){
        printf("File does not exist or cannot be opened.\n"); //error handling
        exit(1);
    }

    //writing data to file
    printf("Enter student details:\n");
    printf("Name: ");
    fgets(name, 25, stdin);
    fprintf(fp, "Name: %s", name);

    printf("Roll Number: ");
    scanf("%d", &rollnum);
    fprintf(fp, "Roll Number: %d\n", rollnum);

    printf("Age: ");
    scanf("%d", &age);
    fprintf(fp, "Age: %d\n",age);

    fclose(fp); //close file after writing

    fp = fopen("StudentsRecord.txt", "r"); //open file in read mode
    if(fp == NULL){
        printf("File does not exist or cannot be opened.\n"); //error handling
        exit(1);
    }

    //reading data from file
    printf("\nStudent details:\n");
    while(fscanf(fp, "%s", name) != EOF){
        printf("%s ",name);
        if(fscanf(fp, "%s", name) != EOF){
            printf("%s ",name);
        }
        if(fscanf(fp, "%d", &rollnum) != EOF){
            printf("%d ",rollnum);
        }
        if(fscanf(fp, "%d", &age) != EOF){
            printf("%d\n",age);
        }
    }

    fclose(fp); //close file after reading

    return 0;
}