//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SCROLLS 10
#define SCROLL_SIZE 256

typedef struct {
    char name[30];
    char content[SCROLL_SIZE];
} Scroll;

typedef struct {
    Scroll scrolls[MAX_SCROLLS];
    int count;
} KingdomLibrary;

void initializeLibrary(KingdomLibrary *library) {
    library->count = 0;
}

void createScroll(KingdomLibrary *library) {
    if (library->count >= MAX_SCROLLS) {
        printf("Alas! The library hath no more space for scrolls.\n");
        return;
    }
    
    Scroll newScroll;
    printf("Enter the name of thy scroll: ");
    scanf("%s", newScroll.name);
    printf("Indite thy scroll content (max 256 characters): ");
    getchar(); // to consume the newline
    fgets(newScroll.content, SCROLL_SIZE, stdin);
    
    library->scrolls[library->count] = newScroll;
    library->count++;
    printf("Huzzah! The scroll '%s' hath been inscribed.\n", newScroll.name);
}

void readScroll(KingdomLibrary *library) {
    char scrollName[30];
    printf("Whose scroll dost thou seek? (Enter scroll name): ");
    scanf("%s", scrollName);
    
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->scrolls[i].name, scrollName) == 0) {
            printf("The contents of the scroll '%s' are as follows:\n", scrollName);
            printf("%s\n", library->scrolls[i].content);
            return;
        }
    }
    
    printf("Alas! There be no scroll with the name '%s' in the library.\n", scrollName);
}

void deleteScroll(KingdomLibrary *library) {
    char scrollName[30];
    printf("Which scroll doth thou wish to cast into the abyss? (Enter scroll name): ");
    scanf("%s", scrollName);
    
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->scrolls[i].name, scrollName) == 0) {
            printf("The scroll '%s' hath been erased from existence!\n", scrollName);
            for (int j = i; j < library->count - 1; j++) {
                library->scrolls[j] = library->scrolls[j + 1];
            }
            library->count--;
            return;
        }
    }
    
    printf("Alas! There be no scroll with the name '%s' in the library.\n", scrollName);
}

void displayScrolls(KingdomLibrary *library) {
    if (library->count == 0) {
        printf("Nay! The library is barren, it contains no scrolls.\n");
        return;
    }
    
    printf("Behold the scrolls gracing the library:\n");
    for (int i = 0; i < library->count; i++) {
        printf("- %s\n", library->scrolls[i].name);
    }
}

int main() {
    KingdomLibrary library;
    initializeLibrary(&library);
    
    int choice;
    do {
        printf("\n--- The Royal Library of the Kingdom ---\n");
        printf("1. Create a new scroll\n");
        printf("2. Read a scroll\n");
        printf("3. Delete a scroll\n");
        printf("4. Display all scrolls\n");
        printf("5. Leave the library\n");
        printf("Choose thine action (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createScroll(&library);
                break;
            case 2:
                readScroll(&library);
                break;
            case 3:
                deleteScroll(&library);
                break;
            case 4:
                displayScrolls(&library);
                break;
            case 5:
                printf("Thou hast left the Royal Library. Fare thee well!\n");
                break;
            default:
                printf("Nay! That be not an option fit for a noble.\n");
        }
    } while (choice != 5);
    
    return 0;
}