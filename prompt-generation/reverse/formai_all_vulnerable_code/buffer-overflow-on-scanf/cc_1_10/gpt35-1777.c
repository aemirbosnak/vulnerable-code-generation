//FormAI DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define INDEX_FILE_NAME "index.dat"

struct index_t {
    char keyword[32];
    long offset;
};

FILE *dbptr;
FILE *indexptr;

int add_entry(struct index_t index);
int search_keyword(char *keyword);
int print_index();

int main() {
    char keyword[32];
    long offset;
    int option;

    indexptr = fopen(INDEX_FILE_NAME, "r+");
    if (indexptr == NULL) {
        indexptr = fopen(INDEX_FILE_NAME, "w+");
        if (indexptr == NULL) {
            printf("Could not open index file '%s'.\n", INDEX_FILE_NAME);
            exit(EXIT_FAILURE);
        }
    }

    printf("Welcome to our Database Indexing System.\n");

    do {
        printf("\nChoose an option:\n");
        printf("  1. Add new entry.\n");
        printf("  2. Search by keyword.\n");
        printf("  3. Print index.\n");
        printf("  4. Quit.\n");
        printf("Option: ");

        if (scanf("%d", &option) < 1) {
            printf("Invalid option.\n");
            continue;
        }

        switch (option) {
            case 1:
                printf("\nEnter a keyword: ");
                scanf("%32[^\n]", keyword);
                while (getchar() != '\n');
                printf("Enter offset (>= 0): ");
                scanf("%ld", &offset);
                if (add_entry((struct index_t){keyword, offset})) {
                    printf("Entry added successfully.\n");
                } else {
                    printf("Could not add entry.\n");
                }
                break;
            case 2:
                printf("\nEnter a keyword: ");
                scanf("%32[^\n]", keyword);
                while (getchar() != '\n');
                if (search_keyword(keyword)) {
                    printf("Entry found.\n");
                } else {
                    printf("Entry not found.\n");
                }
                break;
            case 3:
                print_index();
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }

    } while (option != 4);

    fclose(indexptr);
    return 0;
}

int add_entry(struct index_t index) {
    if (fseek(indexptr, 0, SEEK_END)) {
        return 0;
    }
    if (fwrite(&index, sizeof(struct index_t), 1, indexptr) < 1) {
        return 0;
    }
    return 1;
}

int search_keyword(char *keyword) {
    struct index_t index;
    fseek(indexptr, 0, SEEK_SET);
    while (fread(&index, sizeof(struct index_t), 1, indexptr) == 1) {
        if (!strcasecmp(keyword, index.keyword)) {
            printf("Keyword: %s, Offset: %ld.\n", index.keyword, index.offset);
            return 1;
        }
    }
    return 0;
}

int print_index() {
    struct index_t index;
    fseek(indexptr, 0, SEEK_SET);
    printf("\nIndex:\n");
    printf("-----------------------------------------\n");
    printf("|            Keyword |         Offset |\n");
    printf("-----------------------------------------\n");
    while (fread(&index, sizeof(struct index_t), 1, indexptr) == 1) {
        printf("|%20s |%14ld |\n", index.keyword, index.offset);
    }
    printf("-----------------------------------------\n");
    return 1;
}