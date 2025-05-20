//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define PAGE_SIZE 5

void loadEbook(const char* filename, char lines[][BUFFER_SIZE], int* lineCount) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open the ebook");
        exit(EXIT_FAILURE);
    }

    *lineCount = 0;
    while (fgets(lines[*lineCount], BUFFER_SIZE, file) && *lineCount < PAGE_SIZE) {
        (*lineCount)++;
    }

    fclose(file);
}

void displayPage(char lines[][BUFFER_SIZE], int lineCount, int page) {
    // Shape-shifting header
    printf("=== Page %d ===\n", page + 1);
    for (int i = 0; i < lineCount; i++) {
        printf("| %s", lines[i]); // Shape shifts into a bordered format
    }
    printf("================\n");
}

void navigateEbook(char lines[][BUFFER_SIZE], int lineCount) {
    int currentPage = 0;
    char input;

    while (1) {
        displayPage(lines, lineCount, currentPage);
        printf("Press 'n' for next page, 'p' for previous page, or 'q' to quit: ");
        scanf(" %c", &input);

        if (input == 'n') {
            if (currentPage < lineCount - 1) {
                currentPage++;
            } else {
                printf("This is the last page.\n");
            }
        } else if (input == 'p') {
            if (currentPage > 0) {
                currentPage--;
            } else {
                printf("This is the first page.\n");
            }
        } else if (input == 'q') {
            printf("Exiting the ebook reader. Goodbye!\n");
            break;
        } else {
            printf("Invalid input! Please try again.\n");
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <ebook_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char lines[PAGE_SIZE][BUFFER_SIZE];
    int lineCount = 0;

    loadEbook(argv[1], lines, &lineCount);
    navigateEbook(lines, lineCount);

    return EXIT_SUCCESS;
}