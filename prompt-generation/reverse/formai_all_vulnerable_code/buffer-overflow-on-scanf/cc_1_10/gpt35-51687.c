//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum number of records
#define MAX_RECORDS 1000

// define record structure
typedef struct record {
    char title[100];
    char artist[100];
    char album[100];
    int year;
} Record;

// global variables
Record records[MAX_RECORDS];
int num_records = 0;

// function prototypes
void add_record();
void edit_record();
void delete_record();
void search_record();
void display_records();

int main() {
    // display menu and wait for user input
    int option = 0;
    do {
        printf("\nWelcome to the C Music Library Management System!\n");
        printf("1. Add a new record\n");
        printf("2. Edit an existing record\n");
        printf("3. Delete a record\n");
        printf("4. Search for a record\n");
        printf("5. Display all records\n");
        printf("6. Exit\n");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        // execute selected option
        switch(option) {
            case 1: add_record(); break;
            case 2: edit_record(); break;
            case 3: delete_record(); break;
            case 4: search_record(); break;
            case 5: display_records(); break;
            case 6: break;
            default: printf("Invalid option!\n"); break;
        }

    } while(option != 6);

    // exit program
    printf("Thank you for using the C Music Library Management System!\n");
    return 0;
}

// function to add a new record
void add_record() {
    // check if maximum number of records has been reached
    if(num_records >= MAX_RECORDS) {
        printf("Maximum number of records has been reached!\n");
        return;
    }

    // get user input for the new record
    printf("\nEnter the title: ");
    scanf("%s", records[num_records].title);
    printf("Enter the artist: ");
    scanf("%s", records[num_records].artist);
    printf("Enter the album: ");
    scanf("%s", records[num_records].album);
    printf("Enter the year: ");
    scanf("%d", &records[num_records].year);

    // increment number of records
    num_records++;

    printf("Record added successfully!\n");
}

// function to edit an existing record
void edit_record() {
    // get user input for the record to be edited
    printf("\nEnter the title of the record to be edited: ");
    char title[100];
    scanf("%s", title);

    // search for the record with the specified title
    int index = -1;
    for(int i = 0; i < num_records; i++) {
        if(strcmp(records[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    // check if record was found
    if(index == -1) {
        printf("Record not found!\n");
        return;
    }

    // get user input for the new values of the record
    printf("Enter the new title (leave empty to keep the same): ");
    char new_title[100];
    scanf("%s", new_title);
    if(strlen(new_title) > 0) {
        strcpy(records[index].title, new_title);
    }
    printf("Enter the new artist (leave empty to keep the same): ");
    char new_artist[100];
    scanf("%s", new_artist);
    if(strlen(new_artist) > 0) {
        strcpy(records[index].artist, new_artist);
    }
    printf("Enter the new album (leave empty to keep the same): ");
    char new_album[100];
    scanf("%s", new_album);
    if(strlen(new_album) > 0) {
        strcpy(records[index].album, new_album);
    }
    printf("Enter the new year (leave empty to keep the same): ");
    char year_str[10];
    scanf("%s", year_str);
    if(strlen(year_str) > 0) {
        records[index].year = atoi(year_str);
    }

    printf("Record edited successfully!\n");
}

// function to delete a record
void delete_record() {
    // get user input for the record to be deleted
    printf("\nEnter the title of the record to be deleted: ");
    char title[100];
    scanf("%s", title);

    // search for the record with the specified title
    int index = -1;
    for(int i = 0; i < num_records; i++) {
        if(strcmp(records[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    // check if record was found
    if(index == -1) {
        printf("Record not found!\n");
        return;
    }

    // shift all subsequent records back by one position
    for(int i = index; i < num_records - 1; i++) {
        strcpy(records[i].title, records[i+1].title);
        strcpy(records[i].artist, records[i+1].artist);
        strcpy(records[i].album, records[i+1].album);
        records[i].year = records[i+1].year;
    }

    // decrement number of records
    num_records--;

    printf("Record deleted successfully!\n");
}

// function to search for a record
void search_record() {
    // get user input for the title to search for
    printf("\nEnter the title to search for: ");
    char title[100];
    scanf("%s", title);

    // search for records with the specified title
    int count = 0;
    for(int i = 0; i < num_records; i++) {
        if(strcmp(records[i].title, title) == 0) {
            printf("Title: %s\n", records[i].title);
            printf("Artist: %s\n", records[i].artist);
            printf("Album: %s\n", records[i].album);
            printf("Year: %d\n", records[i].year);
            printf("\n");
            count++;
        }
    }

    // check if any records were found
    if(count == 0) {
        printf("No records found!\n");
    }
}

// function to display all records
void display_records() {
    // check if there are any records
    if(num_records == 0) {
        printf("No records found!\n");
        return;
    }

    // display all records
    for(int i = 0; i < num_records; i++) {
        printf("Title: %s\n", records[i].title);
        printf("Artist: %s\n", records[i].artist);
        printf("Album: %s\n", records[i].album);
        printf("Year: %d\n", records[i].year);
        printf("\n");
    }
}