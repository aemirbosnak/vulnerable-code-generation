//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(diary[num_entries].date, 20, "%Y-%m-%d %H:%M:%S", t);
    printf("Enter your entry:\n");
    scanf("%[^\n]", diary[num_entries].entry);
    num_entries++;
}

void view_entries() {
    printf("Date\tEntry\n");
    for(int i=0;i<num_entries;i++) {
        printf("%s\t%s\n", diary[i].date, diary[i].entry);
    }
}

void search_entry() {
    char keyword[MAX_ENTRY_LENGTH];
    printf("Enter the keyword to search: ");
    scanf("%[^\n]", keyword);
    for(int i=0;i<num_entries;i++) {
        if(strstr(diary[i].entry, keyword)!= NULL) {
            printf("%s\t%s\n", diary[i].date, diary[i].entry);
        }
    }
}

int main() {
    int choice;
    while(1) {
        printf("\nDigital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Search Entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}