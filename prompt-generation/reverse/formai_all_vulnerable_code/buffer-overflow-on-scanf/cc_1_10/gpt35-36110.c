//FormAI DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define ENTRY_SIZE 1000

typedef struct {
    char date[50];
    char entry[ENTRY_SIZE];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *date, char *entry) {
    if(num_entries == MAX_ENTRIES) {
        printf("Sorry, diary is full.\n");
        return;
    }
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
    printf("Entry added.\n");
}

void view_entries() {
    if(num_entries == 0) {
        printf("No entries to view.\n");
        return;
    }
    printf("Diary Entries:\n");
    for(int i=0; i<num_entries; i++) {
        printf("%s: %s\n",entries[i].date,entries[i].entry);
    }
}

void delete_entry(char *date) {
    int entry_index = -1;
    for(int i=0; i<num_entries; i++) {
        if(strcmp(entries[i].date,date) == 0) {
            entry_index = i;
            break;
        }
    }
    if(entry_index == -1) {
        printf("Entry not found.\n");
        return;
    }
    for(int i=entry_index; i<num_entries-1; i++) {
        strcpy(entries[i].date,entries[i+1].date);
        strcpy(entries[i].entry,entries[i+1].entry);
    }
    num_entries--;
    printf("Entry deleted.\n");
}

int main() {
    int choice;
    char date[50];
    char entry[ENTRY_SIZE];
    while(1) {
        printf("1. Add entry\n2. View entries\n3. Delete entry\n4. Quit\nEnter choice (1-4): ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("\nEnter date (dd/mm/yyyy): ");
                scanf("%s",date);
                printf("Enter entry (max %d characters):\n",ENTRY_SIZE);
                getchar();
                fgets(entry, ENTRY_SIZE, stdin);
                add_entry(date,entry);
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("\nEnter date of entry to delete (dd/mm/yyyy): ");
                scanf("%s",date);
                delete_entry(date);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}