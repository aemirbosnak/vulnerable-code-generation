//FormAI DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50

typedef struct Database {
    int id;
    char name[MAX_SIZE];
    float score;
} Database;

void print_db(Database db) {
    printf("ID: %d\n", db.id);
    printf("Name: %s\n", db.name);
    printf("Score: %.2f\n\n", db.score);
}

void print_all_db(Database db[], int size) {
    int i;
    for(i=0; i<size; i++) {
        print_db(db[i]);
    }
}

void add_db(Database db[], int *size) {
    printf("Enter ID: ");
    scanf("%d", &db[*size].id);

    printf("Enter name: ");
    scanf("%s", &db[*size].name);

    printf("Enter score: ");
    scanf("%f", &db[*size].score);

    (*size)++;
}

void query_db(Database db[], int size) {
    int i, id;
    printf("Enter ID to query: ");
    scanf("%d", &id);

    for(i=0; i<size; i++) {
        if(db[i].id == id) {
            print_db(db[i]);
            return;
        }
    }

    printf("ID not found in database.\n");
}

void modify_db(Database db[], int size) {
    int i, id;
    printf("Enter ID to modify: ");
    scanf("%d", &id);

    for(i=0; i<size; i++) {
        if(db[i].id == id) {
            printf("Enter new score: ");
            scanf("%f", &db[i].score);
            return;
        }
    }

    printf("ID not found in database.\n");
}

int main() {
    int option, size=0;
    Database db[MAX_SIZE];

    while(1) {
        printf("Enter option:\n");
        printf("1. Add data\n");
        printf("2. Query data\n");
        printf("3. Modify data\n");
        printf("4. Print all data\n");
        printf("0. Exit program\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_db(db, &size);
                break;
            case 2:
                query_db(db, size);
                break;
            case 3:
                modify_db(db, size);
                break;
            case 4:
                print_all_db(db, size);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}