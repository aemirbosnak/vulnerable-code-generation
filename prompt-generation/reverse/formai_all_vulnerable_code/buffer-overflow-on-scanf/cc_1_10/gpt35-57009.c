//FormAI DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_EBOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_FILENAME_LENGTH 100

struct Ebook {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char filename[MAX_FILENAME_LENGTH];
};

void display_menu() {
    printf("Welcome to the Ebook Reader!\n");
    printf("1. Add an Ebook\n");
    printf("2. View Ebook library\n");
    printf("3. Read Ebook\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Ebook library[MAX_EBOOKS];
    int num_ebooks = 0;

    int choice;
    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_ebooks == MAX_EBOOKS) {
                    printf("Sorry, library is full!\n");
                } else {
                    printf("Enter title: ");
                    scanf("%s", library[num_ebooks].title);
                    printf("Enter author: ");
                    scanf("%s", library[num_ebooks].author);
                    printf("Enter filename: ");
                    scanf("%s", library[num_ebooks].filename);
                    num_ebooks++;
                }
                break;
            case 2:
                printf("Ebook library:\n");
                for (int i=0; i<num_ebooks; i++) {
                    printf("%d. %s by %s\n", i+1, library[i].title, library[i].author);
                }
                break;
            case 3:
                printf("Enter the number of the Ebook you want to read: ");
                int ebook_num;
                scanf("%d", &ebook_num);
                if (ebook_num < 1 || ebook_num > num_ebooks) {
                    printf("Invalid Ebook number!\n");
                } else {
                    char filename[MAX_FILENAME_LENGTH + 10] = "./ebooks/";
                    strcat(filename, library[ebook_num-1].filename);
                    FILE* ebook_file = fopen(filename, "r");
                    if (ebook_file == NULL) {
                        printf("Error opening Ebook file!\n");
                    } else {
                        char line[100];
                        while (fgets(line, 100, ebook_file)) {
                            printf("%s", line);
                        }
                        fclose(ebook_file);
                    }
                }
                break;
            case 4:
                printf("Exiting Ebook Reader!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}