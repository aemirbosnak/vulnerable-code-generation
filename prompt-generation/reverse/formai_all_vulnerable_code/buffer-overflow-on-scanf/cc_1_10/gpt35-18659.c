//FormAI DATASET v1.0 Category: Ebook reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_EBOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_FILE_NAME_LENGTH 20

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
} EBook;

EBook ebook_collection[MAX_EBOOKS];
int num_ebooks = 0;

void display_menu() {
    printf("EBook Reader\n");
    printf("=============================\n");
    printf("1. Add EBook\n");
    printf("2. Remove EBook\n");
    printf("3. View All EBooks\n");
    printf("4. View EBook Details\n");
    printf("5. Exit\n");
    printf("=============================\n");
}

void clear_screen() {
    system("clear");
}

void add_ebook() {
    if (num_ebooks >= MAX_EBOOKS) {
        printf("The maximum number of ebooks has been reached.\n");
        return;
    }

    printf("Enter Ebook Title: ");
    scanf("%s", ebook_collection[num_ebooks].title);

    printf("Enter Ebook Author: ");
    scanf("%s", ebook_collection[num_ebooks].author);

    printf("Enter Ebook File Name: ");
    scanf("%s", ebook_collection[num_ebooks].file_name);

    num_ebooks++;
}

void remove_ebook() {
    char title[MAX_TITLE_LENGTH];
    int i, index=-1;

    printf("Enter Ebook Title: ");
    scanf("%s", title);

    for (i=0; i<num_ebooks; i++) {
        if (strcmp(ebook_collection[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("EBook not found.\n");
        return;
    }

    for (i=index; i<num_ebooks-1; i++) {
        ebook_collection[i] = ebook_collection[i+1];
    }

    num_ebooks--;

    printf("EBook removed successfully.\n");
}

void view_all_ebooks() {
    int i;

    if (num_ebooks == 0) {
        printf("No ebooks.\n");
        return;
    }

    printf("EBook List\n");
    printf("| %-50s | %-50s | %-20s |\n", "Title", "Author", "File Name");
    printf("====================================================================================================\n");

    for (i=0; i<num_ebooks; i++) {
        printf("| %-50s | %-50s | %-20s |\n", ebook_collection[i].title, ebook_collection[i].author, ebook_collection[i].file_name);
    }
}

void view_ebook_details() {
    char title[MAX_TITLE_LENGTH];
    int i, index=-1;

    printf("Enter Ebook Title: ");
    scanf("%s", title);

    for (i=0; i<num_ebooks; i++) {
        if (strcmp(ebook_collection[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("EBook not found.\n");
        return;
    }

    printf("EBook Details\n");
    printf("=============================\n");
    printf("Title: %s\n", ebook_collection[index].title);
    printf("Author: %s\n", ebook_collection[index].author);
    printf("File Name: %s\n", ebook_collection[index].file_name);
}

int main() {
    int menu_choice;

    while (1) {
        display_menu();

        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                clear_screen();
                add_ebook();
                break;
            case 2:
                clear_screen();
                remove_ebook();
                break;
            case 3:
                clear_screen();
                view_all_ebooks();
                break;
            case 4:
                clear_screen();
                view_ebook_details();
                break;
            case 5:
                printf("Thank you for using the Ebook Reader.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}