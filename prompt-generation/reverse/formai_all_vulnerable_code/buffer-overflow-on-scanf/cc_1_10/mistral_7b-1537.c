//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define DIARY_SIZE 25
#define ENTRY_SIZE 200
#define KEY_SIZE 16

typedef struct {
    char title[ENTRY_SIZE];
    char content[ENTRY_SIZE];
    char key[KEY_SIZE];
    time_t timestamp;
} Entry;

Entry diary[DIARY_SIZE];

void encrypt(char *str, char key) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = isalpha(str[i]) ? (char)(((int)str[i] + key - 65) % 26 + 'A') : str[i];
    }
}

int findEmptyEntry() {
    for (int i = 0; i < DIARY_SIZE; i++) {
        if (diary[i].title[0] == '\0') {
            return i;
        }
    }
    return -1;
}

void saveEntry(Entry *entry, char key[]) {
    int index = findEmptyEntry();
    if (index >= 0) {
        strcpy(entry->key, key);
        time(&entry->timestamp);
        printf("Saved entry with title '%s' and key '%s' at %s\n", entry->title, entry->key, ctime(&entry->timestamp));
    } else {
        printf("No empty space in the diary.\n");
    }
}

int main() {
    char key[KEY_SIZE];
    char title[ENTRY_SIZE];
    char content[ENTRY_SIZE];

    printf("Welcome to the Cryptic Digital Diary.\n");
    printf("Enter your encryption key: ");
    scanf("%s", key);

    while (1) {
        printf("\nEnter title (leave empty to save and exit): ");
        fgets(title, ENTRY_SIZE, stdin);
        title[strcspn(title, "\n")] = '\0';

        if (strlen(title) == 0) {
            break;
        }

        printf("Enter content (leave empty to save and exit): ");
        fgets(content, ENTRY_SIZE, stdin);
        content[strcspn(content, "\n")] = '\0';

        encrypt(title, *(int *)key % 26);
        encrypt(content, *(int *)key % 26);

        saveEntry(&diary[0], key);
        strcpy(diary[0].title, title);
        strcpy(diary[0].content, content);
    }

    printf("\nGoodbye!\n");

    return 0;
}