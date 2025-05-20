//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ENTRIES 100

struct Entry{
    char date[10];
    char time[8];
    char content[500];
};

void addEntry(struct Entry entry[], int numEntries){
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", entry[numEntries].date);
    printf("Enter time (hh:mm:ss): ");
    scanf("%s", entry[numEntries].time);
    printf("Enter content:\n");
    fgets(entry[numEntries].content, 500, stdin);
    entry[numEntries].content[strcspn(entry[numEntries].content, "\n")] = '\0';
    numEntries++;
}

void displayEntries(struct Entry entry[], int numEntries){
    printf("Date\tTime\tContent\n");
    for(int i=0; i<numEntries; i++){
        printf("%s\t%s\t%s\n", entry[i].date, entry[i].time, entry[i].content);
    }
}

void deleteEntry(struct Entry entry[], int numEntries){
    printf("Enter the date (dd/mm/yyyy) of the entry you want to delete: ");
    scanf("%s", entry[numEntries-1].date);
    if(strcmp(entry[numEntries-1].date, "invalid") == 0){
        printf("Entry not found.\n");
    }
    else{
        entry[numEntries-1].date[0] = 'i';
        entry[numEntries-1].content[0] = '\0';
        numEntries--;
        printf("Entry deleted successfully.\n");
    }
}

void searchEntry(struct Entry entry[], int numEntries){
    printf("Enter the date (dd/mm/yyyy) of the entry you want to search: ");
    scanf("%s", entry[numEntries-1].date);
    if(strcmp(entry[numEntries-1].date, "invalid") == 0){
        printf("Entry not found.\n");
    }
    else{
        printf("Date: %s\n", entry[numEntries-1].date);
        printf("Time: %s\n", entry[numEntries-1].time);
        printf("Content: %s\n", entry[numEntries-1].content);
    }
}

int main(){
    struct Entry entry[MAX_ENTRIES];
    int numEntries = 0;

    while(1){
        printf("1. Add entry\n");
        printf("2. Display entries\n");
        printf("3. Delete entry\n");
        printf("4. Search entry\n");
        printf("5. Exit\n");
        scanf("%d", &numEntries);

        switch(numEntries){
            case 1:
                addEntry(entry, numEntries);
                break;
            case 2:
                displayEntries(entry, numEntries);
                break;
            case 3:
                deleteEntry(entry, numEntries);
                break;
            case 4:
                searchEntry(entry, numEntries);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}