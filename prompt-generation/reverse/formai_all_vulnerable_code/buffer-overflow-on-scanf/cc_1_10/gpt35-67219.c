//FormAI DATASET v1.0 Category: Ebook reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOK_LENGTH 1000
#define MAX_CHAPTERS 50
#define MAX_TITLE_LENGTH 50

struct Chapter {
    char title[MAX_TITLE_LENGTH];
    char* content;
};

struct Ebook {
    char title[MAX_TITLE_LENGTH];
    struct Chapter* chapters[MAX_CHAPTERS];
    int num_chapters;
};

void display_menu() {
    printf("1. Open ebook\n");
    printf("2. Add chapter\n");
    printf("3. Remove chapter\n");
    printf("4. Save ebook\n");
    printf("5. Exit\n");
}

void open_ebook(struct Ebook* ebook) {
    char filename[MAX_TITLE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    char* buffer = (char*) malloc(MAX_BOOK_LENGTH * sizeof(char));

    if (file != NULL) {
        ebook->num_chapters = 0;

        while (fgets(buffer, MAX_BOOK_LENGTH, file) != NULL) {
            struct Chapter* chapter = (struct Chapter*) malloc(sizeof(struct Chapter));
            sscanf(buffer, "%50[^:]:%999s", chapter->title, chapter->content);
            ebook->chapters[ebook->num_chapters] = chapter;
            ebook->num_chapters++;
        }

        fclose(file);
        free(buffer);

        printf("Ebook '%s' opened with %d chapter(s)\n", ebook->title, ebook->num_chapters);
    } else {
        printf("Error: Could not open file '%s'\n", filename);
    }
}

void add_chapter(struct Ebook* ebook) {
    if (ebook->num_chapters < MAX_CHAPTERS) {
        struct Chapter* chapter = (struct Chapter*) malloc(sizeof(struct Chapter));
        printf("Enter chapter title: ");
        scanf("%s", chapter->title);
        printf("Enter chapter content: ");
        scanf("%s", chapter->content);
        ebook->chapters[ebook->num_chapters] = chapter;
        ebook->num_chapters++;
        printf("Chapter added successfully\n");
    } else {
        printf("Error: Maximum number of chapters reached\n");
    }
}

void remove_chapter(struct Ebook* ebook) {
    int index;
    printf("Enter index of chapter to remove: ");
    scanf("%d", &index);

    if (index >= 0 && index < ebook->num_chapters) {
        free(ebook->chapters[index]);
        ebook->num_chapters--;

        for (int i = index; i < ebook->num_chapters; i++) {
            ebook->chapters[i] = ebook->chapters[i + 1];
        }

        printf("Chapter removed successfully\n");
    } else {
        printf("Error: Invalid chapter index\n");
    }
}

void save_ebook(struct Ebook* ebook) {
    char filename[MAX_TITLE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "w");

    if (file != NULL) {
        for (int i = 0; i < ebook->num_chapters; i++) {
            fprintf(file, "%s:%s\n", ebook->chapters[i]->title, ebook->chapters[i]->content);
        }

        fclose(file);
        printf("Ebook saved successfully\n");
    } else {
        printf("Error: Could not save file '%s'\n", filename);
    }
}

int main() {
    struct Ebook ebook;
    ebook.num_chapters = 0;

    int choice;

    do {
        display_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                open_ebook(&ebook);
                break;
            case 2:
                add_chapter(&ebook);
                break;
            case 3:
                remove_chapter(&ebook);
                break;
            case 4:
                save_ebook(&ebook);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}