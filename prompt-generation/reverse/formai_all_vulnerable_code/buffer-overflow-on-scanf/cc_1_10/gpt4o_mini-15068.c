//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char mood[20];
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int numberOfEntries = 0;

void getCurrentDate(char *buffer) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(buffer, 11, "%Y-%m-%d", tm_info);
}

void addEntry() {
    if (numberOfEntries >= MAX_ENTRIES) {
        printf("Sorry, can't add more entries. Your diary is full! Maybe you should publish a book?\n");
        return;
    }
    
    char currentDate[11];
    getCurrentDate(currentDate);
    
    printf("Today's date is: %s. Let's record some wise words...\n", currentDate);
    
    strcpy(diary[numberOfEntries].date, currentDate);

    printf("Enter your mood today (like 'Happy', 'Innovative', or 'Just-ate-a-whole-pizza'): ");
    scanf("%s", diary[numberOfEntries].mood);

    printf("Now, pour your thoughts into our virtual parchment: ");
    getchar();  // Clear the newline after mood
    fgets(diary[numberOfEntries].entry, MAX_LENGTH, stdin);
    diary[numberOfEntries].entry[strcspn(diary[numberOfEntries].entry, "\n")] = 0;  // Remove newline

    numberOfEntries++;
    printf("Entry added! Remember, future you will read this - or not... depending on if you forget your password!\n");
}

void viewEntries() {
    if (numberOfEntries == 0) {
        printf("Your diary is as empty as my wallet after grocery shopping!\n");
        return;
    }

    printf("\nHere are your glorious and magnificent entries:\n");
    for (int i = 0; i < numberOfEntries; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Date: %s\n", diary[i].date);
        printf("Mood: %s\n", diary[i].mood);
        printf("Thoughts: %s\n", diary[i].entry);
        printf("------------------------------\n");
    }
}

void saveDiary() {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Oops! I can't save your diary... It's like screaming into the void!\n");
        return;
    }

    for (int i = 0; i < numberOfEntries; i++) {
        fprintf(file, "Entry %d:\n", i + 1);
        fprintf(file, "Date: %s\n", diary[i].date);
        fprintf(file, "Mood: %s\n", diary[i].mood);
        fprintf(file, "Thoughts: %s\n", diary[i].entry);
        fprintf(file, "------------------------------\n");
    }

    fclose(file);
    printf("Your thoughts have been safely imprisoned in diary.txt! At least until your next meltdown.\n");
}

int main() {
    int choice;
    
    printf("Welcome to your Digital Diary, where deep thoughts meet shallow coding skills!\n");
    printf("---------------------------------------------------------\n");
    
    while (1) {
        printf("Choose an option:\n");
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Save diary\n");
        printf("4. Exit (and go live your life!)\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                saveDiary();
                break;
            case 4:
                printf("Goodbye! May your life plot twist gently!\n");
                exit(0);
            default:
                printf("Oops! That's not a valid choice. Do you need a map?\n");
        }
    }
    
    return 0;
}