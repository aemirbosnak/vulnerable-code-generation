//FormAI DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining the structure for the database
struct Database{
    int rollno;
    char name[50];
    int marks;
};

//Function to add a new record to the database
void add_record(struct Database *db, int n){
    printf("\nEnter Roll Number: ");
    scanf("%d",&db[n].rollno);
    printf("\nEnter Student Name: ");
    scanf("%s",&db[n].name);
    printf("\nEnter Student Marks: ");
    scanf("%d",&db[n].marks);
}

//Function to display the contents of the database
void display_database(struct Database *db,int n){
    printf("\nRoll Number\tName\tMarks\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%s\t%d\n",db[i].rollno,db[i].name,db[i].marks);
    }
}

int main(){
    int n,choice;
    printf("Enter the number of records you want to store: ");
    scanf("%d",&n);
    struct Database *db=(struct Database*)calloc(n,sizeof(struct Database)); //Allocating memory for database
    do{
        printf("\nWhat do you want to do?\n1. Add a record\n2. Display the Database contents\n3. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_record(db,n); //Adding a new record
                n++; //Increasing the number of records
                break;
            case 2:
                display_database(db,n); //Displaying the contents of the database
                break;
            case 3:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Choice! Try Again\n");
        }
    }while(choice!=3);
    free(db); //Freeing the allocated memory
    return 0;
}