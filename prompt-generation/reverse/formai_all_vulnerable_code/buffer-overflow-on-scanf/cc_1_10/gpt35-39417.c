//FormAI DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EBOOKS 10
#define MAX_TITLE_SIZE 50
#define MAX_AUTHOR_SIZE 30

typedef struct Ebook {
    char title[MAX_TITLE_SIZE];
    char author[MAX_AUTHOR_SIZE];
    int year;
    double price;
} Ebook;

typedef struct EbookReader {
    Ebook ebooks[MAX_EBOOKS];
    int count;
} EbookReader;

void print_menu() {
    printf("Ebook Reader Menu:\n");
    printf("-------------------\n");
    printf("1) Add Ebook\n");
    printf("2) List Ebooks\n");
    printf("3) Delete Ebook\n");
    printf("4) Save Ebook List\n");
    printf("5) Load Ebook List\n");
    printf("6) Exit\n");
}

void add_ebook(EbookReader *ereader) {
    if (ereader->count >= MAX_EBOOKS) {
        printf("Error: Ebook list is full. Cannot add more ebooks.\n");
        return;
    }

    Ebook ebook;

    printf("Enter Ebook Title: ");
    fgets(ebook.title, MAX_TITLE_SIZE, stdin);
    strtok(ebook.title, "\n"); // remove newline character

    printf("Enter Ebook Author: ");
    fgets(ebook.author, MAX_AUTHOR_SIZE, stdin);
    strtok(ebook.author, "\n"); // remove newline character

    printf("Enter Publication Year: ");
    scanf("%d", &ebook.year);

    printf("Enter Ebook Price: ");
    scanf("%lf", &ebook.price);

    ereader->ebooks[ereader->count++] = ebook;

    printf("Ebook added successfully!\n");

    // clear the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void list_ebooks(EbookReader *ereader) {
    if (ereader->count == 0) {
        printf("Ebook list is empty.\n");
        return;
    }

    printf("%-4s %-50s %-30s %-6s %-6s\n", "ID", "TITLE", "AUTHOR", "YEAR", "PRICE");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < ereader->count; i++) {
        Ebook ebook = ereader->ebooks[i];
        printf("%-4d %-50s %-30s %-6d %-6.2f\n", i+1, ebook.title, ebook.author, ebook.year, ebook.price);
    }
}

void delete_ebook(EbookReader *ereader) {
    if (ereader->count == 0) {
        printf("Ebook list is empty.\n");
        return;
    }

    int id;

    printf("Enter Ebook ID to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > ereader->count) {
        printf("Invalid Ebook ID.\n");
        return;
    }

    for (int i = id-1; i < ereader->count-1; i++) {
        ereader->ebooks[i] = ereader->ebooks[i+1];
    }

    ereader->count--;

    printf("Ebook deleted successfully!\n");
}

void save_ebooks(EbookReader *ereader) {
    FILE *fp = fopen("ebooks.txt", "w");

    if (fp == NULL) {
        printf("Error: Cannot open ebooks.txt file for writing.\n");
        return;
    }

    fprintf(fp, "ID,TITLE,AUTHOR,YEAR,PRICE\n");

    for (int i = 0; i < ereader->count; i++) {
        Ebook ebook = ereader->ebooks[i];
        fprintf(fp, "%d,%s,%s,%d,%.2f\n", i+1, ebook.title, ebook.author, ebook.year, ebook.price);
    }

    fclose(fp);

    printf("Ebook list saved successfully!\n");
}

void load_ebooks(EbookReader *ereader) {
    FILE *fp = fopen("ebooks.txt", "r");

    if (fp == NULL) {
        printf("Error: Cannot open ebooks.txt file for reading.\n");
        return;
    }

    char line[1024];
    int i = 0;

    // skip the header line
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL) {
        Ebook ebook;
        sscanf(line, "%*d,%[^,],%[^,],%d,%lf", ebook.title, ebook.author, &ebook.year, &ebook.price);
        ereader->ebooks[i++] = ebook;
    }

    ereader->count = i;

    fclose(fp);

    printf("Ebook list loaded successfully!\n");
}

int main() {
    EbookReader ereader = {0};

    int choice = 0;

    while (choice != 6) {
        print_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_ebook(&ereader);
                break;
            case 2:
                list_ebooks(&ereader);
                break;
            case 3:
                delete_ebook(&ereader);
                break;
            case 4:
                save_ebooks(&ereader);
                break;
            case 5:
                load_ebooks(&ereader);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
                break;
        }
    }

    return 0;
}