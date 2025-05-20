//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[20];
    char content[MAX_LENGTH];
    int isEncrypted;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void encrypt(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] ^ 0xAA; // Simple XOR encryption for paranoia
    }
}

void decrypt(char *text) {
    encrypt(text); // XOR again to decrypt
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    DiaryEntry newEntry;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(newEntry.date, sizeof(newEntry.date), "%02d-%02d-%04d %02d:%02d:%02d",
             tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

    printf("Enter your diary entry (max %d characters):\n", MAX_LENGTH - 1);
    fgets(newEntry.content, sizeof(newEntry.content), stdin);
    newEntry.content[strcspn(newEntry.content, "\n")] = 0; // Remove newline

    printf("Is this entry a secret? (1 for yes, 0 for no): ");
    scanf("%d", &newEntry.isEncrypted);
    getchar(); // Clear newline from buffer

    if (newEntry.isEncrypted) {
        encrypt(newEntry.content);
    }

    diary[entryCount++] = newEntry;
    printf("Entry saved on %s\n", newEntry.date);
}

void viewEntries() {
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d [Date: %s]: ", i + 1, diary[i].date);
        if (diary[i].isEncrypted) {
            char decryptedContent[MAX_LENGTH];
            strcpy(decryptedContent, diary[i].content);
            decrypt(decryptedContent);
            printf("%s\n", decryptedContent);
        } else {
            printf("%s\n", diary[i].content);
        }
    }
}

void deleteEntry() {
    int index;
    printf("Enter the index of the entry to delete (1 to %d): ", entryCount);
    scanf("%d", &index);
    getchar(); // Clear newline from buffer

    if (index >= 1 && index <= entryCount) {
        for (int i = index - 1; i < entryCount - 1; i++) {
            diary[i] = diary[i + 1];
        }
        entryCount--;
        printf("Entry deleted successfully!\n");
    } else {
        printf("Invalid index!\n");
    }
}

void paranoidMode() {
    printf("Activating paranoid mode... Beware! Anyone lurking may attempt to access your sensitive thoughts!\n");
}

void menu() {
    while (1) {
        printf("\nDigital Diary Menu:\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Activate Paranoid Mode\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                paranoidMode();
                break;
            case 5:
                printf("Exiting the Diary. Stay aware of your thoughts!\n");
                return;
            default:
                printf("Invalid option! Choose wisely, or the shadows may catch you.\n");
        }
    }
}

int main() {
    printf("Welcome to the Paranoid Digital Diary!\n");
    menu();
    return 0;
}