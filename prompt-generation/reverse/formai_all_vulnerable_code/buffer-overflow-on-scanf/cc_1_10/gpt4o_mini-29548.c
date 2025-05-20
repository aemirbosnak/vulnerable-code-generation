//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGE_SIZE 1024
#define MAX_TITLE_SIZE 100

void display_menu() {
    printf("\n--- Simple Ebook Reader ---\n");
    printf("1. Read Ebook\n");
    printf("2. Search Word\n");
    printf("3. Quit\n");
    printf("Please choose an option: ");
}

void read_ebook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    char buffer[MAX_PAGE_SIZE];
    int page_num = 0;
    while (fgets(buffer, MAX_PAGE_SIZE, file) != NULL) {
        printf("%s", buffer);
        if (++page_num % 20 == 0) {
            printf("\n--- Press Enter to continue ---");
            getchar();
        }
    }
    fclose(file);
}

void search_in_ebook(const char *filename, const char *word) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    char buffer[MAX_PAGE_SIZE];
    int line_number = 0;
    int found = 0;

    while (fgets(buffer, MAX_PAGE_SIZE, file) != NULL) {
        line_number++;
        if (strstr(buffer, word) != NULL) {
            printf("Found '%s' in line %d: %s", word, line_number, buffer);
            found = 1;
        }
    }

    if (!found) {
        printf("The word '%s' was not found in the ebook.\n", word);
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <ebook_file.txt>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    int choice;
    char search_word[50];

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // consume newline after choice

        switch (choice) {
            case 1:
                read_ebook(filename);
                break;
            case 2:
                printf("Enter the word to search: ");
                fgets(search_word, sizeof(search_word), stdin);
                search_word[strcspn(search_word, "\n")] = 0; // Remove newline
                search_in_ebook(filename, search_word);
                break;
            case 3:
                printf("Exiting Ebook Reader. Happy Reading!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}