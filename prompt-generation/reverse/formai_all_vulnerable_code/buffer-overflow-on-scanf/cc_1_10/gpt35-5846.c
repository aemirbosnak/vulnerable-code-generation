//FormAI DATASET v1.0 Category: Digital Diary ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_TEXT_LEN 1000

struct entry {
    time_t timestamp;
    char text[MAX_TEXT_LEN];
};

int num_entries = 0;
struct entry diary[MAX_ENTRIES];

void print_menu() {
    printf("\n====== Digital Diary ======\n");
    printf("1. Add new entry\n");
    printf("2. View past entries\n");
    printf("3. Search for entry\n");
    printf("4. Exit program\n");
    printf("Enter your choice: ");
}

void add_entry() {
    char text[MAX_TEXT_LEN];
    printf("Enter new entry (max %d characters):\n", MAX_TEXT_LEN);
    fgets(text, MAX_TEXT_LEN, stdin);

    if (strlen(text) > 1) {
        diary[num_entries].timestamp = time(NULL);
        strcpy(diary[num_entries].text, text);
        num_entries++;
        printf("New entry added!\n");
    } else {
        printf("Error: entry must have at least one character.\n");
    }
}

void view_entries() {
    for (int i = 0; i < num_entries; i++) {
        struct tm *lt = localtime(&diary[i].timestamp);
        printf("%d/%d/%d %d:%d %s", lt->tm_mday, lt->tm_mon + 1, lt->tm_year + 1900, 
                                        lt->tm_hour, lt->tm_min, diary[i].text);
    }
}

void search_entry() {
    char search_term[MAX_TEXT_LEN];
    printf("Enter search term:\n");
    fgets(search_term, MAX_TEXT_LEN, stdin);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].text, search_term)) {
            struct tm *lt = localtime(&diary[i].timestamp);
            printf("%d/%d/%d %d:%d %s", lt->tm_mday, lt->tm_mon + 1, lt->tm_year + 1900, 
                                        lt->tm_hour, lt->tm_min, diary[i].text);
        }
    }
}

int main() {
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);
        getchar(); // flush newline character

        switch (choice) {
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
                printf("Exiting program... Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}