//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a scroll
typedef struct {
    char title[50];
    char content[255];
} Scroll;

// Function prototypes
void displayScrolls(Scroll *library, int count);
void readScroll(Scroll *library, int index);
void cleanUp(Scroll *library);

// Entry point of the application
int main() {
    // An array of scrolls, representing the medieval library
    Scroll library[3] = {
        {"The Art of War", "A treatise on military strategy and tactics."},
        {"Alchemical Secrets", "Writings on transforming base metals into gold."},
        {"Tales of the Round Table", "Stories of chivalry and valor from King Arthur's court."}
    };

    int choice;
    
    while (1) {
        printf("\n=== Welcome to the Grand Library of Eldoria ===\n");
        printf("1. View the Scrolls\n");
        printf("2. Read a Scroll\n");
        printf("3. Leave the Library\n");
        printf("===============================================\n");
        
        printf("What dost thou wish to do? (Enter a number): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayScrolls(library, 3);
                break;
            case 2: {
                int scroll_choice;
                printf("Choose a scroll to read (1-3): ");
                scanf("%d", &scroll_choice);
                if (scroll_choice >= 1 && scroll_choice <= 3) {
                    readScroll(library, scroll_choice - 1);
                } else {
                    printf("Thou hast chosen an invalid scroll number.\n");
                }
                break;
            }
            case 3:
                printf("Farewell, noble soul! Until we meet again in these hallowed halls.\n");
                cleanUp(library);
                exit(0);
            default:
                printf("Thou hast entered an unknown command. Try again.\n");
        }
    }

    return 0;
}

// Function to display the list of scrolls
void displayScrolls(Scroll *library, int count) {
    printf("\n=== The Scrolls of Knowledge ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, library[i].title);
    }
}

// Function to read a specific scroll
void readScroll(Scroll *library, int index) {
    printf("\nReading: %s\n", library[index].title);
    printf("Synopsis: %s\n", library[index].content);
    printf("May this knowledge guide thee well on thy quest!\n");
}

// Function to clean up (if necessary)
void cleanUp(Scroll *library) {
    // Currently does not require any dynamic memory cleanup
    printf("Cleaning the library jewels for thy next visit.\n");
}