//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_BOOK_TITLE_LENGTH 100

void clear_screen() {
    // Function to clear the terminal screen
    printf("\033[H\033[J");
}

void show_welcome() {
    clear_screen();
    printf("====================================\n");
    printf("         Welcome to eBook Reader    \n");
    printf("====================================\n");
    printf("Load your favorite text files and\n");
    printf("enjoy reading them comfortably!\n");
    printf("Press enter to continue...\n");
    getchar();
}

void show_instructions() {
    clear_screen();
    printf("====================================\n");
    printf("        How to Use This Reader      \n");
    printf("====================================\n");
    printf("1. Load a book by entering its filename\n");
    printf("2. Navigate through the book using:\n");
    printf("   - [Enter] to read next line\n");
    printf("   - [B] to go back a line\n");
    printf("   - [Q] to quit\n");
    printf("Press enter to continue...\n");
    getchar();
}

void read_book(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file '%s'.\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    printf("Now Reading: %s\n", filename);
    printf("====================================\n");

    while (fgets(line, sizeof(line), file)) {
        printf("%02d: %s", line_number + 1, line);
        line_number++;

        char choice;
        printf("\nPress [Enter] for next line, [B] for back, or [Q] to quit: ");
        choice = getchar();
        getchar(); // Consume the newline after choice

        if (choice == 'Q' || choice == 'q') {
            printf("Exiting reader. Goodbye!\n");
            fclose(file);
            return;
        } else if (choice == 'B' || choice == 'b') {
            if (line_number > 1) {
                fseek(file, -2 * sizeof(line), SEEK_CUR); // Go back a line
                line_number -= 2; // Adjust line number counter
            } else {
                printf("You are at the beginning of the book!\n");
            }
        }

        clear_screen();
        printf("Now Reading: %s\n", filename);
        printf("====================================\n");
    }

    printf("End of the book reached! Thank you for reading.\n");
    fclose(file);
}

int main(int argc, char *argv[]) {
    show_welcome();
    show_instructions();

    char filename[MAX_BOOK_TITLE_LENGTH];
    
    printf("Enter the filename of the book you want to read: ");
    scanf("%s", filename);

    read_book(filename);
    
    return 0;
}