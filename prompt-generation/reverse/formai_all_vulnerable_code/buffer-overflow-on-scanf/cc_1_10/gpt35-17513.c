//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100  //maximum number of records that can be stored

/*Function prototypes*/
void add_record();
void delete_record();
void search_record();
void display_all_records();

/*Struct to hold information of a single record*/
struct record {
    int id;
    char name[50];
    char email[50];
};

/*Array to hold all records*/
struct record records[MAX_RECORDS];

/*Variable to keep track of number of records present*/
int num_of_records = 0;

/*Main function*/
int main() {
    printf("Welcome to the peaceful database simulation program!\n");
    printf("You can add, delete, search or display records in the database.\n");
    printf("To exit the program, press Ctrl+C.\n\n");

    /*Infinite loop to keep the program running*/
    while(1) {
        /*Display menu*/
        printf("Menu:\n");
        printf("1. Add Record\n");
        printf("2. Delete Record\n");
        printf("3. Search Record\n");
        printf("4. Display All Records\n");
        printf("Enter your choice: ");

        /*Read user's choice*/
        int choice;
        scanf("%d", &choice);

        /*Call appropriate function based on user's choice*/
        switch(choice) {
            case 1:
                add_record();
                break;
            case 2:
                delete_record();
                break;
            case 3:
                search_record();
                break;
            case 4:
                display_all_records();
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("\n"); //newline for formatting
    }
    return 0;
}

/*Function to add a new record to the database*/
void add_record() {
    /*Check if database is full*/
    if(num_of_records == MAX_RECORDS) {
        printf("Database is full! Cannot add new record.\n");
        return;
    }

    /*Get new record details from user*/
    struct record new_record;
    printf("Enter id: ");
    scanf("%d", &new_record.id);
    printf("Enter name: ");
    scanf("%s", new_record.name);
    printf("Enter email: ");
    scanf("%s", new_record.email);

    /*Check if record with given id already exists*/
    for(int i=0; i<num_of_records; i++) {
        if(records[i].id == new_record.id) {
            printf("Record with given id already exists! Cannot add duplicate record.\n");
            return;
        }
    }

    /*Add new record to database*/
    records[num_of_records] = new_record;
    num_of_records++;
    printf("Record added to database successfully!\n");
}

/*Function to delete an existing record from the database*/
void delete_record() {
    /*Get id of record to be deleted from user*/
    int id;
    printf("Enter id of record to be deleted: ");
    scanf("%d", &id);

    /*Search for record with given id*/
    int index = -1;
    for(int i=0; i<num_of_records; i++) {
        if(records[i].id == id) {
            index = i;
            break;
        }
    }

    /*If record not found*/
    if(index == -1) {
        printf("Record with given id not found! Cannot delete non-existent record.\n");
        return;
    }

    /*Delete record*/
    for(int i=index; i<num_of_records-1; i++) {
        records[i] = records[i+1];
    }
    num_of_records--;
    printf("Record deleted from database successfully!\n");
}

/*Function to search for a record*/
void search_record() {
    /*Get id of record to be searched for from user*/
    int id;
    printf("Enter id of record to be searched: ");
    scanf("%d", &id);

    /*Search for record with given id*/
    int index = -1;
    for(int i=0; i<num_of_records; i++) {
        if(records[i].id == id) {
            index = i;
            break;
        }
    }

    /*If record not found*/
    if(index == -1) {
        printf("Record with given id not found!\n");
        return;
    }

    /*Display record*/
    printf("Record found:\n");
    printf("Id: %d\n", records[index].id);
    printf("Name: %s\n", records[index].name);
    printf("Email: %s\n", records[index].email);
}

/*Function to display all records in the database*/
void display_all_records() {
    /*If database is empty*/
    if(num_of_records == 0) {
        printf("Database is empty! No records to display.\n");
        return;
    }

    /*Display all records*/
    printf("All records in the database:\n");
    for(int i=0; i<num_of_records; i++) {
        printf("Record %d:\n", i+1);
        printf("Id: %d\n", records[i].id);
        printf("Name: %s\n", records[i].name);
        printf("Email: %s\n", records[i].email);
    }
}