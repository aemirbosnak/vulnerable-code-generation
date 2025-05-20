//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BOOKMARKS 100
#define URL_LENGTH 256
#define TITLE_LENGTH 100

typedef struct {
    char url[URL_LENGTH];
    char title[TITLE_LENGTH];
} Bookmark;

Bookmark bookmarks[MAX_BOOKMARKS];
int bookmark_count = 0;

void add_bookmark(const char *url, const char *title) {
    if (bookmark_count < MAX_BOOKMARKS) {
        strncpy(bookmarks[bookmark_count].url, url, URL_LENGTH);
        strncpy(bookmarks[bookmark_count].title, title, TITLE_LENGTH);
        bookmark_count++;
        printf("Bookmark added: %s - %s\n", title, url);
    } else {
        printf("Error: Bookmark limit reached!\n");
    }
}

void list_bookmarks() {
    printf("\nListing bookmarks:\n");
    for (int i = 0; i < bookmark_count; i++) {
        printf("%d: %s - %s\n", i + 1, bookmarks[i].title, bookmarks[i].url);
    }
    printf("\n");
}

void save_bookmarks_to_file(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(bookmarks, sizeof(Bookmark), bookmark_count, file);
        fclose(file);
        printf("Bookmarks saved to %s\n", filename);
    } else {
        printf("Error: Unable to open file for writing!\n");
    }
}

void load_bookmarks_from_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file != NULL) {
        bookmark_count = fread(bookmarks, sizeof(Bookmark), MAX_BOOKMARKS, file);
        fclose(file);
        printf("Bookmarks loaded from %s\n", filename);
    } else {
        printf("Error: Unable to open file for reading!\n");
    }
}

void display_menu() {
    printf("1. Add Bookmark\n");
    printf("2. List Bookmarks\n");
    printf("3. Save Bookmarks\n");
    printf("4. Load Bookmarks\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char url[URL_LENGTH], title[TITLE_LENGTH];
    const char *filename = "bookmarks.dat";

    while (1) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character after number input

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(url, URL_LENGTH, stdin);
                url[strcspn(url, "\n")] = 0; // Remove newline character
                
                printf("Enter Title: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                
                add_bookmark(url, title);
                break;

            case 2:
                list_bookmarks();
                break;

            case 3:
                save_bookmarks_to_file(filename);
                break;

            case 4:
                load_bookmarks_from_file(filename);
                break;
            
            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    
    return 0;
}