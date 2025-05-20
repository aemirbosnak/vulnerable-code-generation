//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAPTERS 10
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Chapter;

typedef struct {
    Chapter chapters[MAX_CHAPTERS];
    int chapterCount;
    char bgColor[20];
    char fontType[20];
} EbookReader;

void printMenu();
void displayChapter(EbookReader *ebook, int chapterIndex);
void changeBackgroundColor(EbookReader *ebook);
void changeFontType(EbookReader *ebook);
void readEbook(EbookReader *ebook);

int main() {
    EbookReader ebook = {
        .chapterCount = 3,
        .bgColor = "white",
        .fontType = "Arial"
    };

    // Sample Chapters
    strcpy(ebook.chapters[0].title, "Chapter 1: The Beginning");
    strcpy(ebook.chapters[0].content, "This is the content of Chapter 1.");

    strcpy(ebook.chapters[1].title, "Chapter 2: The Middle");
    strcpy(ebook.chapters[1].content, "This is the content of Chapter 2.");

    strcpy(ebook.chapters[2].title, "Chapter 3: The End");
    strcpy(ebook.chapters[2].content, "This is the content of Chapter 3.");

    readEbook(&ebook);

    return 0;
}

void printMenu() {
    printf("\n========================\n");
    printf("Welcome to the Ebook Reader!\n");
    printf("========================\n");
    printf("1. Read a chapter\n");
    printf("2. Change background color\n");
    printf("3. Change font type\n");
    printf("4. Exit\n");
    printf("========================\n");
}

void displayChapter(EbookReader *ebook, int chapterIndex) {
    if (chapterIndex < 0 || chapterIndex >= ebook->chapterCount) {
        printf("Invalid chapter index.\n");
        return;
    }
    printf("\nCurrently Reading: %s\n", ebook->chapters[chapterIndex].title);
    printf("Content: %s\n", ebook->chapters[chapterIndex].content);
}

void changeBackgroundColor(EbookReader *ebook) {
    printf("Enter new background color (e.g., white, black, blue): ");
    scanf("%s", ebook->bgColor);
    printf("Background color changed to %s.\n", ebook->bgColor);
}

void changeFontType(EbookReader *ebook) {
    printf("Enter new font type (e.g., Arial, Times, Verdana): ");
    scanf("%s", ebook->fontType);
    printf("Font type changed to %s.\n", ebook->fontType);
}

void readEbook(EbookReader *ebook) {
    int choice;
    int chapterIndex;

    while (1) {
        printMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter chapter number (0 to %d): ", ebook->chapterCount - 1);
                scanf("%d", &chapterIndex);
                displayChapter(ebook, chapterIndex);
                break;
            case 2:
                changeBackgroundColor(ebook);
                break;
            case 3:
                changeFontType(ebook);
                break;
            case 4:
                printf("Exiting the Ebook Reader. Happy reading!\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}