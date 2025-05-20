//FormAI DATASET v1.0 Category: Ebook reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    int year;
} Book;

int main() {
    FILE *file;
    char filename[100];
    char buffer[1000];
    int fileLength;
    int selection;

    printf("Enter filename of eBook: ");
    scanf("%s", filename);

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file.");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    fileLength = ftell(file);
    fseek(file, 0, SEEK_SET);

    fread(buffer, sizeof(char), fileLength, file);
    fclose(file);

    printf("eBook loaded successfully.\n\n");

    Book book1 = {"Example Book", "John Doe", 2022};
    Book book2 = {"Another Book", "Jane Doe", 2021};

    printf("Welcome to the eBook reader!\n");
    printf("Please make a selection:\n");
    printf("1. Read %s by %s (%d)\n", book1.title, book1.author, book1.year);
    printf("2. Read %s by %s (%d)\n", book2.title, book2.author, book2.year);
    printf("3. Exit\n");

    scanf("%d", &selection);

    switch (selection) {
        case 1:
            printf("%s\n\n", buffer);
            printf("Thank you for reading %s by %s!\n", book1.title, book1.author);
            break;
        case 2:
            printf("%s\n\n", buffer);
            printf("Thank you for reading %s by %s!\n", book2.title, book2.author);
            break;
        case 3:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid selection.\n");
            break;
    }

    return 0;
}