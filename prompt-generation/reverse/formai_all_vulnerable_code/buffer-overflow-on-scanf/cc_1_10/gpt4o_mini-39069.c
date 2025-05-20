//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void display_menu() {
    printf("\n--- E-Book Reader ---\n");
    printf("1. Load E-Book\n");
    printf("2. View E-Book\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

char *load_ebook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }
    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *content = (char *)malloc(file_size + 1);
    if (!content) {
        fclose(file);
        perror("Memory allocation failed");
        return NULL;
    }
    
    fread(content, 1, file_size, file);
    content[file_size] = '\0'; // Null-terminate the string

    fclose(file);
    return content;
}

void view_ebook(const char *content) {
    if (content == NULL) {
        printf("No e-book loaded. Please load an e-book first.\n");
        return;
    }

    printf("\n--- Viewing E-Book ---\n");
    printf("%s\n", content);
}

void free_ebook(char *content) {
    if (content) {
        free(content);
    }
}

int main() {
    char *ebook_content = NULL;
    int option;
    char filename[100];

    while (1) {
        display_menu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter the e-book filename: ");
                scanf("%s", filename);
                ebook_content = load_ebook(filename);
                if (ebook_content != NULL) {
                    printf("E-Book '%s' loaded successfully.\n", filename);
                }
                break;
            case 2:
                view_ebook(ebook_content);
                break;
            case 3:
                free_ebook(ebook_content);
                printf("Exiting E-Book Reader. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }
    
    return 0;
}