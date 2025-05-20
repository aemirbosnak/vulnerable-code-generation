//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 256
#define MAX_LINE_LENGTH 1024

void display_menu() {
    printf("=================================\n");
    printf("Welcome to the C Ebook Reader!\n");
    printf("1. Open Ebook\n");
    printf("2. Next Page\n");
    printf("3. Previous Page\n");
    printf("4. Exit\n");
    printf("=================================\n");
}

typedef struct {
    char **lines;
    int total_lines;
    int current_page;
    int lines_per_page;
} Ebook;

Ebook* load_ebook(const char *filename, int lines_per_page) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }
  
    Ebook *ebook = (Ebook *)malloc(sizeof(Ebook));
    ebook->lines = (char **)malloc(MAX_LINE_LENGTH * sizeof(char *));
    ebook->total_lines = 0;
    ebook->current_page = 0;
    ebook->lines_per_page = lines_per_page;

    while (fgets(ebook->lines[ebook->total_lines], MAX_LINE_LENGTH, file)) {
        ebook->lines[ebook->total_lines] = strdup(ebook->lines[ebook->total_lines]);
        ebook->total_lines++;
    }
    
    fclose(file);
    return ebook;
}

void display_page(Ebook *ebook) {
    int start_index = ebook->current_page * ebook->lines_per_page;
    int end_index = start_index + ebook->lines_per_page;
    
    if (start_index >= ebook->total_lines) {
        printf("No more pages.\n");
        return;
    }
    
    printf("Page %d:\n", ebook->current_page + 1);
    for (int i = start_index; i < end_index && i < ebook->total_lines; i++) {
        printf("%s", ebook->lines[i]);
    }
}

void next_page(Ebook *ebook) {
    if ((ebook->current_page + 1) * ebook->lines_per_page < ebook->total_lines) {
        ebook->current_page++;
    } else {
        printf("You are already on the last page.\n");
    }
}

void previous_page(Ebook *ebook) {
    if (ebook->current_page > 0) {
        ebook->current_page--;
    } else {
        printf("You are already on the first page.\n");
    }
}

void free_ebook(Ebook *ebook) {
    for (int i = 0; i < ebook->total_lines; i++) {
        free(ebook->lines[i]);
    }
    free(ebook->lines);
    free(ebook);
}

int main() {
    char filepath[MAX_PATH];
    int choice;
    int lines_per_page = 10; // Display 10 lines per page

    printf("Enter the path to the ebook file: ");
    fgets(filepath, MAX_PATH, stdin);
    filepath[strcspn(filepath, "\n")] = 0; // Remove newline character

    Ebook *ebook = load_ebook(filepath, lines_per_page);
    if (!ebook) {
        return 1;
    }

    while (1) {
        display_page(ebook);
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                free_ebook(ebook);
                ebook = load_ebook(filepath, lines_per_page);
                break;
            case 2:
                next_page(ebook);
                break;
            case 3:
                previous_page(ebook);
                break;
            case 4:
                free_ebook(ebook);
                printf("Exiting ebook reader..\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}