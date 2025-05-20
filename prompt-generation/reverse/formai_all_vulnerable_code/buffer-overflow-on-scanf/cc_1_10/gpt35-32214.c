//FormAI DATASET v1.0 Category: Online Examination System ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int rno;
    char name[30];
    float marks;
};

void clear_lines(){
    printf("\n\nPress ENTER key to continue.");
    while(getchar() != '\n');
    getchar();
    system("clear");
}

void add_records(){
    char choice;
    FILE *fp;
    struct student s;
    fp = fopen("records.dat", "a");
    if(fp == NULL){
        printf("\nError: Could not open file.");
        return;
    }
    do{
        printf("\nEnter Roll Number: ");
        scanf("%d", &s.rno);
        printf("\nEnter Name: ");
        scanf("%s", s.name);
        printf("\nEnter Marks: ");
        scanf("%f", &s.marks);
        fwrite(&s, sizeof(s), 1, fp);
        printf("\nRecord added successfully!");
        printf("\nDo you want to add another record? (Y/N): ");
        while(getchar() != '\n');
        scanf("%c", &choice);
    }while(choice == 'Y'|choice == 'y');
    fclose(fp);
    clear_lines();
}

void display_records(){
    FILE *fp;
    struct student s;
    fp = fopen("records.dat", "r");
    if(fp == NULL){
        printf("\nError: Could not open file.");
        return;
    }
    printf("\n\n");
    printf("============================================================\n");
    printf("       ROLL NO. |     NAME     |     MARKS     \n");
    printf("============================================================\n");
    while(fread(&s, sizeof(s), 1, fp) == 1){
        printf("        %04d    |   %-10s  |   %-3.2f \n", s.rno, s.name, s.marks);
    }
    printf("============================================================\n");
    fclose(fp);
    clear_lines();
}

int main(){
    int option;
    printf("************************************************************\n");
    printf("               ONLINE EXAMINATION SYSTEM\n");
    printf("************************************************************\n\n");
    do{
        printf("Main Menu:\n");
        printf("1. Add Records\n");
        printf("2. Display Records\n");
        printf("0. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                add_records(); break;
            case 2:
                display_records(); break;
            case 0:
                printf("\nExiting Program.."); break;
            default:
                printf("\nInvalid input. Please enter a valid option.");
                clear_lines(); break;
        }
        
    }while(option != 0);
    return 0;
}