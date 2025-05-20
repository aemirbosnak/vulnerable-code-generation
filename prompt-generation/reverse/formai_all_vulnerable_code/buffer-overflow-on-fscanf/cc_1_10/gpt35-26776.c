//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to add a student record to the database
void addRecord(char name[], int id, float gpa){

    FILE *fp;
    fp = fopen("database.txt", "a");
    fprintf(fp, "%s %d %.2f\n", name, id, gpa);
    fclose(fp);
}

//Function to search for a student record in the database
void searchRecord(int id){

    FILE *fp;
    char name[50];
    int tempID;
    float gpa;
    fp = fopen("database.txt", "r");
    while(fscanf(fp, "%s %d %f\n", name, &tempID, &gpa) != EOF){
        
        if(id == tempID){
            printf("Name: %s\nID: %d\nGPA: %.2f\n", name, tempID, gpa);
            return;
        }
    }
    printf("Record not found!\n");
    fclose(fp);
}

//Function to delete a student record from the database
void deleteRecord(int id){

    FILE *fp1, *fp2;
    char name[50];
    int tempID;
    float gpa;
    fp1 = fopen("database.txt", "r");
    fp2 = fopen("temp.txt", "w");
    while(fscanf(fp1, "%s %d %f\n", name, &tempID, &gpa) != EOF){
        
        if(id != tempID){
            fprintf(fp2, "%s %d %.2f\n", name, tempID, gpa);
        }
    }
    fclose(fp1);
    fclose(fp2);
    
    remove("database.txt");
    rename("temp.txt", "database.txt");
}

int main(){
    
    int option;
    char name[50];
    int id;
    float gpa;
    
    //Display menu
    printf("Database Simulation\n");
    printf("--------------------\n");
    printf("1. Add Record\n");
    printf("2. Search Record\n");
    printf("3. Delete Record\n");
    printf("4. Exit\n");
    
    do{
        printf("Enter option: ");
        scanf("%d", &option);
        switch(option){
            
            case 1:
                printf("Enter student name: ");
                scanf("%s", name);
                printf("Enter student ID: ");
                scanf("%d", &id);
                printf("Enter student GPA: ");
                scanf("%f", &gpa);
                addRecord(name, id, gpa);
                break;
                
            case 2:
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                searchRecord(id);
                break;
                
            case 3:
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                deleteRecord(id);
                break;
                
            case 4:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid option!\n");
        }
        
    }while(option != 4);
    
    return 0;
}