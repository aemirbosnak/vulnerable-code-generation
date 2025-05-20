//FormAI DATASET v1.0 Category: Music Library Management System ; Style: active
#include <stdio.h>
#include <string.h>

// Declaring all the functions required for the program
void addRecord();
void viewRecord();
void searchRecord();
void updateRecord();
void deleteRecord();

// Structure for storing music record
typedef struct{
    char title[50];
    char artist[50];
    char album[50];
    char genre[50];
    int rating;
} MusicRecord;

// Global Variables
MusicRecord records[100];  // Array for storing music records
int numRecords = 0;  // Counter for number of records stored

int main(){
    int choice;  // Variable to store user's choice

    do{
        printf("\nMusic Library Management System\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Search Record\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addRecord();
                break;
            case 2:
                viewRecord();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                updateRecord();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                printf("\nThank you for using Music Library Management System!\n");
                break;
            default:
                printf("\nInvalid Choice! Please try again.\n");
                break;
        }
    } while(choice != 6);
    
    return 0;
}

// Function to add record to the music library
void addRecord(){
    MusicRecord newRecord;

    getchar();  // Clearing the input buffer
    printf("\nEnter the Title of the Song: ");
    fgets(newRecord.title, 50, stdin);
    strtok(newRecord.title, "\n");  // Removing the newline character

    printf("Enter the Name of Artist: ");
    fgets(newRecord.artist, 50, stdin);
    strtok(newRecord.artist, "\n");  // Removing the newline character

    printf("Enter the Name of Album: ");
    fgets(newRecord.album, 50, stdin);
    strtok(newRecord.album, "\n");  // Removing the newline character

    printf("Enter the Genre: ");
    fgets(newRecord.genre, 50, stdin);
    strtok(newRecord.genre, "\n");  // Removing the newline character

    printf("Enter the Rating (1 to 5): ");
    scanf("%d", &newRecord.rating);

    records[numRecords++] = newRecord;

    printf("\nRecord added successfully!\n");
}

// Function to view all records from the music library
void viewRecord(){
    if(numRecords == 0){
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\nAll Records in the Music Library:\n");
    printf("%-3s%-30s%-30s%-30s%-20s%-10s\n", "No.", "Title", "Artist", "Album", "Genre", "Rating");
    for(int i=0; i<numRecords; i++){
        printf("%-3d%-30s%-30s%-30s%-20s%-10d\n", i+1, records[i].title, records[i].artist, records[i].album, records[i].genre, records[i].rating);
    }
}

// Function to search and display a record from the music library
void searchRecord(){
    if(numRecords == 0){
        printf("\nNo Records Found!\n");
        return;
    }

    char searchTitle[50];
    int found = 0;

    getchar();  // Clearing the input buffer
    printf("\nEnter the Title of the Song you want to search: ");
    fgets(searchTitle, 50, stdin);
    strtok(searchTitle, "\n");  // Removing the newline character

    printf("%-3s%-30s%-30s%-30s%-20s%-10s\n", "No.", "Title", "Artist", "Album", "Genre", "Rating");
    for(int i=0; i<numRecords; i++){
        if(strstr(records[i].title, searchTitle) != NULL){
            printf("%-3d%-30s%-30s%-30s%-20s%-10d\n", i+1, records[i].title, records[i].artist, records[i].album, records[i].genre, records[i].rating);
            found = 1;
        }
    }

    if(!found){
        printf("\nNo Records Found!\n");
    }
}

// Function to update a record in the music library
void updateRecord(){
    if(numRecords == 0){
        printf("\nNo Records Found!\n");
        return;
    }

    int updateIndex;
    char choice;

    printf("\nEnter the index of the record you want to update: ");
    scanf("%d", &updateIndex);

    if(updateIndex < 1 || updateIndex > numRecords){
        printf("\nInvalid Index! Please try again.\n");
        return;
    }

    printf("\nYou are going to update this record:\n");
    printf("%-3s%-30s%-30s%-30s%-20s%-10s\n", "No.", "Title", "Artist", "Album", "Genre", "Rating");
    printf("%-3d%-30s%-30s%-30s%-20s%-10d\n", updateIndex, records[updateIndex-1].title, records[updateIndex-1].artist, records[updateIndex-1].album, records[updateIndex-1].genre, records[updateIndex-1].rating);

    getchar();  // Clearing the input buffer
    printf("\nDo you want to update Title (Y/N)? ");
    scanf("%c", &choice);
    if(choice == 'Y' || choice == 'y'){
        getchar();  // Clearing the input buffer
        printf("Enter the new Title: ");
        fgets(records[updateIndex-1].title, 50, stdin);
        strtok(records[updateIndex-1].title, "\n");  // Removing the newline character
    }

    printf("\nDo you want to update Artist (Y/N)? ");
    scanf("%c", &choice);
    if(choice == 'Y' || choice == 'y'){
        getchar();  // Clearing the input buffer
        printf("Enter the new Artist: ");
        fgets(records[updateIndex-1].artist, 50, stdin);
        strtok(records[updateIndex-1].artist, "\n");  // Removing the newline character
    }

    printf("\nDo you want to update Album (Y/N)? ");
    scanf("%c", &choice);
    if(choice == 'Y' || choice == 'y'){
        getchar();  // Clearing the input buffer
        printf("Enter the new Album: ");
        fgets(records[updateIndex-1].album, 50, stdin);
        strtok(records[updateIndex-1].album, "\n");  // Removing the newline character
    }

    printf("\nDo you want to update Genre (Y/N)? ");
    scanf("%c", &choice);
    if(choice == 'Y' || choice == 'y'){
        getchar();  // Clearing the input buffer
        printf("Enter the new Genre: ");
        fgets(records[updateIndex-1].genre, 50, stdin);
        strtok(records[updateIndex-1].genre, "\n");  // Removing the newline character
    }

    printf("\nDo you want to update Rating (Y/N)? ");
    scanf("%c", &choice);
    if(choice == 'Y' || choice == 'y'){
        printf("Enter the new Rating (1 to 5): ");
        scanf("%d", &records[updateIndex-1].rating);
    }

    printf("\nRecord updated successfully!\n");
}

// Function to delete a record from the music library
void deleteRecord(){
    if(numRecords == 0){
        printf("\nNo Records Found!\n");
        return;
    }

    int deleteIndex;

    printf("\nEnter the index of the record you want to delete: ");
    scanf("%d", &deleteIndex);

    if(deleteIndex < 1 || deleteIndex > numRecords){
        printf("\nInvalid Index! Please try again.\n");
        return;
    }

    printf("\nYou are going to delete this record:\n");
    printf("%-3s%-30s%-30s%-30s%-20s%-10s\n", "No.", "Title", "Artist", "Album", "Genre", "Rating");
    printf("%-3d%-30s%-30s%-30s%-20s%-10d\n", deleteIndex, records[deleteIndex-1].title, records[deleteIndex-1].artist, records[deleteIndex-1].album, records[deleteIndex-1].genre, records[deleteIndex-1].rating);

    for(int i=deleteIndex-1; i<numRecords-1; i++){
        records[i] = records[i+1];
    }

    numRecords--;

    printf("\nRecord deleted successfully!\n");
}