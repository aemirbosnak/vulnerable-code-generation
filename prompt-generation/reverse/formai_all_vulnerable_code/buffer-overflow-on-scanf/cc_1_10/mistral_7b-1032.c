//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define RECORD_SIZE 100
#define FIELD_SIZE 50

typedef struct {
    char title[FIELD_SIZE];
    int release_year;
} GameRecord;

GameRecord database[MAX_RECORDS];
int num_records = 0;

void print_menu() {
    printf("\n----------------------------------\n");
    printf("| Retro Game Database Simulation |\n");
    printf("----------------------------------\n");
    printf("| 1. Add a new game record       |\n");
    printf("| 2. Search for a game           |\n");
    printf("| 3. Display all games           |\n");
    printf("| 4. Quit                        |\n");
    printf("----------------------------------\n");
}

void add_record() {
    if (num_records >= MAX_RECORDS) {
        printf("Database is full.\n");
        return;
    }

    printf("Enter game title: ");
    scanf("%s", database[num_records].title);
    printf("Enter release year: ");
    scanf("%d", &database[num_records].release_year);

    num_records++;
}

void search_record(int year) {
    int i;

    for (i = 0; i < num_records; i++) {
        if (database[i].release_year == year) {
            printf("\nGame found:\n");
            printf("Title: %s\n", database[i].title);
            printf("Release year: %d\n", database[i].release_year);
            return;
        }
    }

    printf("Game not found.\n");
}

void display_records() {
    int i;

    if (num_records == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\nGame records:\n");
    for (i = 0; i < num_records; i++) {
        printf("----------------------------------\n");
        printf("| Title: %s | Release year: %d |\n", database[i].title, database[i].release_year);
        printf("----------------------------------\n");
    }
}

int main() {
    int choice, search_year;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                printf("Enter release year to search: ");
                scanf("%d", &search_year);
                search_record(search_year);
                break;
            case 3:
                display_records();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}