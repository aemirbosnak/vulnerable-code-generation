//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256

typedef struct {
    char entry[ENTRY_SIZE];
    time_t timestamp;
} DiaryEntry;

typedef struct {
    DiaryEntry entries[MAX_ENTRIES];
    int entry_count;
} CyberDiary;

void init_diary(CyberDiary *diary) {
    diary->entry_count = 0;
}

void add_entry(CyberDiary *diary, const char *entry) {
    if (diary->entry_count < MAX_ENTRIES) {
        strncpy(diary->entries[diary->entry_count].entry, entry, ENTRY_SIZE - 1);
        diary->entries[diary->entry_count].entry[ENTRY_SIZE - 1] = '\0'; // ensure null-termination
        diary->entries[diary->entry_count].timestamp = time(NULL);
        diary->entry_count++;
    } else {
        printf("Diary full! Can't add more entries.\n");
    }
}

void view_entries(const CyberDiary *diary) {
    printf("=== Cyberpunk Digital Diary ===\n");
    for (int i = 0; i < diary->entry_count; i++) {
        char buffer[20];
        struct tm *tm_info;

        tm_info = localtime(&diary->entries[i].timestamp);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        
        printf("[%s] %s\n", buffer, diary->entries[i].entry);
    }
}

void save_diary(const CyberDiary *diary, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file) {
        fwrite(diary, sizeof(CyberDiary), 1, file);
        fclose(file);
        printf("Diary saved successfully to %s\n", filename);
    } else {
        perror("Unable to save diary");
    }
}

void load_diary(CyberDiary *diary, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file) {
        fread(diary, sizeof(CyberDiary), 1, file);
        fclose(file);
        printf("Diary loaded successfully from %s\n", filename);
    } else {
        perror("Unable to load diary");
    }
}

void display_menu() {
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Save Diary\n");
    printf("4. Load Diary\n");
    printf("5. Exit\n");
}

int main() {
    CyberDiary diary;
    init_diary(&diary);

    char filename[100] = "cyber_diary.dat";
    int choice;
    char entry[ENTRY_SIZE];

    while (1) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:
                printf("Enter your diary entry: ");
                fgets(entry, ENTRY_SIZE, stdin);
                entry[strcspn(entry, "\n")] = 0; // remove newline
                add_entry(&diary, entry);
                break;
            case 2:
                view_entries(&diary);
                break;
            case 3:
                save_diary(&diary, filename);
                break;
            case 4:
                load_diary(&diary, filename);
                break;
            case 5:
                printf("Shutting down... until next time, light in the dark.\n");
                exit(0);
            default:
                printf("Invalid option. Try again!\n");
                break;
        }
    }

    return 0;
}