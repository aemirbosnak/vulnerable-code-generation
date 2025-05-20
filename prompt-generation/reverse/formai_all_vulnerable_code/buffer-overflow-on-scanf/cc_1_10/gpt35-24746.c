//FormAI DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct DiaryEntry {
    char date[11];
    char content[500];
};

struct DigitalDiary {
    struct DiaryEntry entries[MAX_ENTRIES];
    int num_entries;
};

void display_menu() {
    printf("\n\n **** Digital Diary **** \n\n");
    printf("1. Add Entry \n");
    printf("2. View All Entries \n");
    printf("3. Search by Date \n");
    printf("4. Delete Entry \n");
    printf("5. Exit \n\n");
}

void add_entry(struct DigitalDiary *diary) {
    if(diary->num_entries == MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", diary->entries[diary->num_entries].date);
    printf("Enter content: ");
    scanf(" %[^\n]s", diary->entries[diary->num_entries].content);
    diary->num_entries++;
    printf("Entry added successfully!\n");
}

void view_all_entries(struct DigitalDiary *diary) {
    if(diary->num_entries == 0) {
        printf("No entries found!\n");
        return;
    }
    printf("\n\n **** All Entries **** \n\n");
    for(int i=0; i<diary->num_entries; i++) {
        printf("%d. Date: %s\n", i+1, diary->entries[i].date);
        printf("   Content: %s\n\n", diary->entries[i].content);
    }
}

void search_by_date(struct DigitalDiary *diary) {
    char search_date[11];
    printf("Enter date to search for (dd/mm/yyyy): ");
    scanf("%s", search_date);
    printf("\n\n *** Search Results *** \n\n");
    for(int i=0; i<diary->num_entries; i++) {
        if(strcmp(search_date, diary->entries[i].date) == 0) {
            printf("Entry %d: Date: %s\n", i+1, diary->entries[i].date);
            printf("          Content: %s\n", diary->entries[i].content);
        }
    }
}

void delete_entry(struct DigitalDiary *diary) {
    int entry_num;
    printf("Enter entry number to delete: ");
    scanf("%d", &entry_num);
    if(entry_num < 1 || entry_num > diary->num_entries) {
        printf("Invalid entry number!\n");
        return;
    }
    for(int i=entry_num-1; i<diary->num_entries-1; i++) {
        strcpy(diary->entries[i].date, diary->entries[i+1].date);
        strcpy(diary->entries[i].content, diary->entries[i+1].content);
    }
    diary->num_entries--;
    printf("Entry deleted successfully!\n");
}

int main() {
    struct DigitalDiary diary;
    diary.num_entries = 0;
    int choice = 0;
    while(choice != 5) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_entry(&diary);
                break;
            case 2:
                view_all_entries(&diary);
                break;
            case 3:
                search_by_date(&diary);
                break;
            case 4:
                delete_entry(&diary);
                break;
            case 5:
                printf("Exiting Digital Diary...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}