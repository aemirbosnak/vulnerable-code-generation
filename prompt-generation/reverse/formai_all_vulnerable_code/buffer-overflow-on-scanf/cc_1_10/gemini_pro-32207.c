//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char *title;
    char *body;
    int length;
    bool isEncrypted;
} DiaryEntry;

void initDiaryEntry(DiaryEntry *entry) {
    entry->title = NULL;
    entry->body = NULL;
    entry->length = 0;
    entry->isEncrypted = false;
}

void freeDiaryEntry(DiaryEntry *entry) {
    free(entry->title);
    free(entry->body);
    free(entry);
}

int main() {
    // Here's my digital diary! Feel free to write your secrets in it.
    // But beware, I might read them!
    DiaryEntry diary;
    initDiaryEntry(&diary);

    while (true) {
        printf("What do you want to do? (write/read/encrypt/decrypt/quit): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "write") == 0) {
            printf("Title: ");
            char title[100];
            scanf("%s", title);
            diary.title = malloc(strlen(title) + 1);
            strcpy(diary.title, title);

            printf("Body: ");
            char body[1000];
            scanf("%s", body);
            diary.body = malloc(strlen(body) + 1);
            strcpy(diary.body, body);

            diary.length = strlen(body);
        } else if (strcmp(command, "read") == 0) {
            if (diary.title == NULL) {
                printf("Your diary is empty!\n");
            } else {
                printf("Title: %s\n", diary.title);
                printf("Body: %s\n", diary.body);
            }
        } else if (strcmp(command, "encrypt") == 0) {
            if (diary.isEncrypted) {
                printf("Your diary is already encrypted!\n");
            } else {
                for (int i = 0; i < diary.length; i++) {
                    diary.body[i] ^= 42;
                }
                diary.isEncrypted = true;
                printf("Your diary has been encrypted!\n");
            }
        } else if (strcmp(command, "decrypt") == 0) {
            if (!diary.isEncrypted) {
                printf("Your diary is not encrypted!\n");
            } else {
                for (int i = 0; i < diary.length; i++) {
                    diary.body[i] ^= 42;
                }
                diary.isEncrypted = false;
                printf("Your diary has been decrypted!\n");
            }
        } else if (strcmp(command, "quit") == 0) {
            printf("Bye!\n");
            freeDiaryEntry(&diary);
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}