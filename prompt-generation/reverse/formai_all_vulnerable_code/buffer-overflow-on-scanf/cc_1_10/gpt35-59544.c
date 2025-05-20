//FormAI DATASET v1.0 Category: Database querying ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// define structure to hold student information
struct Student{
    int roll_no;
    char name[20];
    float marks;
};
// function to create table 
void create_table(){
    FILE *fp;
    fp = fopen("student_db.dat", "wb");
    fclose(fp);
    printf("Table Created Successfully\n");
}

// function to insert data into table
void insert_data(){
    FILE *fp;
    struct Student s;
    fp = fopen("student_db.dat", "ab");
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll_no);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    fwrite(&s, sizeof(struct Student), 1, fp);
    fclose(fp);
    printf("Data inserted successfully.\n");
}

// function to display all data from table
void display_all_data(){
    FILE *fp;
    struct Student s;
    int count=0;
    fp = fopen("student_db.dat", "rb");
    while(fread(&s, sizeof(struct Student), 1, fp)){
        count++;
        printf("\n\nRecord No: %d\n", count);
        printf("Roll Number: %d\n", s.roll_no);
        printf("Name: %s\n", s.name);
        printf("Marks: %f\n", s.marks);
    }
    fclose(fp);
    if(count == 0){
        printf("No records found.\n");
    }
}

// function to display specific data from table based on roll number
void display_specific_data(){
    FILE *fp;
    struct Student s;
    int rn, found=0;
    fp = fopen("student_db.dat", "rb");
    printf("Enter Roll Number to search: ");
    scanf("%d", &rn);
    while(fread(&s, sizeof(struct Student), 1, fp)){
        if(s.roll_no == rn){
            found = 1;
            printf("\n\nRecord Found\n");
            printf("Roll Number: %d\n", s.roll_no);
            printf("Name: %s\n", s.name);
            printf("Marks: %f\n", s.marks);
            break;
        }
    }
    fclose(fp);
    if(found == 0){
        printf("Record not found.\n");
    }
}

// function to delete specific data from table based on roll number
void delete_data(){
    FILE *fp, *temp_fp;
    struct Student s;
    int rn, found = 0;
    fp = fopen("student_db.dat", "rb");
    temp_fp = fopen("temp_db.dat", "wb");
    printf("Enter Roll Number to delete: ");
    scanf("%d", &rn);
    while(fread(&s, sizeof(struct Student), 1, fp)){
        if(s.roll_no != rn){
            fwrite(&s, sizeof(struct Student), 1, temp_fp);
        }else{
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp_fp);
    remove("student_db.dat");
    rename("temp_db.dat", "student_db.dat");
    if(found == 1){
        printf("Data deleted successfully.\n");
    }else{
        printf("Record not found.\n");
    }
}

int main(){
    int option;
    printf("Welcome to Student Database\n");
    do{
        printf("\nEnter the operation you want to perform:");
        printf("\n1. Create Table");
        printf("\n2. Insert Data");
        printf("\n3. Display All Data");
        printf("\n4. Display Specific Data");
        printf("\n5. Delete Data");
        printf("\n6. Exit\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                create_table();
                break;
            case 2:
                insert_data();
                break;
            case 3:
                display_all_data();
                break;
            case 4:
                display_specific_data();
                break;
            case 5:
                delete_data();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }while(option != 6);
    return 0;
}