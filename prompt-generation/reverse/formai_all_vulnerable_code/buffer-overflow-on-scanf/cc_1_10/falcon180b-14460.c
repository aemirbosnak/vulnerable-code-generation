//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LEN 500

struct entry {
    char date[11];
    char mood[50];
    char text[MAX_ENTRY_LEN];
};

int num_entries = 0;
struct entry diary[MAX_ENTRIES];

void add_entry(char* d, char* m, char* t) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Sorry, diary is full!\n");
        return;
    }
    strcpy(diary[num_entries].date, d);
    strcpy(diary[num_entries].mood, m);
    strcpy(diary[num_entries].text, t);
    num_entries++;
}

void print_entry(int i) {
    printf("Date: %s\n", diary[i].date);
    printf("Mood: %s\n", diary[i].mood);
    printf("Text:\n%s\n", diary[i].text);
}

void print_diary() {
    if (num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }
    printf("Diary:\n");
    for (int i = 0; i < num_entries; i++) {
        print_entry(i);
    }
}

int main() {
    srand(time(NULL));
    int choice;
    char date[11];
    char mood[50];
    char text[MAX_ENTRY_LEN];

    printf("Welcome to the Digital Diary!\n");
    while (1) {
        printf("\n1. Add entry\n2. Print diary\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter mood: ");
                scanf("%s", mood);
                printf("Enter text:\n");
                scanf("%[^\n]", text);
                add_entry(date, mood, text);
                break;
            case 2:
                print_diary();
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}