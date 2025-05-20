//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256

typedef struct {
    char title[128];
    char description[128];
    time_t timestamp;
} DigitalDiaryEntry;

void print_entry(DigitalDiaryEntry entry) {
    char timestamp_str[20];
    strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", localtime(&entry.timestamp));
    printf("Title: %s\n", entry.title);
    printf("Description: %s\n", entry.description);
    printf("Timestamp: %s\n", timestamp_str);
    printf("\n");
}

int main() {
    DigitalDiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (num_entries < MAX_ENTRIES) {
        printf("Enter title (up to 128 characters): ");
        scanf("%s", entries[num_entries].title);
        getchar(); // consume newline character

        printf("Enter description (up to 128 characters): ");
        fgets(entries[num_entries].description, sizeof(entries[num_entries].description), stdin);
        entries[num_entries].description[strcspn(entries[num_entries].description, "\n")] = '\0'; // remove newline character

        entries[num_entries].timestamp = time(NULL);
        num_entries++;

        printf("Entry saved successfully.\n");
        printf("Do you want to add another entry? (y/n): ");
        char add_another;
        scanf("%c", &add_another);
        getchar();

        if (add_another != 'y') {
            break;
        }
    }

    printf("\nListing all entries:\n");
    for (int i = 0; i < num_entries; i++) {
        print_entry(entries[i]);
    }

    return 0;
}