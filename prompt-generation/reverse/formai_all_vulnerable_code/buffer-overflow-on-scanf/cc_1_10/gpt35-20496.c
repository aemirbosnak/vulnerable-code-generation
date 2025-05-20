//FormAI DATASET v1.0 Category: Music Library Management System ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// struct to hold each music file record
struct MusicFile {
    char title[50];
    char artist[50];
    char genre[20];
    int year;
};

// function to add a new record to the music library
void addRecord(struct MusicFile *lib, int *count) {
    printf("Enter the title of the song: ");
    scanf("%s", lib[*count].title); // getting title input from user and storing in the struct
    printf("Enter the name of the artist: ");
    scanf("%s", lib[*count].artist); // getting artist input from user and storing in the struct
    printf("Enter the genre of the song: ");
    scanf("%s", lib[*count].genre); // getting genre input from user and storing in the struct
    printf("Enter the year the song was released: ");
    scanf("%d", &lib[*count].year); // getting year input from user and storing in the struct
    *count += 1; // incrementing the count of records in the library
    printf("Record added successfully!\n\n");
}

// function to remove a record from the music library
void removeRecord(struct MusicFile *lib, int *count) {
    char title[50];
    printf("Enter the title of the song to remove: ");
    scanf("%s", title); // getting the title of the song to remove from the user
    int i, j;
    for(i=0; i<*count; i++) { // looping through all the records to find the record with matching title
        if(strcmp(lib[i].title, title) == 0) {
            for(j=i; j<*count-1; j++) { // shifting the records to remove the record at the given index
                strcpy(lib[j].title, lib[j+1].title);
                strcpy(lib[j].artist, lib[j+1].artist);
                strcpy(lib[j].genre, lib[j+1].genre);
                lib[j].year = lib[j+1].year;
            }
            *count -= 1; // updating the record count after removing a record
            printf("Record removed successfully!\n\n");
            return; // exiting the function after removing a single record
        }
    }
    printf("No record found with the given title!\n\n");
}

// function to display all the records in the music library
void displayLibrary(struct MusicFile *lib, int *count) {
    printf("Title\t\tArtist\t\tGenre\t\tYear\n"); // printing the table headers
    int i;
    for(i=0; i<*count; i++) { // looping through all the records to print each record in the table
        printf("%s\t\t%s\t\t%s\t\t%d\n", lib[i].title, lib[i].artist, lib[i].genre, lib[i].year);
    }
    printf("\n");
}

int main() {
    struct MusicFile library[100]; // declaring an array of MusicFile objects to hold music records
    int count = 0; // variable to keep track of number of records in the library
    printf("Welcome to the Music Library Management System!\n\n");
    while(1) { // menu driven program loop
        printf("Enter 1 to add a new record to the library\n");
        printf("Enter 2 to remove a record from the library\n");
        printf("Enter 3 to display all records in the library\n");
        printf("Enter 0 to exit\n");
        int choice;
        scanf("%d", &choice); // getting user choice
        switch(choice) {
            case 0: // exiting the program
                printf("Goodbye!\n");
                exit(0);
            case 1: // adding a new record to the library
                addRecord(library, &count);
                break;
            case 2: // removing a record from the library
                removeRecord(library, &count);
                break;
            case 3: // displaying all the records in the library
                displayLibrary(library, &count);
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }
    return 0;
}