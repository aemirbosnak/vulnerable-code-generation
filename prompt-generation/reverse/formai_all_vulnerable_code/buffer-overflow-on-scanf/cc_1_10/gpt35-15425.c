//FormAI DATASET v1.0 Category: Ebook reader ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 50
#define MAX_FILE_NAME 50
#define MAX_LINES 1000

struct Book {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char fileName[MAX_FILE_NAME];
};

struct Ebook {
    char lines[MAX_LINES][MAX_TITLE_LEN];
};

struct Book ebookLibrary[MAX_BOOKS];
int numBooks = 0;

struct Ebook currentEbook;
int currentLine = 0;
char currentFile[MAX_FILE_NAME];

void init() {
    printf("Welcome to Ebook Reader!\n");
    printf("Please enter the name of the file containing your library:\n");

    char fileName[MAX_FILE_NAME];
    scanf("%s", fileName);

    FILE* libraryFile = fopen(fileName, "r");
    if (!libraryFile) {
        printf("Error: Unable to open file %s\n", fileName);
        exit(1);
    }

    char buffer[100];
    while (fgets(buffer, 100, libraryFile)) {
        char* title = strtok(buffer, ",");
        char* author = strtok(NULL, ",");
        char* fileName = strtok(NULL, "\n");

        if (title && author && fileName && numBooks < MAX_BOOKS) {
            strcpy(ebookLibrary[numBooks].title, title);
            strcpy(ebookLibrary[numBooks].author, author);
            strcpy(ebookLibrary[numBooks].fileName, fileName);

            numBooks++;
        }
    }

    fclose(libraryFile);
}

void listBooks() {
    printf("Available books:\n");

    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s, by %s\n", i + 1, ebookLibrary[i].title, ebookLibrary[i].author);
    }
}

void selectBook() {
    printf("Enter the number of the book you would like to read:\n");

    int choice;
    scanf("%d", &choice);

    if (choice <= 0 || choice > numBooks) {
        printf("Invalid choice!\n");
        return;
    }

    currentLine = 0;
    strcpy(currentFile, ebookLibrary[choice - 1].fileName);

    FILE* ebookFile = fopen(currentFile, "r");
    if (!ebookFile) {
        printf("Error: Unable to open file %s\n", currentFile);
        return;
    }

    char buffer[MAX_TITLE_LEN];
    while (fgets(buffer, MAX_TITLE_LEN, ebookFile)) {
        buffer[strlen(buffer) - 1] = '\0';
        strcpy(currentEbook.lines[currentLine], buffer);

        currentLine++;
    }

    fclose(ebookFile);
}

void readBook() {
    if (currentLine == 0) {
        printf("No book has been selected!\n");
        return;
    }

    int choice = 0;
    do {
        printf("%s\n", currentEbook.lines[currentLine]);

        printf("1. Next line\n");
        printf("2. Previous line\n");
        printf("3. Exit book\n");

        scanf("%d", &choice);

        if (choice == 1) {
            currentLine++;
            if (currentLine >= MAX_LINES || strlen(currentEbook.lines[currentLine]) == 0) {
                printf("End of book!\n");
                return;
            }
        } else if (choice == 2) {
            currentLine--;
            if (currentLine < 0) {
                printf("Beginning of book!\n");
                currentLine = 0;
            }
        }
    } while (choice != 3);
}

int main() {
    init();

    int choice = 0;
    do {
        printf("1. List books\n");
        printf("2. Select book\n");
        printf("3. Read book\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listBooks();
                break;

            case 2:
                selectBook();
                break;

            case 3:
                readBook();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}