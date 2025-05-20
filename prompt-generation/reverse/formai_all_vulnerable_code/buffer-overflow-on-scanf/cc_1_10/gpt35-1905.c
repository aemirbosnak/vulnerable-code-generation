//FormAI DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FRIENDS 10
#define MAX_STR_LEN 100
#define MAX_ENTRIES 100

#define FALSE 0
#define TRUE 1

typedef struct {
    char name[MAX_STR_LEN];
    char email[MAX_STR_LEN];
} Friend;

typedef struct {
    char date[MAX_STR_LEN];
    char entry[MAX_STR_LEN];
} DiaryEntry;

int nfriends = 0; 
Friend friends[MAX_FRIENDS]; 

int nentries = 0; 
DiaryEntry entries[MAX_ENTRIES];

void displayMenu() {
    printf("Digital Diary Operations: \n\n");
    printf("1. Add a Friend.\n");
    printf("2. List all Friends.\n");
    printf("3. Add an Entry.\n");
    printf("4. List all Entries.\n");
    printf("5. Exit.\n\n");
}

void addFriend() {
    if(nfriends < MAX_FRIENDS) {
        printf("Enter the following details to add a friend: \n");
        printf("Name: ");
        scanf("%s", friends[nfriends].name);
        printf("Email: ");
        scanf("%s", friends[nfriends].email);
        printf("Friend added successfully! \n\n");
        nfriends++;
    }
    else {
        printf("Sorry, the maximum number of friends has been reached.\n\n");
    }
}

void listFriends() {
    printf("The list of friends is: \n\n");
    for(int i = 0; i < nfriends; i++) {
        printf("Name: %s\n", friends[i].name);
        printf("Email: %s\n", friends[i].email);
        printf("\n");
    }
}

void addEntry() {
    if(nentries < MAX_ENTRIES) {
        char date[MAX_STR_LEN];
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        strftime(date, sizeof(date), "%A, %d %B %Y %I:%M %p", tm);
            
        printf("Enter your entry: ");
        
        fgets(entries[nentries].entry, MAX_STR_LEN, stdin);
        fgets(entries[nentries].entry, MAX_STR_LEN, stdin);

        strcpy(entries[nentries].date, date);

        printf("Entry added successfully! \n\n");

        nentries++;
    }
    else {
        printf("Sorry, the maximum number of entries has been reached. \n\n");
    }
}

void listEntries() {
    printf("The list of all diary entries with dates is: \n\n");
    for(int i = 0; i < nentries; i++) {
        printf("-----------------------------------------------\n");
        printf("Date: %s\n", entries[i].date);
        printf("Entry:\n%s\n", entries[i].entry);
        printf("-----------------------------------------------\n\n");
    }
}

int main(void) {
    int option = 0;

    printf("Welcome to your Digital Diary!\n");

    while(TRUE) {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addFriend();
                break;
            case 2:
                listFriends();
                break;
            case 3:
                addEntry();
                break;
            case 4:
                listEntries();
                break;
            case 5:
                printf("Thank you for using your Digital Diary! Have a great day:) \n\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return EXIT_SUCCESS;
}