//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

void add_entry(diary_entry* diary, int count, char* date, char* entry) {
    strncpy(diary[count].date, date, sizeof(diary[count].date));
    strncpy(diary[count].entry, entry, sizeof(diary[count].entry));
}

void print_entries(diary_entry* diary, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    diary_entry diary[MAX_ENTRIES];
    int count = 0;
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
    char input[MAX_ENTRY_LENGTH];

    printf("Welcome to your digital diary!\n");

    while (count < MAX_ENTRIES) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);

        printf("Enter your entry for %s:\n", date);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        add_entry(diary, count, date, input);
        count++;
    }

    printf("\nYour diary entries:\n");
    print_entries(diary, count);

    return 0;
}