//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_FILES 10
#define MAX_FILENAME_LENGTH 50
#define MAX_DATA_LENGTH 1024

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char data[MAX_DATA_LENGTH];
} File;

void amusingWelcome() {
    printf("🎉 Welcome to the \"Oops! Where Did My Data Go?\" Recovery Tool! 🎉\n");
    printf("We will recover your lost data faster than you can say, \"I really shouldn't have clicked that link!\"\n\n");
}

void funnyGoodbye() {
    printf("\n👋 Goodbye! Remember, if you lose your data again, consult a professional or a magician!\n");
    printf("If you run into any issues, just close your eyes, chant 'Data come back!', and cross your fingers! 😉\n");
}

void recoverFile(File *files, int *fileCount) {
    if (*fileCount >= MAX_FILES) {
        printf("💥 Oh no! We've run out of space for more files! Just like my diet on cheat days!\n");
        return;
    }

    File newFile;
    printf("📝 Enter the filename you want to recover: ");
    scanf("%s", newFile.filename);

    printf("🗣️ Please describe your lost data (in less than %d characters): ", MAX_DATA_LENGTH);
    getchar(); // To consume newline
    fgets(newFile.data, MAX_DATA_LENGTH, stdin);
    newFile.data[strcspn(newFile.data, "\n")] = 0; // Remove trailing newline

    files[*fileCount] = newFile;
    (*fileCount)++;

    printf("🤖 We have successfully recovered: %s\n", newFile.filename);
    printf("📜 Data: %s\n", newFile.data);
}

void showRecoveredFiles(File *files, int fileCount) {
    if (fileCount == 0) {
        printf("😱 Uh-oh! We haven't recovered any files yet! Maybe they're on vacation?\n");
        return;
    }

    printf("\n📂 Recovered Files:\n");
    for (int i = 0; i < fileCount; i++) {
        printf(" %d) %s\n     Data: %s\n", i + 1, files[i].filename, files[i].data);
    }
}

int main() {
    amusingWelcome();

    File files[MAX_FILES];
    int fileCount = 0;
    int option;

    do {
        printf("\n🌟 Choose an option:\n");
        printf("1) Recover a lost file\n");
        printf("2) Show recovered files\n");
        printf("3) Run away (Exit)\n");
        printf("Please enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                recoverFile(files, &fileCount);
                break;
            case 2:
                showRecoveredFiles(files, fileCount);
                break;
            case 3:
                funnyGoodbye();
                break;
            default:
                printf("🤔 I didn't get that! But hey, life is too short for bad choices, right? Try again!\n");
        }
    } while (option != 3);

    return 0;
}