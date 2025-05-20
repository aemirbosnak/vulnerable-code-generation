//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: curious
#include <stdio.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char mood[20];
    char entry[500];
} DiaryEntry;

void addEntry(DiaryEntry* diary, int index) {
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", diary[index].date);
    printf("Enter your mood: ");
    scanf("%s", diary[index].mood);
    printf("Enter your entry:\n");
    fgets(diary[index].entry, 500, stdin);
    diary[index].entry[strcspn(diary[index].entry, "\n")] = '\0';
}

void viewEntry(DiaryEntry* diary, int index) {
    printf("Date: %s\n", diary[index].date);
    printf("Mood: %s\n", diary[index].mood);
    printf("Entry:\n%s", diary[index].entry);
}

void searchEntry(DiaryEntry* diary, int size, char* keyword) {
    int i;
    for(i=0; i<size; i++) {
        if(strstr(diary[i].entry, keyword)!= NULL) {
            viewEntry(diary, i);
        }
    }
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int size = 0;
    char choice;
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char date[20];
    strftime(date, 20, "%Y-%m-%d", t);

    while(1) {
        printf("\nDigital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entry\n");
        printf("3. Search Entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(size >= MAX_ENTRIES) {
                    printf("Diary is full.\n");
                } else {
                    addEntry(diary, size);
                    size++;
                }
                break;
            case '2':
                printf("Enter the index of the entry you want to view: ");
                scanf("%d", &size);
                viewEntry(diary, size-1);
                break;
            case '3':
                printf("Enter the keyword to search: ");
                scanf("%s", diary[size-1].entry);
                searchEntry(diary, size, diary[size-1].entry);
                break;
            case '4':
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}