//FormAI DATASET v1.0 Category: Digital Diary ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Diary{
    int id;
    char date[20];
    char msg[500];
};

// Global Variables
int numOfEntries = 0;
struct Diary *entries;

// Function Prototypes
void start();
void newEntry();
void view();
void searchByDate();
void searchByID();
void saveToFile();
void loadFromFile();

int main(){
    start();
    return 0;
}

// Function to display the menu
void start(){
    printf("\n\t\t\tDigital Diary\n");
    printf("\n1. New Entry\n2. View Entries\n3. Search by Date\n4. Search by ID\n5. Save Entries\n6. Load Entries\n7. Exit\n");

    int choice;
    printf("\nEnter Choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            newEntry();
            break;
        case 2:
            view();
            break;
        case 3:
            searchByDate();
            break;
        case 4:
            searchByID();
            break;
        case 5:
            saveToFile();
            break;
        case 6:
            loadFromFile();
            break;
        case 7:
            printf("\nExiting...");
            exit(0);
        default:
            printf("\nInvalid Choice. Try Again!\n");
            start();
            break;
    }
}

// Function to create new diary entry
void newEntry(){
    numOfEntries++;

    if(numOfEntries == 1){
        entries = (struct Diary*) malloc(sizeof(struct Diary));
    } else {
        entries = (struct Diary*) realloc(entries, numOfEntries*sizeof(struct Diary));
    }

    int id = numOfEntries;
    printf("\nNew Entry\n");
    printf("\nID: %d\n", id);

    time_t current_time;
    struct tm *info;
    char date[20];

    time(&current_time);
    info = localtime(&current_time);

    strftime(date, sizeof(date), "%x", info);
    printf("Date: %s\n", date);

    char msg[500];
    printf("Your Message: ");
    fflush(stdin);
    gets(msg);

    entries[id-1].id = id;
    strcpy(entries[id-1].date, date);
    strcpy(entries[id-1].msg, msg);

    printf("\nEntry Saved Successfully!\n");
    start();
}

// Function to view all the diary entries
void view(){
    printf("\nAll Entries\n");
    if(numOfEntries == 0){
        printf("\nNo Entries Found!\n");
    } else {
        printf("\nID\tDate\t\tMessage");
        for(int i=0; i<numOfEntries; i++){
            printf("\n%d\t%s\t\t%s", entries[i].id, entries[i].date, entries[i].msg);
        }
    }
    start();
}

// Function to search the diary entries by Date
void searchByDate(){
    printf("\nSearch Entry by Date\n");
    char date[20];
    printf("Enter Date (mm/dd/yy): ");
    scanf("%s", &date);

    int found = 0;
    printf("\nID\tDate\t\tMessage");

    for(int i=0; i<numOfEntries; i++){
        if(strcmp(entries[i].date, date) == 0){
            printf("\n%d\t%s\t\t%s", entries[i].id, entries[i].date, entries[i].msg);
            found = 1;
        }
    }

    if(found == 0){
        printf("\nNo Matching Entries Found!\n");
    }
    start();
}

// Function to search the diary entries by ID
void searchByID(){
    printf("\nSearch Entry by ID\n");
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    if(id > numOfEntries || id <= 0){
        printf("\nInvalid ID!\n");
    } else {
        printf("\nID\tDate\t\tMessage");
        printf("\n%d\t%s\t\t%s", entries[id-1].id, entries[id-1].date, entries[id-1].msg);
    }
    start();
}

// Function to save entries to a file
void saveToFile(){
    FILE *fptr;
    fptr = fopen("diary_entries.txt", "w");

    if(fptr == NULL){
        printf("\nError Opening File!\n");
        start();
    } else {
        for(int i=0; i<numOfEntries; i++){
            fprintf(fptr,"%d\n%s\n%s\n", entries[i].id, entries[i].date, entries[i].msg);
        }

        fclose(fptr);
        printf("\nEntries Saved to File!\n");
        start();
    }
}

// Function to load entries from a file
void loadFromFile(){
    FILE *fptr;
    fptr = fopen("diary_entries.txt", "r");

    if(fptr == NULL){
        printf("\nError Opening File!\n");
        start();
    } else {
        numOfEntries = 0;

        while(!feof(fptr)){
            numOfEntries++;

            if(numOfEntries == 1){
                entries = (struct Diary*) malloc(sizeof(struct Diary));
            } else {
                entries = (struct Diary*) realloc(entries, numOfEntries*sizeof(struct Diary));
            }

            fscanf(fptr, "%d", &entries[numOfEntries-1].id);
            fscanf(fptr, "\n%[^\n]", entries[numOfEntries-1].date);
            fscanf(fptr, "\n%[^\n]", entries[numOfEntries-1].msg);
        }

        fclose(fptr);
        printf("\nEntries Loaded Successfully!\n");
        start();
    }
}