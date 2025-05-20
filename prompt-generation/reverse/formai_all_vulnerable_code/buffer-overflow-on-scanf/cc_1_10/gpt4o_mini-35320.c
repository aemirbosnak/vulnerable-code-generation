//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKMARKS 100
#define URL_LENGTH 256

typedef struct {
    char url[URL_LENGTH];
} Bookmark;

void displayBookmarks(Bookmark bookmarks[], int count) {
    printf("\n--- Your Bookmarks ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, bookmarks[i].url);
    }
    printf("-----------------------\n");
}

int addBookmark(Bookmark bookmarks[], int count) {
    if (count >= MAX_BOOKMARKS) {
        printf("Bookmark limit reached! Cannot add more.\n");
        return count;
    }

    char newUrl[URL_LENGTH];
    printf("Enter new bookmark URL: ");
    fgets(newUrl, URL_LENGTH, stdin);
    newUrl[strcspn(newUrl, "\n")] = 0; // Remove newline character

    strcpy(bookmarks[count].url, newUrl);
    printf("Bookmark added!\n");
    return count + 1;
}

void removeBookmark(Bookmark bookmarks[], int *count) {
    int index;
    displayBookmarks(bookmarks, *count);
    printf("Enter the bookmark number to remove: ");
    scanf("%d", &index);
    getchar(); // Clear newline from buffer

    if (index < 1 || index > *count) {
        printf("Invalid bookmark number.\n");
    } else {
        for (int i = index - 1; i < *count - 1; i++) {
            bookmarks[i] = bookmarks[i + 1];
        }
        (*count)--;
        printf("Bookmark removed!\n");
    }
}

void clearBookmarks(Bookmark bookmarks[], int *count) {
    *count = 0;
    printf("All bookmarks cleared!\n");
}

void showMenu() {
    printf("\n--- Bookmark Manager ---\n");
    printf("1. Display Bookmarks\n");
    printf("2. Add Bookmark\n");
    printf("3. Remove Bookmark\n");
    printf("4. Clear All Bookmarks\n");
    printf("5. Exit\n");
    printf("------------------------\n");
    printf("Choose an option: ");
}

int main() {
    Bookmark bookmarks[MAX_BOOKMARKS];
    int count = 0;
    int choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                displayBookmarks(bookmarks, count);
                break;
            case 2:
                count = addBookmark(bookmarks, count);
                break;
            case 3:
                removeBookmark(bookmarks, &count);
                break;
            case 4:
                clearBookmarks(bookmarks, &count);
                break;
            case 5:
                printf("Exiting... Thank you for using the Bookmark Manager!\n");
                exit(0);
            default:
                printf("Invalid option. Please select again.\n");
                break;
        }
    }

    return 0;
}